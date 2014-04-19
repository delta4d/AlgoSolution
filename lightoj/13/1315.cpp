#include <cstdio>
using namespace std;

const int N = 1001;
const int dx[] = {1, -1, -1, -2, -3, -2};
const int dy[] = {-2, -3, -2, -1, -1, 1};

int sg[N][N];

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
} 

void init() {
	for (int k=0; k<N; ++k) for (int i=0; i<=k; ++i) {
		int j = k - i;
		bool v[10] = {false};
		for (int t=0; t<6; ++t) {
			int x = i + dx[t], y = j + dy[t];
			if (0 <= x && x < N && 0 <= y && y < N) v[sg[x][y]] = true;
		}
		for (int t=0; ; ++t) if (!v[t]) { sg[i][j] = t; break; }
	}
}

int main() {
	init();
	int tc, cn = 0, n, t;
	for (tc=fastin<int>(); tc--; ) {
		n = fastin<int>(), t = 0;
		for (int i=0,x,y; i<n; ++i) x = fastin<int>(), y = fastin<int>(), t ^= sg[x][y];
		printf("Case %d: %s\n", ++cn, t?"Alice":"Bob");
	}
	return 0;
}

// 258123	2013-09-01 00:04:45	 1315 - Game of Hyper Knights	 C++	 0.040	 5000	Accepted
