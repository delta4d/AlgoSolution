#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int i, j, k;
	int n;
	char buff[81], unit[10];
	double U, P, I;			// P = UI
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	for (i=1; i<=n; ++i) {
		k = 0;
		U = P = I = -1000000;
		while (k < 2) {
			scanf("%s", buff);
			if (buff[1] == '=') {
				if (buff[0] == 'U') {
					sscanf(buff, "U=%lf%s", &U, unit);
					if (unit[0] == 'm') U /= 1000.0;
					else if (unit[0] == 'k') U *= 1000.0;
					else if (unit[0] == 'M') U *= 1000000.0;
				} else if (buff[0] == 'I') {
					sscanf(buff, "I=%lf%s", &I, unit);
					if (unit[0] == 'm') I /= 1000.0;
					else if (unit[0] == 'k') I *= 1000.0;
					else if (unit[0] == 'M') I *= 1000000.0;
				} else if (buff[0] == 'P') {
					sscanf(buff, "P=%lf%s", &P, unit);
					if (unit[0] == 'm') P /= 1000.0;
					else if (unit[0] == 'k') P *= 1000.0;
					else if (unit[0] == 'M') P *= 1000000.0;
				}
				++k;
			}
		}
		printf("Problem #%d\n", i);
		if (U == -1000000) printf("U=%.2lfV\n", P/I);
		else if (I == -1000000) printf("I=%.2lfA\n", P/U);
		else printf("P=%.2lfW\n", U*I);
		puts("");
	}
	return 0;
}