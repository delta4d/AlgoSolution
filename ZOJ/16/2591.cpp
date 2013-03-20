#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[2001][5][5];
int b[2001][5][5];

struct DVD {
	char name[101];
	int year;
	int region;
	
	bool input() {
		return 3 == scanf("%s %d %d", name, &year, &region);
	}
} dvd[2000];

inline bool cmp(const DVD &a, const DVD &b) {
	if (a.year != b.year) return a.year < b.year;
	if (a.region != b.region) return a.region < b.region;
	return strcmp(a.name, b.name) < 0;
}

void trace_back() {
	
}

void dp(const int n) {
	int i, j, k;
	int len;
	for (i=0; i<5; ++i) for (j=0; j<5; ++j) f[0][i][j] = 0;
	for (i=1; i<=n; ++i) {
		for (j=0; j<5; ++j) {
			for (k=0; k<5; ++k) {
				
			}
		}
	} 
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) dvd[i].input();
		sort(dvd, dvd+n, cmp);
		dp(n);
		trace_back();
		//??
		if (tc) puts("");
	}
	return 0;
}