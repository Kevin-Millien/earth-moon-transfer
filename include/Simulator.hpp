#pragma once

#include "DateTime.hpp"
#include <iostream>
#include "Moon.hpp"

class Simulator{
    public:
        DateTime currentTime;
        Moon moon;

    // Constructor to initialize the simulator
    Simulator(DateTime date);

    // Method to start the simulation
    void runSimulation();

    // Method to display the current state of the simulation
    void  displaySimulationState() const;

    void updateSimulationVisuals();

    // Method to handle user interactions (if any)
    void handleUserInteractions();

    // Add any additional methods or functionalities here as needed.
};