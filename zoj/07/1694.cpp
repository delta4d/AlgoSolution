#include <cstdio>
#include <memory>
using namespace std;

#define debug 0
const int INF = 0x7fffffff;
const int MaxL = 128;
char given[MaxL];
int f[MaxL];
int num[MaxL];
int out[MaxL];
int target;
int cnt;
int MAX;
int len;
int ol;
int L;

void dfs(int p, int sum, int cur)
{
	int i;
	int j;
	if (sum > target) return;
	if (p == len)
	{
		if (sum == MAX) ++cnt;
		else if (sum > MAX)
		{
			MAX = sum;
			ol = L;
			for (i=0; i<ol; ++i) out[i] = f[i];
			cnt = 1;
		}
		return;
	}
	f[L++] = cur * 10 + num[p];
	dfs(p+1, sum+f[L-1], 0);
	--L;
	if (p < len - 1)
	dfs(p+1, sum, cur*10+num[p]);
}

int main()
{
	int i;
	int j;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif	
	scanf("%d %s", &target, given);
	
	while (target != 0 || given[0] != '0')
	{
		len = strlen(given);
		for (i=0; i<len; ++i) num[i] = given[i] - '0';
		cnt = 0;
		MAX = -INF;
		L = 0;
    	dfs(0, 0, 0);
    	if (cnt == 0) printf("error\n");
    	else if (cnt > 1) printf("rejected\n");
    	else
    	{
    		printf("%d ", MAX);
    		for (i=0; i<ol-1; ++i) printf("%d ", out[i]);
    		printf("%d\n", out[ol-1]);
		}
		scanf("%d %s", &target, given);
	}
	
	return 0;
}
