#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100;
const int MAXL = 81;
const char ss[] = "the quick brown fox jumps over the lazy dog";
const int ssl = strlen(ss);
char s[MAXN][MAXL];
char out[MAXN][MAXL];
int f[26];

inline bool is_alp(const char x) {
	return x >= 'a' && x <= 'z';
}

inline bool is_plain(const int k) {
	int i, j;
	int len(strlen(s[k]));
	if (len != ssl) return false;
	for (i=0; i<len; ++i) {
		if (is_alp(ss[i]) && !is_alp(s[k][i])) return false;
		if (ss[i] == ' ' && s[k][i] != ' ') return false;
	}
	return true;
}

inline bool update_f(const int k) {
	int i, j;
	int x, y;
	memset(f, -1, sizeof(f));
	for (i=0; i<ssl; ++i) {
		if (is_alp(s[k][i])) {
			x = s[k][i] - 'a', y = ss[i] - 'a';
			if (f[x] == -1) f[x] = y;
			else if (f[x] != y) return false;
		}
	}
	return true;
}

int main() {
	int i, j, k(0);
	int m, n;
	//freopen("f:\\in.txt", "r", stdin);
	gets(s[k++]);
	while (true) {
		while (strcmp(s[k-1], "") != 0) {
			if (!gets(s[k++])) break;
		}
		--k;
		for (i=0; i<k; ++i) {
			if (is_plain(i)) {
				if (update_f(i)) break;
			}
		}
		if (i == k) {
			puts("No solution.");
		} else {
			for (i=0; i<k; ++i) {
				for (j=0; s[i][j]; ++j) {
					if (is_alp(s[i][j])) printf("%c", f[s[i][j]-'a']+'a');
					else printf("%c", s[i][j]);
				}
				puts("");
			}
		}
		k = 0;
		if (!gets(s[k++])) break;
		puts("");
	}
	return 0;
}