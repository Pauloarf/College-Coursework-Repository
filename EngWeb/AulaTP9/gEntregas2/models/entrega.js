var mongoose = require('mongoose')

var entregaSchema = new mongoose.Schema({
    _id : String,
    date : Date,
    uc : String,
    projeto : String,
    titulo : String,
    equipa_id : String,
    equipa_desc : String,
    file : String,
    obs : String
}, {versionKey : false})

module.exports = mongoose.model('entrega', entregaSchema)