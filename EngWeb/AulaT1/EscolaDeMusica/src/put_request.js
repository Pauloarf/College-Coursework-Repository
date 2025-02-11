const axios = require('axios');

axios.put('http://localhost:3000/instrumentos/123', 
    {
        "id": 'I23',
        "#text": 'Kazoo',
    })
    .then(response => {
        console.log(response.data);
    }).catch(error => {
        console.log(error);
    });