import { createServer } from 'http'
import { myDateTime } from './auxiliar.js'
import { parse } from 'url'
import { readFile } from 'fs'

var myServer = createServer(function (req, res) {
    console.log(req.method + " " + req.url + " " + myDateTime())

    // A biblioteca parse é util para poder extrair elementos da query string
    var pedido = parse(req.url, true).pathname

    readFile('pag' + pedido.substring(1) + '.html', function(err, data) {
        res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})
        if(err){
            res.write("ERRO: na leitura do ficheiro :: " + err)
        }
        else{
            res.write(data)
        }
        res.end()
    })
})

myServer.listen(7777)
console.log("Servidor à escuta na porta 7777...")