const express = require('express')
const path = require('path')
const exphbs = require('express-handlebars')
const port = 3000
const app = express()

app.engine('.hbs', exphbs({
	  defaultLayout: 'main',
	  extname: '.hbs',
	  layoutsDir: path.join(__dirname, 'views/layouts')
}))

app.set('view engine', '.hbs')

app.set('views', path.join(__dirname, 'views'))

app.use((request, response, next) => {
	console.log(request.headers)
	next()
})

app.get('/', (request, response) => {
	response.sendfile("index.html")
})

app.get('/events.html', (request, response) => {
	response.sendfile("events.html")
})

app.get('/create.html', (request, response) => {
	response.sendfile("create.html")
})

app.get('/index.html', (request, response) => {
	response.sendfile("index.html")
})

app.listen(port, (err) => {
	if (err){
		return console.log('error: ',err)
	}
	console.log('Listening on port',port)
})
