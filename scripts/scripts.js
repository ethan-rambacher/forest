function submitEvent(str){
	var request = new XMLHttpRequest();
	request.onreadystatechange = function(){
		if (this.readyState == 4 && this.status == 200) {
			document.getElementByID("submit").innerHTML = "Event created!";
		}
	}
	request.open("GET",str,true);
	request.send();
	document.getElementById("submit").innerHTML = "Submitting event...";
}

function createEvent(){ // driver function for submitEvent
	lat = document.getElementById('latitude').value;
	lon = document.getElementById('longitude').value;
	eventstring = "MyRun|"+lon+"|"+lat+"|1|1|2017/1/2|12:30";
	submitEvent(eventstring);
}