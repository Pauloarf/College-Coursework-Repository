const http = require('http');
const axios = require('axios');
const meta = require('./aux');

http.createServer((req, res) => {
    console.log("METHOD: " + req.method);
    console.log("URL: " + req.url);

    switch(req.method){
        case "GET":
            switch(req.url){
                case "/":
                    res.writeHead(200, {'Content-Type': 'text/html;charset=utf-8'});
                    res.write('Olá MALUCOSSS!\n');
                    res.write('<p><a href="/cidades">Cidades</a></p>');
                    res.write('<p><a href="/ligacoes">Ligações</a></p>');
                    res.end();    
                    break;
                case "/cidades":
                    axios.get('http://localhost:3000/cidades?sort=nome').then((resp) => {
                        var cidades = resp.data;
                        res.writeHead(200, {'Content-Type': 'text/html;charset=utf-8'});
                        res.write('<h1>Cidades</>');
                        res.write('<ul>');
                        cidades.forEach(cidade => {
                            res.write('<li>' + cidade.nome + '</li>');
                        });
                        res.write('</ul>');
                        res.end();    
                    }).catch((error) => {
                        res.writeHead(500, {'Content-Type': 'text/html;charset=utf-8'});
                        res.write("<p>Erro: " + error + "</p>");
                        res.end();    
                    });
                    break;
                case "/ligacoes":
                    res.writeHead(501, {'Content-Type': 'text/html;charset=utf-8'});
                    res.end();    
                    break;
                default:
                    res.writeHead(404, {'Content-Type': 'text/html;charset=utf-8'});
                    res.end();    
                    break;
            }
            break;
        default:
            res.writeHead(405, {'Content-Type': 'text/html;charset=utf-8'});
            res.end();    
            break;
    }
}).listen(1234);

console.log('Servidor à escuta na porta 1234...');