#include <cstdio>
using namespace std;

int p[1000], h, t;
char op[20];

int main() {
	int tc, cn = 0, n, m, x;
	for (scanf("%d", &tc); tc--; ) {
		printf("Case %d:\n", ++cn);
		scanf("%d%d", &n, &m);
		h = t = 500;
		while (m--) {
			scanf("%s", op);
			if (op[1] == 'u') {
				scanf("%d", &x);
				if (op[4] == 'L') {
					if (t - h == n) {
						puts("The queue is full");
					} else {
						p[h--] = x;
						printf("Pushed in left: %d\n", x);
					}
				} else {
					if (t - h == n) {
						puts("The queue is full");
					} else {
						p[++t] = x;
						printf("Pushed in right: %d\n", x);
					}
				}
			} else {
				if (op[3] == 'L') {
					if (t - h == 0) {
						puts("The queue is empty");
					} else {
						printf("Popped from left: %d\n", p[++h]);
					}
				} else {
					if (t - h == 0) {
						puts("The queue is empty");
					} else {
						printf("Popped from right: %d\n", p[t--]);
					}
				}
			}
		}
	}
	return 0;
}

// 252599	2013-08-17 20:11:18	 1212 - Double Ended Queue	 C++	 0.000	 1092	Accepted
