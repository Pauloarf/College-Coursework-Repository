var jwt = require('jsonwebtoken');

let token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VybmFtZSI6ImpjciIsImxldmVsIjoiZWRpdG9yIiwiZGVzYyI6IkNvaXNhcyBkYSB2aWRhLi4uIiwiaWF0IjoxNzQ2NDU0MjcwLCJleHAiOjE3NDY0NTQzNzB9.r3jauoaKB1emcezSNvPwnsmhz2mqRBCxdY_Ht9ETgEI"

jwt.verify(token, 'EngWeb2025', function(e, payload){
    if(e) console.log('Erro na verificação do token: ' + e)
    else console.log('Payload ' + payload)
})
