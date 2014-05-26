#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int const N = 5e3 + 10;

char s1[N], s2[N];
int f11[N][N], f22[N][N], f12[N][N];
int mx1[N], mx2[N];

void pre(char s1[], int l1, char s2[], int l2, int f[][N]) {
	for (int i=l1-1; i>=0; --i) for (int j=l2-1; j>=0; --j) {
		if (s1[i] == s2[j]) f[i][j] = f[i+1][j+1] + 1;
	}
}

void mx(int f[][N], int l, int m[]) {
	for (int i=0; i<l; ++i) for (int j=0; j<l; ++j) {
		if (j != i) m[i] = max(m[i], f[i][j]);
	}
}

int mn(int l1, int l2) {
	int ret = l1 + l2;
	for (int i=0; i<l1; ++i) for (int j=0; j<l2; ++j) {
		if (mx1[i] < f12[i][j] && mx2[j] < f12[i][j]) {
			ret = min(ret, max(mx1[i], mx2[j]) + 1);
		}
	}
	return ret == l1 + l2 ? -1 : ret;
}

int main() {
	scanf("%s%s", s1, s2);
	int l1 = (int)strlen(s1), l2 = strlen(s2);
	pre(s1, l1, s2, l2, f12);
	pre(s1, l1, s1, l1, f11);
	pre(s2, l2, s2, l2, f22);
	mx(f11, l1, mx1);
	mx(f22, l2, mx2);
	printf("%d\n", mn(l1, l2));
	return 0;
}

// 6538246	 May 3, 2014 3:15:40 PM	delta_4d	 D - Match & Catch	 GNU C++0x	Accepted	 358 ms	 294700 KB
