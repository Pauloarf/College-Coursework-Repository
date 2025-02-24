const http = require('http');
const meta = require('./auxiliar');

http.createServer((req, res) => {
    console.log("METHOD: " + req.method);
    console.log("URL: " + req.url);

    switch(req.method){
        case "GET":
            switch(req.url){
                case "/":
                    res.writeHead(200, {'Content-Type': 'text/html;charset=utf-8'});
                    res.write('Olá turma de 2025!\n');
                    break;
                case "/data":
                    res.writeHead(200, {'Content-Type': 'text/html;charset=utf-8'});    
                    res.write(meta.myDateTime());
                    break;
                case "/nome":
                    res.writeHead(200, {'Content-Type': 'text/html;charset=utf-8'});    
                    res.write(meta.myName());
                    break;
                case "/turma":
                    res.writeHead(200, {'Content-Type': 'text/html;charset=utf-8'});
                    res.write(meta.turma);
                    break;
                default:
                    res.writeHead(404, {'Content-Type': 'text/html;charset=utf-8'});
                    break;
            }
            break;
        default:
            res.writeHead(405, {'Content-Type': 'text/html;charset=utf-8'});
            break;
    }
    res.end();    
}).listen(1234);

console.log('Servidor à escuta na porta 1234...');