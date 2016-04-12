#include<stdio.h>
#include<math.h>
#include"ark.h"

double g(double x, double f);


int main( int argc, char **argv)
{

  int i = 0;
  int n = 20; //step betwn begining and ending interval
  double f0 = 0.0;
  double x0 = 0.0;
  double x1 = 1.0;
  double xi;
  double fi = f0;
  double fi_new;

  double h = (x1 - x0) / ((double)(n-1));
  double h_new = h;
  double h_step = h;

  xi = x0;

  while(xi+h<=x1)
    {
      fi_new = ark4(g,xi,fi,h, &h_step, &h_new); //calc f_i+1
      h = h_new; // update x_i+1 = x_i+h
      xi += h_step; //h_step is the step we actually took
      fi = fi_new;

      printf("i %4d xi %e fi %e h_step %e h_new %e\n", i,xi,fi,h_step,h,h_new);


      if(xi+h>x1)
	{
	  if(xi == x1)
	    break;
	  h = x1 - xi;
	}

      i++;

    } // end while

  //output answer
  printf("xi %e fi %e\n",xi,fi);

  return 0;
}


//function from before main
double g(double x, double f)
{
  double a = 5.05;
  double b = -12.16;
  double c = -12.6;
  double d = 17.0;
  double p = 10;


  return a*pow(x,4) + b*pow(x,3) + c*pow(x,2) + d*x + p;
}
