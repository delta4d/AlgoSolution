#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-5;
double x[3], y[3], r[3];

inline double sqr(const double x) {
    return x * x;
}

double sigma(double dx, double dy) {
    double ret(0), t[3]={0};
    for (int i=0; i<3; ++i) t[i] = sqrt(sqr(dx-x[i])+sqr(dy-y[i])) / r[i];
    for (int i=0; i<3; ++i) ret += sqr(t[i]-t[i==2?0:i+1]);
    return ret;
}

int main() {
    double dx(0), dy(0);
    double step, xx;
    bool find_one;

    for (int i=0; i<3; ++i) scanf("%lf%lf%lf", x+i, y+i, r+i), dx += x[i], dy += y[i];
    dx /= 3, dy /= 3;
    for (step=1; step>eps; ) {
        xx = sigma(dx, dy);
        if (xx > sigma(dx+step, dy)) dx += step, find_one = true;
        else if (xx > sigma(dx-step, dy)) dx -= step, find_one = true;
        else if (xx > sigma(dx, dy+step)) dy += step, find_one = true;
        else if (xx > sigma(dx, dy-step)) dy -= step, find_one = true;
        if (!find_one) step *= 0.7;
        find_one = false;
    }
    if (xx < eps) printf("%.5lf %.5lf\n", dx, dy);

    return 0;
}

//#		When	Who		Problem		Lang	Verdict		 Time	 Memory
//2885419	 Jan 8, 2013 6:45:55 PM	delta_4d	 C - Commentator problem	 GNU C++	Accepted	 15 ms	 0 KB
