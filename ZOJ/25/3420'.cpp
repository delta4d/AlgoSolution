#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 6;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const int barrier[] = {2, 1, 4, 8};
const char dir[] = "DLRU";

int f[MAXN][MAXN], g[MAXN][MAXN];
int ftx, fty, gtx, gty;
int fsx, fsy, gsx, gsy;
bool visit[5556];

struct node {
	int fx, fy;
	int gx, gy;
	int number;
	string path;
	void sett(int _fx, int _fy, int _gx, int _gy) {
		fx = _fx, fy = _fy;
		gx = _gx, gy = _gy;
		path.clear();
		number = fx * 1000 + fy * 100 + gx * 10 + gy;
	}
	bool gaoding() {
		return fx == ftx && fy == fty && gx == gtx && gy == gty;
	}
};

queue<node> q;

inline bool in(int x, int y) {
	return x >= 0 && x < MAXN && y >= 0 && y < MAXN;
}

bool go(int graph[][MAXN], int x, int y, int k, int &fx, int &fy) {
	int i, j;
	int tx(x+dx[k]), ty(y+dy[k]);
	fx = x, fy = y;
	if (graph[x][y] & barrier[k]) {
		return true;
	} else {
		if (!in(tx, ty)) return false;
		if (graph[x][y] & 16) {
			fx = tx, fy = ty;
			return true;
		}
		return false;
	}
}

void bfs() {
	int i, j, k;
	int fx, fy, gx, gy;
	node tt, s;
	
	memset(visit, false, sizeof(visit));
	s.sett(fsx, fsy, gsx, gsy);
	visit[s.number] = true;
	while (!q.empty()) q.pop();
	q.push(s);
	
	while (!q.empty()) {
		tt = q.front();
		q.pop();
		
		if (tt.gaoding()) {
			puts(tt.path.c_str());
			return;
		}
		
		for (k=0; k<4; ++k) {
			if (!go(f, tt.fx, tt.fy, k, fx, fy)) continue;
			if (!go(g, tt.gx, tt.gy, k, gx, gy)) continue;
			s.sett(fx, fy, gx, gy);
			s.path = tt.path + dir[k];
			if (visit[s.number]) continue;
			visit[s.number] = true;
			q.push(s);
		}
	}
	puts("-1");
}

int main() {
	int i, j, k;
	int tc;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (i=0; i<MAXN; ++i) {
		for (j=0; j<MAXN; ++j) {
			scanf("%d", f[i]+j);
			if (f[i][j] & 32) fsx = i, fsy = j;
			if (f[i][j] & 64) ftx = i, fty = j;
		}
	}
	while (--tc) {
		for (i=0; i<MAXN; ++i) {
			for (j=0; j<MAXN; ++j) {
				scanf("%d", g[i]+j);
				if (g[i][j] & 32) gsx = i, gsy = j;
				if (g[i][j] & 64) gtx = i, gty = j;
			}
		}
		bfs();
		for (i=0; i<MAXN; ++i) for (j=0; j<MAXN; ++j) f[i][j] = g[i][j];
		fsx = gsx, fsy = gsy, ftx = gtx, fty = gty;
	}
 	return 0;
}