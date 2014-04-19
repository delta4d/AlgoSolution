#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int MAXN = 1 << 9;

int M, N;
char s[MAXN][MAXN];
int tag[MAXN][MAXN], cnt[MAXN*MAXN], tot, tt;
queue <pair<int,int> > q;

inline bool in(int x, int y) {
	return 0 <= x && x < M && 0 <= y && y < N;
}

int gao(int x, int y) {
	int sx = x, sy = y;
	if (tag[x][y] != -1) return cnt[tag[x][y]];
	while (!q.empty()) q.pop();
	q.push(make_pair(x, y));
	tot = 0;
	tag[x][y] = tt;
	if (s[x][y] == 'C') ++tot;
	s[x][y] = '#';
	while (!q.empty()) {
		x = q.front().first, y = q.front().second; q.pop();
		for (int k=0; k<4; ++k) {
			int tx = x + dx[k], ty = y + dy[k];
			if (!in(tx, ty) || tag[tx][ty] != -1 || s[tx][ty] == '#') continue;
			tag[tx][ty] = tt;
			if (s[tx][ty] == 'C') ++tot;
			s[tx][ty] = '#';
			q.push(make_pair(tx, ty));
		}
	}
	cnt[tt++] = tot;
	return cnt[tag[sx][sy]];
}

int main() {
	int tc, cn = 0, Q;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d%d", &M, &N, &Q);
		for (int i=0; i<M; ++i) scanf("%s", s[i]);
		tt = 0;
		memset(tag, -1, sizeof(tag));
		printf("Case %d:\n", ++cn);
		for (int x, y; Q--; ) {
			scanf("%d%d", &x, &y);
			printf("%d\n", gao(x-1, y-1));
		}
	}
	return 0;
}

// 297246	2013-12-09 21:37:45	 1337 - The Crystal Maze	 C++	 0.124	 3552	Accepted
