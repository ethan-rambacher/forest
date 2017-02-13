#include <iostream>
#include <vector>
#include <cmath>


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

private:
  float lon;
  float lat;

};

