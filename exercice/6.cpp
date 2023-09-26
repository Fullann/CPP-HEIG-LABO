#include <iostream>
using namespace std;
int main()
{
    {
        double x;
        int n, p;
        p = 2;
        x = 15 / p;
        n = x + 0.5;
        cout << "a) " << p << ' ' << x << ' ' << n << endl;
    }

    {
        double x;
        int n, p;
        p = 2;
        x = 15. / p;
        n = x + 0.5;
        cout << "b) " << p << ' ' << x << ' ' << n << endl;
    }

    {
        int n, p;
        double x;
        n = 10;
        p = 7;
        x = 2.5;
        cout << "c) " << x + n % p << endl;
        cout << "d) " << x + p / n << endl;
        cout << "e) " << (x + p) / n << endl;
        cout << "f) " << .5 * n << endl;
        cout << "g) " << .5 * (double)n << endl;
        cout << "h) " << (int).5 * n << endl;
        cout << "i) " << (n + 1) / n << endl;
        cout << "j) " << (n + 1.0) / n << endl;
    }
}