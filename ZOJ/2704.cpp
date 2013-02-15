#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 100001;

char s[MAXL];
stack<int> f;

int main() {
	int i, j, k;
	int m, n;
	int len, p;
	int x, y, xy;
	int xx, yy;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", s) == 1) {
		while (!f.empty()) f.pop();
		len = strlen(s);
		f.push(0);
		for (i=1; i<len; ++i) {
			if (f.empty()) {
				f.push(i);
			} else {
				p = f.top();
				if (s[p] == '(' && s[i] == ')' || s[p] == '[' && s[i] == ']') {
					f.pop();
				} else {
					f.push(i);
				}
			}
		}
		x = 0, y = len;
		xy = -1;
		while (!f.empty()) {
			x = f.top();
			f.pop();
			if (y - x >= xy) {
				xx = x, yy = y;
				xy = y - x;
			}
			y = x;
		}
		if (y > xy) xx = -1, yy = y, xy = y + 1;
		if (xy <= 1) puts("\n");
		else {for (i=xx+1; i<yy; ++i) printf("%c", s[i]); puts("\n");}
	}
	return 0;
}