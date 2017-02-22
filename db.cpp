#include <iostream>
#include <list>
#include <cmath>
#include <string>
//#include <unordered_map>

#define PI 3.14159265358979323846264

/* Coordinate is a class to store a geographical location.
lon is the longitude - north being positive, south being negative.
lon ranges from -90 to 90.

 */
class Coordinate{
public:
  Coordinate(float longitude, float latitude){
    lon = longitude; // note long is a C++ keyword so cannot be used as var name
    lat = latitude;
  }
  Coordinate(){
    lon = 0;
    lat = 0;
  }

  float getLon() const { return lon; }
  float getLat() const { return lat; }

  /* The first index of a coordinate equals the floored integer value of its lon or lat coords. */
  int getFirstLonIndex() const {
    return (int) floor(lon);
  }
  int getFirstLatIndex() const {
    return (int) floor(lat);
  }

  /* The second index of a coordinate equals the int corresponding to tenths and hundredths place of its lon/lat coords. */
  int getSecondLonIndex() const {
    return (int) floor((lon - floor(lon))*100);
  }
  int getSecondLatIndex() const {
    return (int) floor((lat - floor(lat))*100);
  }

  /* Use 'haversine' formula from movable-type.co.uk */
  float getDistance(Coordinate c1) const {
    float lonRad = lon * PI / 180.0;
    float latRad = lat * PI / 180.0;
    // continue....
    //completely wrong, was just annoying compiler
    return lonRad*latRad; //I got tired of the error
  }

private:
  // coordinates are stored in degrees.
  float lon;
  float lat;

};

class Event{
public:
  Event(){
    id = 0;
    title = "NULL";
    pace = -1;
  }
  Event(int ident, const std::string &t, Coordinate c, int p = -1){
    id = ident;
    title = t;
    location = c;
    pace = p;
  }

  Event(int ident, const std::string &t, float lon, float lat, int p = -1){
    id = ident;
    title = t;
    location = Coordinate(lon,lat);
    pace = p;
  }

  int getID() const { return id; }
  std::string getTitle() const { return title; }
  Coordinate getLocation() const { return location; }
  int getPace() const { return pace; }

  /* Retrns string of JSON object corresponding to event */
  std::string getJSON() const {
    //return "{id:"+std::to_string(id)+",title:'"+title+"',lon:"
      //+std::to_string(location.getLon())+",lat:"+std::to_string(location.getLat())
      //+",pace:"+std::to_string(pace)+"}"; //calls an error, im going to worry about later
      return "NULL";
  }

private:
  int id;
  std::string title;
  Coordinate location;
  int pace;

};

class Events{
public:
  Events(){
    file_name = "default.txt";
    clear();
  }
  Events(std::string file_name){
    clear();
    //initialize things
  }
  void save(){

  }
  void allocate_first_level(int r, int c){
    if(globe[r][c] != NULL) return;
    globe[r][c] = new std::list<Event>*[100];
    for(int i = 0; i < 100; i++){
      globe[r][c][i] = new std::list<Event>[100];
      //for(int j = 0; j < 100; j++){
        //globe[r][c][i][j] = NULL;
      //}
    }
  }
  void addEvent(Event e){
    Coordinate c = e.getLocation();
    allocate_first_level(c.getFirstLatIndex(), c.getFirstLonIndex());
    globe[c.getFirstLatIndex()][c.getSecondLonIndex()][c.getSecondLatIndex()][c.getSecondLonIndex()].push_back(e);

  }
  void clear(){
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        globe[i][j] = NULL; //you need to manually set them to null;
      }
    }
  }


private:
  std::string file_name;
  std::list<Event>** globe[100][100];

};


/* Adds an event to the unordered hash map, indexed by ID */
/*void addEvent(std::string input,std::unordered_map<int,Event>& events){
  static int ID_count = 0;
  std::string temp;
  int index;
  index = input.find("|");
  temp = input.substr(0,index);

}*/



int main(){
  Events e;
  std::string input;
  //std::unordered_map<int,Event> eventsByID;

  //int map[10][10];
  while(1){
    std::cin >> input;
    //addEvent(input);
  }
}
