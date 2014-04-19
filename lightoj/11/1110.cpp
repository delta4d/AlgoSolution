#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 111;

char s1[N], s2[N], s[N];
string f[N][N];

char * gao() {
	int l1 = strlen(s1+1), l2 = strlen(s2+1);
	for(int i=1; i<=l1; ++i) for (int j=1; j<=l2; ++j) {
		f[i][j].clear();
		if (s1[i] == s2[j]) {
			f[i][j] = f[i-1][j-1] + s1[i];
		} else {
			if (f[i-1][j].length() > f[i][j-1].length()) {
				f[i][j] = f[i-1][j];
			} else if (f[i-1][j].length() < f[i][j-1].length()) {
				f[i][j] = f[i][j-1];
			} else {
				f[i][j] = f[i-1][j] < f[i][j-1] ? f[i-1][j] : f[i][j-1];
			}
		}
	}
	if (f[l1][l2].length() == 0) puts(":(");
	else puts(f[l1][l2].c_str());
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s%s", s1+1, s2+1);
		printf("Case %d: ", ++cn);
		gao();
	}
	return 0;
}

// 294095	2013-12-01 21:14:08	 1110 - An Easy LCS	 C++	 0.040	 1344	Accepted
