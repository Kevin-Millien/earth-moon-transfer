#pragma once
#include <vector>
#include <matplot/matplot.h>

/// @brief 
class Visuals{
    


    public:
    std::vector<std::vector<double>> objects;
    matplot::figure_handle figure;

    Visuals();

    Visuals(int num_objects);

    //Initialize Plot with object and initals points and stuff
    void createPlot(std::vector<double> initialPositions);

    //And new plot Position.
    void updatePlot(std::vector<double> newPositions);


};