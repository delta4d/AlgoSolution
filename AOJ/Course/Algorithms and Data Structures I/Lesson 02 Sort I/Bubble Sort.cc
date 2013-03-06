#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 128;

int A[MAXN];

int main() {
	int i, j, k;
	int n;

	for (scanf("%d", &n), i=0; i<n; scanf("%d", A+i), ++i);
	for (k=i=0; i<n; ++i) {
		for (j=n-1; j>=i+1; --j) {
			if (A[j] < A[j-1]) {
				swap(A[j], A[j-1]);
				++k;
			}
		}
	}
	for (i=0; i<n; ++i) printf("%d%s", A[i], i==n-1?"\n":" ");
	printf("%d\n", k);

	return 0;
}
