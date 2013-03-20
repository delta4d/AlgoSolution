#include <cstdio>
#include <cmath>
using namespace std;

double x;
double y;
double a;
double b;
double k;
double n1;
double n2;
const double eps = 1e-14;

double max(double a, double b) {
	return a > b ? a : b;
}

double min(double a, double b) {
	return a < b ? a : b;
}

int judge(double n) {
	if (a + b < n) return 1;
	if (a < n) return 2;
	if (b < n) return 3;
	if (0 < n) return 4;
	return 5;
}

void gao11() {
	printf("0.000000\n");
}

void gao21() {
	double a1 = a + b - n1;
	double s = a1 * a1 / 2.0;
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao22() {
	double a1 = a + b - n1;
	double a2 = a + b - n2;
	double s = fabs(a1*a1/2.0 - a2*a2/2.0);
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao31() {
	double s = (a + b - n1 + a - n1) * b / 2.0;
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao32() {
	double a1 = a + b - n2;
	double s1 = a1 * a1 / 2.0;
	double s2 = (a + b - n1 + a - n1) * b / 2.0;
	double s = fabs(s1-s2);
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao33() {
	double s = (n2 - n1) * b;
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao41() {
	double s = n1 * n1 / 2.0;
	s = a * b - s;
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao42() {
	double a1 = n1;
	double a2 = a + b - n2;
	double s1 = a1 * a1 / 2.0;
	double s2 = a2 * a2 / 2.0;
	double s = a * b - s1 - s2;
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao43() {
	double s1 = n1 * n1 / 2.0;
	double s2 = (n2 - b + n2) * b / 2.0;
	double s = fabs(s1 - s2);
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao44() {
	double s =fabs(n2*n2/2.0 - n1*n1/2.0);
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao51() {
	printf("1.000000\n");
}

void gao52() {
	double a1 = a + b - n2;
	double s = a * b - a1 * a1 / 2.0;
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao53() {
	double s = (n2 - b + n2) * b / 2.0;
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao54() {
	double s = n2 * n2 / 2.0;
	double res = s / (a * b);
	printf("%.6lf\n", res);
}

void gao55() {
	printf("0.000000\n");
}

void gao() {
	int m = judge(n1);
	int n = judge(n2);
	if (b == 0 && a != 0) {
		double a1 = max(0, n1);
		double a2 = min(a, n2);
		double res = (a2 - a1) / a;
		printf("%.6lf\n", res);
	} else if (a == 0 && b != 0) {
		double a1 = max(0, n1);
		double a2 = min(b, n2);
		double res = (a2 - a1) / b;
		printf("%.6lf\n", res);
	} else if (a == 0 && b == 0) {
		if (n1 - eps <= 0.0 && n2 + eps >= 0.0) {
			printf("1.000000\n");
		} else {
			printf("0.000000\n");
		}
	} else
	switch (m*10+n) {
		case 11: gao11(); break;
		case 21: gao21(); break;
		case 22: gao22(); break;
		case 31: gao31(); break;
		case 32: gao32(); break;
		case 33: gao33(); break;
		case 41: gao41(); break;
		case 42: gao42(); break;
		case 43: gao43(); break;
		case 44: gao44(); break;
		case 51: gao51(); break;
		case 52: gao52(); break;
		case 53: gao53(); break;
		case 54: gao54(); break;
		case 55: gao55(); break;
		default: throw "gao() error!!!!"; break;
	}
	return;
}

int main() {
	double t;
	while (scanf("%lf %lf %lf %lf %lf", &x, &y, &a, &b, &k) != EOF) {
		if (a < b) {
			t = a;
			a = b;
			b = t;
		}
		n1 = x + y - k;
		n2 = x + y + k;
		gao();
	}
	
	return 0;
}