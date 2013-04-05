#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double a, v, l, d, w, vt;

double gao1(double d, double &vt) {
    double x = v * v / (2 * a);
    if (v <= w) return x > d ? (vt=sqrt(2*a*d),vt/a) : (vt=v,v/a+(d-x)/v);
    if (v*v+2*w*(v-w)+(v-w)*(v-w)>=2*d*a) {
        vt = sqrt(2*a*d);
        if (vt <= w) return vt / a;
        vt = w;
        return (sqrt(2*w*w+4*a*d)-w)/a;
    }
    vt = w;
    return (w*w-2*v*v)/(2*a*v)+(2*v-w)/a+d/v;
}

double gao2(double w, double d) {
    double x = (v * v - w * w) / (2 * a);
    return x > d ? (sqrt(w*w+2*a*d)-w)/a : (v-w)/a+(d-x)/v;
}

int main() {
    scanf("%lf%lf%lf%lf%lf", &a, &v, &l, &d, &w);   
    printf("%.16lf\n", gao1(d, vt)+gao2(vt, l-d));
    return 0;
}

// 2926168	 Jan 15, 2013 10:29:06 AM	delta_4d	 D - Follow Traffic Rules	 GNU C++	Accepted	 15 ms	 0 KB
