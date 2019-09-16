#include "Address.h"
//Implementation of the Address class
//Default Constructor
Address::Address()
{
  lat = 0;
  lon = 0;
  houseNum = 0;
  street = "";
}
//Non-Default Constructor
Address::Address(float _lat, float _lon, int _houseNum, string _street)
{
  lat = _lat;
  lon = _lon;
  houseNum = _houseNum;
  street = _street;
}
//Copy Constructor
Address::Address(const Address & orig)
{
  lat = orig.lat;
  lon = orig.lon;
  houseNum = orig.houseNum;
  street = orig.street;
}
//Deconstructor
Address::~Address()
{

}
//Accessor Methods
float Address::getLatitude()
{
  return lat;
}
float Address::getLongitude()
{
  return lon;
}
int Address::getHouseNumber()
{
  return houseNum;
}
string Address::getStreetName()
{
  return street;
}
//Mutator Methods
void Address::setLatitude(float _lat)
{
  lat = _lat;
}
void Address::setLongitude(float _lon)
{
  lon = _lon;
}
void Address::setHouseNumber(int _houseNum)
{
  houseNum = _houseNum;
}
void Address::setStreetName(string _street)
{
  street = _street;
}
void Address::print()
{
   cout << "Latitude: " << lat << endl;
   cout << "Longitude: " << lon << endl;
   cout << "House Number: " << houseNum << endl;
   cout << "Street: " << street << endl;
}
