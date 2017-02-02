console.log("hello world")


var g =  new person("greg hansell", 19, 138)

console.log(g.greet("Steve!"))
g.name

function say_hello(){
  console.log("hello world")
}




function person(nm, a, wt){
  name = nm
  age = a
  weight = wt
  this.greet = function(name) {
        return "Hello " + name;
  }
}
