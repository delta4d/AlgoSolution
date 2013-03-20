#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 26;
const int INF = 1000000000;
#define _clr(x) memset(x, 0xff, sizeof(int) * n)

int mat[MAXN][MAXN];
int mp[MAXN], match1[MAXN], match2[MAXN];
vector<int> f1[MAXN], f2[MAXN];
char s[100086];

int KM(int m, int n, int mat[][MAXN], int * match1, int * match2) {
	int s[MAXN + 1], t[MAXN], l1[MAXN], l2[MAXN], p, q, ret = 0, i, j, k;
	for (i = 0; i < m; i++) {
		l1[i] =  - INF;
		for (j = 0; j < n; j++) {
			l1[i] = mat[i][j] > l1[i] ? mat[i][j]: l1[i];
		}
	}
	for (i = 0; i < n; l2[i++] = 0);
	_clr(match1);
	_clr(match2);
	for (i = 0; i < m; i++) {
		_clr(t);
		for (s[p = q = 0] = i; p <= q && match1[i] < 0; p++) {
			k = s[p];
			for (j = 0; j < n && match1[i] < 0; j++) {
				if (l1[k] + l2[j] == mat[k][j] && t[j] < 0) {
					s[++q] = match2[j];
					t[j] = k;
					if (s[q] < 0) {
						for (p = j; p >= 0; j = p) {
							match2[j] = k = t[j];
							p = match1[k];
							match1[k] = j;
						}
					}
				}
			}
		}
		if (match1[i] < 0) {
			i--;
			p = INF;
			for (k = 0; k <= q; k++) {
				for (j = 0; j < n; j++) {
					if (t[j] < 0 && l1[s[k]] + l2[j] - mat[s[k]][j] < p) {
						p = l1[s[k]] + l2[j] - mat[s[k]][j];
					} 
				}
			}
			for (j = 0; j < n; j++) {
				l2[j] += t[j] < 0 ? 0 : p;
			}
			for (k = 0; k <= q; k++) {
				l1[s[k]] -= p;
			}
		}
	}
	for (i = 0; i < m; i++) {
		ret += mat[i][match1[i]];
	}
	return ret;
}

int gao(int a, int b) {
	int ret(0);
	int sa(f1[a].size()), sb(f2[b].size());
	int i(0), j(0), k;
	
	while (i < sa && j < sb) {
		if (f1[a][i] == f2[b][j]) {
			++i, ++j;
			++ret;
		} else if (f1[a][i] < f2[b][j]) {
			++i;
	 	} else {
		 	++j;
	 	}
	}
	return ret;
}

int main() {
	int i, j, k, t;
	int m, n;
	int tc, cnt, tot;
	
	//freopen("d:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &n, &k, &m);
		for (i=0; i<26; ++i) f1[i].clear();
		gets(s);
		gets(s);
		cnt = 0;
		memset(mp, -1, sizeof(mp));
		for (tot=0,i=0; tot<n; ++i) {
			if ('A' <= s[i] && s[i] <= 'Z') {
				if (mp[s[i]-'A'] == -1) mp[s[i]-'A'] = cnt++;
				j = mp[s[i]-'A'];
				f1[j].push_back(tot++);
			}
		}
		while (m--) {
			for (i=0; i<26; ++i) f2[i].clear();
			gets(s);
			cnt = 0;
			memset(mp, -1, sizeof(mp));
			for (tot=0,i=0; tot<n; ++i) {
				if ('A' <= s[i] && s[i] <= 'Z') {
					if (mp[s[i]-'A'] == -1) mp[s[i]-'A'] = cnt++;
					j = mp[s[i]-'A'];
					f2[j].push_back(tot++);
				}
			}
			memset(mat, 0, sizeof(mat));
			for (i=0; i<cnt; ++i) for (j=0; j<k; ++j) mat[i][j] = gao(j, i);
			printf("%.4lf\n", 1.0*KM(cnt, k, mat, match1, match2)/n);
		}
	}

	return 0;
}