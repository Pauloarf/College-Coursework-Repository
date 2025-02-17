import axios from 'axios'
import { createServer } from 'http'
import { genMainPage } from './mypages.js'
import { readFile } from 'fs'

createServer(function (req, res) {
    const date = new Date().toISOString().substring(0,16)
    console.log(req.method + " " + req.url + " " + date)

    if(req.url == '/'){
        res.writeHead(200, {'Content-type': 'text/html; charset=utf-8'})
        res.write(genMainPage(data))
        res.end()
    }
    else if (req.url == '/reps'){
        axios.get('http://localhost:3000/reparacoes').then(function(res) {
            const reps = res.data
            res.writeHead(200, {'Content-type': 'text/html; charset=utf-8'})
            res.write(genRepsPage(reps, date))
            res.end()
        }).catch((error) => {
            res.writeHead(500, {'Content-Type': 'text/html;charset=utf-8'});
            res.write("<p>Erro: " + error + "</p>");
            res.end();    
        });
    } else if (req.url.match(/w3\.css$/)) {
        fs.readFile("w3.css", function(erro,dados) {
            if(erro) {
                res.writeHead(404, {'Content-Type': 'text/html;charset=utf-8'})
                res.end('<p>Erro na leitura do ficheiro: ' + erro + '</p>')
            }
            else {
                res.writeHead(200, {'Content-Type': 'text/css'})
                res.end(dados)
            }
        })
    } else {
        res.writeHead(404, {'Content-Type': 'text/html;charset=utf-8'});
        res.end()
    }
}).listen(7777)

console.log("Servidor à escuta na porta 7777...")




