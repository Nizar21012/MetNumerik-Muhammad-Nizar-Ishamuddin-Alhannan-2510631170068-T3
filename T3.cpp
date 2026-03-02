#include <iostream>
using namespace std;

// Fungsi yang dicari akarnya
double f(double x) {
    return x * x * x - 2 * x - 5;   // contoh: f(x) = x^3 - 2x - 5
}

int main() {
    double a = 2.0, b = 3.0;   // interval awal
    double tol = 1e-6;          // toleransi
    int maxIter = 100;           // maksimum iterasi

    // Tampilkan informasi awal
    cout << "Metode Bisection\n";
    cout << "Fungsi: f(x) = x^3 - 2x - 5\n";
    cout << "Interval: [" << a << ", " << b << "]\n";
    cout << "Toleransi: " << tol << "\n\n";

    // Cek syarat interval
    if (f(a) * f(b) >= 0) {
        cout << "Error: f(a) dan f(b) harus berbeda tanda.\n";
        return 1;
    }

    cout << "Iterasi\t\tc\n";   // Header 2 kolom
    cout << "----------------\n";

    int iter = 0;
    double c;

    do {
        c = (a + b) / 2.0;
        double fc = f(c);
        double error = (b - a) / 2.0;

        // Cetak iterasi dan nilai c (2 kolom)
        cout << iter << "\t\t" << c << "\n";

        if (fc == 0.0 || error < tol) break;

        if (f(a) * fc < 0)
            b = c;
        else
            a = c;

        iter++;
    } while (iter < maxIter);

    cout << "----------------\n";
    cout << "Akar hampiran: " << c << "\n";
    cout << "Jumlah iterasi: " << iter << "\n";

    return 0;
}
