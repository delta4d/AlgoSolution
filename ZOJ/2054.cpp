#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 10000;
struct interval
{
	int start;
	int end;
}I[MaxN];

bool binary_search(int x, int N, int& L)
{
	int p;
	int q;
	int i;

	p = 0;   /* Left border of the search  */
  	q = N-1; /* Right border of the search */
  	L = 0;   /* Comparison counter         */
  	while (p <= q)
  	{
    	i = (p + q) / 2;
    	++L;
    	if (i == x)
      		return true;
    	if (x < i)
      		q = i - 1;
    	else
      		p = i + 1;
  	}
  	return false;
}

int main()
{
	int i;
	int j;
	int x;
	int L;
	int tc;
	int pre;
	int cur;
	int p;
	int rep;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (i=0; i<tc; ++i)
	{
		p = 1;
		pre = -1;
		scanf("%d %d", &x, &L);
		for (j=1; j<=MaxN; ++j)
		{
			if (binary_search(x, j, rep) && rep == L)
			{
				cur = j;
				if (cur != pre + 1)
				{
					I[p-1].end = pre;
					I[p].start = cur;
					++p;
				}
				pre = cur;
			}
		}
		I[p-1].end = pre;
		printf("%d\n", p-1);
		for (j=1; j<p; ++j)
		{
			printf("%d %d\n", I[j].start, I[j].end);
		}
		if (i < tc - 1) printf("\n");
	}
	
	return 0;
}