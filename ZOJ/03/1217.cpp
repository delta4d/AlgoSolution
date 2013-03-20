#include <set>
#include <cstdio>
#include <memory>
using namespace std;

const int tt = 123456789;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char dir[5] = {"durl"};
int graph[3][3];
int ss;
bool find;
char buff[8];
char out[1<<16];
set<int> visit;

bool input() {
	int i;
	ss = 0;
	for (i=0; i<9; ++i) {
		if (scanf("%s", buff) == EOF) return false;
		ss *= 10;
		ss += (buff[0] != 'x' ? buff[0] - '0' : 9);
	}
	return true;
}

inline bool border(int x, int y) {
	return x >= 0 && x <= 2 && y >= 0 && y <= 2;
}

inline void get_graph_pos(int state, int &x, int &y) {
	for (int i=2; i>=0; --i) {
		for (int j=2; j>=0; --j) {
			graph[i][j] = state % 10;
			if (graph[i][j] == 9) {x = i; y = j;}
			state /= 10;
		}
	}
}

inline int get_state(int x, int y, int tx, int ty) {
	int res(0);
	for (int i=0; i<=2; ++i) {
		for (int j=0; j<=2; ++j) {
			res *= 10;
			if (i == x && j == y) res += graph[tx][ty];
			else if (i == tx && j == ty) res += graph[x][y];
			else res += graph[i][j];
		}
	}
	return res;
}

void dfs(int d, int state) {
	int i;
	int k;
	int x;
	int y;
	int tx;
	int ty;
	int new_state;
	if (state == tt) {
		find = true;
		out[d] = '\0';
		return;
	}
	get_graph_pos(state, x, y);
	for (k=0; k<4; ++k) {
		tx = x + dx[k];
		ty = y + dy[k];
		if (border(tx, ty)) {
			new_state = get_state(x, y, tx, ty);
			if (visit.count(new_state) == 0) {
				visit.insert(new_state);
				out[d] = dir[k];
				dfs(d+1, new_state);
				if (find) return;
				visit.erase(visit.find(new_state));
			}
		}
	}
}

void gao() {
	visit.clear();
	find = false;
	dfs(0, ss);
	if (find) printf("%s\n", out);
	else printf("unsolvable\n");
}

int main() {
	freopen("f:\\in.txt", "r", stdin);
	while (input()) gao();
	return 0;
}
