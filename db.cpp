#include <iostream>
#include <list>
#include <cmath>
#include <string>
#include <unordered_map>

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

  void operator=(const Coordinate& c){
    lon = c.getLon();
    lat = c.getLat();
  }

private:
  // coordinates are stored in degrees.
  float lon;
  float lat;
};

/* A Date is an object representing a specific day, month, year, */
/* and time from 00:00 to 23:59, down to the minute (not second) */
class Date{
public:
  Date(){ // set default values to 1/1/2017 00:00
    y = 2017;
    m = d = 1;
    hr = min = 0;
  }
  
  Date(int year, int month, int day, int hour, int minute){
    y = year;
    m = month;
    d = day;
    hr = hour;
    min = minute;
  }
  int getYear() const{ return y; }
  int getMonth() const{ return m; }
  int getDay() const{ return d; }
  int getHour() const{ return hr; }
  int getMinute() const{ return min; }

  std::string toString() const{
    return std::to_string(y)+"/"+std::to_string(m)+"/"+std::to_string(d)
      +"|"+std::to_string(hr)+":"+std::to_string(min);
  }

  void operator=(const Date& date){
    y = date.getYear();
    m = date.getMonth();
    d = date.getDay();
    hr = date.getHour();
    min = date.getMinute();
  }

private:
  int y;
  int m;
  int d;
  int hr;
  int min;
};


/* An Event is an object that contains information pertaining to */
/* one event - i.e. a unique ID, a title, location, pace, etc. */
/* The latest JSON representation of an event is the following:
{
id: XXX,
title: XXX,
lon: XX.XXXXXXX,
lat: XX.XXXXXXX,
pace: XX,
distance: XX,
date: XXXX
}
 */
class Event{
public:
  Event(){
    id = 0;
    title = "NULL";
    pace = -1;
  }
  Event(int ident, const std::string t, Coordinate c, int p = -1){
    id = ident;
    title = t;
    location = c;
    pace = p;
  }

  Event(int ident, const std::string t, float lon, float lat, Date da, int p = -1,
	int di=-1){
    id = ident;
    title = t;
    location = Coordinate(lon,lat);
    pace = p;
    distance = di;
    date = da;
  }

  int getID() const { return id; }
  std::string getTitle() const { return title; }
  Coordinate getLocation() const { return location; }
  int getPace() const { return pace; }

  /* Retrns string of JSON object corresponding to event */
  std::string getJSON() const {
    return "{id:"+std::to_string(id)+",title:'"+title+"',lon:"+
      std::to_string(location.getLon())+",lat:"+std::to_string(location.getLat())+
      ",pace:"+std::to_string(pace)+",distance:"+std::to_string(distance)+
      ",date:"+date.toString()+"}";
  }

private:
  int id;
  std::string title;
  Coordinate location;
  int pace;
  int distance;
  Date date;
};


/* An instance of EventsByLocation is a data structure that */
/* allows access of an Event by its location */
class EventsByLocation{
public:
  EventsByLocation(){
    file_name = "default.txt";
    //clear();
  }
  EventsByLocation(std::string file_name){
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
    globe[c.getFirstLatIndex()][c.getFirstLonIndex()][c.getSecondLatIndex()][c.getSecondLonIndex()].push_back(e);

  }
  void clear(){
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
	delete *globe[i][j]; // remove data at each pointer to avoid mem leak
        globe[i][j] = NULL; //you need to manually set them to null;
      }
    }
  }


private:
  std::string file_name;
  std::list<Event>** globe[100][100];

};

/* Parses a string of the format:
YYYY/MM/DD|HH:MM
into a Date, and returns the corresponding Date object
*/
Date parseDate(std::string & dateString){
  std::cout << "mark 1: called parseDate" << std::endl;
  int index1 = dateString.find("/");

  int y = std::stoi(dateString.substr(0,index1)); // year

  std::cout << "mark 1.1: year="<<y<<std::endl;
  int index2 = dateString.find("/",index1+1);
  int m = std::stoi(dateString.substr(index1+1,index2-index1-1)); // month

  std::cout << "mark 1.2: month="<<m<<std::endl;
  
  index1 = dateString.find("|");
  int d = std::stoi(dateString.substr(index2+1,index1-index2-1)); // day

  std::cout << "mark 1.3: day="<<d<<std::endl;
  
  index2 = dateString.find(":");
  int hr = std::stoi(dateString.substr(index1+1,index2-index1-1)); // hour

  int min = std::stoi(dateString.substr(index2+1, dateString.size()-index2-1)); // minute

  std::cout << "mark 2: " <<y<<","<<m<<","<<d<<","<<hr<<","<<min<<std::endl;
  return Date(y,m,d,hr,min);

}


/* Adds an event to the unordered hash map, indexed by ID */
/*
The standard for incoming event information is the following:

title|longitude|latitude|pace|distance|date

The date format is of the following form:

YYYY/MM/DD|HH:MM

 */
void addEvent(std::string input,std::unordered_map<int,Event>& eventsID, EventsByLocation& eventsLoc){
  static int ID_count = 0; // increments each time this function is called; creates unique ID for each Event
  int ID = ID_count++;
  std::string temp;
  int index;
  int index2;
  index = input.find("|");
  std::string title = input.substr(0,index);
  //  std::cout << "mark 3-" << title << std::endl;

  
  index2 = input.find("|",index+1);
  float longitude = std::stof(input.substr(index+1,index2-index-1));

  index = input.find("|",index2+1);
  float latitude = std::stof(input.substr(index2+1,index-index2-1));

  index2 = input.find("|",index+1);
  int pace = std::stoi(input.substr(index+1,index2-index-1));

  std::cout << "mark 0: found pace" << std::endl;

  
  index = input.find("|",index2+1);
  int distance = std::stoi(input.substr(index2+1,input.size()-index2-1));

  std::cout << "mark 0.5: found distance="<<distance << std::endl;
  
  std::string dateString = input.substr(index+1,input.size()-index-1);

  std::cout << "mark 0.6: found datestring='"<<dateString<<"'"<<std::endl;
  Date date = parseDate(dateString);
  
  // Create event and add it to hash map by ID

  std::cout << "Event: " << title << " at " << longitude << "," << latitude << " and " << pace << std::endl;
  
  Event e = Event(ID,title,longitude,latitude,date,pace,distance);
  eventsID[ID] = e;
  // Add code to add to index by location
  eventsLoc.addEvent(e);
  
  std::cout << "Event added: " << e.getJSON() << std::endl;
}



int main(){
  EventsByLocation eventsByLoc;
  std::string input;
  std::unordered_map<int,Event> eventsByID; // stores hash map of events searchable by ID

  
  //int map[10][10];
  while(1){
    // NOTE: input string MAY NOT contain any spaces (' ') or parsing WILL fail
    // input string is of form: title|longitude|latitude|pace|distance|date
    std::cin >> input;
    addEvent(input,eventsByID,eventsByLoc);
  }
}
