const express = require('express')
const app = express()
const port = 3000

app.get('/', (request, response) => {
	response.send('Hello world!')
})


app.listen(port, (err) => {
	if (err){
		return console.log('error: ',err)
	}

	console.log('Listening on port',port)
})


