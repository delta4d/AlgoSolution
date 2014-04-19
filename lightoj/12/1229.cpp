#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 201;

int sg[N];
char s[N];

void init() {
	sg[1] = sg[2] = 1;
	for (int i=3; i<N; ++i) {
		bool v[N] = {false};
		v[sg[i-3]] = true;
		if (i > 3) v[sg[i-4]] = true;
		for (int j=2; j+j<=i; ++j) v[sg[j-2] ^ sg[i-j-3]] = true;
		for (int j=0; ; ++j) if (!v[j]) { sg[i] = j; break; }
	}
}

inline bool oneline(int p, int len) {
	if (p >= 1 && p + 1 < len && s[p-1] == 'X' && s[p+1] == 'X') return true;
	if (p + 2 < len && s[p+1] == 'X' && s[p+2] == 'X') return true;
	if (p >= 2 && s[p-2] == 'X' && s[p-1] == 'X') return true;
	return false;
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", s);
		int p[N+10]={-3}, c = 1, t = 0, len = strlen(s);
		for (int i=0; ; ++i) {
			if (s[i] == 'X') {
				p[c++] = i;
			} else if (!s[i]) {
				p[c++] = i + 2;
				break;
			}
		}
		for (int i=0; i+1<c; ++i) t ^= sg[max(p[i+1]-p[i]-5, 0)];
		int out[N], cc = 0;
		for (int i=0; i+1<c; ++i) for (int j=p[i]+1; j<p[i+1]; ++j) if (0 <= j && j < len) {
			if (oneline(j, len)) out[cc++] = j + 1;
		}
		if (!cc) for (int i=0; i+1<c; ++i) for (int j=p[i]+3; j+2<p[i+1]; ++j) if (0 <= j && j < len) {
			int ct = t ^ sg[max(p[i+1]-p[i]-5, 0)];
			if ((ct ^ sg[max(j-p[i]-5, 0)] ^ sg[max(p[i+1]-j-5, 0)]) == 0) out[cc++] = j + 1;
		}
		printf("Case %d: ", ++cn);
		if (cc) for (int i=0; i<cc; ++i) printf("%d%s", out[i], i==cc-1?"\n":" ");
		else puts("0");
	}
	return 0;
}

// 258287	2013-09-01 14:38:15	 1229 - Treblecross	 C++	 0.000	 1088	Accepted
