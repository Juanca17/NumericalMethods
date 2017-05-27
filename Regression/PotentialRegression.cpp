#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

void potential_regression(vector<double> &x, vector<double> &y);

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

  printf("\nLeast squares fitting by Potential Regression method\n");
  potential_regression(x, y);

  return 0;
}

void potential_regression(vector<double> &x, vector<double> &y) {
  int n;
  double a1, a0, sumx, sumy, sumlogx, sumlogy, sumlogxlogy, sumlogxsq, sr, syx, st, r;
  n = x.size();
  sumx=sumy=sumlogx=sumlogy=sumlogxlogy=sumlogxsq=sr=st=0;

  for (int i = 0; i < n; i++) {
    sumx += x[i];
    sumy += y[i];
    sumlogx += log10(x[i]);
    sumlogy += log10(y[i]);
    sumlogxlogy += log10(x[i]) * log10(y[i]);
    sumlogxsq += pow(log10(x[i]), 2);
  }
  a1 = (n*sumlogxlogy - sumlogx*sumlogy) / (n*sumlogxsq - pow(sumlogx, 2));
  a0 = (sumlogy/n) - a1*(sumlogx/n);
  printf("\nPotential function:\ny = %gx^(%g)\n\n",pow(10, a0),a1);

  for (int i = 0; i < n; i++) {
    sr += pow(y[i] - pow(10, a0) * pow(x[i], a1), 2);
    st += pow(y[i] - (sumy/n), 2);
  }

  syx = sqrt(sr / (n-2));
  printf("Standard error of the estimate: Sy/x = %g\n\n",syx);

  r = sqrt((st - sr) / st);
  printf("Correlation coefficient: r = %g\n\n",r);
  printf("Determination coefficient: r^2 = %g\n\n",pow(r, 2));
}
