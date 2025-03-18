var express = require('express');
var Alunos = require('../controllers/alunos')
var router = express.Router();

/* GET users listing. */
router.get('/', async function(req, res, next) {
  try {
    const response = await Alunos.list();
    const doc = response[0].toObject();
    const alunos = doc['alunos'];
    let date = new Date().toISOString().substring(0,10);
    res.render('studentsListPage', {alunos: alunos, data: date});
  } catch (err){
    res.status(500);
    res.render('error', {error: err});
  }
});

router.get('/registo', async (req, res, next) => {
  try{
    res.render('studentFormPage');
  } catch (err) {
    res.status(500);
    res.render('error', {error: err});
  }
})


router.get('/:id', async (req, res, next) => {
  try{
    const response = await Alunos.findById(req.params.id);
    console.log(response);
    const aluno = res.jsonp(response);
  } catch (err) {
    res.status(500);
    res.render('error', {error: err});
  }
})


module.exports = router;
