#include <iostream>
using namespace std;

double f(double x) {
    return x * x * x - 2 * x - 5;
}

void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Interval tidak valid (f(a) dan f(b) harus berbeda tanda)" << endl;
        return;
    }

    double c;
    int iter = 0;

    cout.precision(8);
    cout.setf(ios::fixed, ios::floatfield);

    cout.width(5);  cout << "Iter";
    cout.width(15); cout << "a";
    cout.width(15); cout << "b";
    cout.width(15); cout << "c";
    cout.width(15); cout << "f(c)";
    cout.width(15); cout << "Error" << endl;

    for (int i = 0; i < 80; i++) cout << "-";
    cout << endl;

    do {
        c = (a + b) / 2;
        double fc = f(c);
        double error = (b - a) / 2;

        cout.width(5);  cout << iter;
        cout.width(15); cout << a;
        cout.width(15); cout << b;
        cout.width(15); cout << c;
        cout.width(15); cout << fc;

        cout.unsetf(ios::fixed);
        cout.setf(ios::scientific, ios::floatfield);
        cout.precision(2);
        cout.width(15); cout << error << endl;

        cout.unsetf(ios::scientific);
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(8);

        if (fc == 0 || error < tol) break;

        if (f(a) * fc < 0)
            b = c;
        else
            a = c;

        iter++;
    } while (iter < 100);

    cout << "\nAkar hampiran = " << c << endl;
}

int main() {
    double a = 2.0, b = 3.0;
    double tol = 1e-6;

    cout << "Mencari akar f(x) = x^3 - 2x - 5 pada interval [" << a << ", " << b << "]" << endl;
    cout << "Toleransi = " << tol << "\n\n";
    bisection(a, b, tol);

    return 0;
}
