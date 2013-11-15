#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double INF = 9999999999999.9;
const int MAXN = 100000;

double f[MAXN][5];

int main() {
	int i, j, k;
	int m, n;
	int s[5];
	double low, high, sum;
	double maxdiff;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) for (j=0; j<5; ++j) scanf("%lf", f[i]+j);
		maxdiff = -INF;
		for (s[0]=-1; s[0]<=1; s[0]+=2) {
			for (s[1]=-1; s[1]<=1; s[1]+=2) {
				for (s[2]=-1; s[2]<=1; s[2]+=2) {
					for (s[3]=-1; s[3]<=1; s[3]+=2) {
						for (s[4]=-1; s[4]<=1; s[4]+=2) {
							low = INF, high = -INF;
							for (i=0; i<n; ++i) {
								sum = 0;
								for (k=0; k<5; ++k) sum += f[i][k] * s[k];
								low = min(low, sum), high = max(high, sum);
							}
							maxdiff = max(maxdiff, high-low);
						}
					}
				}
			}
		}
		printf("%.2lf\n", maxdiff);
	}
	return 0;
}