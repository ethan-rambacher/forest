/* -----------------  CREATING EVENTS ------------------- */

// submitEvent sends a string corresponding to an event and sends it to the server
// to be added. The string is of the format:
// title|longitude|latitude|pace|distance|date
// and the date is of the format:
// year/month/day|hour:minute
function submitEvent(str){
	var request = new XMLHttpRequest();
	request.onreadystatechange = function(){
		if (this.readyState == 4 && this.status == 200) {
			document.getElementByID("submit").innerHTML = "Event created!";
		}
	};
	request.open("GET",str,true);
	request.send();
	document.getElementById("submit").innerHTML = "Submitting event...";
}


// createEvent takes the information in the form and creates a string corresponding to
// the desired object. The string is of the format documented above.
// Currently, this function only takes 2 parameters, and the rest are test values.
// This will eventually be expanded to take all custom values for title, longitude,
// latitude, pace, distance, date, and time.
function createEvent(){ // driver function for submitEvent
	lat = document.getElementById('latitude').value;
	lon = document.getElementById('longitude').value;
	eventstring = "MyRun|"+lon+"|"+lat+"|1|1|2017/1/2|12:30";
	submitEvent(eventstring);
}



/* -----------------  SEARCHING FOR EVENTS ------------------- */

// query takes a string corresponding to a query and sends it to the server. Upon
// response from the server (in the form of a JSON object of events), query calls
// populateResults to fill in the results div.
function query(str){
	var request = new XMLHttpRequest();
	request.onreadystatechange = function() {
		if (this.readyState == 4 && this.status == 200){
			populateResults(this.responseText);
		}
	};
	request.open("GET",str,true);
	request.send();
}

// populateResults takes a JSON object, as a string, parses it into JSON,
// then generates the HTML to display the results.
function populateResults(str){
	var obj = JSON.parse(str);
	var HTMLToAdd = "";
	for (i=0; i<obj.length; i++){
		HTMLToAdd += HTMLFromJSON(obj[i]);
	}
	document.getElementByID("results").innerHTML = HTMLToAdd;
}

// HTMLFromJSON takes a JSON object for an event and creates the HTML
// corresponding to that event
function HTMLFromJSON(event){
	// ....
	
}