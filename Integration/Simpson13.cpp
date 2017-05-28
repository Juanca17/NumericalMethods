#include <iomanip>
#include <cmath>
using namespace std;

double simpson13(double (*f)(double), double a, double b, int n);
double f(double x);

int main() {
  double  a = 0,
          b = 0.8;
  double s, error, realValue = 1.640533;
  int n[5] = {2,4,6,8,10};

  printf ("\nNumerical integration by Simpson 1/3 Rule method\n");

  printf ("\nn\tSimpson 1/3\tPorcentual error\n");
  for (int i = 0; i < (sizeof(n)/sizeof(n[0])); i++) {
    s = simpson13(f, a, b, n[i]);
    error = fabs(((realValue - s)/realValue))*100;
    printf ("%d\t%g\t\t%0.4f%%\n",n[i],s,error);
  }
  printf ("\n");

  return 0;
}

double simpson13(double (*f)(double), double a, double b, int n) {
  int i;
  double h, sum, integral;
  double x[n+1], y[n+1];
  sum = 0;
  h = (b - a) / n;

  for (i = 0; i < n+1; i++) {
    x[i] = a + i*h;
    y[i] = f(x[i]);
  }
  for (i = 1; i < n; i+=2) {
    sum = sum + 4.0*y[i];
  }
  for (i = 2; i < n-1; i+=2) {
    sum = sum + 2.0*y[i];
  }

  integral = (h/3.0)*(y[0] + y[n] + sum);
  return integral;
}

// 0.2 + 25x - 200x^2 + 675x^3 - 900 x^4 + 400x^5
double f(double x) {
  return ( (400*pow(x,5)) - (900*pow(x,4)) + (675*pow(x,3))
                          - (200*pow(x,2)) + (25*x) + 0.2 );
}
