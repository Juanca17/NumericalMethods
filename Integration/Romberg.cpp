#include <iomanip>
#include <cmath>
using namespace std;

double romberg(double (*f)(double), double a, double b,int n);
double f(double x);


int main() {
  double  a = 0,
          b = 0.8;
  double s, error, realValue = 1.640533;
  int n[4] = {1,2,3,4};

  printf ("\nNumerical integration by Romberg method\n");

  printf ("\nLevel n\tRomberg\tPorcentual error\n");
  for (int i = 0; i < (sizeof(n)/sizeof(n[0])); i++) {
    s = romberg(f, a, b, n[i]);
    error = fabs(((realValue - s)/realValue))*100;
    printf ("%d\t%g\t\t%0.4f%%\n",n[i],s,error);
  }
  printf ("\n");

  return 0;
}

double romberg(double (*f)(double), double a, double b, int n) {
  double h[n+1], r[n+1][n+1];

  for (int i = 1; i < n + 1; ++i) {
    h[i] = (b - a) / pow(2, i - 1);
  }

  r[1][1] = h[1] / 2 * (f(a) + f(b));
  for (int i = 2; i < n + 1; ++i) {
    double coeff = 0;
    for (int k = 1; k <= pow(2, i - 2); ++k) {
      coeff += f(a + (2 * k - 1) * h[i]);
    }
    r[i][1] = 0.5 * (r[i - 1][1] + h[i - 1] * coeff);
  }
  for (int i = 2; i < n + 1; ++i) {
    for (int j = 2; j <= i; ++j) {
      r[i][j] = r[i][j - 1] + (r[i][j - 1] - r[i - 1][j - 1]) / (pow(4, j - 1) - 1);
    }
  }
  return r[n][n];
}

// 0.2 + 25x - 200x^2 + 675x^3 - 900 x^4 + 400x^5
double f(double x) {
  return ( (400*pow(x,5)) - (900*pow(x,4)) + (675*pow(x,3))
                          - (200*pow(x,2)) + (25*x) + 0.2 );
}
