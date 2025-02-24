// treinos_server.js
// EW2025 : 2025-02-24
// by jcr

var http = require('http')
var axios = require('axios')
const { parse } = require('querystring');

var templates = require('./templates.js')           // Necessario criar e colocar na mesma pasta
var static = require('./static.js')                 // Colocar na mesma pasta

// Aux functions
function collectRequestBodyData(request, callback) {
    if(request.headers['content-type'] === 'application/x-www-form-urlencoded') {
        let body = '';
        request.on('data', chunk => {
            body += chunk.toString();
        });
        request.on('end', () => {
            callback(parse(body));
        });
    }
    else {
        callback(null);
    }
}

// Server creation

var treinosServer = http.createServer((req, res) => {
    // Logger: what was requested and when it was requested
    var d = new Date().toISOString().substring(0, 16)
    console.log(req.method + " " + req.url + " " + d)

    // Handling request
    if(static.staticResource(req)){
        static.serveStaticResource(req, res)
    }
    else{
        switch(req.method){
            case "GET": 
                switch(req.url){
                    // GET /treinos ------------------------------------------------------------------
                    case '/treinos':
                        axios.get('http://localhost:3000/treinos').then(
                        (response) => {
                            data = response.data;
                            res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})
                            res.write(templates.treinosListPage(data, d))
                            res.end()
                        }).catch(error => {
                            console.log(error);
                            res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'})
                            res.end(templates.errorPage(error, d))
                        })
                        break;
                    // GET /treinos/register ---------------------------------------------------------
                    case '/treinos/register':
                        res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})
                        res.write(templates.treinoFormPage(d))
                        res.end()
                        break;
                        
                        // GET /treinos/edit/:id ---------------------------------------------------------
                
                        // GET /treinos/delete/:id -------------------------------------------------------

                        // GET /treinos/:personID --------------------------------------------------------
                        
                        // GET ? -> Lancar um erro
                    default:
                        res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'})
                        res.end(templates.errorPage(`Pedido não suportado ${req.url}`, d))
                    }
                break
            case "POST":
                switch(req.url){
                    case '/treinos/register':
                        collectRequestBodyData(req, result => {
                            if(result){
                                axios.post("http://localhost:3000/treinos", result).then(
                                    (response) => {
                                        data = response.data;
                                        res.writeHead(201, {'Content-Type': 'text/html; charset=utf-8'})
                                        res.write(`<pre>${JSON.stringify(data)}</pre>`)
                                        res.end()
                                    }).catch(error => {
                                        console.log(error);
                                        res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'})
                                        res.end(templates.errorPage(error, d))
                                    })
                            } else {
                                res.writeHead(512, {"Content-Type": 'text/html; charset=utf-8'})
                                res.end(template.errorPage('Não chegou informação ao servidor...'))
                            }
                        })
                }
                // POST /treinos --------------------------------------------------------------------

                // POST ? -> Lancar um erro
                
            default: 
                // Outros metodos nao sao suportados
        }
    }
})

treinosServer.listen(7777, ()=>{
    console.log("Servidor à escuta na porta 7777...")
})



