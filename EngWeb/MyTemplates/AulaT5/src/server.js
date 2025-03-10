const express = require('express')
const fs = require('fs')
const { myDateTime, myName, myTurma, pageList } = require('./misc')

// Inicializar o express
const app = express()
const port = 3001
app.listen(port)

//const itemRouter = require('./routes/items')
// Carregar imagens
// const pic501 = require('fs').readFileSync('./Errors/501.jpg');
//const favicon = fs.readFileSync('./favicon.png')

app.set('view engine', 'ejs')
app.use(logger)
app.use(express.static("./public"))

console.log('Server listening at port 3001')

// Render Main Page
app.get('/', (req, res) => {
    res.render("mainPage", 
        { pageList: pageList, author: myName(), date: myDateTime()}
    )
})

// Setting up routers
//app.use('/items', itemRouter)

// MiddleWare to logg information
function logger(req, res, next){
    console.log(req.method + ' RECIEVED at ' + myDateTime())
    console.log('URL: ' + req.originalUrl)
    next()
}
