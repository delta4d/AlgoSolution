#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct time_tt {
	int h;
	int m;
	
	time_tt(int _h=0, int _m=0):h(_h), m(_m) {}
	bool input() {
		return 2 == scanf("%d %d", &h, &m);
	}
	bool below(const time_tt &a) {
		if (h < a.h) return true;
		if (h > a.h) return false;
		return m <= a.m;
	}
	int interval(const time_tt &a) {
		if (below(a)) return (a.h - h) * 60 + (a.m - m);
		return (a.h + 12 - h) * 60 + (a.m - m);
	}
	double get_hp() {
		return h == 12 ? m * 0.5 : h * 30 + m * 0.5;
	}
	double get_mp() {
		return m * 6.0;
	}
	int meet(const time_tt &a) {
		double t0, T, tot;
		double q, hp, mp;
		hp = get_hp(), mp = get_mp();
		if (hp > mp) q = hp - mp;
		else q = hp + 360 - mp;
		t0 = q * 2.0 / 11.0;
		tot = interval(a);
		if (t0 > tot) return 0;
		else return int((tot-t0)*11.0/720.0) + 1;
	}
	void output(const time_tt &a) {
		printf("       ");
		printf("%02d:%02d", h, m);
		printf("       ");
		printf("%02d:%02d", a.h, a.m);
		printf("%8d\n", meet(a));
	}
};

int main() {
	time_tt x, y;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	puts("Program 3 by team X");
	puts("Initial time  Final time  Passes");
	while (x.input()) {
		y.input();
		x.output(y);
	}
	puts("End of program 3 by team X");
	return 0;
}