var mongoose = require('mongoose')

var hEntregaSchema = new mongoose.Schema({
    _id : String,
    date : Date,
    uc : String,
    projeto : String,
    titulo : String,
    equipa_id : String,
    equipa_desc : String,
    file : String,
    obs : String,
    date_del: Date,
    justificacao: String
}, {versionKey : false})

module.exports = mongoose.model('hEntrega', hEntregaSchema)