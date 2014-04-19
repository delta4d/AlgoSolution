#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[26*26*26 + 10], st, ed;
char buf[30], s1[30], s2[30], s3[30];
queue <int> q;

inline int v(int a, int b, int c) {
	return (a * 26 + b) * 26 + c;
}

inline int r() {
	scanf("%s", buf);
	return v(buf[0]-'a', buf[1]-'a', buf[2]-'a');
}

inline void fb() {
	scanf("%s%s%s", s1, s2, s3);
	for (int i=0; s1[i]; ++i) for (int j=0; s2[j]; ++j) for (int k=0; s3[k]; ++k) {
		f[v(s1[i]-'a', s2[j]-'a', s3[k]-'a')] = -2;
	}
}

int bfs() {
	if (f[st] == -2 || f[ed] == -2) return -1;
	while (!q.empty()) q.pop();
	q.push(st);
	f[st] = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (t == ed) return f[t];
		int x[] = {t / 26 / 26, (t % (26 * 26)) / 26, t % 26};
		for (int i=0; i<3; ++i) {
			x[i] = (x[i] + 1) % 26;
			int cc = v(x[0], x[1], x[2]);
			if (f[cc] == -1) f[cc] = f[t] + 1, q.push(cc);
			x[i] = (x[i] + 24) % 26;
			cc = v(x[0], x[1], x[2]);
			if (f[cc] == -1) f[cc] = f[t] + 1, q.push(cc);
			x[i] = (x[i] + 1) % 26;
		}
	}
	return -1;
}

int main() {
	int tc, cn = 0, m;
	for (scanf("%d", &tc); tc--; ) {
		st = r(), ed = r();
		memset(f, -1, sizeof(f));
		for (scanf("%d", &m); m--; ) fb();
		printf("Case %d: %d\n", ++cn, bfs());
	}
	return 0;
}

// 307454	2014-01-04 22:37:20	 1039 - A Toy Company	 C++	 0.008	 1316	Accepted
