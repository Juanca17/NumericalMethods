#include <iomanip>
#include <cmath>
using namespace std;

void middle_point(double x0, double y0, double h, double x);
double f(double x, double y);

int main() {
  double  x0 = 0,
          y0 = 2,
          h = 0.5,
          x = 4;

  printf ("\nExtrapolating differential equations by Middle Point method\n");

  middle_point(x0, y0, h, x);

  return 0;
}

void middle_point(double x0, double y0, double h, double x){
  double y1, x1;
  printf("x\ty\n");
  while(x0 <= x){
    printf("%g\t%g\n",x0,y1);
    y1 = y0 + f(x0,y0)*(h/2);
    x1 = x0 + h/2;
    y1 = y0 + f(x1,y1)*h;
    x0 += h;
    y0 = y1;
  }
}

double f(double x, double y) {
  return 4*exp(0.8*x) - 0.5*y;
}
