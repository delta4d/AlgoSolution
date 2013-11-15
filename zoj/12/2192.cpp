#include <cstdio>
#include <cstring>
using namespace std;

int n, sum;
int p[26];
int w[5];
char s[20][3], msg[20];
bool find;

void dfs(int d) {
	int i, j, k;
	int src, dst;
	if (d == n) {
		find = true;
		return;
	}
	for (i=d; i<n; ++i) {
		src = p[s[i][0]-'A'], dst = p[s[i][1]-'A'];
		k = 0;
		for (j=src; j<=dst; ++j) {
			if (w[j] > 0) ++k;
		}
		if (k == 0) return;
	}
	src = p[s[d][0]-'A'], dst = p[s[d][1]-'A'];
	for (i=src; i<=dst; ++i) {
		if (w[i] >= 1) {
			--w[i];
			dfs(d+1);
			if (find) return;
			++w[i];
		}
	}
}

bool gao() {
	if (sum < n) return false;
	find = false;
	dfs(0);
	return find;
}

int main() {
	int i, j ,k ;
	//freopen("f:\\in.txt", "r", stdin);
	p['S'-'A'] = 0, p['M'-'A'] = 1, p['L'-'A'] = 2, p['X'-'A'] = 3, p['T'-'A'] = 4;
	scanf("%s", msg);
	while (strcmp(msg, "ENDOFINPUT") != 0) {
		scanf("%d", &n);
		for (i=0; i<n; ++i) scanf("%s", s[i]);
		sum = 0;
		for (i=0; i<5; ++i) {
			scanf("%d", w+i);
			sum += w[i];
		}
		scanf("%s", msg);
		printf("%s\n", gao()?"T-shirts rock!":"I'd rather not wear a shirt anyway...");
		scanf("%s", msg);
	}
	return 0;
}