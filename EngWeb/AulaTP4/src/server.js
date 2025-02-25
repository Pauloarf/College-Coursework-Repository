// alunos_server.js
// EW2024 : 04/03/2024
// by jcr

var http = require('http')
var axios = require('axios')
const { parse } = require('querystring');

var templates = require('../templates.js')          // Necessario criar e colocar na mesma pasta
var static = require('../static.js')             // Colocar na mesma pasta

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

var alunosServer = http.createServer((req, res) => {
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
                // GET /alunos --------------------------------------------------------------------
                if(req.url === '/' || req.url === '/alunos'){
                    axios.get("http://localhost:3000/alunos").then(
                        (response) => {
                            data = response.data;
                            console.log(data)
                            res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})
                            res.write(templates.studentsListPage(data, d))
                            res.end()
                        }).catch(error => {
                            console.log(error);
                            res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'})
                            res.end(templates.errorPage(error, d))
                        })
                }
                // GET /alunos/:id --------------------------------------------------------------------
                else if (req.url.match(/\/alunos\/(A|PG)\d+$/)){
                    res.writeHead(405, {'Content-Type': 'text/html; charset=utf-8'})
                    res.end()
                }
                // GET /alunos/registo --------------------------------------------------------------------
                else if (req.url.match(/\/alunos\/registo$/)){
                    res.writeHead(405, {'Content-Type': 'text/html; charset=utf-8'})
                    res.write(templates.studentFormPage(d))
                    res.end()
                }
                // GET /alunos/edit/:id --------------------------------------------------------------------
                else if (req.url.match(/\/alunos\/edit\/(A|PG)\d+$/)){
                    id = req.url.split('/')[3]
                    axios.get('http://localhost:3000/alunos/' + id).then(
                        resp => {
                            aluno = resp.data
                            res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'})
                            res.write(templates.studentFormEditPage(aluno, d))
                            res.end()
                        }).catch(erro => {
                            console.log(error);
                            res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'})
                            res.end(templates.errorPage(error, d))
                        })
                }
                // GET /alunos/delete/:id --------------------------------------------------------------------
                else if (req.url.match(/\/alunos\/delete\/(A|PG)\d+$/)){
                    res.writeHead(405, {'Content-Type': 'text/html; charset=utf-8'})
                    res.end()
                
                }
                // GET ? -> Lancar um erro
                break
            case "POST":
                if(req.url === '/alunos/registo'){
                    collectRequestBodyData(req, result =>{
                        if(result){
                            axios.post('http://localhost:3000/alunos', result).then(
                                resp => {
                                    res.writeHead(201, {'Content-Type': 'text/html; charset=utf-8'})
                                    res.end("<p>Registo inserido</p>")
                                }).catch(erro => {
                                    console.log(error);
                                    res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'})
                                    res.end(templates.errorPage(error, d))
                                })
                        } else {
                            res.writeHead(500, {"Content-Type": 'text/html; charset=utf-8'})
                            res.end()
                        }
                    })
                }
                // POST /alunos/registo --------------------------------------------------------------------
                
                // POST /alunos/edit/:id --------------------------------------------------------------------
                else if(req.url.match(/\/alunos\/edit\/(A|PG)\d+$/)){
                    collectRequestBodyData(req, result =>{
                        if(result){
                            axios.put('http://localhost:3000/alunos/' + result.id, result).then(
                                resp => {
                                    res.writeHead(201, {'Content-Type': 'text/html; charset=utf-8'})
                                    res.end("<p>Registo alterado</p>")
                                }).catch(erro => {
                                    console.log(error);
                                    res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'})
                                    res.end(templates.errorPage(error, d))
                                })
                        } else {
                            res.writeHead(500, {"Content-Type": 'text/html; charset=utf-8'})
                            res.end()
                        }
                    })
                }

                // POST ? -> Lancar um erro
                break;
            case "PUT":
                if(req.url.match(/\/alunos\/edit\/(A|PG)\d+$/)){
                    collectRequestBodyData(req, result =>{
                        if(result){
                            axios.put('http://localhost:3000/alunos/' + result.id, result).then(
                                resp => {
                                    res.writeHead(201, {'Content-Type': 'text/html; charset=utf-8'})
                                    res.end("<p>Registo alterado</p>")
                                }).catch(erro => {
                                    console.log(error);
                                    res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'})
                                    res.end(templates.errorPage(error, d))
                                })
                        } else {
                            res.writeHead(500, {"Content-Type": 'text/html; charset=utf-8'})
                            res.end()
                        }
                    })
                }
                break;
            case "DELETE":
                break;
            default: 
                res.writeHead(500, {'Content-Type': 'text/html; charset=utf-8'})
                res.write("<p>Metodo nao suportado: " + req.method + "</p>")
                res.end()
        }
    }
})

alunosServer.listen(7777, ()=>{
    console.log("Servidor à escuta na porta 7777...")
})



