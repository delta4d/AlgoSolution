#include <cstdio>
using namespace std;

#define OMIT scanf("%s", buff)
const int MAXN = 10000;
int f[MAXN];
char buff[2];

int main() {
	int n;
	int x;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		OMIT;
		for (i=0; i<n; ++i) {
			scanf("%d", &x);
			f[x] = i;
		}
		bool is_ag(false);
		for (i=0; i<n; ++i) {
			for (j=i+1; 2*j-i<n; ++j) {
				k = 2 * j - i;
				if (f[i] < f[j] && f[j] < f[k] || f[i] > f[j] && f[j] > f[k]) {
					is_ag = true;
					goto done;
				}
			}
		}
	done:
		printf("%s\n", is_ag?"no":"yes");
		scanf("%d", &n);
	}
	
	return 0;
}
