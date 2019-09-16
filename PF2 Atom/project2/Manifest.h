//Header file for the Manifest Class
#include "Passenger.h"
class Manifest
{
    public:
        //Constructors and deconstructor
        Manifest();
        ~Manifest();
        //Books a passenger
        void insert(string firstName, string lastName);
        //Cancels a passenger's booking
        void deletePassenger(string firstName, string lastName);
        //Confirms a booking
        void search(string firstName, string lastName);
        //Prints the list of passengers in sorted order
        void print();
    private:
        Passenger * head;
};
