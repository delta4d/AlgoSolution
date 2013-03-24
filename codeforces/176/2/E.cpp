#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;

bool v[MAXN];
int x[MAXN];
stack <int> q;

int main() {
	int n, t;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%d", x+i);
	scanf("%d", &t);
	for (int i=0; i<t; ++i) {
		int k;
		scanf("%d", &k);
		v[k-1] = true;
	}
	for (int i=n-1; i>=0; --i) {
		if (q.empty()) {
			q.push(i);
		} else {
			int cc = q.top();
			q.pop();
			if (!v[i] && x[i] == x[cc]) {
				x[cc] = -x[cc];
			} else {
				q.push(cc);
				q.push(i);
			}
		}
	}
	if (q.empty()) {
		puts("YES");
		for (int i=0; i<n; ++i) printf("%d%s", x[i], i==n-1?"\n":" ");
	} else {
		puts("NO");
	}

	return 0;
}

// 3395717	 Mar 23, 2013 7:43:38 PM	delta_4d	 286C - Main Sequence	 GNU C++	Accepted	812 ms	9300 KB
