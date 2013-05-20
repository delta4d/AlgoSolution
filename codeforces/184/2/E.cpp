#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 86;

char s[MAXN];
int sg[MAXN], p[MAXN], sz;
int a[MAXN], b[MAXN], c;

void init() {
	sg[0] = 0;	
	for (int i=1; i<MAXN; ++i) {
		bool v[10]={false};
		for (int j=0; j+j+3<=i; ++j) v[sg[j] ^ sg[i-3-j]] = true;
		v[sg[max(0, i-2)]] = true;
		for (int j=0; ; ++j) if (!v[j]) { sg[i] = j; break; }
	}
}

int main() {
	init();

	scanf("%s", s);
	for (int i=1; s[i]; ++i) if (s[i-1] == s[i+1]) p[sz++] = i;	
	int t = 0, st = 0, cc = 1;
	for (int i=0; i<sz; ++i) {
		if (p[i] + 1 == p[i+1]) ++cc;
		else t ^= sg[cc], a[c] = p[st] + 1, b[c++] = cc, cc = 1, st = i + 1;
	}
	if (!t) return puts("Second"), 0;
	puts("First");
	for (int i=0; i<c; ++i) {
		cc = sg[b[i]] ^ t;
		if (sg[max(b[i]-2, 0)] == cc) return printf("%d\n", a[i]), 0;	
		for (int j=0; j+j+3<=b[i]; ++j) if ((sg[j] ^ sg[b[i]-3-j]) == cc) return printf("%d\n", a[i]+j+1), 0;
	}

	return 0;
}

// 3748641	 May 20, 2013 11:26:20 AM	delta_4d	 E - Playing with String	 GNU C++	Accepted	15 ms	64 KB
