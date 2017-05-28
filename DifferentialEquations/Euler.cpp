#include <iomanip>
#include <cmath>
using namespace std;

void euler(double x0, double y0, double h, double x);
double f(double x, double y);

int main() {
  double  x0 = 0,
          y0 = 2,
          h = 0.5,
          x = 4;

  printf ("\nExtrapolating differential equations by Euler method\n");

  euler(x0, y0, h, x);

  return 0;
}

void euler(double x0, double y0, double h, double x){
  double x1, y1;
  printf("x\ty\n");
  while(x0 <= x){
    printf("%g\t%g\n",x0,y0);
    y1 = y0 + f(x0,y0)*h;
    x0 += h;
    y0 = y1;
  }
}

double f(double x, double y) {
  return 4*exp(0.8*x) - 0.5*y;
}
