const express = require('express')
const multer  = require('multer')
const upload = multer({ dest: 'uploads/' })

const app = express()
const port = 15000

app.post('/ficheiro', upload.single('myFile'), function(req, res, next) {
    console.log("informação sobre o ficheiro:")
    console.log(JSON.stringify(req.file))
    if(req.file.size > 5000){
        console.log("O file tem mais de 5kB")
    }
    console.log("Informação sobre os campos textuais:")
    console.log(JSON.stringify(req.body))
    res.send(`<p>Recebi 1 ficheiro: ${JSON.stringify(req.file)}</p>`)
})

app.listen(port, () => {
    console.log(`Servidor à escuta na porta ${port}...`)
})



