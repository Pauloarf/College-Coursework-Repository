var express = require('express');
var router = express.Router();
var userModel = require('../models/user');
const passport = require('passport');

/* GET home page. */
router.post('/register', function(req, res, next) {
    userModel.register(
        new userModel({
            username : req.body.username,
            name: req.body.name,
            level: req.body.level,
            active : true,
            creationDate : new Date()
        }),
        req.body.password,
        (err, user) => {
            if (err) res.jsonp(err)
            else res.send("Sucess")
        }
    );
});

router.post('/login', passport.authenticate('local'), (req, res) => {
    jwt.sign(
        {
            username : req.user.username,
            level: req.user.level,
            sub : 'aula de EngWeb2025'
        },
        "EngWeb2025",
        {expiresIn: 3600},
        (err, token) => {
            if (err) res.jsonp(err)
            else res.status(201).jsonp({token: token})
        }
    )
})

module.exports = router;
