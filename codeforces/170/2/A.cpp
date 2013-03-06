#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 128;

int d[MAXN];

int main() {
	int n;
	int s, t;
	int t1(0), t2(0);

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", d+i), t2 += d[i];
	scanf("%d%d", &s, &t);
	--s, --t;
	if (s > t) swap(s, t);
	for (int i=s; i<t; ++i) t1 += d[i];
	printf("%d\n", min(t1, t2-t1));

	return 0;
}
