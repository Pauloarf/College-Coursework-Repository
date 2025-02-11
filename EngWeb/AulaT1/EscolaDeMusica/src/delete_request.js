const axios = require('axios');

axios.delete('http://localhost:3000/instrumentos/123')
    .then(response => {
        console.log(response.data);
    }).catch(error => {
        console.log(error);
    });