const express = require('express')
const multer  = require('multer')
const upload = multer({ dest: 'uploads/' })

const app = express()
const port = 15001

app.post('/ficheiro', upload.array('myFile'), function(req, res, next) {
    console.log("Informação sobre os ficheiros:")
    let i = 0;
    for (const file of req.files){
        console.log(`Ficheiro ${i++}:`)
        console.log(JSON.stringify(file))


        let oldPath = __dirname + '/../' + file.path
        console.log("old: " + oldPath)
        let newPath = __dirname + '../public/fileStore/' + file.originalname
        console.log("new: " + newPath)
    }
    res.send(`Recebi ${req.files.length} ficheiros`)
    console.log("Informação sobre os campos textuais:")
    console.log(JSON.stringify(req.body))

    // Guardar o ficheiro no sitio certo
})

app.listen(port, () => {
    console.log(`Servidor à escuta na porta ${port}...`)
})