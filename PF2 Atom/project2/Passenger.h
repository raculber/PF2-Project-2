//Header file for the Passenger class
#include <iostream>
#include <string>
using namespace std;
class Passenger
{
    public:
    //Constructors and Deconstructor
        Passenger();
        Passenger(string _firstName, string _lastName);
        Passenger(const Passenger & orig);
        ~Passenger();
    //Accessor Methods
        Passenger * getNext();
        string getFirstName();
        string getLastName();
    //Mutator Methods
        void setNext(Passenger * _next);
        void setFirstName(string _firstName);
        void setLastName(string _lastName);
    //Prints out passenger information
        void print();
    private:
        string firstName;
        string lastName;
        Passenger * next;
};
