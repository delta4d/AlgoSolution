#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

const int INF = 0x7fffffff;
const int MAXN = 10001;

int v[MAXN];

int main() {
	int i, j, k;
	int N, T, L;
	int tc;
	int mv;
	double tot, rem;
	freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &N, &T, &L);
		mv = INF;
		for (i=1; i<=N; ++i) {
			scanf("%d", v+i);
			mv = min(mv, v[i]);
		}
		if (mv * T * N <= L) {
			puts("-1");
		} else {
			sort(v+1, v+N+1, greater<int>());
			for (i=1; i<=N; ++i) {
				if (v[i] * i * T > L) {
					rem = L - v[i-1] * (i - 1) * T;
					tot = (i - 1) * T + rem / v[i];
					break;
				}
			}
			printf("%.2lf\n", tot);
		}
	}
	return 0;
}