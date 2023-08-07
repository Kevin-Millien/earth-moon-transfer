#include "Simulator.hpp"
#include "DateTime.hpp"

#include <iostream>
#include <string>

using namespace std;

void displayWelcomeMessage(){
    cout << "Welcome to AstroTransfer" << endl;
}



void displayGoodbyeMessage(){
    cout << endl << "Thank you for using AstroTransfer" ;
};



int main() {


    // Display a welcome message or instructions (optional)
    displayWelcomeMessage();

    //Create a Simulator instance
    DateTime date;
    Simulator simulator (date);

    //Start the simulation
    simulator.runSimulation();

    // Display a goodbye message or summary (optional)
    displayGoodbyeMessage();

    return 0;
}