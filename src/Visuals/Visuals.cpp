#include "Visuals.hpp"
#include <iostream>
#include "matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

Visuals::Visuals(){
    std::cout << "Starting Viusals" << std::endl;
}

void Visuals::plot() {
    std::vector<double> y = { 1, 3, 2, 4 };
    plt::plot(y);

    plt::show();

};