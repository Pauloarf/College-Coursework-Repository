const express = require('express');
const router = express.Router();
const User = require('../controllers/user');

// GET /users
router.get('/', async (req, res) => {
    try {
        const { name, role } = req.query;
        let result;

        if (name) result = await User.findByName(name);
        else if (role) result = await User.findByRole(role);
        else result = await User.list();

        res.json(result);
    } catch (err) {
        res.status(500).json({ error: err.message });
    }
});

// GET /users/:id
router.get('/:id', async (req, res) => {
    try {
        const user = await User.findById(req.params.id);
        if (!user) return res.status(404).json({ error: 'User not found' });
        res.json(user);
    } catch (err) {
        res.status(400).json({ error: 'Invalid ID' });
    }
});

// POST /users
router.post('/', async (req, res) => {
    try {
        const created = await User.insert(req.body);
        res.status(201).json(created);
    } catch (err) {
        res.status(400).json({ error: err.message });
    }
});

// PUT /users/:id
router.put('/:id', async (req, res) => {
    try {
        req.body._id = req.params.id;
        const updated = await User.update(req.body);
        if (!updated) return res.status(404).json({ error: 'User not found' });
        res.json(updated);
    } catch (err) {
        res.status(400).json({ error: err.message });
    }
});

// DELETE /users/:id
router.delete('/:id', async (req, res) => {
    try {
        const deleted = await User.delete(req.params.id);
        if (!deleted) return res.status(404).json({ error: 'User not found' });
        res.json({ message: 'User deleted successfully' });
    } catch (err) {
        res.status(400).json({ error: err.message });
    }
});

// GET /users/roles (distinct)
router.get('/filters/roles', async (req, res) => {
    try {
        const roles = await User.getRoles();
        res.json(roles);
    } catch (err) {
        res.status(500).json({ error: err.message });
    }
});

module.exports = router;
