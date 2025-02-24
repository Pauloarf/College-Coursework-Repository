import { createServer } from 'http'
import { myDateTime } from './auxiliar.js'
import { parse } from 'url'

var myServer = createServer(function (req, res) {
    console.log(req.method + " " + req.url + " " + myDateTime())
    res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})

    // Este exemplo faz análise sematinca ({a = x, b = y})
    var q = parse(req.url, true)
    res.write('True: <pre>' + JSON.stringify(q) + '</pre>')

    // Este exemplo nao faz analise semantica, só sintática. soma?a=x&b=y
    var q2 = parse(req.url, false)
    res.write('False: <pre>' + JSON.stringify(q2) + '</pre>')

    res.end()
})

myServer.listen(7777)
console.log("Servidor à escuta na porta 7777...")