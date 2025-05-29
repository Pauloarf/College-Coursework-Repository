var jwt = require('jsonwebtoken');
try{
    var token = jwt.sign(
    { username: 'jcr', level: 'editor', desc: 'Coisas da vida...'},
    'EngWeb2025',
    {expiresIn: 100});
    console.log('Token: ' + token)
} catch(e) {
    console.log('Erro na criação do token: ' + e);
}

