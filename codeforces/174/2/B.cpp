#include <cstdio>
using namespace std;

const int MAXN = 200000 + 86;

char s[MAXN];

int main() {
	int i = 0, j = 0;
	scanf("%*d%s", s);
	for (int k=0; s[k]; ++k) i += s[k] == 'I';
	for (int k=0; s[k]; ++k) j += s[k] == 'I' && i == 1 || s[k] == 'A' && i == 0;
	printf("%d\n", j);
	return 0;
}

// 3359421	 Mar 20, 2013 9:37:18 AM	delta_4d	 284B - Cows and Poker Game	 GNU C++	Accepted	15 ms	200 KB
