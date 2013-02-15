#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 21;

char in[MAXL], out[MAXL];
char op[MAXL];

void gao(int src, int dst, int &cnt) {
	int i, j, k;
	int m, n;
	if (src >= dst) {
		out[src] = '\0';
		return;
	}
	if (in[src] == '0') {
		strcpy(out+src, in+src);
		return;
	} else if (in[src] >= 'A' && in[src] <= 'Z') {
		++cnt;
		n = cnt;
		gao(src+1, dst, cnt);
		out[src] = ((cnt - n) % 10) + '0'; 
	} else if (in[src] >= '1' && in[src] <= '9') {
		++cnt;
		k = in[src] - '0';
		out[src] = in[src] - 1;
		if (src + k >= dst) k = 1;
		for (i=0; i<k&&src+1+i<dst; ++i) out[src+1+i] = in[src+1+i];
		gao(src+k, dst, cnt);
	} else {
		throw "gao() error !!!!!!!!!!!!!";
	}
}

int main() {
	int i, j, k;
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%s", op);
	while (strcmp(op, "ENDOFINPUT") != 0) {
		scanf("%d %s %*s", &n, in);
		k = 0;
		gao(0, strlen(in), k);
		puts(out);
		scanf("%s", op);
	}
	return 0;
}