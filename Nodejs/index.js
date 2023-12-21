const express = require('express')
var cors = require('cors')
var app = express()

app.use(cors()) //조건 설정
const port = 3000

app.get('/', (req, res) => {
    res.send('Hello World!')
})

app.get('/dog', (req, res) => {
    res.send({ 'sound': '멍멍' })
})

app.get('/cat', (req, res) => {
    res.send('sound: MWWW')
})

app.get('/user/:id', (req, res) => {
    const p = req.params
    console.log(p)
    res.json({ 'userid': q.name });
})

app.get('/user/:id', (req, res) => {
    const q = req.query
    console.log(q)
    res.json({ 'userid': q.name });
})

app.get('/sound/:name', (req, res) => {
    const { name } = req.params
    if (name == "dog") {
        res.json({ 'sound': '멍멍' });
    } else if (name == "cat") {
        res.json({ 'sound': '야용' });
    } else {
        res.json({ 'sound': null });
    }
})


app.listen(port, () => {
    console.log(`Example app listening on port ${port}`)
})