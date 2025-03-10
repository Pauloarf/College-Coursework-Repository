exports.myDateTime = () => {
    return new Date().toISOString().substring(0,16);
}

exports.myName = () => {
    return "Paulo Ferreira"
}

exports.myTurma = "EngWeb2025"

exports.pageList = [
    {name: 'Main Page', url: '/'},
    {name: 'Page 2', url: '/page 2'},
]