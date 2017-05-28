#include <iomanip>
#include <cmath>
using namespace std;

double riemann_sum(double (*f)(double), double lowerLimit, double upperLimit, int pieces);
double f(double x);

int main() {
  double  lowerLimit = 0,
          upperLimit = 0.8;
  double rs, error, realValue = 1.640533;
  int pieces[11] = {1,10,20,30,40,50,60,70,80,90,100};

  printf ("\nNumerical integration by Riemann Sum method\n");

  printf ("\nPieces\tRiemann Sum\tPorcentual error\n");
  for (int i = 0; i < (sizeof(pieces)/sizeof(pieces[0])); i++) {
    rs = riemann_sum(f, lowerLimit, upperLimit, pieces[i]);
    error = fabs(((realValue - rs)/realValue))*100;
    printf ("%d\t%g\t\t%0.4f%%\n",pieces[i],rs,error);
  }
  printf ("\n");

  return 0;
}

double riemann_sum(double (*f)(double), double lowerLimit, double upperLimit, int pieces) {
  double x, sum, middle, deltaX, deltaT;
  sum = 0;
  deltaT = upperLimit - lowerLimit;
  deltaX = deltaT / (pieces);
  x = lowerLimit;

  while (x < upperLimit) {
    middle = (x + (x + deltaX)) / 2.0;
    sum = sum + f(middle)*deltaX;
    x = x + deltaX;
  }
  return sum;
}

// 0.2 + 25x - 200x^2 + 675x^3 - 900 x^4 + 400x^5
double f(double x) {
  return ( (400*pow(x,5)) - (900*pow(x,4)) + (675*pow(x,3))
                          - (200*pow(x,2)) + (25*x) + 0.2 );
}
