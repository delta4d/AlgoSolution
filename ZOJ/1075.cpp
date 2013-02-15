#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[81][5];

inline bool input(int &n) {
	if (gets(s[0]) == NULL) return false;
	n = 1;
	while (true) {
		gets(s[n]);
		if (s[n][0] == '\0') return true;
		++n;
	}
}

inline bool form_suc(int a, int b, int c) {
	int i, j, k;
	for (i=0; i<4; ++i) {
		if (s[a][i] == s[b][i] && s[b][i] == s[c][i]) continue;
		if (s[a][i] != s[b][i] && s[b][i] != s[c][i] && s[c][i] != s[a][i]) continue;
		return false;
	}
	return true;
}

int main() {
	int i, j, k, t;
	int m, n;	
	int cn(0), sn;
	bool find_one;
	//freopen("f:\\in.txt", "r", stdin);
	input(n);
	while (true) {
		sn = 0;
		find_one = false;
		printf("CARDS:  ");
		for (i=0; i<n; ++i) printf("%s%s", s[i], i==n-1?"\n":" ");
		for (i=0; i<n; ++i) {
			for (j=i+1; j<n; ++j) {
				for (k=j+1; k<n; ++k) {
					if (form_suc(i, j, k)) {
						find_one = true;
						if (sn == 0) printf("SETS:   %d.  %s %s %s\n", ++sn, s[i], s[j], s[k]);
						else printf("        %d.  %s %s %s\n", ++sn, s[i], s[j], s[k]);
					}
				}
			}
		}
		if (!find_one) puts("SETS:   *** None Found ***");
		if (input(n)) puts("");
		else break;
	}
	return 0;
}