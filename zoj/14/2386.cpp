#include <cstdio>
using namespace std;

typedef long long LL;
const int MAXN = 500001;
int f[MAXN];
int temp[MAXN];
LL res;

void merge(int left, int mid, int right) {
	int pl(left);
	int pr(mid+1);
	int k(0);
	while (pl <= mid && pr <= right) {
		if (f[pl] < f[pr]) {
			temp[k] = f[pl];
			++k;
			++pl;
		} else {
			temp[k] = f[pr];
			++k;
			++pr;
			res += mid - pl + 1;
		}
	}
	while (pl <= mid) {
		temp[k] = f[pl];
		++k;
		++pl;
	}
	while (pr <= right) {
		temp[k] = f[pr];
		++k;
		++pr;
	}
	for (int i=0; i<=right-left; ++i) {
		f[i+left] = temp[i];
	}
}

void merge_sort(int left, int right) {
	if (left >= right) return;
	int mid((left + right) >> 1);
	merge_sort(left, mid);
	merge_sort(mid+1, right);
	merge(left, mid, right);
}

int main() {
	int n;
	int i, j;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) scanf("%d", f+i);
		res = 0;
		merge_sort(0, n-1);
		printf("%lld\n", res);
		scanf("%d", &n);
	}
	return 0;
} 
