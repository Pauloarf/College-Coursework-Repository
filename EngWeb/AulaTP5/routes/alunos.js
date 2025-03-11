var express = require('express');
var router = express.Router();

/* GET users listing. */
router.get('/', async function(req, res, next) {
  try {
    const response = await fetch("http://localhost:3000/alunos", {
      method: 'GET',
    });
    const alunos = await response.json();
    let date = new Date().toISOString().substring(0,10);
    if(response.ok){
      res.render('studentsListPage', {alunos: alunos, data: date});
    } else {
      res.status(500);
      res.render('error', {error: err});
    }
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

module.exports = router;
