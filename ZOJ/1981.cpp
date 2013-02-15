#include <cmath>
#include <cstdio>
using namespace std;

inline bool not_zero(const double x) {
	return fabs(x) > 1e-6;
}

int main() {
	const double cw = 4.19;
	const double ci = 2.09;
	double mw, tw;
	double mi, ti;
	double t, w, i;
	double sum, m;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%lf %lf %lf %lf", &mw, &mi, &tw, &ti), not_zero(mw)||not_zero(mi)||not_zero(tw)||not_zero(ti)) {
		sum = cw * mw * tw + ci * mi * ti;
		m = sum / 335.0;
		if (sum > 0) {
			if (m <= mi) {
				w = mw + m;
				i = mi - m;
				t = 0;
			} else {
				w = mw + mi;
				i = 0;
				t = (sum - mi * 335) / (w * cw);
			}
		} else {
			sum *= -1;
			m *= -1;
			if (m <= mw) {
				w = mw - m;
				i = mi + m;
				t = 0;
			} else {
				i = mi + mw;
				w = 0;
				t = -(sum - mw * 335) / (i * ci);
			}
		}
		printf("%.1lf g of ice and %.1lf g of water at %.1lf C\n", i, w, t);
	}
	return 0;
}