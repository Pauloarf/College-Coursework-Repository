# Comandos mongo
e45d85f4e080

docker pull mongo
docker images

docker run -d -p 27017:27017 --name mongoEW -v "nome do volume":"onde guardar os dados dentro do container" "nome da imagem"(e.g: mongoData2025:/data/db mongo)
-d detach
-p mapeia a porta da maquina na porta interna do container, a primeira é a da minha maquina(27017 é default do mongoDB)
--name Define o nome

-lista os dockers que estão a correr
docker ps

-- remove docker com containerID
sudo docker stop c831ad0730f3    

docker logs -f mongoEW
-f pendura a consola, deixa-a sempre a escuta

docker volume --help

docker cp jcrpubs.json lucid_poitras:/tmp

docker exec lucid_poitras mongoimport -d pubs -c pubs /tmp/jcrpubs.json --jsonArray
-d nome da base de dados
-c nome da colução

docker exec -it mongoEW sh

-O jsnoArray é caso a formatação já esteja de acordo com o mongo
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


# Importing a dataset
Copy dataset into container
Execute a shell inside container
Import dataset into mongodb
Check it with mongosh.