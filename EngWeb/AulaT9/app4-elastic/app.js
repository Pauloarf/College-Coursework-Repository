const express = require('express')
const multer  = require('multer')
const upload = multer({ dest: 'uploads/' })

const app = express()
const port = 15001

// Tratar o pedido ...
app.post()

app.listen(port, () => {
    console.log(`Servidor à escuta na porta ${port}...`)
})



