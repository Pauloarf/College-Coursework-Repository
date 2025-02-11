const axios = require('axios');

axios.post('http://localhost:3000/instrumentos', 
    {
        "id": 'I23',
        "#text": 'Grafonola',
    })
    .then(response => {
        console.log(response.data);
    }).catch(error => {
        console.log(error);
    });