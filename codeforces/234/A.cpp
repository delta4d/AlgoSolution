#include <cstdio>

char s[13];
int x[13], p;

bool ok(int a, int b) {
	for (int j=0; j<b; ++j) {
		bool same = true;
		for (int i=0; same&&i<a; ++i) if (s[i*b+j] != 'X') same = false;
		if (same) return true;
	}
	return false;
}

int main() {
	int tc;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", s);
		p = 0;
		for (int a=1; a<=12; ++a) if (12 % a == 0) if (ok(a, 12/a)) x[p++] = a;
		printf("%d", p);
		for (int i=0; i<p; ++i) printf(" %dx%d", x[i], 12/x[i]);
		puts("");
	}
	return 0;
}

// 6561468	 May 6, 2014 1:52:24 PM	delta_4d	 A - Inna and Choose Options	 GNU C++0x	Accepted	 31 ms	 0 KB
