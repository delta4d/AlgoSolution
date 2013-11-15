#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int p2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 
				  16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 
				  4194304, 8388608, 16777216, 33554432};

int main() {
	int i, j, k;
	int m, n;
	int tc, cn;
	int bestlen, curlen;
	char s[160];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc); getchar();
	for (cn=1; cn<=tc; ++cn) {
		gets(s);
		bestlen = 0;
		curlen = 0;
		for (i=0; s[i]; ++i) {
			if (s[i] == '[') {
				++curlen;
				bestlen = max(bestlen, curlen);
			} else {
				--curlen;
			}
		}
		bestlen = max(bestlen, curlen);
		printf("%d %d\n", cn, p2[bestlen]);
	}
	return 0;
}