#include <cstdio>
#include <cstring>
using namespace std;

const double eps = 1e-8;
double gx, gy, dx, dy;
char buff[80];

inline bool suc(const double x, const double y) {
	return 4.0 * ((gx - x) * (gx - x) + (gy - y) * (gy - y)) <= eps + (dx - x) * (dx - x) + (dy - y) * (dy - y);
}

int main() {
	double x, y;
	double rx, ry;
	bool esc;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%lf %lf %lf %lf", &gx, &gy, &dx, &dy) != EOF) {
		esc = false;
		getchar();
		gets(buff);
		while (strcmp(buff, "") != 0) {
			sscanf(buff, "%lf %lf", &x, &y);
			if (!esc) {
				if (suc(x, y)) {
					rx = x, ry = y;
					esc = true;
				}
			}
			if (!gets(buff)) break;
		}
		if (esc) printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", rx, ry);
		else printf("The gopher cannot escape.\n");
	}
	return 0;
}