#include <iostream>
#include <iomanip> // setprecision
#include <cmath>

#define PRECISION 6

using namespace std;

void tabula(double a, double b);
double f(double x);

int main()
{
   cout << setprecision(PRECISION);
   cout << "\nCalculo de las raices de una funcion aplicando el metodo de la biseccion\n";
   cout << "\nIngrese el intervalo inicial [a,b]:" << endl;

   double a, b, tolerancia;

   cout << "\na = ";
   cin >> a;

   cout << "b = ";
   cin >> b;

   tabula(a, b);

   cout << "\nEscoja el intervalo adecuado" << endl;
   cout << "\na = ";
   cin >> a;

   cout << "b = ";
   cin >> b;

   double xr;

   if (f(a) * f(b) > 0) {
      cout << "\nNo se puede aplicar el metodo de la biseccion\n";
      cout << "porque f(" << a << ") y f(" << b << ") tienen el mismo signo" << endl;

   } else {
      cout << "Tolerancia = ";
      cin >> tolerancia;

      cout << "\na\tb\tx\tf(a)\t\tf(b)\t\tf(x)\n" << endl;
      do {

         xr = (a + b) / 2.0;
         cout << a << "\t" << b << "\t" << xr << "\t" << f(a) << "\t" << f(b) << "\t" << f(xr) << endl;

         if (fabs(f(xr)) <= tolerancia) {
            cout << "\n\nPara una tolerancia de " << tolerancia << " la raiz de f es: " << xr << endl;
            break;

         } else {
            if (f(xr) * f(a) > 0) {
               a = xr;
            } else if (f(xr) * f(b) > 0) {
               b = xr;
            }
         }

      } while (1);
   }

   cin.get();
   cin.get();
   return 0;
}

#define INTERVALOS 10
void tabula(double a, double b)
{
   int puntos = INTERVALOS + 1;

   double ancho = (b - a) / INTERVALOS;

   cout << "\n\tx\tf(x) " << endl;
   for (int i = 0; i < puntos; i++) {
      cout << "\t" << a << "\t" << f(a) << endl;
      a = a + ancho;
   }
}

double f(double x)
{
   return exp(-1 * x) - cos(3 * x) - 0.5;
}
