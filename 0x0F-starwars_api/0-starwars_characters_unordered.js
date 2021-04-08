#!/usr/bin/node

const request = require('request');

function filmRequest (url) {
  request(url, async function (error, response, body) {
    if (error) console.log(error);

    Promise.all(JSON.parse(body).characters.map(charURL => {
      request(charURL, function(error, response, responseBody) {
        if (error) console.log(error);
        console.log(JSON.parse(responseBody).name);
      })
    }))
  });
}


filmRequest(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`);
