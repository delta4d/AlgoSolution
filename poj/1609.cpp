#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10001;
int len;

struct node {
	int x;
	int y;
} f[MAXN];
int b[MAXN+1];

inline bool cmp(const node &a, const node &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

inline int gao(const int t) {
	int l(1), r(len), mid;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(b[mid] > t) r = mid - 1;
		else l = mid + 1;
	}
	if(l > len) len = l;
	return l;
}

int main() {
	int i, j, k;
	int n;
	int left, right, mid;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		for (i=0; i<n; ++i) scanf("%d %d", &f[i].x, &f[i].y);
		sort(f, f+n, cmp);
		len = 0;
		b[0] = -INF;
		for (i=0; i<n; ++i) {
			b[gao(f[i].y)] = f[i].y;
		}
		printf("%d\n", len);
		scanf("%d", &n);
	}
	puts("*");
	return 0;
}