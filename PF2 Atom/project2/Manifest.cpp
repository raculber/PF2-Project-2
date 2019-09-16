#include "Manifest.h"
//Implementation of the Manifest class
//Constructor and deconstructor
Manifest::Manifest()
{
    head = NULL;
}
Manifest::~Manifest()
{
    Passenger * ptr = head;
    while (ptr != NULL)
    {
        head = head->getNext();
        delete ptr;
        ptr = head;
    }
}
//Adds a passenger to the link list in sorted order
void Manifest::insert(string firstName, string lastName)
{
    Passenger * current = head;
    Passenger * prev = current;
    string fullName = lastName + firstName;
    while ((current != NULL) && (current->getLastName() + current->getFirstName() < fullName))
    {
        prev = current;
        current = current->getNext();
    }
    //Case if the passenger is already in the list
    if ((current != NULL) && (current->getLastName() + current->getFirstName() == fullName))
    {
      cout << "Declined booking for " << firstName << " " << lastName << endl;
    }
    //Case if passenger needs to be inserted at the head of the list
    else if (current == head)
    {
        head = new Passenger(firstName, lastName);
        cout << "Booked " << firstName << " " << lastName << endl;
        head->setNext(current);
    }
    //Case if the passenger needs to be inserted at the middle or end of the list
    else
    {
      prev->setNext(new Passenger(firstName, lastName));
      cout << "Booked " << firstName << " " << lastName << endl;
      prev->getNext()->setNext(current);
    }
}
//Deletes a passenger from the linked list
void Manifest::deletePassenger(string firstName, string lastName)
{
    Passenger * current = head;
    Passenger * prev = NULL;
    while ((current != NULL) && (current->getFirstName() != firstName) && (current->getLastName() != lastName))
    {
        prev = current;
        current = current->getNext();
    }
    //If passenger to be deleted is at the head of the list
    if ((current != NULL) && (current == head))
    {
        head = current->getNext();
        delete current;
        cout << "Cancelled booking for " << firstName << " " << lastName << endl;
    }
    //If passenger to be deleted is at the middle or end of the list
    else if (current != NULL)
    {
        prev->setNext(current->getNext());
        delete current;
    }
    //If passenger to be deleted was not found in the list
    else
    {
        cout << "Could not cancel booking for " << firstName << " " << lastName << endl;
    }


}
//Searches to see if someone is on the flight
void Manifest::search(string firstName, string lastName)
{
    Passenger * ptr = head;
    bool isBooked = false;
    while ((ptr != NULL) && (isBooked == false))
    {
        if ((ptr->getFirstName() == firstName) && (ptr->getLastName() == lastName))
            isBooked = true;
        else
            ptr = ptr->getNext();
    }
    if (isBooked == true)
        cout << "Confirmed passenger " << firstName << " " << lastName << endl;
    else
        cout << "Passenger " << firstName << " " << lastName << " not found." << endl;

}
//Prints out the name of each passenger in the list
void Manifest::print()
{
    Passenger * ptr = head;
    while (ptr != NULL)
    {
        ptr->print();
        cout << " -> ";
        ptr = ptr->getNext();
    }
    cout << " x" << endl;
}
