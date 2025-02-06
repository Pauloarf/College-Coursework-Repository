import json
import os
import shutil

def open_json(filename):
    # Abre o arquivo JSON e retorna o conteúdo
    with open(filename, 'r', encoding='utf-8') as file:
        data = json.load(file)

    return data

def mk_dir(relative_path):
    # Cria a pasta se ela não existir
    if not os.path.exists(relative_path):
        os.mkdir(relative_path)
    # Se a pasta já existir, apaga e cria uma nova
    else:
        shutil.rmtree(relative_path)
        os.mkdir(relative_path)

def new_file(filename, content):
    f = open(filename, 'w', encoding='utf-8')
    f.write(content)
    f.close()


'''        
lista_nif = []
lista_matriculas = []
json_obj = open_json('dataset_reparacoes.json')
for reparacao in json_obj['reparacoes']:
    nif = reparacao['nif']
    matricula = reparacao['viatura']['matricula']

    # Verifica se o NIF já existe na lista
    if(nif in lista_nif):
        print(f"O NIF {nif} já existe na lista")
    else:
        lista_nif.append(nif)

    # Verifica se a matrícula já existe na lista
    if(matricula in lista_matriculas):
        print(f"A matrícula {matricula} já existe na lista")
    else:
        lista_matriculas.append(matricula)
'''

# Aqui vamos escrever o código HTML 

# Notas:
# O header é metainformação sobre o documento (Mas aparece na página)
# Para representar títulos usamos os elementos <h1>, <h2>, ..., <h6> (heading)
# Para representar listas podemos usar o elemento <ul> (unordered list) ou <ol> (ordered list)
# Para representar itens de lista usamos o elemento <li> (list item)
html = '''
<!DOCTYPE html>

<html>
    <head>
        <title>Reparações</title>
    </head>
    <body>
        <h1>Reparações</h1>
            <ul>
'''

lista_reparacoes = []
json_obj = open_json('dataset_reparacoes.json')
for reparacao in json_obj['reparacoes']:
    data = reparacao['data']
    nif = reparacao['nif']
    nome = reparacao['nome']
    marca = reparacao['viatura']['marca']
    modelo = reparacao['viatura']['modelo']
    matricula = reparacao['viatura']['matricula']
    html += f'<li>{data} || {nif} || {nome} || {marca} || {modelo} || {matricula}</li>\n'

html += '''
            </ul>
    
    </body>
</html>
'''

new_file('lista_geral.html', html)

html = '''
<!DOCTYPE html>

<html>
    <head>
        <title>Intervenções</title>
    </head>
    <body>
        <h1>Intervenções</h1>
            <ul>
'''

dict_intervencoes = {}
json_obj = open_json('dataset_reparacoes.json')
for reparacao in json_obj['reparacoes']:
    for intervencao in reparacao['intervencoes']:   
        dict_intervencoes[intervencao['codigo']] = intervencao

for codigo in sorted(dict_intervencoes.keys()):
    nome = dict_intervencoes[codigo]['nome']
    descricao = dict_intervencoes[codigo]['descricao']
    html += f'<li>{codigo} || {nome} || {descricao}</li>\n'

html += '''
            </ul>
    
    </body>
</html>
'''

new_file('lista_intervencoes.html', html)

# Fazer lista das marcas e modelos que foram intervencionados, por marcas e modelos
# Colocar marca modelo e numero de carros

html = '''
<!DOCTYPE html>

<html>
    <head>
        <title>Carros</title>
    </head>
    <body>
        <h1>Carros</h1>
            <ul>
'''

dict_carros = {}

json_obj = open_json('dataset_reparacoes.json')
for reparacao in json_obj['reparacoes']:
    for viatura in reparacao['viatura']:
        marca = reparacao['viatura']['marca']
        modelo = reparacao['viatura']['modelo']

        if(marca in dict_carros.keys()):
            # Verificar se o modelo existe
            if(modelo in dict_carros[marca]):
                # Aumentar o numero de carros
                dict_carros[marca][modelo] += 1
            else:
                dict_carros[marca][modelo] = 1
        else:
            dict_carros[marca] = {}
            dict_carros[marca][modelo] = 1

for marca in sorted(dict_carros.keys()):
    total = 0
    aux = '<ul>'
    for modelo in sorted(dict_carros[marca]):
        number = dict_carros[marca][modelo]
        total += number
        aux += f'<li>{modelo} || {number} </li>\n'
    aux += '</ul>'
    html += f'<li>{marca} || {total} </li>\n'
    html += aux

html += '''
            </ul>
    
    </body>
</html>
'''

new_file('lista_marcas.html', html)