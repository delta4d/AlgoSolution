#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int c[2], d[2];
char buff[256];

int main() {
	int tc;
	int i, j, k;
	int r, s, t;
	int len;
	char ch, pre;
	double v;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (getchar() != '\n');
	while (tc--) {
		scanf("%s", buff);
		k = t = 0;
		c[0] = c[1] = d[0] = d[1] = 0;
		s = 1;
		ch = buff[i=0];
		pre = '?';
		while (ch != '\0') {
			if (ch == '=') {
				if (pre <= '9' && pre >= '0') d[k] += t * s;
				t = 0, s = 1, k = 1;
			} else if (ch == 'x') {
				if (pre <='9' && pre >= '0') c[k] += s * t;
				else c[k] += s;
				t = 0;
			} else if (ch == '+') {
				if (pre <= '9' && pre >= '0') d[k] += t * s;
				if (pre == '+') s = 1;
				else if (pre == '-') s = -1;
				else s = 1;
				t = 0;
			} else if (ch == '-') {
				if (pre <= '9' && pre >= '0') d[k] += t * s;
				if (pre == '+') s = -1;
				else if (pre == '-') s = 1;
				else s = -1;
				t = 0;
			} else {
				t = t * 10 + ch - '0';
			}
			pre = ch;
			ch = buff[++i];
		}
		if (pre <= '9' && pre >= '0') d[k] += t * s;
		v = double(d[1] - d[0]) / double(c[0] - c[1]);
		if (int(v) * (c[0] - c[1]) == (d[1] - d[0])) t = int(v);
		else if (v < 0) t = int(v) - 1;
		else t = int(v);
		if (c[0] != c[1]) printf("%d\n", t);
		else if (d[0] == d[1]) puts("IDENTITY");
		else puts("IMPOSSIBLE");
	}
	return 0;
}