#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Address.h"
#include <cmath>
using namespace std;
//Iterative Binary Search
int binarySearch(vector<Address> & address_list, float lat,
int low, int high)
{
  while (low <= high)
  {
    int mid = (low + high)/2;
    //If address is in range
    if (address_list[mid].getLatitude() == lat)
    {
      return mid;
    }
    //If address is lower than range
    else if (address_list[mid].getLatitude() < lat)
    {
      low = mid + 1;
    }
    //If address is higher than range
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int main()
{
  float lat = 0;
  float lon = 0;
  int houseNum = 0;
  string street = "";
  char ch = ' ';
  vector<Address>address_list;
  ifstream din;
  //Opens file with address information
  din.open("input2.txt");
  //Ends program if file failed to open
  if (din.fail())
  {
    return 0;
  }
  //Loops until end of file is reached
  while (!din.eof())
  {
    din >> lat >> lon >> houseNum;
    /*Stores the space after the house number
    so its not part of the street address*/
    din.get(ch);
    getline(din, street);
    Address add;
    add.setLatitude(lat);
    add.setLongitude(lon);
    add.setHouseNumber(houseNum);
    add.setStreetName(street);
    address_list.push_back(add);
  }
  //Command for continuing or ending the program
  string yesOrNo = " ";
  float searchLat = 0;
  float searchLon = 0;
  float searchRadius = 0;
  int index = 0;
  while (yesOrNo != "N")
  {
    cout << "Enter the latitude value you want to search for: " << endl;
    cin >> searchLat;
    cout << "Enter the longitude value you want to search for: " << endl;
    cin >> searchLon;
    cout << "Enter the search radius: " << endl;
    cin >> searchRadius;
    index = binarySearch(address_list, searchLat, 0, address_list.size()-1);
    float upperLatRange = searchRadius + searchLat;
    float lowerLatRange = searchLat - searchRadius;
    double distance = 0;
    if (index !=-1)
    {
      int i = index;
      //While loop for checking upper range
      while (address_list[i].getLatitude() <= upperLatRange && i < address_list.size())
      {
        //Calulate the distance
        distance = sqrt(pow(searchLat - address_list[i].getLatitude(), 2.0) + pow(searchLon - address_list[i].getLongitude(), 2.0));
        if (distance <= searchRadius)
        {
          address_list[i].print();
        }
        i++;
      }
      //While loop for checking lower range
      i = index - 1;
      while (address_list[i].getLatitude() >= lowerLatRange && i >= 0)
      {
        //Calulate the distance
        distance = sqrt(pow(searchLat - address_list[i].getLatitude(), 2.0) + pow(searchLon - address_list[i].getLongitude(), 2.0));
        if (distance <= searchRadius)
        {
          address_list[i].print();
        }
        i--;
      }
    }
    cout << "Do you want to continue searching? (Enter Y or N) ";
    cin >> yesOrNo;
    //Checks if user entered a valid command
    while (yesOrNo != "Y" && yesOrNo != "N")
    {
      cout << "Do you want to continue searching? (Enter Y or N) ";
      cin >> yesOrNo;
    }
  }
  return 0;
}
