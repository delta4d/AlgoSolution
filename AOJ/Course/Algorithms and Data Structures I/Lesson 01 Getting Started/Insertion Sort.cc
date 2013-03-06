#include <cstdio>
using namespace std;

const int MAXN = 128;

int A[MAXN];

int main() {
	int i, j, k;
	int n;

	for (scanf("%d", &n),i=0; i<n; scanf("%d", A+i),++i);
	for (j=1; j<n; ++j) {
		for (i=0; i<n; ++i) printf("%d%s", A[i], i==n-1?"\n":" ");
		k = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > k) {
			A[i+1] = A[i];
			--i;
		}
		A[i+1] = k;
	}
	for (i=0; i<n; ++i) printf("%d%s", A[i], i==n-1?"\n":" ");

	return 0;
}
