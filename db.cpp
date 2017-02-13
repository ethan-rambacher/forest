#include <iostream>
#include <vector>
#include <cmath>
#include <string>

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
  }

private:
  // coordinates are stored in degrees.
  float lon;
  float lat;

};

class Event{
public:
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
    return "{id:"+std::to_string(id)+",title:'"+title+"',lon:"
      +std::to_string(location.getLon())+",lat:"+std::to_string(location.getLat())
      +",pace:"+std::to_string(pace)+"}";
  }									     
  
private:
  id = ident;
  std::string title;
  Coordinate location;
  int pace;
  
};

