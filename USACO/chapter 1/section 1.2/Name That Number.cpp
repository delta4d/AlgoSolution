/*
ID: delta 4d
PROG: namenum
LANG: C++
*/

#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 20;
const char f[10][4] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
char buff[MAXL];
char out[MAXL];
set<string> dict;
bool zhaodaole;
int len;

inline void read_dict() {
	int i, j, k;
	freopen("dict.txt", "r", stdin);
	dict.clear();
	while (scanf("%s", buff) != EOF) dict.insert(string(buff));
	//freopen("CON", "r", stdin);
}

void dfs(int d) {
	int i, j, k;
	k = buff[d] - '0';
	if (d == len) {
		out[d] = '\0';
		if (dict.find(string(out)) != dict.end()) {
			zhaodaole = true;
			puts(out);
		}
		return;
	}
	for (i=0; i<3; ++i) {
		out[d] = f[k][i];
		dfs(d+1);
	}
}

int main() {
	int i, j, k;
	read_dict();
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	while (scanf("%s", buff) != EOF) {
		zhaodaole = false;
		len = strlen(buff);
		dfs(0);
		if (!zhaodaole) puts("NONE");
	}
	return 0;
}