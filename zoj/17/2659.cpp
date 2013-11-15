#include<cstdio>
#include<cstdlib>
using namespace std;

struct rec
{
	int x;
	int y;
}f[6];

int cmp(const void *a, const void *b)
{
	rec *c = (rec *)a;
	rec *d = (rec *)b;
	
	if (c -> x != d -> x)
	{
		return c -> x - d -> x;
	}
	
	return c -> y - d -> y;
}

bool equal(rec &a, rec &b)
{
	return (a.x == b.x) && (a.y == b.y);
}

void solve()
{
	if (equal(f[0], f[1]) && equal(f[2], f[3]) && equal(f[4], f[5]) &&
        (f[1].x == f[3].x) && (f[1].y == f[5].x) && (f[3].y == f[5].y))
 	{
 		printf("POSSIBLE\n");
 		return;
    }
    
    printf("IMPOSSIBLE\n");
    return;
}

int main(void)
{
	int i;
	int t;
	
	while (scanf("%d %d", &f[0].x, &f[0].y) != EOF)
	{
		for (i=1; i<6; ++i)
		{
			scanf("%d %d", &f[i].x, &f[i].y);
		}
		
		for (i=0; i<6; ++i)
		{
			if (f[i].x > f[i].y)
			{
				t = f[i].x;
				f[i].x = f[i].y;
				f[i].y = t;
			}
		}
		
		qsort(f, 6, sizeof(f[0]), cmp);
		
		solve();
	}
	
	return 0;
}
