#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

struct node {
	int ID;
	int uptime;
	int period;
	
	node() {}
	node(int _ID, int _uptime, int _period):ID(_ID), uptime(_uptime), period(_period) {}
	void input() {
		scanf("%d %d", &ID, &period);
		uptime = period;
	}
	void output() {
		printf("%d\n", ID);
	}
	void next() {
		uptime += period;
	}
};

priority_queue<node> q;

inline bool operator<(node a, node b) {
	if (a.uptime != b.uptime) return a.uptime > b.uptime;
	return a.ID > b.ID;
}

int main() {
	int i, j, k(0);
	int m, n;
	char op[20];
	node x;
	
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", op), op[0] != '#') {
		x.input();
		q.push(x);
	}
	scanf("%d", &n);
	for (i=0; i<n; ++i) {
		x = q.top();
		q.pop();
		x.output();
		x.next();
		q.push(x);
	}
	return 0;
}