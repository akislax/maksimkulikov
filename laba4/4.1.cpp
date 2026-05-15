#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

struct Interval {
    double a, b;
};

double f(double x) {
    return (x * x) - cos(x + 0.3);
}

double f1(double x) {
    double a = pow(cos(x + 0.3), 0.5);
    return a;
}

vector<Interval> find(double start, double end, double step) {
    vector<Interval> found;
    for (double x = start; x < end; x += step) {
        if (f(x) * f(x + step) <= 0) f{
            found.push_back({x, x + step});
        }
    }
    return found;
}

double proizvod(double x) {
    double h = pow(10, -7);
    return (f(x + h) - f(x)) / h;
}

double proizvod2(double x) {
    double h = pow(10, -7);
    return (proizvod(x + h) - proizvod(x)) / h;
}

int main() {
    double E = 4 * pow(10, -4);
    vector<Interval> roots = find(-2.0, 1.4, 0.1);

    cout << fixed << setprecision(6);

    for (int i = 0; i < roots.size(); i++) {
        cout << "\n--- РЕЗУЛЬТАТЫ ДЛЯ КОРНЯ " << i + 1 << " ---" << endl;

        cout << "N\ta_n\t\tb_n\t\tb_n - a_n" << endl;
        double a = roots[i].a;
        double b = roots[i].b;
        int n = 0;
        while (abs(b - a) > E) {
            cout << n++ << "\t" << a << "\t" << b << "\t" << abs(b - a) << endl;
            double c = ((a + b) / 2);
            if ((f(a) * f(c)) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
        cout << "По методу половинного деления получаем " << i + 1 << " корень = " << ((a + b) / 2) << endl;

        cout << "\nN\tX_n\t\tX_n+1\t\tX_n+1 - X_n" << endl;
        double a_1 = roots[i].a;
        double x = a_1, x1 = f1(x);
        n = 0;
        while (abs(x1 - x) > E) {
            cout << n++ << "\t" << x << "\t" << x1 << "\t" << abs(x1 - x) << endl;
            x = x1;
            x1 = f1(x);
        }
        cout << "По методу итераций корень " << i + 1 << " = " << x1 << endl;

        
        cout << "\nN\tX_n\t\tX_n+1\t\tX_n+1 - X_n" << endl;
        double a_2 = roots[i].a;
        double x0 = a_2;
        if (f(x0) * proizvod2(x0) <= 0) {
            x0 = roots[i].b;
        }
        double x_2 = (x0 - (f(x0) / proizvod(x0)));
        n = 0;
        while (abs(x_2 - x0) >= E) {
            cout << n++ << "\t" << x0 << "\t" << x_2 << "\t" << abs(x_2 - x0) << endl;
            x0 = x_2;
            x_2 = x0 - (f(x0) / proizvod(x0));
        }
        cout << "Корень по Ньютону: " << x_2 << endl;
    }

    return 0;
}