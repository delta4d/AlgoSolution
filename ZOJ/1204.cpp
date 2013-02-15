#include <cstdio>
#include <memory>
#include <cstdlib>
using namespace std;

#define debug 0
const int MaxN = 32;
int n;
int depth;
int s[MaxN];
int in[MaxN];
bool visit[MaxN];
bool huaile;

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

inline bool suc(int sum)
{
	int i;
	for (i=0; i<n; ++i) if (s[i] == sum) return true;
	return false;
}

void dfs(int d, int sum)
{
	int i;
	int j;
	int k;
	
	if (sum > s[n-1]) return;
	if (d > depth) return;
	if (d == depth && suc(sum))
	{
		huaile = false;
		for (i=0; i<d-1; ++i) printf("%d+", in[i]);
		printf("%d=%d\n", in[d-1], sum);
		return;
	}
	for (i=0; i<n; ++i)
	{
		if (!visit[i] && (s[i] > in[d-1] || d == 0))
		{
			visit[i] = true;
			in[d] = s[i];
			dfs(d+1, sum+s[i]);
			visit[i] = false;
		}
	}
}

int main()
{
    int tc;
    int k;
    int i;
#if debug
    freopen("f:\\in.txt", "r", stdin);
#endif
    scanf("%d", &tc);

    for (k=0; k<tc; ++k)
    {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%d", s+i);
		qsort(s, n, sizeof(s[0]), cmp);
		memset(visit, false, sizeof(visit));
		huaile = true;
		for (depth=2; depth<n; ++depth)	dfs(0, 0);
		if (huaile) printf("Can't find any equations.\n");
		printf("\n");
    }

    return 0;
}
