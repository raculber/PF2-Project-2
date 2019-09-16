#include "Address.h"
/*Header file for linked list class
that will hold Address objects*/
class List
{
public:
  //Public Methods
  //COnstructor and Deconstructor
  List();
  ~List();
  //Inserts address into List
  bool Insert(Address add);
  //Removes address form List
  bool Delete(Address add);
  //Finds Address in the list
  bool Search(int num, string name, float &lat, float &lon);
  //Prints out content of List
  void Print();
private:
  Address * head;
};
