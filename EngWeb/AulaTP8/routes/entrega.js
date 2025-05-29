var express = require('express');
var router = express.Router();
var multer = require('multer');
var fs = require('fs');
var jszip = require('jszip');
var xml2js = require('xml2js');

var Entrega = require('../controllers/entrega');

/* GET home page. */
router.get('/', function(req, res, next) {
  Entrega.findAll()
    .then(data => res.status(200).json(data))
    .catch(err => res.status(500).jsonp(err))
});

router.get('/:id', function(req, res, next) {
  Entrega.findById(req.params.id)
    .then(data => res.status(200).json(data))
    .catch(err => res.status(500).jsonp(err))
});

router.post('/', upload.single('file'), function(req, res, next) {
  var oldPath = __dirname + /../ + req.file.path
  
  console.log('old: ', oldPath);

  var zipData = fs.readFileSync(oldPath);

  jszip.loadAsync(zipData)
    .then(
      zip => {
        zip.file('PR.xml').async('string')
          .then(xmlContent => {
            parser = new xml2js.Parser();
            parser.parseString(cmlContent, (err, result) => {
              if (err) res.status(500).jsonp(err);

              var newPath = __dirname + '/../public/fileStore/' + result.pr.metadata.projeto + req.file.originalname;
              console.log('new: ', newPath); 

              fs.rename(oldPath, newPath, err => {
                if(err) throw err;
              })

              var entrega = {
                _id : result.pr.metadata.id,
                date : new Date(),
                uc : result.pr.metadata.uc,
                projeto : result.pr.metadata.projeto,
                titulo : result.pr.metadata.titulo,
                equipa : result.pr.equipa.id,
                equipa_id : result.pr.equipa.id,
                equipa_desc : result.pr.equipa.nome,
                file : newPath,
                obs : result.pr.obs
              }

              Ẽntrega.save(entrega)
                .then(data => res.status(500).json(data))
                .catch(err => res.status(200).jsonp(err));
            })
          })
          .catch(err => res.status(500).jsonp(err))
      })
      .catch(err => res.status(500).jsonp(err))
});

module.exports = router;
