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

  printf ("\nExtrapolating differential equations by Ralston method\n");

  euler(x0, y0, h, x);

  return 0;
}

void euler(double x0, double y0, double h, double x){
  double x1, y1, k1, k2;
  printf("x\ty\n");
  while(x0 <= x){
    printf("%g\t%g\n",x0,y1);
    k1 = f(x0,y0);
    k2 = f(x0+((3/4)*h), y0+((3/4)*k1*h));
    y1 = y0 + (((1/3)*k1) + ((2/3)*k2))*h;
    x0 += h;
    y0 = y1;
  }
}

double f(double x, double y) {
  return 4*exp(0.8*x) - 0.5*y;
}
