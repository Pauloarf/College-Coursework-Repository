const http = require('http');
const axios = require('axios');
const meta = require('./aux');

http.createServer((req, res) => {
    console.log("METHOD: " + req.method);
    console.log("URL: " + req.url);

    switch(req.method){
        case "GET":
            if (req.url == "/cidades") {
                axios.get('http://localhost:3000/cidades?_sort=nome').then((resp) => {
                    var cidades = resp.data;
                    res.writeHead(200, {'Content-Type': 'text/html;charset=utf-8'});
                    res.write('<h1>Cidades</>');
                    res.write('<ul>');
                    cidades.forEach(cidade => {
                        res.write('<li><a href="/cidades/' + cidade.id + '">' + cidade.nome + '</a></li>');
                    });
                    res.write('</ul>');
                    res.end();    
                }).catch((error) => {
                    res.writeHead(500, {'Content-Type': 'text/html;charset=utf-8'});
                    res.write("<p>Erro: " + error + "</p>");
                    res.end();
                });
            } else if (req.url.match(/\/cidades\/.+/)) {
                var id = req.url.split("/")[2];
                axios.get('http://localhost:3000/cidades/' + id).then((resp) => {
                    var cidade = resp.data;
                    res.writeHead(200, {'Content-Type': 'text/html;charset=utf-8'});
                    res.write(`<h1>${cidade.nome}</>`);
                    res.write(`<pre>${JSON.stringify(cidade)}</pre>`);
                    res.write('</ul>');
                    res.write("<h6><a href='/cidades'>Voltar</a></h6>");
                    res.end();    
                }).catch((error) => {
                    res.writeHead(500, {'Content-Type': 'text/html;charset=utf-8'});
                    res.write("<p>Erro: " + error + "</p>");
                    res.end();    
                });
            } else {
                res.writeHead(404, {'Content-Type': 'text/html;charset=utf-8'});
                res.end();
            }
            break;
        default:
            res.writeHead(405, {'Content-Type': 'text/html;charset=utf-8'});
            res.end();    
            break;
    }
}).listen(1234);

console.log('Servidor à escuta na porta 1234...');