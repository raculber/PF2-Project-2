//Header file for the Address class
#include <iostream>
#include <string>
using namespace std;
class Address
{
public:
  //Constructors and Deconstructor
  Address();
  Address(float _lat, float _lon, int _houseNum, string _street);
  Address(const Address & orig);
  ~Address();
  //Accessor Methods
  float getLatitude();
  float getLongitude();
  int getHouseNumber();
  string getStreetName();
  //Mutator Methods
  void setLatitude(float _lat);
  void setLongitude(float _lon);
  void setHouseNumber(int _houseNum);
  void setStreetName(string _street);
  //Print Method
  void print();
private:
  float lat;
  float lon;
  int houseNum;
  string street;
};
