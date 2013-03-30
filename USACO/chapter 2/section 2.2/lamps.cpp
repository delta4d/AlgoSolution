/*
ID: delta 4d
PROG: lamps
LANG: C++
*/

#include <set>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define FLIP(x) x = '0' + '1' - x

string cc;
vector <int> s[2];
set <string> ss;
int n, c;

void gao(const int op) {
	if (op == 0) for (int i=0; i<cc.size(); ++i) FLIP(cc[i]);	
	else if (op == 1) for (int i=0; i<cc.size(); i+=2) FLIP(cc[i]);	
	else if (op == 2) for (int i=1; i<cc.size(); i+=2) FLIP(cc[i]);
	else for (int i=0; i<cc.size(); i+=3) FLIP(cc[i]);	
}

bool ok() {
	for (int k=0; k<2; ++k) {
		for (int i=0; i<s[k].size(); ++i) if (cc[s[k][i]-1] != 1 - k + '0') return false;
	}
	return true;
}
void dfs(int d, int c) {
	if (d == 4) {
		if (c <= ::c && (::c - c) % 2 == 0 && ok()) ss.insert(cc);
		return;
	} 
	dfs(d+1, c);
	gao(d);	
	dfs(d+1, c+1);
	gao(d);
}

int main() {
#ifndef __DELTA__
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
#endif

	scanf("%d%d", &n, &c);
	for (int i=0; i<2; ++i) {
		for (int j=0,k; scanf("%d", &k)&&k!=-1; s[i].push_back(k));
	}
	for (int i=0; i<n; ++i) cc += "1";
	dfs(0, 0);
	for (set<string>::iterator it=ss.begin(); it!=ss.end(); ++it) {
		printf("%s\n", it->c_str());
	}
	if (ss.empty()) puts("IMPOSSIBLE");

	return 0;
}
