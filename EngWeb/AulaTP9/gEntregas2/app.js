var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var mongoose = require('mongoose')

const {v4 : uuidv4} = require('uuid')
var session = require('express-session')
var passport = require('passport')
var LocalStrategy = require('passport-local').Strategy

var mongoDB = 'mongodb://localhost:27017/entregas'
mongoose.connect(mongoDB)
var connection = mongoose.connection
connection.on('error', console.error.bind(console, 'Erro na conexão ao MongoDB'))
connection.once('open', () => console.log('Conexão ao MongoDB realizada com sucesso'))

//passport config
let User = require('./models/user')
passport.use(new LocalStrategy(User.authenticate()))
passport.serializeUser(User.serializeUser())
passport.deserializeUser(User.deserializeUser())

var entregaRouter = require('./routes/entrega');
var equipaRouter = require('./routes/equipa');
var projetoRouter = require('./routes/projeto');
var ucRouter = require('./routes/uc');
var userRouter = require('./routes/user');

var app = express();

app.use(session({
  genid:res => {
    return uuidv4()
  },
  secret: 'EngWeb2025',
  resave: false,
  saveUninitialized: true
}))

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'pug');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/entrega', entregaRouter);
app.use('/equipa', equipaRouter);
app.use('/projeto', projetoRouter);
app.use('/uc', ucRouter);
app.use('/user', userRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
