let jwt = require('jsonwebtoken')

module.exports.validate = (req, res, next) => {
    let token = req.query.token || req.body.token || req.get('Authorization')
    if(token){
        jwt.verify(token, "EngWeb2025", (err, payload) => {
            if(err) res.status(401).jsonp(err)
            else {
                console.log(payload)
                next()
            } 
        })
    } else {
        res.status(401).jsonp({error: "Token inexistente"})
    }
}

module.exports.validateDoc = (req, res, next) => {
    let token = req.query.token || req.body.token || req.get('Authorization')

    token = token.split(' ')[1]

    if(token){
        jwt.verify(token, "EngWeb2025", (err, payload) => {
            if(err) res.status(401).jsonp(err)
            else {
                console.log(payload)
                if(payload.level = "DOCENTE"){
                    next()
                } else {
                    res.status(401).jsonp(payload)
                }
                next()
            } 
        })
    } else {
        res.status(401).jsonp({error: "Token inexistente"})
    }
}