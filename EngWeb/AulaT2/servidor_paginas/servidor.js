import { createServer } from 'http';

createServer(function (req, res) {
    res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'});
    res.end('Olá turma de 2025!');
}).listen(7777);

console.log("Servidor à escuta na porta 7777...")