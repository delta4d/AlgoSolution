#include <cstdio>
#include <memory>
using namespace std;

#define debug 0
const int MaxN = 12;
int tot;
int n;
int k;
int depth;
int s[MaxN];
int cut[MaxN];
int cnt[MaxN];
int buff[MaxN];
bool huaile;

void dfs(int pn, int d, int sum)
{
	int i;
	int j;
	int end;
	if (sum > tot) return;
	if (d > n) return;
	if (sum == tot)
	{
		huaile = false;
		for (end=k-1; end>=0; --end) if (cut[end] > 0) break;
		for (i=0; i<end; ++i) for (j=0; j<cut[i]; ++j) printf("%d+", s[i]);
		for (i=0; i<cut[end]-1; ++i) printf("%d+", s[end]);
		printf("%d\n", s[end]);
		//return;
	}
	for (i=pn; i<k; ++i)
	{
		if (cnt[i] > 0)
		{
			--cnt[i];
			++cut[i];
			dfs(i, d+1, sum+s[i]);
			--cut[i];
			++cnt[i];
		}
	}
}

int main()
{
#if debug
	freopen("f:\\in.txt", "r", stdin);
	freopen("f:\\out.txt", "w", stdout);
#endif
	
	int i;
	int j;
	
	scanf("%d %d", &tot, &n);
	
	while (n != 0 || tot != 0)
	{
		memset(cnt, 0, sizeof(cnt));
		for (i=0; i<n; ++i) scanf("%d", buff+i);
		s[0] = buff[0];
		cnt[0] = 1;
		k = 1;
		for (i=1; i<n; ++i)
		{
			if (buff[i] == s[k-1]) ++cnt[k-1];
			else
			{
				s[k] = buff[i];
				++cnt[k];
				++k;
			}
		}
		huaile = true;
		printf("Sums of %d:\n", tot);
		memset(cut, 0, sizeof(cut));
		dfs(0, 0, 0);
		if (huaile) printf("NONE\n");
		scanf("%d %d", &tot, &n);
	}
	
	return 0;
}
