#include <cstdio>
#include <cstring>
using namespace std;

const double r4 = 0.25;
const double r8 = 0.125;
const double r16 = 0.0625;
const double r3r8 = 0.375;
const double r3r16 = 0.1875;
const int MAXN = 61;

double f[21][MAXN][MAXN];
double w[21];
double l[21];
double t[21];

void gen() {
	int i, j, k;
	int n, x, y;
	double t;
	memset(f, 0, sizeof(f));
	f[0][0][0] = 1.0;
	for (n=0; n<20; ++n) {
		for (x=0; x<MAXN; ++x) {
			for (y=0; y<MAXN; ++y) {
				t = f[n][x][y];
				f[n+1][x+2][y+1] += t * r3r16;
				f[n+1][x+2][y] += t * r8;
				f[n+1][x+3][y] += t * r16;
				f[n+1][x+1][y+2] += t * r8;
				f[n+1][x+1][y+1] += t * r3r8;
				f[n+1][x][y+3] += t * r16;
				f[n+1][x+1][y] += t * r16;
			}
		}
	}
}

void gao() {
	int i, j, k;
	memset(w, 0, sizeof(w));
	memset(l, 0, sizeof(l));
	memset(t, 0, sizeof(t));
	for (k=1; k<21; ++k) {
		for (i=0; i<MAXN; ++i) {
			for (j=0; j<MAXN; ++j) {
				if (i == j) t[k] += f[k][i][j];
				else if (i > j) w[k] += f[k][i][j];
				else l[k] += f[k][i][j];
			}
		}
	}	
}

void output() {
	int i, j, k;
	printf("puts(\"Round   A wins    B wins    Tie\");\n");
	for (i=1; i<21; ++i) {
		//printf("%5d   %7.4f%% %8.4f%% %8.4f%%\n", i, A*100, B*100, C*100);
		printf("puts(\"%5d   %7.4lf%%  %7.4lf%%  %7.4lf%%\");\n", i, w[i]*100, l[i]*100, t[i]*100);
	}
}

int main() {
	freopen("f:\\out.txt", "w", stdout);
	gen();
	gao();
	output();
	return 0;
}