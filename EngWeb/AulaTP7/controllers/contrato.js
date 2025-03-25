const contratoModel = require('../models/contrato')

module.exports.list = () => {
    return contratoModel.find().exec()
}

module.exports.findById = id => {
    return contratoModel.findOne({"_id" : id}).exec()
}

module.exports.findByEntidade = entidade => {
    return contratoModel.find({"NIPC_entidade_comunicante" : entidade}).exec();
}

module.exports.findByType = type => {
    return contratoModel.find({"tipoprocedimento" : type}).exec();
}

module.exports.getEntidades = () => {{
    return contratoModel.distinct("entidade_comunicante").sort({"entidade_comunicante": 1});
}}

module.exports.getTipos = () => {{
    return contratoModel.distinct("tipoprocedimento").sort({"tipoprocedimento": 1});
}}

module.exports.insert = Contrato => {
    let contToSave = new contratoModel(Contrato);
    return contToSave.save()
}

module.exports.update = Contrato => {
    return contratoModel.findOneAndUpdate({"_id":Contrato._id} ,Contrato, {new: true})
 
}

module.exports.delete = id => {
    return contratoModel.findByIdAndDelete(id);
}