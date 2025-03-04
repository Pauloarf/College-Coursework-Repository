const express = require('express')
const fs = require('fs')

const { myDateTime, myName, myTurma } = require('./misc')
const itemRouter = require('./routes/items')

// Carregar imagens
// const pic501 = require('fs').readFileSync('./Errors/501.jpg');

const app = express()
const favicon = fs.readFileSync('./favicon.png')

const pageList = [
    {name: 'Item list', url: '/items'},
]

app.set('view engine', 'ejs')
app.use(logger)
app.use(express.static("./public"))
app.listen(3001)

console.log('Server listening at port 3001')

// Render Main Page
app.get('/', (req, res) => {
    res.render("mainPage", 
        { pageList: pageList, author: myName(), date: myDateTime()}
    )
})

// Render favicon
app.get('/favicon.ico', (req, res) => {
    res.writeHead(200, {'Content-Type': 'image/png'})
    res.end(favicon)
})

// Setting up routers
app.use('/items', itemRouter)

// MiddleWare to logg information
function logger(req, res, next){
    console.log(req.method + ' RECIEVED at ' + myDateTime())
    console.log('URL: ' + req.originalUrl)
    next()
}
