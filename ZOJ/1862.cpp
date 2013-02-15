#include <cstdio>
#include <memory>
using namespace std;

#define debug 0
const int MaxN = 20;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
char map[MaxN][MaxN];
char done[MaxN][MaxN];
char mine[MaxN][MaxN];
bool huaile;

int main()
{
    int i;
    int j;
    int k;
    int n;
#if debug
    freopen("f:\\in.txt", "r", stdin);
    freopen("f:\\out.txt", "w", stdout);
#endif
	scanf("%d", &n);
    while (1)
    {
    	memset(map, '\0', sizeof(map));
        for (i=1; i<=n; ++i) scanf("%s", map[i]+1);
        for (i=1; i<=n; ++i) scanf("%s", done[i]+1);
        memset(mine, '0', sizeof(mine));
        huaile = false;
        for (i=1; i<=n; ++i)
        {
            for (j=1; j<=n; ++j)
            {
                if (done[i][j] == 'x' && map[i][j] == '*')
                {
                    huaile = true;
                }
                if (map[i][j] == '.')
                for (k=0; k<8; ++k)
                {
                	if (map[i+dx[k]][j+dy[k]] == '*') mine[i][j] += 1;
				}
            }
        }
        for (i=1; i<=n; ++i)
        {
            for (j=1; j<=n; ++j)
            {
                if (done[i][j] == '.')
                {
                	mine[i][j] = '.';
				}
            }
        }
        if (huaile)
        for (i=1; i<=n; ++i)
        {
        	for (j=1; j<=n; ++j)
        	{
        		if (map[i][j] == '*') mine[i][j] = '*';
			}
		}

        for (i=1; i<=n; ++i)
        {
            for (j=1; j<=n; ++j) printf("%c", mine[i][j]);
            printf("\n");
        }
        if (scanf("%d", &n) != EOF) printf("\n");
        else break;
    }

    return 0;
}
