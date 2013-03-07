#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const long double eps = 1e-7;
const long double PI = acos(-1.0);
long double H, D, V, R, V0;

long double f(long double x) {
	if (x > R) return V0 - f(D - x);
	long double a = R - x, alpha = acos(a / R);
	long double t = sqrt(R * R - a * a);
	long double ret =  R * R * H * alpha / 6.0 - H / 2.0 * a * t + 
	H * a * t / 6.0 + (fabs(a) < eps ? 0 : H * a * a * a / R / 6.0 * log(a / (R - t)));
	return 2 * ret;
}

int main() {
	int i, j, k;
	int tc;
	long double left, right, mid, res;
	
	freopen("in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%Lf %Lf %Lf", &H, &D, &V);
		R = D / 2.0;
		V0 = PI * R * R * H / 3.0;
		
		//printf("%.5Lf\n", f(10));
		k = 100;
		left = 0, right = D;
		while (k--) {
			mid = (left + right) / 2.0;
			//printf("%.5Lf\n", res=f(mid));
			if (f(mid) < V) left = mid;
			else right = mid;
		}
		printf("%.5Lf\n", D-left);
	}
	
	return 0;
}