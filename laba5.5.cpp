#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x)
{
    return sin(x) - cos(x);
}

double root(double a, double b, double eps, int level, int& depth)
{
    if (level > depth)
        depth = level;

     cout << "level = " << level << endl;

    double m = (a + b) / 2;

    if (b - a < eps || f(m) == 0)
        return m;

    if (f(a) * f(m) < 0)
        return root(a, m, eps, level + 1, depth);
    else
        return root(m, b, eps, level + 1, depth);
}

int main()
{
    double a, b, eps, x;
    int depth = 0;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "eps = "; cin >> eps;

    x = root(a, b, eps, 1, depth);

    cout << fixed << setprecision(8);

    cout << "x = " << x << endl;
    cout << "f(x) = " << f(x) << endl;
    cout << "depth = " << depth << endl;

    return 0;
}
