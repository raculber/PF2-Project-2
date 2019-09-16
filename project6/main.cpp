#include "BinaryTree.h"
//Main program to test BinaryTree class
int main()
{
  float lat = 0;
  float lon = 0;
  int houseNum = 0;
  string street = "";
  char ch = ' ';
  BinaryTree bst;
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
    bst.Insert(add);
  }
  //Command for continuing or ending the program
  string yesOrNo = " ";
  int searchNum;
  string searchName;
  bool search;
  float latSearch = 0;
  float lonSearch = 0;
  while (yesOrNo != "N")
  {
    cout << "Enter the street address you want to search for: " << endl;
    cin >> searchNum;
    //Ignores space between the house number and address
    cin.ignore();
    getline(cin, searchName);
    search = bst.Search(searchNum, searchName, latSearch, lonSearch);
    //Address successfully found
    if (search)
    {
      cout << "Latitidue: " << latSearch << endl;
      cout << "Longitude: " << lonSearch << endl;
    }
    //Address not found
    else
      cout << "Address not found" << endl;
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
