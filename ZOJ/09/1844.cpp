#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int i, j, k;
	int cn(0);
	int n, p, r;
	int bestr;
	double price, bestprice;
	char prop[81], bestprop[81], buff[81];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d", &n, &p);
	while (true) {
		getchar();
		for (i=0; i<n; ++i) gets(buff);
		bestr = -1;
		for (k=0; k<p; ++k) {
			gets(prop);
			scanf("%lf %d", &price, &r);
			getchar();
			for (i=0; i<r; ++i) gets(buff);
			if (r > bestr || (r == bestr && price < bestprice)) {
				bestr = r;
				bestprice = price;
				strcpy(bestprop, prop);
			}
		}
		printf("RFP #%d\n%s\n", ++cn, bestprop);
		scanf("%d %d", &n, &p);
		if (n || p) puts("");
		else break;
	}
	return 0;
}