#include <iomanip>
#include <cmath>
using namespace std;

double trapezoidal_rule(double (*f)(double), double lowerLimit, double upperLimit, int pieces);
double f(double x);

int main() {
  double  lowerLimit = 0,
          upperLimit = 0.8;
  double t, error, realValue = 1.640533;
  int pieces[11] = {1,10,20,30,40,50,60,70,80,90,100};

  printf ("\nNumerical integration by Trapezoidal Rule method\n");

  printf ("\nPieces\tTrapezoidal\tPorcentual error\n");
  for (int i = 0; i < (sizeof(pieces)/sizeof(pieces[0])); i++) {
    t = trapezoidal_rule(f, lowerLimit, upperLimit, pieces[i]);
    error = fabs(((realValue - t)/realValue))*100;
    printf ("%d\t%g\t\t%0.4f%%\n",pieces[i],t,error);
  }
  printf ("\n");

  return 0;
}

double trapezoidal_rule(double (*f)(double), double lowerLimit, double upperLimit, int pieces) {
  int i;
  double h, sum, integral;
  double x[pieces+1], y[pieces+1];
  sum = 0;
  h = (upperLimit - lowerLimit) / pieces;

  for (i = 0; i <= pieces; i++) {
    x[i] = lowerLimit + i*h;
    y[i] = f(x[i]);
  }
  for (i = 1; i < pieces; i++) {
    sum = sum + h*y[i];
  }
  integral = (h/2.0)*(y[0] + y[pieces]) + sum;
  return integral;
}

// 0.2 + 25x - 200x^2 + 675x^3 - 900 x^4 + 400x^5
double f(double x) {
  return ( (400*pow(x,5)) - (900*pow(x,4)) + (675*pow(x,3))
                          - (200*pow(x,2)) + (25*x) + 0.2 );
}
