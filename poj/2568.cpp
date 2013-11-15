#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

typedef vector<int> VI;
typedef VI::iterator VII;

const int MAXN = 51;
int d[MAXN];
int x[MAXN];
VI tree[MAXN];
string out;

inline bool input(int &n) {
	int i, j, k;
	char c;
	n = 0;
	memset(d, 0, sizeof(d));
	x[0] = 0;
	if (scanf("%c", &c) == EOF) return false;
	if (c == '\n') return true;
	while (true) {
		x[0] = x[0] * 10 + c - '0';
		if ((c = getchar()) == ' ') break;
		if (c == '\n') {
			++d[x[0]]; ++n;
		 	return true;
		}
	}
	++d[x[0]]; ++n;
	while (true) {
		scanf("%d", x+n);
		++d[x[n]];
		++n;
		if (getchar() == '\n') break;
	}
	return true;
}

inline string tran(int x) {
	string r;
	if (x < 10) {
		r = x + '0';
	} else {
		r = x / 10 + '0';
		r += x % 10 + '0';
	} 
	return r; 
}

inline void dfs(const int root) {
	int i, j, k;
	
	out += "(";
	out += tran(root);
	if (tree[root].size() == 0) {
		out += ")";
		return;
	}
	for (i=0; i!=tree[root].size(); ++i) {
		out += " ";
		dfs(tree[root][i]);
	}
	out += ")";
}

void gao(const int n) {
	int i, j, k;
	if (n == 0) {
		puts("(1)");
		return;
	}
	for (i=0; i<MAXN; ++i) tree[i].clear();
	for (i=0; i<n; ++i) {
		k = 1;
		while (d[k] != 0) ++k;
		--d[k]; --d[x[i]];
		tree[x[i]].push_back(k);
	}
	out.clear();
	dfs(x[n-1]);
	cout << out << endl;
}

int main() {
	int i, j, k;
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (input(n)) gao(n);
	return 0;
}