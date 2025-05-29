var mongoose = require('mongoose')

var ucSchema = new mongoose.Schema({
    
}, {versionKey : false})

module.exports = mongoose.model('uc', ucSchema)