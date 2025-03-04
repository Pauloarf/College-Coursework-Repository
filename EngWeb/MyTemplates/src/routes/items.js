// Estas variáveis são necessárias para o funcionamento do router
const express = require("express")
const router = express.Router()

router.get('/', (req, res) => {
    fetch('http://localhost:3000/items').then(
        async response => {
            const items = await response.json()

            res.render('items', {items/*: renameditems*/})
        }
    ).catch(
        async error => {
            console.log(error)
            res.sendStatus(500)
        } 
    )
})

router.get('/:id', (req, res) => {
    const id = req.params.id
    fetch(`http://localhost:3000/items/${id}`).then(
        async response => {
            const item = await response.json()
            fetch(`http://localhost:3000/alunos?items=${item['#text']}`).then(
                async response2 => {
                    const alunos = await response2.json()
                    res.render('item', {alunos: alunos, item: item})
                }
            ).catch(
                async error => {
                    console.log('Erro no fetch dos alunos\n' + error)
                    res.sendStatus(500)
                }
            )
        }
    ).catch(
        async err => {
            console.log('Erro no fetch do item\n' + err)
            res.sendStatus(500)
        }
    )  
})

// Esta variável exporta o router para ser usado no server.js
module.exports = router
