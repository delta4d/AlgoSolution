#include <cstdio>
using namespace std;

const int MAXN = 100;

int x[MAXN];

void merge(int x[], int left, int mid, int right) {
	int i, j, k(0);
	int lp(left), rp(mid+1);
	int *temp = new int[right-left+1];
	while (lp <= mid && rp <= right) {
		if (x[rp] > x[lp]) {
			temp[k] = x[lp];
			++k, ++lp;
		} else {
			temp[k] = x[rp];
			++k, ++rp;
		}
	}
	while (lp <= mid) {
		temp[k] = x[lp];
		++k, ++lp;
	}
	while (rp <= right) {
		temp[k] = x[rp];
		++k, ++rp;
	}
	for (i=left; i<=right; ++i) {
		x[i] = temp[i-left];
	}
	delete []temp;
}

void merge_sort(int x[], int s, int t) {
	int i, j, k;
	int c((s+t)>>1);
	if (s == t) return;
	merge_sort(x, s, c);
	merge_sort(x, c+1, t);
	merge(x, s, c, t);
}

int main() {
	int n;
	int i, j, k;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		for (i=0; i<n; ++i) scanf("%d", x+i);
		merge_sort(x, 0, n-1);
		for (i=0; i<n; ++i) printf("%d ", x[i]);
		puts("");
	}
	return 0;
}