#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[101][600];
char word[600][11];
bool match[600][600];

inline bool is_match(int i, int j) {
	for (int k=1; word[i][k]; ++k) if (word[i][k] != word[j][k-1]) return false;
	return true;
}

int main() {
	int i, j, k;
	int n, len, m, l;
	int sum;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %d %d", &n, &l, &m), n||l||m) {
		for (i=0; i<m; ++i) scanf("%s", word[i]);
		for (i=0; i<m; ++i) for (j=0; j<m; ++j) match[i][j] = is_match(i, j);
		for (i=0; i<=l; ++i) for (j=0; j<m; ++j) f[i][j] = 0;
		len = strlen(word[0]);
		for (i=0; i<m; ++i) f[len][i] = 1;
		for (k=len+1; k<=l; ++k) {
			for (i=0; i<m; ++i) {
				for (j=0; j<m; ++j) {
					if (match[i][j]) f[k][j] += f[k-1][i];
				}
			}
		}
		sum = 0;
		for (i=0; i<m; ++i) sum += f[l][i];
		printf("%d\n", sum);
	}
	return 0;
}