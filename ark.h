#ifndef RK_H
#define RK_H


double rk4(double (*g)(double,double),double xi, double fi, double h);

double ark4(double (*g)(double,double),double xi, double fi, double h, double *h_step, double *h_new);


#endif
