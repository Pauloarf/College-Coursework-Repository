const mongoose = require('mongoose')

const userSchema = new mongoose.Schema({
    _id : String,
    nome : String,
    email : String,
    nif : String,
    idade : Number
}, {version : false})

module.exports = mongoose.model('users', contratoSchema)