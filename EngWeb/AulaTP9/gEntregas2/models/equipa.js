var mongoose = require('mongoose')

var equipaSchema = new mongoose.Schema({
    
}, {versionKey : false})

module.exports = mongoose.model('equipa', equipaSchema)