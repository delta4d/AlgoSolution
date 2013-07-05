#include <cstdio>
#include <cstring>
using namespace std;

inline int power(const int k, const int p) {
	int i, j;
	int res(1);
	for (i=0; i<p; ++i) res *= k;
	return res;
}

int main() {
	int n, sum, p;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		scanf("%d", &p);
		for (i=0; i<n; ++i) {
			scanf("%d", &k);
			j = power(k, p);
			//sum += j > 0 ? j : 0;
			if (p % 2 == 0) {
				sum += j;
			} else {
				if (k > 0) {
					sum += j;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}