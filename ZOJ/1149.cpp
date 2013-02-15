#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 7;
const int INF = 0x3f3f3f3f;
int x[MAXN];

inline bool input() {
	int i, j, k;
	int sum(0);
	for (i=1; i<MAXN; ++i) {
		scanf("%d", x+i);
		sum += x[i];
		x[i] %= 30;
	}
	return sum > 0;
}

int main() {
	int i[MAXN], j, k;
	int sum, tar;
	int cn(0);
	//freopen("f:\\in.txt", "r", stdin);
	while (input()) {
		tar = 0, sum = INF;
		for (k=1; k<MAXN; ++k) tar += k * x[k];
		if (tar & 0x1 == 1) goto gaoding;
		tar >>= 1;
		for (i[1]=0; i[1]<=x[1]; ++i[1]) {
			for (i[2]=0; i[2]<=x[2]; ++i[2]) {
				for (i[3]=0; i[3]<=x[3]; ++i[3]) {
					for (i[4]=0; i[4]<=x[4]; ++i[4]) {
						for (i[5]=0; i[5]<=x[5]; ++i[5]) {
							for (i[6]=0; i[6]<=x[6]; ++i[6]) {
								sum = 0;
								for (k=1; k<MAXN; ++k) sum += k * i[k];
								if (sum == tar) goto gaoding;
							}
						}
					}
				}
			}
		}
	gaoding:
		printf("Collection #%d:\n", ++cn);
		puts(sum==tar?"Can be divided.\n":"Can't be divided.\n");
	}
	return 0;
}