#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;

char s[MAXN];

int main() {
	s[0] = '0';
	scanf("%s", s+1);
	for (int i=strlen(s+1); i>=1; ) {
		for (; i>=0&&s[i]=='0'; --i);
		int j = i;
		for (; j>=0&&s[j]=='1'; --j);
//		printf("%d %d\n", i, j);
		s[i] = '*';
		if (i - j > 1) s[j] = '1';
		i = j;
	}
	int tot = s[0] - '0';
	for (int i=1; s[i]; ++i) tot += s[i] == '*';
	printf("%d\n", tot);

	return 0;
}

// 3266004 	Mar 8, 2013 5:25:47 PM 	delta_4d 	279E - Beautiful Decomposition 	GNU C++ 	Accepted 	31 ms 	1000 KB
