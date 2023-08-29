#include "Moon.hpp"
#include "DateTime.hpp"
#include "Constants.cpp"
#include <iostream>

   Moon::Moon()
   {
      std::cout << "Initializing Moon" <<std::endl;

      //testing starting at  2018-Jan-01 00:00:00.0000
      distance = 2.389077301811979E-03;
      position = Vector3D(3.392716476976470E+04,3.549039223355239E+05,-2.505075823863294E+04);//km
      speed = Vector3D(-9.465924213906458E+04,7.610112340857113E+03,5.584582037559116E+03); //km/day


   }

   double Moon::fx(double x, double y, double z){return -G*Mt*(x)/pow(pow(x,2)+pow(y,2)+pow(z,2),3/2.0);}
   double Moon::fy(double x, double y, double z){return -G*Mt*(y)/pow(pow(x,2)+pow(y,2)+pow(z,2),3/2.0);}
   double Moon::fz(double x, double y, double z){return -G*Mt*(z)/pow(pow(x,2)+pow(y,2)+pow(z,2),3/2.0);}

   void Moon::updatePositionAndVelocity(double timeStep)
   {

      //TimeStep conversion

      //Initializing Runge-Kutta variables
      double kx1, kx2, kx3, kx4;
      double ky1, ky2, ky3, ky4;
      double kz1, kz2, kz3, kz4;

      double kux1, kux2, kux3, kux4;
      double kuy1, kuy2, kuy3, kuy4;
      double kuz1, kuz2, kuz3, kuz4;

      std::cout << "Updating position and Velocity"<<std::endl;

      //Numerical integration steps
      //RGV1
      kx1 = timeStep*speed.x;
      ky1 = timeStep*speed.y;
      kz1 = timeStep*speed.z;

      kux1 = timeStep*fx(position.x,position.y,position.z);
      kuy1 = timeStep*fy(position.x,position.y,position.z);
      kuz1 = timeStep*fz(position.x,position.y,position.z);

      //RKV2
      kx2 = timeStep*(speed.x +0.5*kux1);
      ky2 = timeStep*(speed.y +0.5*kuy1);
      kz2 = timeStep*(speed.z +0.5*kuz1);

      kux2 = timeStep*fx(position.x + 0.5*kx1,position.y + 0.5*ky1,position.z+0.5*kz1);
      kuy2 = timeStep*fy(position.x + 0.5*kx1,position.y + 0.5*ky1,position.z+0.5*kz1);
      kuz2 = timeStep*fz(position.x + 0.5*kx1,position.y + 0.5*ky1,position.z+0.5*kz1);

      //RKV3
      kx3 = timeStep*(speed.x +0.5*kux2);
      ky3 = timeStep*(speed.y +0.5*kuy2);
      kz3 = timeStep*(speed.z +0.5*kuz2);

      kux3 = timeStep*fx(position.x + 0.5*kx2,position.y + 0.5*ky2,position.z+0.5*kz2);
      kuy3 = timeStep*fy(position.x + 0.5*kx2,position.y + 0.5*ky2,position.z+0.5*kz2);
      kuz3 = timeStep*fz(position.x + 0.5*kx2,position.y + 0.5*ky2,position.z+0.5*kz2);

      //RKV4
      kx4 = timeStep*(speed.x + kux3);
      ky4 = timeStep*(speed.y + kuy3);
      kz4 = timeStep*(speed.z + kuz3);

      kux4 = timeStep*fx(position.x + kx3,position.y + ky3,position.z+kz3);
      kuy4 = timeStep*fy(position.x + kx3,position.y + ky3,position.z+kz3);
      kuz4 = timeStep*fz(position.x + kx3,position.y + ky3,position.z+kz3);

      //Final update of values
      position.x = position.x + (timeStep/6.0)*(kx1 + 2*kx2 + 2*kx3 + kx4);
      position.y = position.y + (timeStep/6.0)*(ky1 + 2*ky2 + 2*ky3 + ky4);
      position.z = position.z + (timeStep/6.0)*(kz1 + 2*kz2 + 2*kz3 + kz4);

      //std::cerr << "kvalues for speed " << (1/6.0)*(kux1 + 2*kux2 + 2*kux3 + kux4) << std::endl;
      speed.x = speed.x + (timeStep/6.0)*(kux1 + 2*kux2 + 2*kux3 + kux4);
      speed.y = speed.y + (timeStep/6.0)*(kuy1 + 2*kuy2 + 2*kuy3 + kuy4);
      speed.z = speed.z + (timeStep/6.0)*(kuz1 + 2*kuz2 + 2*kuz3 + kuz4);


   }


