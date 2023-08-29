#include "Visuals.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <matplot/matplot.h>
#include <stdlib.h>     //for using the function sleep

namespace plt = matplot;


Visuals::Visuals(){
    std::cout << "Preparing Simulation viusals" << std::endl;
}

Visuals::Visuals(int num_objects){
    std::cout << "Initializing Simulation viusals with : " << num_objects << " objects" << std::endl;

    //Set initial
    objects = {{0.0,0.0,0.0},{0.0,0.0,0.0}};
    this->figure = plt::figure();
    // this->figure->ion(true);
    this->figure->quiet_mode(true);

    
}

void Visuals::createPlot(std::vector<double> initialPositions) {

objects.at(1) = initialPositions;

std::vector<double> x(3) ;
std::vector<double> y(3) ;
std::vector<double> z(3) ;


for(int i = 0;i<objects.size();i++)
{
    x.at(i) = objects[i][0];
    y.at(i) = objects[i][1];
    z.at(i) = objects[i][2];
}
std::vector<double> sizes = { 7, 1 };
std::vector<double> colors = { 1,8 };

auto ax = figure->current_axes();
ax->xlim({-4e+05,4e+05});
ax->ylim({-4e+05,4e+05});
ax->zlim({-4e+05,4e+05});
auto line1 = ax->scatter3(x,y,z,sizes,colors)->marker_face_color({1,3});


};

void Visuals::updatePlot(std::vector<double>newPositions) {


objects.at(1) = newPositions;

std::vector<double> x(3) ;
std::vector<double> y(3) ;
std::vector<double> z(3) ;


for(int i = 0;i<objects.size();i++)
{
    x.at(i) = objects[i][0];
    y.at(i) = objects[i][1];
    z.at(i) = objects[i][2];
}

std::vector<double> sizes = { 7, 1 };
std::vector<double> colors = { 1,2 };



auto ax = figure->current_axes();

auto line1 = ax->scatter3(x,y,z,sizes,colors)->marker_face_color({1,2});
// ax->plot3(x,y,z);
Sleep(700);
figure->draw();
   
//     plt::plot3(x,y,z);
//     plt::xlabel("x");
//     plt::ylabel("y");
//     plt::zlabel("z");

//     plt::title("Earth and Moon");

//     plt::show();


// using namespace matplot;
//     auto [X, Y] = meshgrid(linspace(-5, +5, 40), linspace(-5, +5, 40));
//     auto Z = transform(X, Y, [](double x, double y) {
//         return 10 * 2 + pow(x, 2) - 10 * cos(2 * pi * x) + pow(y, 2) -
//                10 * cos(2 * pi * y);
//     });
//     surf(X, Y, Z);

//     show();
    // using namespace matplot;
    // std::vector<double> x {1,2,3,4,5,6,7,8,9,10};
    // std::vector<double> y(10);

    // for(int i = 0;i<10; i++)
    // {
    //     y.at(i) = sin(x.at(i));
        
    // };

    
    // auto fig = figure();
    // fig->ion();
    // auto ax = fig->current_axes();
    // auto line1 = ax->plot(x,y);


    // for(int i = 0; i<100; i++)
    // {    
    //     for(int j = 0;j<10; j++)
    // {
    //     y.at(j) = sin(x.at(j)+i*0.1);
    // };

    // line1->x_data(  static_cast<const std::vector<double>>(x)) ;
    // line1->y_data(  static_cast<const std::vector<double>>(y)) ;
    // fig->draw();
    //    };






};