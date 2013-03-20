#include <cstdio>
using namespace std;

const int MAXN = 4;
char f[MAXN][MAXN];

inline void is_anyone_win(bool &X, bool &O) {
	int i, j, k;
	for (i=0; i<3; ++i) {
		if (f[i][0] == f[i][1] && f[i][1] == f[i][2]) {
			if (f[i][0] == 'X') X = true;
			else if (f[i][0] == 'O') O = true;
		}
		if (f[0][i] == f[1][i] && f[1][i] == f[2][i]) {
			if (f[0][i] == 'X') X = true;
			else if (f[0][i] == 'O') O = true;
		}
	}
	if (f[0][0] == f[1][1] && f[1][1] == f[2][2]) {
		if (f[1][1] == 'X') X = true;
		else if (f[1][1] == 'O') O = true;
	}
	if (f[0][2] == f[1][1] && f[1][1] == f[2][0]) {
		if (f[1][1] == 'X') X = true;
		else if (f[1][1] == 'O') O = true;
	}
}
 
bool gao() {
	int i, j, k;
	int nx(0), no(0);
	bool xwin(false), owin(false);
	for (i=0; i<3; ++i) {
		for (j=0; j<3; ++j) {
			if (f[i][j] == 'O') ++no;
			else if (f[i][j] == 'X') ++nx;
		}
	}
	if (!(no == nx || nx - no == 1)) return false;
	is_anyone_win(xwin, owin);
	if (xwin && owin) return false;
	if (nx == no && xwin) return false;
	if (nx - no == 1 && owin) return false;
	return true;
}

int main() {
	int i, j, k, t;
	int n, tc;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=0; t<tc; ++t) {
		for (i=0; i<3; ++i) scanf("%s", f[i]);
		printf("%s\n", gao()?"yes":"no");
	}
	return 0;
}
