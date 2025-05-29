const   axios = require('axios'),
        FormData = require( "form-data" ),
        fs = require('fs')

const form = new FormData();
const filepath = "../ficheiros-cartoons/coyotte.png"; 

form.append("myFile", fs.createReadStream( filepath ))
form.append("desc", "Uma imagem do Coyotte!")

axios.post( "http://localhost:15000/ficheiro", form )
    .then(resposta => {
        console.log("Enviado com sucesso.")
        console.log(JSON.stringify(resposta))
    })
    .catch(erro => {
        console.log(JSON.stringify(erro))
    })