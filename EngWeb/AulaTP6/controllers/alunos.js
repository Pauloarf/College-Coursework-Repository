const alunoModel = require('../models/aluno')

module.exports.list = () => {
    return alunoModel.find().sort({nome: 1}).exec()
}

module.exports.findById = id => {
    return alunoModel.findOne({"alunos._id": id}).exec();
}

module.exports.insert = aluno => {
    if(alunoModel.find({_id : aluno.id}).exec().lenght > 0){
        let newAluno = new alunoModel(aluno);

    }
} 

module.exports.inverteTpc = (id, idTpc) => {
    return alunoModel.findOne({'_id' : id}).exec().then(aluno => {
        var tpc = `tpc${idTpv}`
        if(aluno[tpc] != null){
            aluno[tpc] = !aluno[tpc]
        } else {
            aluno[tpc] = true;
        }

        return alunoModel.findByIdAndUpdate(id, Aluno).exec();
    })
}