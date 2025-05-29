var Entrega = require('../models/entrega')
var HEntrega = require('../models/hEntrega')

module.exports.findAll = () => {
    return Entrega
        .find()
        .exec()
}

module.exports.findByProjeto = (projId) => {
    return Entrega
        .find({projeto: projId})
        .exec()
}

module.exports.findById = (id) => {
    return Entrega
        .findById(id)
        .exec()
}

module.exports.save = async (entrega) => {
    var entregas = await Entrega.find({_id : entrega._id}).exec()

    if(entregas.length < 1){
        var entregaDb = new Entrega(entrega)
        return entregaDb.save()
    }
}

module.exports.update = (id, data) => {
    return Entrega
        .findByIdAndUpdate(id, data, {new : true})
        .exec()
}

module.exports.delete = async (id, justificacao) => {
    var entrega = await Entrega
        .findByIdAndDelete(id, {new : true})
        .exec()

    var hEntrega = new HEntrega({
        ...entrega.toObject(),
        date_del: new Date(),
        justificacao: justificacao
    })

    return hEntrega.save()
}

module.exports.countEntregasByProjeto = projeto => {
    return Entrega
        .find({projeto : projeto})
        .countDocuments()
        .exec()
}