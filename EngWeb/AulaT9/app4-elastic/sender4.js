const   axios = require('axios'),
        FormData = require( "form-data" ),
        fs = require('fs')

const form = new FormData();
var filepath = "../ficheiros-cartoons/coyotte.png"; 
// ...

filepath = "../ficheiros-cartoons/bugs-bunny.jpg"; 
// ...

filepath = "../fpessoa/musica.txt"; 
// ...

axios.post( "http://localhost:15001/ficheiros", form )
    .then(resposta => {
        console.log("Enviado com sucesso.")
        console.log(JSON.stringify(resposta))
    })
    .catch(erro => {
        console.log(JSON.stringify(erro))
    })

  


