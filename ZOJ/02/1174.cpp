#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 1000001;
const int MAXN = 100;
map<string, string> f;
set<string> used;
char buff[10];
char out[MAXL];
char sen[MAXL];
string cc, res;
bool chongfu, any_alp;

void dfs(int k, int d, const int len) {
	int i, j;
	if (d == len) {
		if (k == 0) return;
		out[k] = '\0';
		string s(out);
		if (used.find(s) != used.end()) return;
		if (f.find(s) == f.end()) f.insert(make_pair(s, cc));
		else f[s] = string(">_<");
		used.insert(s);
		return;
	}
	dfs(k, d+1, len);
	out[k] = buff[d];
	dfs(k+1, d+1, len);
}

inline bool alp(const char x) {
	return x >= 'A' && x <= 'Z';
}

void gao(const int len) {
	int i, j, k;
	string msg("");
	for (i=0; i<len; ++i) {
		if (alp(sen[i])) {
			any_alp = true;
			msg += sen[i];
		} else {
			if (msg.size() > 0) {
				if (f[msg] == string(">_<")) {
					chongfu = true;
					return;
				} else {
					res += f[msg];
				}
				msg.clear();
			}
			res += sen[i];
		}
	}
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int len;
	bool wanle;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		f.clear();
		scanf("%d", &n);
		for (i=0; i<n; ++i) {
			scanf("%s", buff);
			cc = string(buff);
			used.clear();
			dfs(0, 0, strlen(buff));
		}
		while (getchar() != '\n');
		wanle = false;
		chongfu = false;
		any_alp = false;
		res.clear();
		while (!wanle) {
			gets(sen);
			len = strlen(sen);
			if (sen[len-1] == '#') {
				--len;
				sen[len] = '\0';
				wanle = true;
			}
			if (chongfu) continue;
			sen[len] = '\n', sen[++len] = '\0';
			gao(len);
		}
		if (chongfu || !any_alp) puts("AMBIGUITY");
		else printf("%s", res.c_str());
		if (tc != 0) puts("");
	}
	return 0;
}
