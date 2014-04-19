#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 51;

int sg[N][N][N], re[N][N];
int x[N][N], len[N];
vector <pair<int, int> > out;

template <class T> inline T fastin() {
	register char c = 0;
	register T a = 0;
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9') a = a * 10 + c - '0', c = getchar();
	return a;
} 

int gao(const int w, int l, int r) {
	if (sg[w][l][r] != -1) return sg[w][l][r];
	bool v[N] = {false};
	for (int i=l; i<=r; ++i) {
		int cc = x[w][i], ll = -1, rr = -1, t = 0;
		for (int j=l; j<=r; ++j) {
			if (x[w][j] < cc) {
				if (ll == -1) ll = j;
				rr = j;
			} else {
				if (ll != -1 && rr != -1) t ^= gao(w, ll, rr);
				ll = -1, rr = -1;
			}
		}
		if (ll != -1 && rr != -1) t ^= gao(w, ll, rr);
		v[t] = true;
		if (l == 0 && r == len[w] - 1) re[w][i] = t;
	}
	for (int i=0; ; ++i) if (!v[i]) return sg[w][l][r] = i;
}

int main() {
	int tc, cn = 0, n, t;
	for (tc=fastin<int>(); tc--; ) {
		memset(sg, -1, sizeof(sg));
		n = fastin<int>(), t = 0;
		for (int i=0; i<n; ++i) {
			len[i] = fastin<int>();
			for (int j=0; j<len[i]; ++j) x[i][j] = fastin<int>();
			t ^= gao(i, 0, len[i]-1);
		}
		if (t) {
			out.clear();
			printf("Case %d: Aladdin\n", ++cn);
			for (int i=0; i<n; ++i) {
				int ct = t ^ sg[i][0][len[i]-1];
				for (int j=0; j<len[i]; ++j) {
					if ((ct ^ re[i][j]) == 0) {
						out.push_back(make_pair(i+1, x[i][j]));
					}
				}
			}
			sort(out.begin(), out.end());
			out.erase(unique(out.begin(), out.end()), out.end());
			for (int i=0; i<(int)out.size(); ++i) printf("(%d %d)", out[i].first, out[i].second);
			puts("");
		} else {
			printf("Case %d: Genie\n", ++cn);
		}
	}
	return 0;
}

// 258738	2013-09-02 14:57:38	 1344 - Aladdin and the Game of Bracelets	 C++	 0.068	 1748	Accepted
