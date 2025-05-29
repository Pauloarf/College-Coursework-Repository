const   axios = require('axios'),
        FormData = require( "form-data" ),
        fs = require('fs')

const form = new FormData();
var filepath = "../ficheiros-cartoons/coyotte.png"; 
// ...

filepath = "../ficheiros-cartoons/bugs-bunny.jpg"; 
// ...

filepath = "../fpessoa/alma.txt"; 
// ...

filepath = "../fpessoa/arte.txt"; 
// ...

axios.post( "http://localhost:15002/ficheiros", form )
    .then(resposta => {
        console.log("Enviado com sucesso.")
        console.log(JSON.stringify(resposta.data))
    })
    .catch(erro => {
        console.log(JSON.stringify(erro))
    })

  


