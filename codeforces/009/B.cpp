#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const int MAXN = 128;

int x[MAXN];

int main() {
	int xu, yu;
	int vb, vs;
	int n;

	scanf("%d%d%d", &n, &vb, &vs);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	scanf("%d%d", &xu, &yu);
	int idx = n - 1;
	double d = hypot(xu-x[n-1], yu), mn = vs * x[n-1] + vb * d;
	
	for (int i=1; i+1<n; ++i) {
		double cd = hypot(xu-x[i], yu), cc = vs * x[i] + vb * cd;
		if (fabs(cc - mn) < eps && cd < d) idx = i, d = cd; 
		else if (cc < mn) mn = cc, idx = i, d = cd;
	}
	printf("%d\n", idx+1);

	return 0;
}

// 3653598	 Apr 30, 2013 11:58:12 AM	delta_4d	 B - Running Student	 GNU C++	Accepted	 15 ms	 0 KB
