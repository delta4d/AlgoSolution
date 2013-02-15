#include <cstdio>
#include <memory>
using namespace std;

const int MAXL = 128;
char buff1[MAXL];
char buff2[MAXL];

inline int tran(char *a) {
	int len(strlen(a));
	int res(0);
	a += len>3?len-3:0;
	while (*a) {
		res *= 10;
		res += *a - '0';
		++a;
	}
	return res;
}

int main() {
	int x, y;
	int res;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s %s", buff1, buff2) != EOF) {
		x = tran(buff1);
		y = tran(buff2);
		res = (x * y) % 8;
		if (res > 4) res -= 4;
		if (!strcmp(buff1, "1")|| !strcmp(buff2, "1")) printf("%s\n", !strcmp(buff1, "1")?buff2:buff1);
		else if(res) printf("%d\n", res);
		else printf("Yes\n");
	}
	return 0;
}
