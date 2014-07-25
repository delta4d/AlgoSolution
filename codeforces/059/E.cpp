#include <bits/stdc++.h>
using namespace std;

vector <int> line[15];
int f[1<<19];

void init() {
	line[0] = {0, 3, 7};
	line[1] = {1, 4, 8, 12};
	line[2] = {2, 5, 9, 13, 16};
	line[3] = {6, 10, 14, 17};
	line[4] = {11, 15, 18};
	line[5] = {2, 6, 11};
	line[6] = {1, 5, 10, 15};
	line[7] = {0, 4, 9, 14, 18};
	line[8] = {3, 8, 13, 17};
	line[9] = {7, 12, 16};
	line[10] = {0, 1, 2};
	line[11] = {3, 4, 5, 6};
	line[12] = {7, 8, 9, 10, 11};
	line[13] = {12, 13, 14, 15};
	line[14] = {16, 17, 18};
}

int dfs(int mask) {
	if (f[mask] != -1) return f[mask];
	if (mask == 0) return f[mask] = 0;
	for (int k=0; k<15; ++k) {
		int sz = (int)line[k].size();
		for (int i=0; i<sz; ++i) if (mask & 1 << line[k][i]) {
			int next_mask = mask;
			for (int j=i; j<sz; ++j) {
				if (!(mask & 1 << line[k][j])) break;
				next_mask ^= 1 << line[k][j];
				if (dfs(next_mask) == 0) return f[mask] = 1;
			}
		}
	}
	return f[mask] = 0;
}

int main() {
	init();
	int mask = 0, st[5]={0,3,7,12,16};
	char s[20];
	for (int i=0; i<5; ++i) {
		gets(s);
		for (int k=0,j=0; s[j]; ++j) {
			if (s[j] == 'O') mask |= 1 << (k + st[i]);
			if (s[j] != ' ') ++k;
		}
	}
	memset(f, -1, sizeof(f));
	if (dfs(mask)) puts("Karlsson");
	else puts("Lillebror");
	return 0;
}

// 7240530	2014-07-25 13:10:01	delta_4d	E - Sweets Game	GNU C++0x	Accepted	124 ms	2060 KB
