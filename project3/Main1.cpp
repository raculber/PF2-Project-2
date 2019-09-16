#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Address.h"
using namespace std;
//Rescursive Binary Search
void binarySearch(vector<Address> & address_list, int houseNum, string street, int low, int high)
{
  int mid = (low+high)/2;
  //If address was not found
  if (low > high)
  {
    cout << "Could not find matching address." << endl;
    return;
  }
  //If Address was found
  else if (address_list[mid].getHouseNumber() == houseNum &&
  address_list[mid].getStreetName() == street)
  {
    cout << "Found matching address: " << endl;
    address_list[mid].print();
    return;
  }
  //Recursive cases
  //Case for if the street names match
  if (address_list[mid].getStreetName() == street)
  {
    if (address_list[mid].getHouseNumber() > houseNum)
      return (binarySearch(address_list, houseNum, street, low, mid-1));
    else if (address_list[mid].getHouseNumber() < houseNum)
      return (binarySearch(address_list, houseNum, street, mid+1, high));
  }
  //For non-matching street names
  else if (address_list[mid].getStreetName() > street)
    return (binarySearch(address_list, houseNum, street, low, mid-1));
  else if (address_list[mid].getStreetName() < street)
    return (binarySearch(address_list, houseNum, street, mid+1, high));
}
/*Reads in file of addresses and performs
binary search to find the latitude and
longitude that goes with a specific street
address*/
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
  din.open("input1.txt");
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
  int searchNum;
  string searchName;
  while (yesOrNo != "N")
  {
    cout << "Enter the street address you want to search for: " << endl;
    cin >> searchNum;
    //Ignores space between the house number and address
    cin.ignore();
    getline(cin, searchName);
    binarySearch(address_list, searchNum, searchName, 0, address_list.size()-1);
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
