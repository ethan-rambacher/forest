
var e =  new Event( new Location("Steep Rock", "Roxbury", "CT", "NONE"), "5:00", 7)

var locations = []
var d = []
locations.push(e)
console.log(locations[0].loc.state)

for(i = 0; i < 100000000; i++){
  locations[i] = "NULL"
}


console.log(locations[99999999])

function Event(loc, time, distance, pace){
  this.loc = loc
  this.time = time
  this.distance = distance
  this.pace = pace
}

function Query(loc, time, distance, pace){
  this.loc = loc
  this.time = time
  this.distance = distance
  this.pace = pace
}

function Location(title, town, state, address, neighbors){
  this.title = title
  this.town = town
  this.state = state
  this.address = address
  this.neighbors = neighbors//array of locations


}
