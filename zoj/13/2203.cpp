#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool gaoding;
bool prime[10000];
bool visit[1001];
int out[1001];
int sum[1001];

inline void mark_prime() {
	int i, j, k;
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (i=2; i<=100; ++i) {
		for (j=i<<1; j<10000; j+=i) prime[j] = false;
	}
	//for (i=2; i<10000; ++i) if (prime[i]) printf("%d ", i);
}

void dfs(int cp, const int n, const int m, const int d) {
	int i, j, k;
	if (cp == m + 1) {
		gaoding = true;
		return;
	}
	for (i=n; i<=m; ++i) {
		if (!visit[i]) {
			for (k=2; k<=d&&n+k<=cp+1; ++k) {
				if (prime[sum[cp-1]-sum[cp-k]+i]) break;
			}
			if (k > d || n + k > cp + 1) {
				visit[i] = true;
				out[cp] = i;
				sum[cp] = sum[cp-1] + i;
				dfs(cp+1, n, m, d);
				if (gaoding) return;
				visit[i] = false;
			}
		}
	}
}

int main() {
	int i, j, k;
	int n, m, d;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	mark_prime();
	while (scanf("%d %d %d", &n, &m, &d), n||m||d) {
		gaoding = false;
		memset(visit, false, sizeof(visit));
		for (k=n; k<=m; ++k) {
			visit[k] = true;
			out[n] = k;
			sum[n] = k;
			sum[n-1] = 0;
			dfs(n+1, n, m, d);
			if (gaoding) break;
			visit[k] = false;
		}
		if (gaoding) {
			for (i=n; i<=m; ++i) printf("%d%s", out[i], i==m?"\n":",");
		} else {
			puts("No anti-prime sequence exists.");
		}
	}
	return 0;
}