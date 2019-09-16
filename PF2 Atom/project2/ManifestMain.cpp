#include "Manifest.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//Main program for the Manifest class
int main()
{
    Manifest flight;
    ifstream din;
    string fileName;
    cout << "Enter the name of the input file: " << endl;
    cin >> fileName;
    din.open(fileName);
    //Ends program if file failed to open
    if (din.fail())
        return 0;
    //Loops until end of file is reached
    string firstName, lastName;
    int command = 0;
    while (!din.eof() && command != 5)
    {
        //Takes in commands from file
        din >> command;
        if (command == 1)//Command for booking passenger
        {
            din >> firstName >> lastName;
            flight.insert(firstName, lastName);
        }
        else if (command == 2)//Command for removing passenger from flight
        {
            din >> firstName >> lastName;
            flight.deletePassenger(firstName, lastName);
        }
        else if (command == 3)//Command for confirming passenger
        {
            din >> firstName >> lastName;
            flight.search(firstName, lastName);
        }
        else if (command == 4)//Command for printing out passenger names
        {
            flight.print();
        }
        else if (command == 5)//Command for exiting program
        {
            //Calls deconstructor to return memory
            flight.~Manifest();
        }
    }
    return 0;
}
