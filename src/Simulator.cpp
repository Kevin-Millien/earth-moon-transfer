#include "Simulator.hpp"
#include "Earth.hpp"
#include "Moon.hpp"
#include "DateTime.hpp"
#include <iostream>
#include <iomanip>      // std::setprecision

// Constructor to initialize the simulator
Simulator::Simulator(DateTime date) {
    // Create instances of Earth and Moon
    // earth = Earth(/* initial parameters */);
    std::cout << "Beginning Simulation" <<std::endl;
    std::cout << std::scientific << std::setprecision(16);
    std::cout << "Moon initial Position (x,y,z): (" << moon.position.x <<","<< moon.position.y << ","<< moon.position.z << ")" << std::endl;
    std::cout << "Moon Initial Speed (x,y,z): (" << moon.speed.x <<","<< moon.speed.y << ","<< moon.speed.z << ")" << std::endl;
}

// Method to start the simulation
void Simulator::runSimulation() {
    // Set up the simulation parameters
    double timeStep = 1; // 1 day
    double totalTime = 1; // Adjust the total simulation time as required
    int numSteps = static_cast<int>(totalTime / timeStep);

    // Main simulation loop
    for (int step = 0; step < numSteps; ++step) {
        // Update positions and velocities of Earth and Moon
        // using their respective methods (defined in Earth.cpp and Moon.cpp)



        // earth.updatePositionAndVelocity(/* parameters */);
        moon.updatePositionAndVelocity(timeStep);

        // Display the current state of the simulation
        displaySimulationState();

        // Display the current state of the simulation
        updateSimulationVisuals();

        // Optionally, include a pause to control the simulation speed
        // You can use a library like <chrono> to add a delay here

        // // Handle user interactions (if any) during the simulation
        // handleUserInteractions();
    }
}

// Method to display the current state of the simulation
void Simulator::displaySimulationState() const {
    // You can print the positions and velocities of the Earth and Moon
    // at the current time step to observe their movement
    // std::cout << "Time: " << currentTime.UTC() << std::endl;
    // std::cout << "Earth Position: (" << earth.getX() << ", " << earth.getY() << ")" << std::endl;

    std::cout << std::scientific;
    std::cout << "Moon Position (x,y,z): (" << moon.position.x <<","<< moon.position.y << ","<< moon.position.z << ")" << std::endl;
    std::cout << "Moon Speed (x,y,z): (" << moon.speed.x <<","<< moon.speed.y << ","<< moon.speed.z << ")" << std::endl;
}

void  Simulator::updateSimulationVisuals() {
    std::cout << "Look at my nice graph please, thanks :)pip3";
}

// // Method to handle user interactions (if any)
// void Simulator::handleUserInteractions() {
//     // You can include code here to check for user input during the simulation
//     // For example, pausing the simulation, adjusting time scale, etc.
// }
