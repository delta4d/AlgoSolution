#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5;
const int MAXL = 4;

struct node {
	int x;
	char c;
	void print() {
		if (x >= 2 && x <= 10) printf("%d", x);
		else if (x == 1) printf("A");
		else if (x == 11) printf("J");
		else if (x == 12) printf("Q");
		else printf("K");
		printf("%c", c);
	}
} f[MAXN];
char buff[MAXL];
bool gaoding;
bool visit[MAXN];
int out[MAXN];
int cn;

inline bool cmp(const node &a, const node &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.c < b.c;
}

inline int tran(const char c) {
	if (c >= '2' && c <= '9') return c - '0';
	if (c == 'A') return 1;
	if (c == 'J') return 11;
	if (c == 'Q') return 12;
	return 13;
}

inline bool suc() {
	int i, j, k(2);
	int x(f[out[1]].x);
	char c(f[out[1]].c);
	for (i=3; i<5; ++i) {
		if (!cmp(f[out[k]], f[out[i]])) k = i;
	}
	x += k - 1;
	if (k == 2) i = 3, j = 4;
	else if (k == 3) i = 2, j = 4;
	else i = 2, j = 3;
	if (!cmp(f[out[i]], f[out[j]])) x += 3;
	x %= 13;
	if (x == 0) x = 13;
	if (x == f[out[0]].x && c == f[out[0]].c) return true;
	return false;
}

void dfs(int d) {
	int i, j, k;
	if (d == 5) {
		if (suc()) {
			gaoding = true;
			printf("Problem %d: ", ++cn);
			for (i=0; i<4; ++i) {
				f[out[i]].print();
				printf(" ");
			}
			f[out[i]].print();
			puts("");
		}
		return;
	}
	for (i=0; i<5; ++i) {
		if (!visit[i]) {
			if (d == 1) {
				if (f[i].c != f[out[0]].c) continue;
			}
			visit[i] = true;
			out[d] = i;
			dfs(d+1);
			if (gaoding) return;
			visit[i] = false;
		}
	}
}

void gao() {
	int i, j, k;
	gaoding = false;
	memset(visit, false, sizeof(visit));
	dfs(0);
}

int main() {
	int i, j, k;
	int tc, len;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		for (i=0; i<5; ++i) {
			scanf("%s", buff);
			len = strlen(buff);
			if (len == 2) {
				f[i].x = tran(buff[0]);
			} else {
				f[i].x = 10;
			}
			f[i].c = buff[len-1];
		}
		sort(f, f+5, cmp);
		gao();
	}
	return 0;
}