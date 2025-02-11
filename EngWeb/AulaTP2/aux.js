exports.myDateTime = () => {
    return new Date().toISOString().substring(0, 16);
}

exports.myName = function() {
    return "Paulo Ferreira";
}

exports.turma = 'EngWeb2025::TP1';
