#include <cstdio>
using namespace std;

int f[30][20][20][4][2];
int x[30][20];

void init() {
	for (int i=0; i<4; ++i) f[2][0][0][i][0] = 3 - i, f[2][0][0][i][1] = i;
	for (int i=2; i<=20; ++i) for (int j=0; j<=10; ++j) for (int k=0; k<=10; ++k) {
		for (int t=0; t<4; ++t) for (int c=0; c<4; ++c) if (c != t) {
			if (t < c) {
				f[i+1][j][k][c][1] += f[i][j][k][t][1];	
				f[i+1][j][k+1][c][1] += f[i][j][k][t][0];
			} else {
				f[i+1][j][k][c][0] += f[i][j][k][t][0];	
				f[i+1][j+1][k][c][0] += f[i][j][k][t][1];	
			}
		}
	}
	for (int i=3; i<=20; ++i) for (int j=1; j<=10; ++j) for (int k=0; k<4; ++k) {
		x[i][j] += f[i][j][j-1][k][0] + f[i][j][j-1][k][1];
	}
}

int main() {
	init();
	int n, t;
	scanf("%d%d", &n, &t);
	printf("%d\n", x[n][t]);
	return 0;
}

// 3793181	 May 30, 2013 10:12:01 AM	delta_4d	 E - Camels	 GNU C++	Accepted	15 ms	356 KB
