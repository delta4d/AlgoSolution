#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100;
bool f[MAXN][MAXN];
bool done[MAXN];
char buff[80];

int main() {
	int i, j, k;
	int m, n;
	int P, T;
	int x, y;
	int res;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d", &P, &T) != EOF) {
		memset(f, false, sizeof(f));
		getchar();
		gets(buff);
		while (strcmp(buff, "") != 0) {
			sscanf(buff, "%d %d", &x, &y);
			f[x][y] = true;
			if (gets(buff) == NULL) break;
		}
		res = 0;
		memset(done, false, sizeof(done));
		for (i=1; i<=P; ++i) {
			if (done[i]) continue;
			++res;
			for (j=i; j<=P; ++j) {
				for (k=1; k<=T&&f[i][k]==f[j][k]; ++k);
				if (k > T) done[j] = true;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}