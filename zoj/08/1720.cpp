#include <cstdio>
using namespace std;

const int MAXN = 9;
int coff[MAXN];

void gao() {
	int i, j, k;
	int s, t;
	for (t=0; t<MAXN&&coff[t]==0; ++t);
	for (s=MAXN-1; s>=0&&coff[s]==0; --s);
	if (t == MAXN) {
		printf("0\n");
		return;
	}
	if (s == t && s == 0) {
		printf("%d\n", coff[s]);
		return;
	}
	
	if (s != 1) {
		if (coff[s] == 1) printf("x^%d", s);
		else if (coff[s] == -1) printf("-x^%d", s);
		else printf("%dx^%d", coff[s], s);
	} else {
		if (coff[s] == 1) printf("x");
		else if (coff[s] == -1) printf("-x");
		else printf("%dx", coff[s]);
	}
	
	for (i=s-1; i>=t; --i) {
		if (coff[i] == 0) continue;
		if (i == 1) {
			if (coff[i] == 1) printf(" + x");
			else if (coff[i] == -1) printf(" - x");
			else if (coff[i] > 0) printf(" + %dx", coff[i]);
			else if (coff[i] < 0) printf(" - %dx", -coff[i]);
			else throw "bei ju !";
			continue;
		}
		if (i == 0) {
			if (coff[i] > 0) printf(" + %d", coff[i]);
			else if (coff[i] < 0) printf(" - %d", -coff[i]);
			else throw "bei ju !";
			continue;
		}
		if (coff[i] == 1) printf(" + x^%d", i);
		else if (coff[i] == -1) printf(" - x^%d", i);
		else if (coff[i] > 0) printf(" + %dx^%d", coff[i], i);
		else if (coff[i] < 0) printf(" - %dx^%d", -coff[i], i);
		else throw "bei ju !";
	}
	puts("");
	return;
}

inline bool input() {
	int i;
	for (i=MAXN-1; i>=0; --i) {
		if (scanf("%d", coff+i) == EOF) return false;
	}
	return true;
}

int main() {
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (input()) gao();
	return 0;
}
