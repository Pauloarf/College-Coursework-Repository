var mongoose = require('mongoose')

var projetoSchema = new mongoose.Schema({
    
}, {versionKey : false})

module.exports = mongoose.model('projeto', projeto)