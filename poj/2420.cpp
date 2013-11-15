#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;

struct Point {
	double x, y;
};

Point p[MAXN];

double dis(const Point &a, const Point &b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double fermentpoint(int m, Point p[]) {
    Point u, v;
    double step = 0;
    u.x = u.y = 0;
    for (int i = 0; i < m; ++i) {
        u.x += p[i].x;
        u.y += p[i].y;
    }
    step = u.x + u.y;
    u.x /= m;
    u.y /= m;
    double nowbest = 0;;
    for (int i = 0; i < m; ++i) {
        nowbest += dis(u, p[i]);
    }
    while (step > 1e-10) {
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                v.x = u.x + step * i;
                v.y = u.y + step * j;
                double now = 0;
                for (int i = 0; i < m; ++i) {
                    now += dis(v, p[i]);
                }
                if (now < nowbest) {
                    nowbest = now;
                    u = v;
                }
            }
        }
        step /= 1.1;
    }
    return nowbest;
}

int main() {
	int i, j, k;
	int m, n;
	
	while (1 == scanf("%d", &n)) {
		for (i=0; i<n; ++i) scanf("%lf %lf", &p[i].x, &p[i].y);
		printf("%.0lf\n", fermentpoint(n, p));
	}
	return 0;
}