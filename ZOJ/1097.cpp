#include <cstdio>
#include <vector>
#include <memory>
using namespace std;

#define debug 1
const int INF = 0x7fffffff;
const int MaxN = 51;
const int MaxL = 256;
char msg[MaxL];
char buff[10];
bool T[MaxN][MaxN];
int d[MaxN];

inline int to_int(int n)
{
	int res(0);
	for (int i=n-1; i>=0; --i) res = res * 10 + buff[i] - '0';
	return res;
}

void gao()
{
	int i;
	int j;
	int k;
	int n(1);
	int cc;
	int pp;
	int index;
	int len(strlen(msg));
	vector<char>f;
	vector<char>::iterator it;
	memset(T, false, sizeof(T));
	memset(d, 0, sizeof(d));
	for (i=0; i<len; ++i)
	{
		if (msg[i] == ' ') continue;
		if (msg[i] != ')')
		{
			f.push_back(msg[i]);
			continue;
		}
		k = 0;
		while (*(f.end()-1) != '(')
		{
			buff[k] = *(f.end() - 1);
			f.pop_back();
			++k;
		}
		cc = to_int(k);
		f.pop_back();
		if (f.empty()) break;
		it = f.end() - 1;
		k = 0;
		while (*it != '(')
		{
			buff[k] = *it;
			++k;
			--it;
		}
		pp = to_int(k);
		T[cc][pp] = T[pp][cc] = true;
		++d[cc];
		++d[pp];
		n = n < cc ? cc : n;
		n = n < pp ? pp : n;
	}
	for (k=1; k<=n-1; ++k)
	{
		index = INF;
		for (i=1; i<=n; ++i)
		{
			if (d[i] == 1 && i < index) index = i;
		}
		for (i=1; i<=n; ++i)
		{
			if (T[index][i])
			{
				printf("%d", i);
				T[index][i] = T[i][index] = false;
				--d[index];
				--d[i];
				break;
			}
		}
		if (k < n - 1) printf(" ");
		else printf("\n");
	}
	if (n == 1) printf("\n");
}

int main()
{
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif	
	
	while (gets(msg)) gao();
	
	return 0;
}