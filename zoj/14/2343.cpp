#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define debug 0
#define D(x) double(x)
#define IN(x) scanf("%d", &x)
const int MaxN = 1 << 10;
int M;
int N;
int Y;
int remain;
int K[MaxN];
struct dif
{
	int index;
	double value;
}off[MaxN];

int cmp(const void *a, const void *b)
{
	dif *c = (dif *)a;
	dif *d = (dif *)b;
	return c->value < d->value ? -1 : 1;
}

inline void input()
{
	int i;
	int n(0);
	int X;
	IN(N); IN(M); IN(Y);
	for (i=0; i<N; ++i)
	{
		IN(X);
		K[i] = M * (D(X)/D(Y));
		n += K[i];
		off[i].index = i;
		off[i].value = D(2*K[i]+1)/D(M) - 2.0*D(X)/D(Y);
	}
	remain = M - n;
}

inline void solve()
{
	int i;
	qsort(off, N, sizeof(off[0]), cmp);
	for (i=0; i<remain; ++i) ++K[off[i].index];
}

inline void output()
{
	for (int i=0; i<N-1; ++i) printf("%d ", K[i]);
	printf("%d\n", K[N-1]);
}

int main()
{
	int i;
	int tc;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif
	IN(tc);
	for (i=0; i<tc; ++i)
	{
		input();
		solve();
		output();
	}
	
	return 0;
}
