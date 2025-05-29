const fs = require('fs');
const path = require('path');

// Função utilitária para limpar nomes de campos inválidos para MongoDB
function cleanKey(key) {
  return key.replace(/\./g, '_').replace(/\$/g, '_');
}

// Função para tentar converter strings para tipos corretos
function coerceType(value) {
  if (value === null || value === undefined) return null;

  if (typeof value === 'string') {
    const trimmed = value.trim();

    // Tenta converter para número
    if (!isNaN(trimmed) && trimmed !== '') {
      return Number(trimmed);
    }

    // Tenta converter para data ISO
    const date = new Date(trimmed);
    if (!isNaN(date.getTime())) {
      return trimmed;
    }

    return trimmed;
  }

  if (Array.isArray(value)) {
    return value.map(coerceType);
  }

  if (typeof value === 'object') {
    return flattenObject(value);
  }

  return value;
}

// Remove aninhamentos problemáticos (achata objetos aninhados)
function flattenObject(obj, prefix = '') {
  const flat = {};
  for (const key in obj) {
    const cleanedKey = cleanKey(key);
    const fullKey = prefix ? `${prefix}_${cleanedKey}` : cleanedKey;
    if (typeof obj[key] === 'object' && obj[key] !== null && !Array.isArray(obj[key])) {
      Object.assign(flat, flattenObject(obj[key], fullKey));
    } else {
      flat[fullKey] = coerceType(obj[key]);
    }
  }
  return flat;
}

// Lê o ficheiro bruto
const inputPath = path.join(__dirname, 'rawDB', 'contratos.json');
const outputPath = path.join(__dirname, 'db', 'contratos.json');

try {
  const rawData = fs.readFileSync(inputPath, 'utf8');
  const data = JSON.parse(rawData);

  if (!Array.isArray(data)) {
    throw new Error('O ficheiro JSON deve conter um array de objetos.');
  }

  // Extrai todas as chaves possíveis
  const allKeysSet = new Set();
  const normalizedData = data.map(item => {
    if (typeof item !== 'object' || item === null || Array.isArray(item)) {
      console.warn('Item inválido removido:', item);
      return null;
    }

    const flattened = flattenObject(item);
    Object.keys(flattened).forEach(key => allKeysSet.add(key));
    return flattened;
  }).filter(Boolean);

  const allKeys = Array.from(allKeysSet);

  // Garante uniformidade de chaves
  const uniformData = normalizedData.map(item => {
    const newItem = {};
    allKeys.forEach(key => {
      newItem[key] = item.hasOwnProperty(key) ? item[key] : null;
    });
    return newItem;
  });

  // Cria pasta de saída, se necessário
  const outputDir = path.dirname(outputPath);
  if (!fs.existsSync(outputDir)) {
    fs.mkdirSync(outputDir, { recursive: true });
  }

  // Escreve o JSON normalizado
  fs.writeFileSync(outputPath, JSON.stringify(uniformData, null, 2), 'utf8');
  console.log(`✅ Ficheiro normalizado gravado com sucesso em: ${outputPath}`);
  console.log(`👉 Pronto para importar com:\n   mongoimport --db contratos --collection contratos --file ./db/contratos.json --jsonArray`);

} catch (err) {
  console.error('❌ Erro ao processar o ficheiro JSON:', err.message);
}

//TODO: ISTO FOI UM EXEMPLO DE TESTE, DEVE SER ALTERADO