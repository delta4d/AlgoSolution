/*
ID: delta 4d
PROG: clocks
LANG: C++
*/

#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const char s[9][10] = {"ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};

vector <int> op[9];
bool visit[1<<18];

struct node {
	int state[9];
	int out;
	vector <int> path;
	
	node() {path.clear();}
	void turn(int k) {
		for (int i=0; i<op[k].size(); ++i) {
			state[op[k][i]] = (state[op[k][i]] + 1) % 4;
		}
		out = getstate();
	}
	int getstate() {
		int ret(0);
//		for (int i=0; i<9; ++i) state[i] = 3;
		for (int i=0; i<9; ++i) ret = ret * 4 + state[i];
		return ret;
	}
	void input() {
		for (int i=0; i<9; ++i) {
			scanf("%d", state+i);
			state[i] = state[i] / 3 - 1;
		}
	}
	void output() {
		for (int i=0; i<path.size(); ++i) printf("%d%c", path[i]+1, i==path.size()-1?'\n':' ');
	}
};

queue <node> q;

void init() {
	for (int i=0; i<9; ++i) for (int j=0; s[i][j]; ++j) {
		op[i].push_back(s[i][j]-'A');
	}
	memset(visit, false, sizeof(visit));
}

int main() {
	int i, j, k;
	int m, n;
	node ss, tt;
	
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
//	freopen("d:\\in.txt", "r", stdin);
	
	init();
	ss.input();
	q.push(ss);
	ss.out = ss.getstate();
	visit[ss.out] = true;
	while (!q.empty()) {
		ss = q.front();
		if (ss.out == (1 << 18) - 1) {
			ss.output();
			break;
		}
		q.pop();
		for (k=0; k<9; ++k) {
			tt = ss;
			tt.turn(k);
			if (!visit[tt.out]) {
				tt.path.push_back(k);
				visit[tt.out] = true;
				q.push(tt);
			}
		}
	}
	return 0;
}
