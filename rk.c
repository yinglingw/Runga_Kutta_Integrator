#include "rk.h"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
/Users/Felix/Phys 305/Completed/InClass/Runge Kutta/rk.c

double rk4(double (*g)(double,double),double xi, double fi, double h)
{

  double k1, k2, k3, k4; 
  //1 2 3 4 steps

  k1 =h*g(xi, fi);
  k2 =h*g(xi + h, fi + 0.5*k1);
  k3 =h*g(xi + h, fi + 0.5*k2);
  k4 =h*g(xi + h, fi + k3);

return fi + k1/6. + k2/3. + k3/3. + k4/6.;


}

/*

  double y11h, x11, f11, h_update;
  double y2h, Delta;

  double TOLERANCE = 1.0e-5;
  double SAFETY = 0.9;

  k1 =2*h*g(xi, fi);
  k2 =2*h*g(xi + h, fi + 0.5*k1);
  k3 =2*h*g(xi + h, fi + 0.5*k2);
  k4 =2*h*g(xi + 2*h, fi + k3);

  y2h = fi + k1/6. + k2/3. + k3/3. + k4/6.;

  //first step
  x11 = xi;
  f11 = fi;

  k1 =h*g(x11, f11);
  k2 =h*g(x11 + 0.5*h, f11 + 0.5*k1);
  k3 =h*g(x11 + 0.5*h, f11 + 0.5*k2);
  k4 =h*g(x11 + h, f11 + k3);

  f11 = fi + k1/6. + k2/3. + k3/3. + k4/6.;

  //second step
  x11 = xi;
  f11 = fi;

  k1 =h*g(x11, f11);
  k2 =h*g(x11 + 0.5*h, f11 + 0.5*k1);
  k3 =h*g(x11 + 0.5*h, f11 + 0.5*k2);
  k4 =h*g(x11 + h, f11 + k3);

  f11 = fi + k1/6. + k2/3. + k3/3. + k4/6.;


  Delta = fabs(y2h - y11h);
  //error estimnate

  if(Delta/TOLERANCE>1.0)
    {

      *h_new = h* SAFETY * pow(Delta/TOLERANCE, -0.25);

      h_update = h_new;

      return  rk4ad(g,xi,fi,h_update,h_step, h_new);
    }else{

    *h_step = h;

    *h_new = 5*h;

    return f11;
  }
}

*/
