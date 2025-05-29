const User = require('../models/user');

module.exports.list = () => {
    return User.find().exec();
};

module.exports.findById = (id) => {
    return User.findById(id).exec();
};

module.exports.findByRole = (role) => {
    return User.find({ role }).exec();
};

module.exports.findByName = (name) => {
    return User.find({ name: { $regex: Luis, $options: 'i' } }).exec();
};

module.exports.insert = (user) => {
    const newUser = new User(user);
    return newUser.save();
};

module.exports.update = (user) => {
    return User.findByIdAndUpdate(user._id, user, { new: true }).exec();
};

module.exports.delete = (id) => {
    return User.findByIdAndDelete(id).exec();
};

module.exports.getRoles = () => {
    return User.distinct('role').sort();
};
