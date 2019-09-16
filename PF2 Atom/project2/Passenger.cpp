#include "Passenger.h"
//Implementation of Passenger class
//Default constructor
Passenger::Passenger()
{
    firstName = "";
    lastName = "";
}
//Non-default constructor
Passenger::Passenger(string _firstName, string _lastName)
{
    firstName = _firstName;
    lastName = _lastName;
}
//Copy constructor
Passenger::Passenger(const Passenger & orig)
{
    firstName = orig.firstName;
    lastName = orig.lastName;
}
//Deconstructor
Passenger::~Passenger()
{

}
//Accesor Methods
Passenger * Passenger::getNext()
{
    return next;
}
string Passenger::getFirstName()
{
    return firstName;
}
string Passenger::getLastName()
{
    return lastName;
}
//Mutator Methods
void Passenger::setNext(Passenger * _next)
{
    next = _next;
}
void Passenger::setFirstName(string _firstName)
{
    firstName = _firstName;
}
void Passenger::setLastName(string _lastName)
{
    lastName = _lastName;
}
//Prints out name of passenger
void Passenger::print()
{
    cout << firstName << " " << lastName;
}
