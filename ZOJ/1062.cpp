#include <cstdio>

using namespace std;

#define debug 1
int num[20] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 
				742900, 2674440, 9694845, 35357670, 129644790, 477638700};

void find(int n, int &l, int &r)
{
	int i;
	int j;
	int k;
	int v;
	int ln;
	int rn;
	int temp(n);
	int add;
	l = -1;
	r = -1;
		
	for (v=1; ; ++v)
	{
		temp -= num[v];
		if (temp <= 0) break;		
	}
	temp += num[v];
	for (k=0; k<=v-1; ++k)
	{
		temp -= num[k] * num[v-1-k];
		if (temp <= 0) break;
	}
	ln = k;
	rn = v - 1 - k;
	for (i=0; i<ln; ++i) l += num[i];
	for (i=0; i<rn; ++i) r += num[i];
	temp += num[ln] * num[rn];
	l += (temp + num[rn] - 1) / num[rn];
	add = temp % num[rn];
	add = add == 0 ? num[rn] : add;
	r += add;
}

void gao(int n)
{
	int l;
	int r;
	if (n == 0) return;
	if (n == 1)
	{
		printf("X");
		return;
	}
	find(n, l, r);
	if (l > 0)
	{
		printf("(");
		gao(l);
		printf(")");
	}
	printf("X");
	if (r > 0)
	{
		printf("(");
		gao(r);
		printf(")");
	}
}

int main()
{
#if debug
	//freopen("f:\\in.txt", "r", stdin);
	freopen("f:\\out.txt", "w", stdout);
#endif
	int n;
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		gao(n);
		puts("");
		scanf("%d", &n);
	}
	
	return 0;
}