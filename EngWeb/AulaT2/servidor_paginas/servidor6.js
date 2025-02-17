import { createServer } from 'http'
import { myDateTime } from './aux.js'
import { parse } from 'url'

var myServer = createServer(function (req, res) {
    console.log(req.method + " " + req.url + " " + myDateTime())
    res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})

    var q = parse(req.url, true)
    
    if(q.pathname == "/add"){
        var soma = parseInt(q.query.n1, 10) + parseInt(q.query.n2, 10)
        res.write("<pre>" + soma + "=" + q.query.n1 + "+" + q.query.n2 + "</pre>")
    }
    else if(q.pathname == "/sub"){
        var sub = parseInt(q.query.n1, 10) - parseInt(q.query.n2, 10)
        res.write("<pre>" + sub + "=" + q.query.n1 + "-" + q.query.n2 + "</pre>")
    }
    else if(q.pathname == "/div"){
        var sub = parseInt(q.query.n1, 10) - parseInt(q.query.n2, 10)
        res.write("<pre>" + sub + "=" + q.query.n1 + "/" + q.query.n2 + "</pre>")
    }
    else{
        res.write("<p>Operação não suportada...</p>")
    }
    res.end()
})

myServer.listen(7777)
console.log("Servidor à escuta na porta 7777...")