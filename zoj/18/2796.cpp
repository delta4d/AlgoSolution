#include <cstdio>
#include <cstring>
using namespace std;

const int MaxL = 26;
const int MaxN = 500;
char word[MaxN][MaxL];
char buff[MaxL];

inline bool legal(char &c)
{
	if (c <= 'z' && c >= 'a') return true;
	if (c <= 'Z' && c >= 'A') {c = c - 'A' + 'a'; return true;}
	return false;
}

void insert(char *f, int &n)
{
	int i;
	if (strcmp(f, "") == 0) return;
	for (i=0; i<n; ++i) if (strcmp(f, word[i]) == 0) return;
	strcpy(word[n], f);
	++n;
}

void sim(int &x, int &y)
{
	int t;
	int tx(x);
	int ty(y);
	if (tx < ty) tx ^= ty ^= tx ^= ty;
	while (ty != 0)
	{
		t = ty;
		ty = tx % ty;
		tx = t;
	}
	x /= tx;
	y /= tx;
}

void gao()
{
	int i;
	int j;
	int k;
	int len;
	int n(0);
	int cn(0);
	int tot(0);
	char ww[MaxL];
	
	while (scanf("%s", buff) != EOF)
	{
		while (strcmp(buff, "BULLSHIT") != 0)
		{
			k = 0;
			len = strlen(buff);
			for (i=0; i<=len; ++i)
			{
				if (legal(buff[i]) && i < len) ww[k++] = buff[i];
				else
				{
					ww[k] = '\0';
					k = 0;
					insert(ww, cn);	
				}
			}
		
			if (scanf("%s", buff) == EOF) goto done;
		}
		++n;
		tot += cn;
		cn = 0;
	}
done:
	sim(n, tot);
	printf("%d / %d\n", tot, n);
}

int main()
{
	//freopen("f:\\in.txt", "r", stdin);
	gao();
	
	return 0;
}