#include<stdio.h>
#include<math.h>
#include"rk.h"

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

  xi = x0;

  while(xi+h<=x1)
    {
      fi_new = rk4(g,xi,fi,h);

      if(xi+h>x1)
	{
	  h = x1 - xi;
	  fi_new = rk4(g,xi,fi,h);
	}

      xi += h;
      fi = fi_new;

      printf("i %2d xi %e fi %e\n", i,xi,fi);

      i++;

    }

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




