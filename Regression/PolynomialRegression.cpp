#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

void polynomial_regression(vector<double> &x, vector<double> &y, int &degree);

int main() {
  vector<double> x, y;
  ifstream fileX, fileY;
  fileX.open("github/numericalmethods/regression/x.txt"); // address_of_file/x.txt
  fileY.open("github/numericalmethods/regression/y.txt"); // address_of_file/y.txt
  if (fileX.is_open() & fileY.is_open()) {
    while (fileX.good() && fileY.good()) {
      x.push_back(0);
      fileX >> x[x.size() - 1];
      y.push_back(0);
      fileY >> y[y.size() - 1];
    }
    fileX.close();
    fileY.close();
  }
  else {
    printf("\n\nThere was a problem with the file\n\n");
    return 0;
  }
  int degree = 2;

  printf("\nLeast squares fitting by Polynomial Regression method\n");
  polynomial_regression(x, y, degree);

  return 0;
}

void polynomial_regression(vector<double> &x, vector<double> &y, int &degree) {
  int i,j,h,n;
  double sigmaX[2*degree+1];
  double sigmaY[degree+1];
  n = x.size();

  // Store the values of sigma(xi),sigma(xi^2),sigma(xi^3)....sigma(xi^2n)
  for (i = 0; i < 2*degree+1; i++) {
    sigmaX[i] = 0;
    for (j = 0; j < n; j++) {
      sigmaX[i] = sigmaX[i]+pow(x[j],i);
    }
  }

   // Store the values of sigma(yi),sigma(xi*yi),sigma(xi^2*yi)...sigma(xi^degree*yi)
  for (i = 0; i < degree+1; i++) {
    sigmaY[i] = 0;
    for (j = 0; j < n; j++) {
      sigmaY[i] = sigmaY[i]+pow(x[j],i)*y[j];
    }
  }

  // Create system of equations according to the polynomial regression
  double B[degree+1][degree+2],a[degree+1];
  for (i = 0; i <= degree; i++) {
    for (j = 0; j <= degree; j++) {
      B[i][j] = sigmaX[i+j];
    }
  }
  for (i = 0; i <= degree; i++) {
    B[i][degree+1] = sigmaY[i];
  }

  // Solve system of equation
  degree = degree+1;
  printf("\nSystem of equations for solve:\n");
  for (i = 0; i < degree; i++) {
    for (j = 0; j <= degree; j++) {
      printf("%g\t\t",B[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < degree-1; i++) {
    for (h = i+1; h < degree; h++) {
      double t = B[h][i]/B[i][i];
      for (j = 0; j <= degree;j++) {
        B[h][j] = B[h][j]-t*B[i][j];
      }
    }
  }
  for (i = degree-1; i >= 0; i--) {
    a[i] = B[i][degree];
    for (j = 0; j < degree; j++) {
      if (j != i) {
          a[i] = a[i]-B[i][j]*a[j];
      }
    }
    a[i] = a[i]/B[i][i];
  }

  printf("\nPolynomial function:\ny = ");
  for (i = 0; i < degree; i++) {
    printf(" + %gx^%u",a[i],i);
  }
  printf("\n");
}
