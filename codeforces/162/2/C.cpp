#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000000 + 86;

char s[MAXN];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i=0; i<n; ++i) if (s[i] == 'r') printf("%d\n", i + 1);
	for (int i=n-1; i>=0; --i) if (s[i] == 'l') printf("%d\n", i + 1);
	return 0;
}

// 3699054	 May 10, 2013 3:56:00 PM	delta_4d	 A - Escape from Stones	 GNU C++	Accepted	421 ms	
