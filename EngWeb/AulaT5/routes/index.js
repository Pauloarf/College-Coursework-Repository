var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', {
    title: 'Cinema8k',
    docente: 'jrc',
    instituicao: 'DI-UM'
  });
});

router.get('/filmes', async (req, res, next) => {
  try {
    const response = await fetch('http://localhost:3000/movies', {
      method: 'GET',
    });
    const movies = await response.json();
    console.log(movies);
    res.render('filmes', {filmes: movies, tit:'Lista de Filmes'});
  } catch (err) {
    console.log(`Erro: ${err}`);
  }
});

module.exports = router;
