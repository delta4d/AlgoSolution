#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

#define M_PI 3.141593

const int MAXN = 1000;

double la[MAXN], lg[MAXN];
double x[MAXN], y[MAXN], z[MAXN];

int main() {
	int i, j, k;
	int n;
	double mincos, bestcos, d;
	int besti;
//	printf("%lf\n", M_PI);
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) == 1) {
		for (i=0; i<n; ++i) {
			scanf("%lf %lf", la+i, lg+i);
			z[i] = sin(la[i]*M_PI/180);
      		x[i] = cos(lg[i]*M_PI/180) * cos(la[i]*M_PI/180);
      		y[i] = sin(lg[i]*M_PI/180) * cos(la[i]*M_PI/180);
		}
		bestcos = -1.0;
		for (i=0; i<n; ++i) {
			d = 1;
			for (j=0; j<n; ++j) {
				d = min(d, x[i] * x[j] + y[i] * y[j] + z[i] * z[j]);
			}
			if (d > bestcos) {
				bestcos = d;
				besti = i;
			}
		}
		printf("%.2lf %.2lf\n", la[besti], lg[besti]);
	}
	return 0;
}