#include<cstdio>
using namespace std;

#define debug 0

const int MaxN = 100001;
int x1[MaxN];
int x2[MaxN];
int y1[MaxN];
int y2[MaxN];
int op[MaxN];
int f[256][256];

int main(void)
{
    int x;
    int y;
    int i;
    int j;
    int k;
    int w;
    int h;
    int n;
    
#if debug    
	freopen("f:\\debug.txt", "r", stdin);
#endif

    while (scanf("%d %d", &w, &h) != EOF)
    {
        for (i=0; i<h; ++i)
        {
            for (j=0; j<w; ++j)
            {
                scanf("%d", &f[i][j]);
            }
        }

        scanf("%d", &n);

        for (i=0; i<n; ++i)
        {
            scanf("%d %d %d %d %d", y1+i, x1+i, y2+i, x2+i, op+i);
        }

        scanf("%d %d", &y, &x);

        for (i=n-1; i>=0; --i)
        {
            if ((x <= x2[i]) && (x >= x1[i]) && (y <= y2[i]) && (y >= y1[i]))
            {
                if (op[i] == 4)
                {
                    y = y1[i] + y2[i] - y;
                }
                else if (op[i] == 5)
                {
                    x = x1[i] + x2[i] - x;
                }
            }
        }

        for (i=0; i<n; ++i)
        {
            if ((x <= x2[i]) && (x >= x1[i]) && (y <= y2[i]) && (y >= y1[i]))
            {
                switch (op[i])
                {
                case 1:
                    f[x][y] = -f[x][y];
                    break;
                case 2:
                    ++f[x][y];
                    break;
                case 3:
                    --f[x][y];
                    break;
                case 4:
                    f[x][y1[i] + y2[i] - y] = f[x][y];
                    y = y1[i] + y2[i] - y;
                    break;
                case 5:
                    f[x1[i] + x2[i] - x][y] = f[x][y];
                    x = x1[i] + x2[i] - x;
                    break;
                }
            }
        }

        printf("%d\n", f[x][y]);
    }
    
#if debug   
	fclose(stdin);
#endif

    return 0;
}
