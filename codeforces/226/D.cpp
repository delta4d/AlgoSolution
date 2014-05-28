#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

double const PI = acos(-1.0);
using triple = tuple <int, int, int>;
vector <triple> light;
double f[1<<20];

int main() {
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	for (int i=0,x,y,a; i<n; ++i) {
		scanf("%d%d%d", &x, &y, &a);
		light.push_back(triple(x, y, a));
	}
	f[0] = l;
	for (int i=1,n2=1<<n; i<n2; ++i) {
		f[i] = l;
		for (int j=0,x,y,a; j<n; ++j) if (i & 1 << j) {
			int ii = i ^ (1 << j);
			tie(x, y, a) = light[j];
			double c = f[ii], a1 = PI * a / 180, a2 = atan(1.0*y/(x-c));
			if (a2 < 0) a2 += PI;
			double a3 = PI - a1 - a2;
			if (a3 <= 0) return printf("%.15lf\n", 1.0*r-l), 0;
			double d = sqrt(1.0*(x-c)*(x-c)+1.0*y*y) * sin(a1) / sin(a3);
			f[i] = max(f[i], c+d);
		}
	}
	printf("%.15lf\n", min(f[(1<<n)-1],1.0*r)-l);
	return 0;
}

// 6582817	 May 10, 2014 5:40:19 PM	delta_4d	 D - Bear and Floodlight	 GNU C++0x	Accepted	 2292 ms	 8200 KB
