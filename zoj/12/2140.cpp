#include <cstdio>
#include <memory>
#include <cstdlib>
using namespace std;

const int MAXN = 101;
struct node {
	int index;
	int degree;
}a[MAXN];
bool f[MAXN][MAXN];

int cmp(const void *a, const void *b) {
	node *c = (node *)a;
	node *d = (node *)b;
	return d->degree - c->degree;
}

int main() {
	int i, j, k;
	int n;
	int ss;
	bool ff;
	//freopen("f:\\debug\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (1) {
		ff = true;
		ss = 0;
		for (i=0; i<n; ++i) {
			scanf("%d", &a[i].degree);
			a[i].index = i;
			ss += a[i].degree;
			if (a[i].degree >= n) ff = false;
		}
		if (ss % 2 == 1) ff = false;
		if (!ff) {
			puts("~><~");
			goto next;
		}
		qsort(a, n, sizeof(a[0]), cmp);
		memset(f, false, sizeof(f));
		for (i=0; i<n; ++i) {
			for (j=i+1; j<=a[i].degree+i; ++j) {
				--a[j].degree;
				if (a[j].degree < 0) {
					ff = false;
					goto decided;
				}
				f[a[i].index][a[j].index] = f[a[j].index][a[i].index] = true;
			}
			qsort(a+i+1, n-i-1, sizeof(a[0]), cmp);
		}
	decided:
		if (!ff) {
			puts("~><~");
			goto next;
		}
		for (i=0; i<n; ++i) {
			printf("%d", f[i][0]?1:0);
			for (j=1; j<n; ++j) {
				printf(" %d", f[i][j]?1:0);
			}
			puts("");
		}
	next:
		scanf("%d", &n);
		if (n == 0) break;
		puts("");
	}
	return 0;
}
