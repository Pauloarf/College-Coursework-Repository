var Entrega = require('../models/entrega')

module.exports.findById = id => {
    return Entrega.findById(id).exec()
}

module.exports.save = entrega => {
    if(Entrega.find({_id : entrega._id}).exec().lenght < 1){
        var entregaDb = new Entrega(entrega);
        return entregaDb.save();
    }
}

module.exports.update = (id, entrega) => {
    return Entrega
        .findByIdAndUpdate(id, entrega, {new : ture})
        .exec()
}

module.exports.delete = async (id, justificacao) => {
    const entrega
}