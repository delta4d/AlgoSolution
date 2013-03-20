#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXL = 20;
const int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 
					 100000000, 1000000000};

char buff[MAXL];

inline void gao(int &x, int &y) {
	int t;
	int tx(y), ty(x);
	do {
		t = tx % ty;
		tx = ty;
		ty = t;
	} while (ty != 0);
	x /= tx, y /= tx;
}

int main() {
	int i, j, k;
	int x, y;
	int rx, ry;
	int tx, ty;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%s", buff);
	while (strcmp(buff, "0") != 0) {
		x = 0;
		for (i=2; buff[i]!='.'; ++i) {
			x = x * 10 + buff[i] - '0';
		}
		ry = INF;
		for (k=1; k<=i-2; ++k) {
			tx = x - x / ten[k], ty = ten[i-2] - ten[i-2-k];
			gao(tx, ty);
			if (ty < ry) {
				rx = tx, ry = ty;
			}
		}
		printf("%d/%d\n", rx, ry);
		scanf("%s", buff);
	}
	return 0;
}