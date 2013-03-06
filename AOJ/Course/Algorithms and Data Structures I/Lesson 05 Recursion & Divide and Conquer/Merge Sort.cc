#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1000000000 + 10086;
const int MAXN = 500086;

int x[MAXN];
int tot;

void merge(int left, int mid, int right) {
	int n1 = mid - left, n2 = right - mid;
	int L[MAXN], R[MAXN];
	for (int i=0; i<n1; ++i) L[i] = x[left + i];
	for (int i=0; i<n2; ++i) R[i] = x[mid + i];
	L[n1] = INF, R[n2] = INF;
	int i = 0, j = 0;
	tot += right - left;
	for (int k=left; k<right; ++k) {
		if (L[i] <= R[j]) x[k] = L[i], ++i;
		else x[k] = R[j], ++j;
	}
}

void msort(int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) >> 1;
		msort(left, mid);
		msort(mid, right);
		merge(left, mid, right);
	}	
}

int main() {
	int n;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	msort(0, n);
	for (int i=0; i<n; ++i) printf("%d%s", x[i], i==n-1?"\n":" ");
	printf("%d\n", tot);

	return 0;
}
