#include <cstdio>
#include <memory>
#include <cstring>
#include <cstdlib>
using namespace std;

#define debug 1
const int MaxN = 32;
const int INF = 10086;
bool conn[MaxN][MaxN];
bool tt[MaxN];
int set[MaxN];
int n;
char buff[MaxN];

void gao()
{
	int i;
	int j;
	int index;
	int max(0);
	memset(set, 0, sizeof(set));
	for (i=0; i<n; ++i)
	{
		memset(tt, false, sizeof(tt));
		for (j=0; j<i; ++j) if (conn[i][j]) tt[set[j]] = true;
		for (index=1; ; ++index) if (!tt[index]) break;
		set[i] = index;
		if (max < index) max = index;
	}
	if (max == 1) printf("1 channel needed.\n");
	else printf("%d channels needed.\n", max);
}

int main()
{
	int i;
	int j;
	int len;
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif	
	scanf("%d", &n);
	while (n != 0)
	{
		memset(conn, false, sizeof(conn));
		for (i=0; i<n; ++i)
		{
			scanf("%s", buff);
			len = strlen(buff);
			for (j=2; j<len; ++j)
			{
				conn[buff[0]-'A'][buff[j]-'A'] = true;
			}
		}
		
		gao();
		
		scanf("%d", &n);
	}
	
	return 0;
}