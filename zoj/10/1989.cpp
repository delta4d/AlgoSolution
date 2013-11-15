#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 30000;

struct node {
	int id;
	int salary;
	int height;
	int boss;
	int sub;
	void input() {
		scanf("%d %d %d", &id, &salary, &height);
		boss = 0;
		sub = 0;
	}
	void output() {
		printf("%d %d\n", boss, sub);
	}
} f[MAXN];

inline bool cmp(const node &a, const node &b) {
	return a.salary > b.salary;
}

int main() {
	int i, j, k;
	int m, n, q;
	int tc, id, cnt;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &q);
		for (i=0; i<n; f[i++].input());
		sort(f, f+n, cmp);
		for (i=n-1; i>=0; --i) for (j=i-1; j>=0; --j) {
			if (f[j].height >= f[i].height) {
				f[i].boss = f[j].id;
				f[j].sub += f[i].sub + 1;
				break;
			}
		}
		//for (i=0; i<n; printf("%d ", f[i++].salary));
		for (i=0; i<q; ++i) {
			scanf("%d", &id);
			for (j=0; j<n; ++j) if (f[j].id == id) break;
			f[j].output();
		}
	}
	return 0;
}