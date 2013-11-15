#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
int x[MAXN];

int main() {
	int i, j, k;
	int n;
	int sum, avg, c;
	double t;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		sum = 0;
		for (i=0; i<n; ++i) {
			scanf("%lf", &t);
			x[i] = t * 100 + 0.5;
			sum += x[i];
		}
		avg = sum / n;
		c = 0, k = 0;
		for (i=0; i<n; ++i) if (x[i] > avg) {
			++k;
			c += x[i] - avg;
		}
		if (k >= sum - avg * n) c -= sum - avg * n;
		else c -= k;
		printf("$%.2lf\n", c/100.0);
		scanf("%d", &n);	
	}
	return 0;
}