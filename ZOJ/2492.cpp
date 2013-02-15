#include <cstdio>
#include <cstring>
using namespace std;

int c[2], d[2];

int main() {
	int tc;
	int i, j, k;
	int r, s, t;
	char ch, pre;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (getchar() != '\n');
	while (tc--) {
		k = t = 0;
		c[0] = c[1] = d[0] = d[1] = 0;
		s = 1;
		ch = getchar();
		while (ch != '\n') {
			if (ch == '=') {
				if (pre <= '9' && pre >= '0') {
					d[k] += t;
				}
				t = 0;
				s = 1;
				k = 1;
			} else if (ch == 'x') {
				c[k] += s * t;
				t = 0;
			} else if (ch == '+') {
				if (pre <= '9' && pre >= '0') {
					d[k] += t * s;
				}
				t = 0;
				s = 1;
			} else if (ch == '-') {
				if (pre <= '9' && pre >= '0') {
					d[k] += t * s;
				}
				t = 0;
				s = -1;
			} else {
				t = t * 10 + ch - '0';
			}
			pre = ch;
			ch = getchar();
		}
		if (c[0] != c[1]) printf("%d\n", (d[1]-d[0])/(c[0]-c[1]));
		else if (d[0] == d[1]) puts("IDENTITY");
		else puts("IMPOSSIBLE");
	}
	return 0;
}