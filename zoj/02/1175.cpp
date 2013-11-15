#include <cstdio>
#include <memory>
#include <cstring>
using namespace std;

const int MAXL = 40001;
char s[MAXL];
int main() {
	int i, j, k, t;
	int tc, n, len;
	int cnt;
	int front, rear;
	int select;
	char op;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=1; t<=tc; ++t) {
		scanf("%d", &n);
		getchar();
		gets(s);
		len = strlen(s);
		for (i=1; i<n; ++i) {
			gets(s+len);
			len = strlen(s);
		}
		op = getchar();
		select = 0;
		cnt = 0;
		front = 0, rear = strlen(s) - 1;
		while (op != '#') {
			if (op == 'G') {
				if (select == 0) {
					printf("%c", s[front]);
					++front;
				} else {
					printf("%c", s[rear]);
					--rear;
				}
				++cnt;
				if (cnt == 80) {
					puts("");
					cnt = 0;
				}
			} else if (op == 'R') {
				select ^= 1;
			}
			op = getchar();
		}
		if (cnt != 0) puts("");
		if (t != tc) puts("");
	}
	return 0;
}
