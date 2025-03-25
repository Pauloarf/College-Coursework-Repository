const mongoose = require('mongoose');

const contratoSchema = new mongoose.Schema({
    _id : String,
    dataCelebracaoContrato: String,
    dataPublicacao : String,
    entidade_comunicante : String,
    fundamentacao : String,
    nAnuncio : String,
    NIPC_entidade_comunicante : String,
    objetoContrato : String,
    prazoExecucao : Number,
    precoContratual : Number,
    tipoprocedimento : String
}, {version : false})

module.exports = mongoose.model('contratos', contratoSchema)