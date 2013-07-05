#include<cstdio>
#include<memory>

using namespace std;

#define debug 0
const int MaxL = 150;
const int MaxN = 26;
char out[MaxN];
char s[MaxL];
bool find;

struct node
{
	int x[3];
	int y[3];
	int num;
}f[MaxN];

bool judge(int x[], int y[])
{
	int i;
	int t;
	int d[3];
	
	for (i=0; i<3; ++i)
	{
		t = i == 2 ? 0 : i + 1;
		d[i] = 3 * (x[i] - x[t]) * (x[i] - x[t]) + (y[i] - y[t]) * (y[i] - y[t]);
	}
	
	return (d[0] == d[1]) && (d[1] == d[2]);
}

int main(void)
{
	int n;
	int i;
	int j;
	int k;
	int x;
	int y;
	int t;
	int p;
	int len;

#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif	
	scanf("%d", &n);
	
	while (n != 0)
	{
		scanf("%s", s);
		k = 0;
		memset(f, 0, sizeof(f));
		
		for (i=1; i<=n; ++i)
		{
			for (j=n+1-i; j<=n+i-1; j+=2)
			{
				t = s[k] - 'a';
				++k;
				p = f[t].num;
				f[t].x[p] = i;
				f[t].y[p] = j;
				++f[t].num; 
			}
		}
		
		find = false;
	 	k = 0;
		for (i=0; i<MaxN; ++i)
		{
			if ((f[i].num == 3) && judge(f[i].x, f[i].y))
			{
				find = true;
				out[k] = i + 'a';
				++k;
			}
		}
		
		if (find)
		{
			out[k] = '\0';
			printf("%s\n", out);
		}
		else
		{
			printf("LOOOOOOOOSER!\n");
		}
		
		scanf("%d", &n);
	}
	
	return 0;
}