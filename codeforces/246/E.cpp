#include <cstdio>
using namespace std;

int const dx[] = {0, 0, 1, -1};
int const dy[] = {1, -1, 0, 0};
int const N = 1 << 7;
char s[N][N];
int n, m;

char color(int x1, int y1) {
	bool v[26] = {false};
	for (int k=0; k<4; ++k) {
		int x = x1 + dx[k], y = y1 + dy[k];
		if (0 <= x && x < m && 0 <= y && y < n && 'A' <= s[x][y] && s[x][y] <= 'Z') {
			v[s[x][y]-'A'] = true;
		}
	}
	int cc = 0;
	for (cc=0; cc<26&&v[cc]; ++cc);
	return cc + 'A';
}

bool can_put(int a, int b, int d, int x1, int y1, char c) {
	for (int k=0; k<4; ++k) {
		int x = x1 + dx[k], y = y1 + dy[k];
		if (x < 0 || x >= m || y < 0 || y >= n) continue;
		if (a <= x && x <= a + d && b <= y && y <= b + d) continue;
		if (s[x][y] == c) return false;
	}
	return true;
}

bool ok(int x, int y, int d, char c) {
	if (x + d >= m || y + d >= n) return false;
	for (int i=0; i<=d; ++i) for (int j=0; j<=d; ++j) {
		if ('A' <= s[x+i][y+j] && s[x+i][y+j] <= 'Z' && s[x+i][y+j] != c) return false;
	}
	for (int i=0; i<=d; ++i) {
		if (!can_put(x, y, d, x, y+i, c) || !can_put(x, y, d, x+d, y+i, c)) return false; 
		if (!can_put(x, y, d, x+i, y, c) || !can_put(x, y, d, x+i, y+d, c)) return false; 
	}
	for (int i=0; i<=d; ++i) for (int j=0; j<=d; ++j) s[x+i][y+j] = c;
	return true;
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
		if (s[i][j]) continue;
		for (char c='A'; c<='Z'; ++c) {
			int d = 1;
			for (; j-d>=0&&s[i][j-d]==c; ++d); --d;
			if (ok(i, j-d, d, c)) break;
		}
	}
	for (int i=0; i<m; ++i) puts(s[i]);
	return 0;
}

// 6722314	 May 27, 2014 7:12:11 PM	delta_4d	 E - Square Tiling	 GNU C++0x	Accepted	78 ms	0 KB
