const express = require('express');
var cors = require('cors')
const app = express();
const port = process.env.PORT || 8001;

app.use(cors())

salles = new Object()
salles = []

var airQuality = ''
var pression = 0
var humidity = 0
var temperature = 0
var salle = ''

materials = new Object()
materials = []

var position = ''
var material = ''
var id = ''

app.get('/newStatus/:airQuality&:pression&:humidity&:temp&:salle', (req, res) => {

    airQuality = req.params.airQuality
    pression = req.params.pression
    humidity = req.params.humidity
    temperature = req.params.temp
    salle = req.params.salle

    let object = new Object()

    object.airQuality = airQuality
    object.pression = pression
    object.humidity = humidity
    object.temperature = temperature
    object.salle = salle

    salles.push(object)

    res.status(200).send();
});

app.get('/status', (req, res) => {

    res.status(200).send(salles);
});

app.get('/newPosition/:position&:material&:id', (req, res) => {

    material = req.params.material
    position = req.params.position
    id = req.params.id

    let object = new Object()

    object.position = position
    object.material = material
    object.id = id

    materials.push(object)

    res.status(200).send();
});

app.get('/position', (req, res) => {

    res.status(200).send(materials);
});

app.listen(port, () => {
    console.log('Server app listening on port ' + port);
});