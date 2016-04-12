#include "ark.h"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>


double ark4(double (*g)(double,double),double xi, double fi, double h, double *h_step, double *h_new)
{

  double k1, k2, k3, k4; 
  //1 2 3 4 steps

  double y11h, x11, f11, h_update;
  double y2h, Delta;

  double TOLERANCE = 1.0e-5;
  double SAFETY = 0.9; // factor for reducing step size safely


  //for y2h

  k1 =2*h*g(xi, fi);
  k2 =2*h*g(xi + h, fi + 0.5*k1);
  k3 =2*h*g(xi + h, fi + 0.5*k2);
  k4 =2*h*g(xi + 2*h, fi + k3);

  y2h = fi + k1/6. + k2/3. + k3/3. + k4/6.;

  //for y11h

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
  y11h = f11;

  k1 =h*g(x11, f11);
  k2 =h*g(x11 + 0.5*h, f11 + 0.5*k1);
  k3 =h*g(x11 + 0.5*h, f11 + 0.5*k2);
  k4 =h*g(x11 + h, f11 + k3);

  y11h = f11 + k1/6. + k2/3. + k3/3. + k4/6.;


  Delta = fabs(y2h - y11h);
  //error estimnate

  if(Delta/TOLERANCE>1.0)
    {
      //if error to large we have reduce the stepsize
      //new stepsize
      *h_new = h * SAFETY * pow(Delta/TOLERANCE, -0.25);

      h_update = *h_new;

      return  ark4(g,xi,fi,h_update,h_step, h_new);

    }else{//this mean the stepsize is good and works fine

    *h_step = h;

    *h_new = 5*h;

    return f11;
  }
}

