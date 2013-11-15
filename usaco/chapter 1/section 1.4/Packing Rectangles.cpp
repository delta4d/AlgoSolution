/*
ID: delta 4d
PROG: packrec
LANG: C++
*/

#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

struct node {
	int a, b;
	node() {}
	node(int _a, int _b):a(_a), b(_b) {}
	void turn() {swap(a, b);}
	int area() {return a * b;}
} f[4];

bool visit[4];

inline bool operator<(node a, node b) {
	if (a.a != b.a) return a.a < b.a;
	return a.b < b.b;
}

int MN;
vector <node> cc;
set <node> out;
set <node> :: iterator it;

void update() {
	int i, j, k;
	int mn(INF);
	int x, y;
	set <node> tmp;
	
/*	for (i=0; i<4; ++i) printf("[%d %d] ", cc[i].a, cc[i].b); puts("--");
	
	if (cc[0].a == 4 && cc[0].b == 3 && cc[1].a == 1 && cc[1].b == 2
	 && cc[2].a == 3 && cc[2].b == 2 && cc[3].a == 4 && cc[3].b == 5) {
	 	int x = 0;
	 	++x;
	 }*/
	
	x = cc[0].a + cc[1].a + cc[2].a + cc[3].a;
	y = max(max(cc[0].b, cc[1].b), max(cc[2].b, cc[3].b));
	mn = x * y;
	if (x > y) swap(x, y);
	tmp.insert(node(x, y));
	
	x = max(cc[0].a, cc[1].a) + cc[2].a + cc[3].a;
	y = max(cc[0].b+cc[1].b, max(cc[2].b, cc[3].b));
	if (x > y) swap(x, y);
	if (mn == x * y) tmp.insert(node(x, y));
	else if (mn > x * y) {mn = x * y; tmp.clear(); tmp.insert(node(x, y));}
	
	x = max(cc[0].a, cc[1].a+cc[2].a) + cc[3].a;
	y = max(cc[0].b + max(cc[1].b, cc[2].b), cc[3].b);
	if (x > y) swap(x, y);
	if (mn == x * y) tmp.insert(node(x, y));
	else if (mn > x * y) {mn = x * y; tmp.clear(); tmp.insert(node(x, y));}
	
	x = cc[0].a + max(max(cc[1].a, cc[2].a), cc[3].a);
	y = max(cc[0].b, cc[1].b+cc[2].b+cc[3].b);
	if (x > y) swap(x, y);
	if (mn == x * y) tmp.insert(node(x, y));
	else if (mn > x * y) {mn = x * y; tmp.clear(); tmp.insert(node(x, y));}
	
	if (cc[0].a <= cc[1].a) {
		x = cc[1].a + max(cc[2].a, cc[3].a);
		y = max(cc[0].b + cc[1].b, cc[2].b + cc[3].b);
		if (x > y) swap(x, y);
		if (mn == x * y) tmp.insert(node(x, y));
		else if (mn > x * y) {mn = x * y; tmp.clear(); tmp.insert(node(x, y));}
		
		x = max(cc[0].a + cc[3].a, cc[1].a + cc[2].a);
		y = max(cc[3].b + max(cc[1].b, cc[2].b), cc[0].b + cc[1].b);
		if (x > y) swap(x, y);
		if (mn == x * y) tmp.insert(node(x, y));
		else if (mn > x * y) {mn = x * y; tmp.clear(); tmp.insert(node(x, y));}
	}
	
	if (mn < MN) {out = tmp; MN = mn;}
	else if (mn == MN) for (it=tmp.begin(); it!=tmp.end(); ++it) out.insert(*it);
}

void dfs(int d) {
	if (d == 4) {
		update();
		return;
	}
	for (int i=0; i<4; ++i) if (!visit[i]) {
		visit[i] = true;
		
		cc[d] = f[i];
		dfs(d+1);
		
		f[i].turn();
		cc[d] = f[i];
		dfs(d+1);
		
		f[i].turn();
		visit[i] = false;
	}
}

int main() {
	int i, j, k;
	int m, n;
	
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);

//	freopen("d:\\in.txt", "r", stdin);
//	freopen("d:\\out.txt", "w", stdout);
	
	for (i=0; i<4; ++i) scanf("%d %d", &f[i].a, &f[i].b);
	memset(visit, false, sizeof(visit));
	cc.resize(4);
	MN = INF;
	dfs(0);
	it = out.begin();
	printf("%d\n", (*it).a*(*it).b);
	for (it=out.begin(); it!=out.end(); ++it) printf("%d %d\n", it->a, it->b);
	
	return 0;
}