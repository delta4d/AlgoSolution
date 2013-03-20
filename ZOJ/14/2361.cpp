#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int MAXN = 1024;
const double INF = 999999999999999.9;
const double PI = acos(-1.0);
const int two[32] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 
16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 
16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
const bool AC = true;

inline double f(double x, double r1, double r2) {
    return sqrt((r1 * r1 - x * x) * (r2 * r2 - x * x));
}

double gao(double a, double b, double(*f)(double x, double y, double z), double eps, double l, double t) {
    const int MAXN = 1000;
    int i, j, temp2, min;
    double h, R[2][MAXN], temp4;
    
    for (i = 0; i < MAXN; i++) {
        R[0][i] = 0.0;
        R[1][i] = 0.0;
    }
    h = b - a;
    min = (int)(log(h * 10.0) / log(2.0)); //h should be at most 0.1
    R[0][0] = ((*f)(a, l, t) + (*f)(b, l, t)) * h * 0.50;
    i = 1;
    temp2 = 1;
    
    while (i < MAXN) {
        i++;
        R[1][0] = 0.0;
        for (j = 1; j <= temp2; j++) {
            R[1][0] += (*f)(a + h *((double)j - 0.50), l, t);
        }
    
        R[1][0] = (R[0][0] + h * R[1][0]) * 0.50;
        temp4 = 4.0;
        
        for (j = 1; j < i; j++) {
            R[1][j] = R[1][j - 1] + (R[1][j - 1] - R[0][j - 1]) / (temp4 - 1.0);
            temp4 *= 4.0;
        }
        
        if ((fabs(R[1][i - 1] - R[0][i - 2]) < eps) && (i > min)) {
            return R[1][i - 1];
        }
      
        h *= 0.50;
        temp2 *= 2;
        for (j = 0; j < i; j++) {
            R[0][j] = R[1][j];
        }
    }
    return R[1][MAXN - 1];
}

int main() {
    double a=0.0, b, eps=1e-4, l, t;
	int tc;
	double r1, r2;
	scanf("%d", &tc);
	while (tc--) {
	    scanf("%lf %lf", &r1, &r2);
	    if (r1 > r2) swap(r1, r2);
        printf("%.20lf\n", 8.0*gao(0, r1, f, eps, r1, r2));
    }   
    return 0;
}
