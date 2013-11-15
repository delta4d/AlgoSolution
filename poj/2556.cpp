#include <cstdio>
#include <cstring>
using namespace std;

const int dx[2][4] = {{0, 10, 0, -10}, {0, -10, 0, 10}};
const int dy[2][4] = {{-10, 0, 10, 0}, {10, 0, -10, 0}};
const int MAXL = 201;

char s[MAXL];
struct node {
	int x;
	int y;
	int d;
	node(int x=310, int y=420, int d=0):x(x), y(y), d(d) {}
	void show_begin() {
		puts("300 420 moveto");
		puts("310 420 lineto");
	}
	void show_proc() {
		printf("%d %d lineto\n", x, y);
	}
	void show_end() {
		puts("stroke");
		puts("showpage");
	}
};

int main() {
	int i, j, k;
	int len;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", s) != EOF) {
		node p;
		p.show_begin();
		len = strlen(s);
		for (i=0; i<len; ++i) {
			if (s[i] == 'A') {
				p.x += dx[0][p.d];
				p.y += dy[0][p.d];
				p.d = (p.d + 3) % 4;
			} else if (s[i] == 'V') {
				p.x += dx[1][p.d];
				p.y += dy[1][p.d];
				p.d = (p.d + 1) % 4;
			} else {
				throw "error!";
			}
			p.show_proc();
		}
		p.show_end();
	}
	return 0;
}