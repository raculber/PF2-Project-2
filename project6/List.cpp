#include "List.h"
//Implementation of List Class
//Default Constructor
List::List()
{
  head = NULL;
}
List::~List()
{
  Address * ptr = head;
  while (ptr != NULL)
  {
      head = head->getNext();
      delete ptr;
      ptr = head;
  }
}
//Insert Address at head
bool List::Insert(Address add)
{
  Address * temp;
  temp = new Address(add);
  temp->setNext(head);
  head = temp;
}
//Deletes Address from List
bool List::Delete(Address add)
{
  Address * current = head;
  Address * prev = NULL;
  while ((current != NULL) && (current->getHouseNumber() != add.getHouseNumber()) &&
  (current->getStreetName() != add.getStreetName()))
  {
      prev = current;
      current = current->getNext();
  }
  //If passenger to be deleted is at the head of the list
  if ((current != NULL) && (current == head))
  {
      head = current->getNext();
      delete current;
      return true;
  }
  //If address to be deleted is at the middle or end of the list
  else if (current != NULL)
  {
      prev->setNext(current->getNext());
      delete current;
      return true;
  }
  //If address to be deleted was not found in the list
  else
    return false;
}
//Searches for Address in list
bool List::Search(int num, string name, float &lat, float &lon)
{
  Address * ptr = head;
  bool isThere = false;
  while ((ptr != NULL) && (isThere == false))
  {
      if ((ptr->getHouseNumber() == num) && (ptr->getStreetName() == name))
      {
          lat = ptr->getLatitude();
          lon = ptr->getLongitude();
          isThere = true;
      }
      else
          ptr = ptr->getNext();
  }
  if (isThere == true)
      return true;
  else
      return false;
}
void List::Print()
{
  Address * ptr = head;
  while (ptr != NULL)
  {
      ptr->print();
      cout << " -> ";
      ptr = ptr->getNext();
  }
  cout << " x" << endl;
}
