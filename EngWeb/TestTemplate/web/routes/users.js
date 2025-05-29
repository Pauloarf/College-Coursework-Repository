const express = require('express');
const router = express.Router();

const API = 'http://localhost:17000/users';

// GET /users → Lista todos os users
router.get('/', async (req, res) => {
    try {
        const response = await fetch(API);
        const users = await response.json();
        res.render('users', { title: 'Lista de Users', users });
    } catch (err) {
        res.status(500).send('Erro ao obter utilizadores.');
    }
});

// GET /users/:id → Detalhes de um user
router.get('/:id', async (req, res) => {
    try {
        const response = await fetch(`${API}/${req.params.id}`);
        const user = await response.json();
        res.render('user', { title: 'Detalhes do User', user });
    } catch (err) {
        res.status(500).send('Erro ao obter utilizador.');
    }
});

// GET /users/post → Formulário de criação
router.get('/post/new', (req, res) => {
    res.render('usersPost', { title: 'Novo User' });
});

// POST /users → Envia form para API
router.post('/', async (req, res) => {
    try {
        const response = await fetch(API, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(req.body)
        });

        if (!response.ok) throw new Error('Erro ao criar utilizador');
        res.redirect('/users');
    } catch (err) {
        res.status(400).send('Erro ao criar utilizador.');
    }
});

module.exports = router;
