const http = require('http');

http.createServer((req, res) => {
    res.writeHead(200, {'Content-Type': 'text/plain;charset=utf-8'});
    res.write('Olá turma de 2025!\n');
    res.end();    
}).listen(1234);

console.log('Servidor à escuta na porta 1234...');