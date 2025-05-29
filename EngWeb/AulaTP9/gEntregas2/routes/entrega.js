var express = require('express');
var router = express.Router();
var Entrega = require('../controllers/entrega')
var multer = require('multer')
var fs = require('fs')
var jszip = require('jszip')
var xml2js = require('xml2js')
const Auth = require('../auth/auth')

var upload = multer({dest: 'upload/'})

/* GET home page. */
router.get('/', Auth.validate, function(req, res, next) {
  console.log("batatas")
  if(req.query.projeto){
    Entrega.findByProjeto(req.query.projeto)
      .then(data => res.status(200).jsonp(data))
      .catch(err => res.status(500).jsonp(err))
  }else{
    Entrega.findAll()
      .then(data => res.status(200).jsonp(data))
      .catch(err => res.status(500).jsonp(err))
  }
});

router.get('/:id', Auth.validate, function(req, res, next) {
  Entrega.findById(req.params.id)
    .then(data => res.status(200).jsonp(data))
    .catch(err => res.status(500).jsonp(err))
});

router.post('/', Auth.validate, upload.single('file'), function(req, res, next) {
  var oldPath = __dirname + '/../' + req.file.path
  console.log('old: ', oldPath)

  var zipData = fs.readFileSync(oldPath)

  jszip.loadAsync(zipData)
    .then(zip => {
      zip.file('PR.xml').async('string')
        .then(xmlContent => {
          var parser = new xml2js.Parser({explicitArray : false})
          parser.parseString(xmlContent, (err, result) => {
            if(err) res.status(500).jsonp(err);
            
            var newPath = __dirname + `/../public/fileStore/${result.pr.metadata.projeto}/${req.file.originalname}`
            console.log({newPath})

            fs.rename(oldPath, newPath, err => {
              if(err) throw err;
            })

            var entrega = {
              _id : result.pr.metadata.id,
              date : new Date(),
              uc : result.pr.metadata.uc,
              projeto : result.pr.metadata.projeto,
              titulo : result.pr.metadata.titulo,
              equipa_id : result.pr.equipa.id,
              equipa_desc : result.pr.equipa.nome,
              file : newPath,
              obs : result.pr.obs
            }

            Entrega.save(entrega)
              .then(data => res.status(201).jsonp(data))
              .catch(err => res.status(500).jsonp(err))
          })
        })
        .catch(err => res.status(500).jsonp(err))
    })
    .catch(err => res.status(500).jsonp(err))
});

router.put('/:id', Auth.validate, function(req, res, next) {
  Entrega.update(req.params.id, req.body)
    .then(data => res.status(200).jsonp(data))
    .catch(err => res.status(500).jsonp(err))
});

router.delete('/:id', Auth.validate, function(req, res, next) {
  Entrega.delete(req.params.id, req.body.justificacao)
    .then(data => res.status(200).jsonp(data))
    .catch(err => res.status(500).jsonp(err))
});

module.exports = router;
