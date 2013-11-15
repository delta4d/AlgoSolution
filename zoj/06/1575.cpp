#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const double cc = 0.5;
const double ss = sqrt(3) / 2;

set <pair<double, double> > in;
vector <pair<double, double> > out;

void gao(int d, const int n, double x1, double y1, double x2, double y2) {
	double x3, y3, x4, y4, x5, y5;
	
	if (d == n) return;
	x3 = x1 + (x2 - x1) / 3, y3 = y1 + (y2 - y1) / 3;
	x4 = x3 + (x2 - x1) / 3, y4 = y3 + (y2 - y1) / 3;
	x5 = (x4 - x3) * cc - (y4 - y3) * ss + x3;
	y5 = (x4 - x3) * ss + (y4 - y3) * cc + y3;
	pair <double, double> x(x1, y1);
	if (in.find(x) == in.end()) {
		out.push_back(x);
		in.insert(x);
	}
	gao(d+1, n, x1, y1, x3, y3);
	gao(d+1, n, x3, y3, x5, y5);
	gao(d+1, n, x5, y5, x4, y4);
	gao(d+1, n, x4, y4, x2, y2);
	pair <double, double> y(x2, y2);
	if (in.find(y) == in.end()) {
		out.push_back(y);
		in.insert(y);
	}
}

int main() {
	int i, j, k;
	int n;
	double sx, sy, dx, dy;

	while (1 == scanf("%d", &n)) {
		scanf("%lf %lf %lf %lf", &sx, &sy, &dx, &dy);
		in.clear();
		out.clear();
		gao(0, n + 1, sx, sy, dx, dy);
//		printf("tot: %d\n", out.size());
		for (i=0; i<out.size(); ++i) printf("%.2lf %.2lf\n", out[i].first, out[i].second);
		puts("");
	}
	return 0;
}