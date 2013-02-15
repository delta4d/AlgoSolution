#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 101;

int f[MAXN][MAXN];
string g[MAXN][MAXN];
char s[MAXN], buff[MAXN];

int gao(int i, int j) {
	if (f[i][j] != -1) {
		return f[i][j];
	}
	if (i == j) {
		if (s[i] == ']' || s[i] == '[') g[i][j] = "[]";
		else g[i][j] = "()";
		return 1;
	}
	if (i > j) {
		g[i][j] = "";
		return 0;
	}
	int k, t;
	int ret(INF);
	if (s[i] == '(' && s[j] == ')') {
		t = gao(i+1, j-1);
		if (ret > t) {
			ret = t;
			g[i][j] = '(' + g[i+1][j-1] + ')';
		}
	}
	if (s[i] == '[' && s[j] == ']') {
		t = gao(i+1, j-1);
		if (ret > t) {
			ret = t;
			g[i][j] = '[' + g[i+1][j-1] + ']';
		}
	}
	if (s[i] == '(' || s[i] == '[') {
		t = gao(i+1, j);
		if (ret > t + 1) {
			ret = t + 1;
			g[i][j] = (s[i] == '(' ? "()" : "[]") + g[i+1][j];
		}
	}
	if (s[j] == ')' || s[j] == ']') {
		t = gao(i, j-1);
		if (ret > t + 1) {
			ret = t + 1;
			g[i][j] = g[i][j-1] + (s[j] == ')' ? "()" : "[]");
		}
	}
	for (k=i; k<j; ++k) {
		t = gao(i, k) + gao(k+1, j);
		if (ret > t) {
			ret = t;
			g[i][j] = g[i][k] + g[k+1][j];
		}
	}
	return f[i][j] = ret;
}

int main() {
	int i, j, k;
	int m, n;
	int tc;

	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	gets(buff);
	gets(buff);
	while (tc--) {
		gets(s);
		if (s[0] == '\0') {
			puts("");
		} else {
			memset(f, -1, sizeof(f));
			m = gao(0, k=strlen(s)-1);
			//printf("%d\n", m);
			puts(g[0][k].c_str());
		}
		if (tc == 0) break;
		puts("");
		gets(buff);
	}
	return 0;
}