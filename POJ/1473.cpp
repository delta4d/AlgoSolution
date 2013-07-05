#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const double sqrt2 = 0.70710678118654752440084436210485;

struct pos {
	double x;
	double y;
	
	pos(double _x=0, double _y=0):x(_x), y(_y) {}
	void sett(double _x, double _y) {
		x = _x, y = _y;
	}
	double dis() {
		return sqrt(x*x+y*y);
	}
	void N(const int d) {
		y += double(d);
	}
	void NE(const int d) {
		double off(double(d) * sqrt2);
		x += off, y += off;
	}
	void E(const int d) {
		x += double(d);
	}
	void SE(const int d) {
		double off(double(d) * sqrt2);
		x += off, y -= off;
	}
	void S(const int d) {
		y -= double(d);
	}
	void SW(const int d) {
		double off(double(d) * sqrt2);
		x -= off, y -= off;
	}
	void W(const int d) {
		x -= double(d);
	}
	void NW(const int d) {
		double off(double(d) * sqrt2);
		x -= off, y += off;
	}
	bool mov(char buff[]) {
		int d, t;
		char op[10];
		sscanf(buff, "%d%s", &d, op);
		t = strlen(op);
		if (op[t-1] == '.') {
			op[t-1] = '\0';
			t = 0;
		}
		if (!strcmp(op, "N")) N(d);
		else if (!strcmp(op, "NE")) NE(d);
		else if (!strcmp(op, "E")) E(d);
		else if (!strcmp(op, "SE")) SE(d);
		else if (!strcmp(op, "S")) S(d);
		else if (!strcmp(op, "SW")) SW(d);
		else if (!strcmp(op, "W")) W(d);
		else if (!strcmp(op, "NW")) NW(d);
		return t;
	}
};

int main() {
	int i, j, k;
	int cn(0);
	char buff[10];
	pos p;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%[^,\n]", buff);
	p.sett(0, 0);
	while (buff[0] != 'E') {
		while (p.mov(buff)) 
			getchar(), scanf("%[^,\n]", buff);
		printf("Map #%d\n", ++cn);
		printf("The treasure is located at (%.3lf,%.3lf).\n", p.x, p.y);
		printf("The distance to the treasure is %.3lf.\n", p.dis());
		getchar();
		scanf("%[^,\n]", buff);
		p.sett(0, 0);
		if (buff[0] != 'E') puts("");
	}
	return 0;
}