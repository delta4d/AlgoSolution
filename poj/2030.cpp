#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 71;
int m, n;
char graph[MAXN][MAXN];
string f[MAXN][MAXN];

inline bool cmp(string &x, string &y) {
	int px(0), py(0);
	int lx(x.length()), ly(y.length());
	while (x[px] == '0' && px < lx) ++ px;
	while (y[py] == '0' && py < ly) ++ py;
	if (lx - px > ly - py) return true;
	if (lx - px < ly - py) return false;
	int len(lx - px);
	for (int i=0; i<len; ++i) {
		if (x[i+px] > y[i+py]) return true;
		else if (x[i+px] < y[i+py]) return false;
	}
}

inline bool digit(const char &x) {
	return x >= '0' && x <= '9';
}

int main() {
	int i, j, k;
	string temp;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	while (n != 0 || m != 0) {
		for (i=0; i<m; ++i) scanf("%s", graph[i]);
		f[0][0].clear();
		if (digit(graph[0][0])) f[0][0] += graph[0][0];
		for (i=1; i<m; ++i) {
			f[i][0].clear();
			if (digit(graph[i][0])) f[i][0] = f[i-1][0] + graph[i][0];
		}
		for (i=1; i<n; ++i) {
			f[0][i].clear();
			if (digit(graph[0][i])) f[0][i] = f[0][i-1] + graph[0][i];
		}
		for (i=1; i<m; ++i) {
			for (j=1; j<n; ++j) {
				f[i][j].clear();
				temp = cmp(f[i-1][j], f[i][j-1]) ? f[i-1][j] : f[i][j-1];
				if (digit(graph[i][j])) f[i][j] = temp + graph[i][j];
			}
		}
		temp.clear();
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				if (cmp(f[i][j], temp)) temp = f[i][j];
			}
		}
		k = 0;
		while (temp[k] == '0') ++k;
		puts(temp.c_str()+k);
		scanf("%d %d", &n, &m);
	}
	return 0;
}