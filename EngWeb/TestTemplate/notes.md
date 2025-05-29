# Docker

[LIST ALL CONTAINERS]
docker ps -a

[OPEN DOCKER SHELL]
docker exec -it mongoEW sh


# Comandos mongo
docker pull mongo
docker images

docker run -d -p 27017:27017 --name mongoEW -v "nome do volume":"onde guardar os dados dentro do container" "nome da imagem"(e.g: mongoData2025:/data/db mongo)
-d detach
-p mapeia a porta da maquina na porta interna do container, a primeira é a da minha maquina(27017 é default do mongoDB)
--name Define o nome

docker ps

docker logs -f mongoEW
-f pendura a consola, deixa-a sempre a escuta

docker volume --help

docker cp jcrpubs.json lucid_poitras:/tmp

docker exec lucid_poitras mongoimport -d pubs -c pubs /tmp/jcrpubs.json --jsonArray
-d nome da base de dados
-c nome da colução

docker exec -it mongoEW sh

mongoimport -d pubs -c pubs /tmp/jcrpubs.json --jsonArray

# Dentro do mongo
mongosh

show databases
use name
db.pubs.countDocuments()
db.pubs.find()
db.find()

//Projeção - Seleciona tudo mas nao mostra o id, e esta ordenada descendentemente por ano 
db.pubs.find({}, {_id:0, title:1, type:1, year:1}).sort({year:-1})

//Quantos artigos tinha em conferences
db.pubs.find({type:"inproceedings"}).count()

//joining projection and selection
db.pubs.find({authors:"Pedro Rangel Henriques"}, {id:1, title:1, _id:0})

//Multiple criteria
db.pubs.find({authors:"Pedro Rangel Henriques", year:"1997"}, {id:1, title:1, _id:0})

// Resulução
db.records.countDocuments()
db.records.find({prov:"Alentejo"})
db.records.countDocuments({"file.-t": "MP3"})

db.records.find({"$or":[{"tit": {"regex": "Jesus", "$options": "i"}},{"tit": {"regex": "Maria", "$options": "i"}}]}, {"tit":1,"_id":0})
db.records.distinct("prov")

Distribution of records by province
db.recors.agrregate([
    {"$group": {"_id": "$prov", "count":{"$sum": 1}}},
    {"$group": {{"_id": 1}}
])

# Prompts chatgpt

## Convert Json
Cria um script em Node.js que:

1. **Lê um ficheiro JSON bruto localizado em `./rawDB/nomeDB.json`** (um array de objetos).
2. **Valida e normaliza o conteúdo para que esteja pronto a ser importado para o MongoDB**, conforme as seguintes regras:

   * Garante que cada item seja um objeto JSON válido.
   * Uniformiza todos os objetos: todos devem conter as mesmas chaves (com valores `null` onde não houver dados).
   * Corrige o tipo de dados quando necessário (ex: números como strings → number).
   * Normaliza valores inconsistentes (ex: string vs array).
   * Corrige chaves inválidas para o MongoDB (ex: remove ou substitui `.` e `$` em nomes de campos).
   * Remove estruturas aninhadas problemáticas, se necessário.
3. **Escreve o JSON resultante no ficheiro `./db/nomeDB.json`**, como um array válido de objetos, pronto para ser importado com:

```bash
mongoimport --db nomeDB --collection nomeDB --file ./db/nomeDB.json --jsonArray
```

DATASET:
```json
```

4. **(Opcional)**: adapta a normalização de acordo com o seguinte contexto do dataset:
**\[DETALHES\_DO\_DATASET]**

Requisitos técnicos:
* Usa apenas bibliotecas nativas do Node.js (`fs`, `path`, etc).
* Tudo deve estar num único ficheiro `.js` (por exemplo, `normalizeJson.js`).
* O script deve ser executável diretamente com `node normalizeJson.js`.

## Pedir queries mongoose
Tu és um assistente especializado em MongoDB.

Vou-te enviar um exemplo de documento da base de dados, e depois uma pergunta sobre os dados.

A tua tarefa é gerar apenas a query MongoDB equivalente à pergunta que eu fizer, assumindo que os documentos têm estrutura semelhante à entrada.

Segue o seguinte formato:

Entrada:
<INSERE AQUI UM DOCUMENTO JSON>

Pergunta:
<INSERE AQUI A PERGUNTA>

Resposta:
<GERA AQUI A QUERY MONGODB>


# How to??
Retirar as primeiras entradas do json com `head --lines=100 rawDB/contratos.json`
Colocar o prompt no chat com o json
Ter o json no rawDB, fazer conversão
Substituir os sitios que tem nomeDB pelo nome, inclusive no yml
Usar o yml