#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 6;
const char dir[] = "DLRU";
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const int barrier[] = {2, 1, 4, 8};
const int startp = 1 << 5;
const int endp = 1 << 6;

int f[MAXN][MAXN], g[MAXN][MAXN];
int fsx, fsy, gsx, gsy;
int ftx, fty, gtx, gty;
bool visit[7000];

struct node {
	int fx, fy;
	int gx, gy;
	string path;
	void clr() {
		path.clear();
	}
	void sett(int _fx, int _fy, int _gx, int _gy) {
		fx = _fx, fy = _fy;
		gx = _gx, gy = _gy;
	}
	bool got_it() {
		return fx == ftx && fy == fty && gx == gtx && gy == gty;
	}
	int number() {
		return 1000 * fx + 100 * fy + 10 * gx + gy;
	}
};
queue<node> q;

inline void read(int f[][MAXN], int &sx, int &sy, int &tx, int &ty) {
	for (int i=0; i<MAXN; ++i) {
		for (int j=0; j<MAXN; ++j) {
			scanf("%d", f[i]+j);
			if (f[i][j] & startp) sx = i, sy = j;
			if (f[i][j] & endp) tx = i, ty = j;
		}
	}
}

inline void mcp(int f[][MAXN], int g[][MAXN]) {
	for (int i=0; i<MAXN; ++i) for (int j=0; j<MAXN; ++j) f[i][j] = g[i][j];
	fsx = gsx, fsy = gsy, ftx = gtx, fty = gty;
}

inline bool square(int f[][MAXN], int x, int y) {
	return f[x][y] & 16;
}

inline bool in(int x, int y) {
	return x >= 0 && x < MAXN && y >= 0 && y < MAXN;
}

inline bool reach(int f[][MAXN], int x, int y, int k, int &tx, int &ty) {
	int i, j;
	tx = x, ty = y;
	if (in(x+dx[k], y+dy[k])) {
		if (!(f[x][y] & barrier[k])) {
			if (square(f, x+dx[k], y+dy[k])) tx = x + dx[k], ty = y + dy[k];
			else return false;
		}
	}
	return false;
}

void gao() {
	int i, j, k;
	int fx, fy, gx, gy;
	node tt, s;
	bool rf, rg;
	
	memset(visit, false, sizeof(visit));
	while (!q.empty()) q.pop();
	s.clr();
	s.sett(fsx, fsy, gsx, gsy);
	visit[s.number()] = true;
	q.push(s);
	
	while (!q.empty()) {
		tt = q.front();
		q.pop();
		if (tt.got_it()) {
			puts(tt.path.c_str());
			return;
		}
		for (k=0; k<4; ++k) {
			if (!reach(f, tt.fx, tt.fy, k, fx, fy)) continue;
			if (!reach(g, tt.gx, tt.gy, k, gx, gy)) continue;
			s.sett(fx, fy, gx, gy);
			if (visit[s.number()]) continue;
			s.path = tt.path + dir[k];
			visit[s.number()] = true;
			q.push(s);
		}
	}
	puts("-1");
}

int main() {
	int i, j, k;
	int tc;
	freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	read(f, fsx, fsy, ftx, fty);
	while (--tc) {
		read(g, gsx, gsy, gtx, gty);
		gao();
		mcp(f, g);
	}
	return 0;
}