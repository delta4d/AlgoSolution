#include <deque>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000086;

int x[MAXN];
deque <int> q;

int main() {
	int i, j, k;
	int m, n;
	int tt;
	
	//freopen("in.txt", "r", stdin);
	while (2 == scanf("%d %d", &n, &m)) {
		for (i=0; i<n; ++i) scanf("%d", x+i);
		while (!q.empty()) q.pop_back();
		for (i=0; i<n; ++i) {
			if (q.empty()) {
				q.push_back(i);
			} else {
				while (!q.empty() && x[q.back()] >= x[i]) q.pop_back();
				q.push_back(i);
			}
			while (q.front() < i - m + 1 && !q.empty()) q.pop_front();
			if (i >= m - 1) printf("%d%s", x[q.front()], i==n-1?"\n":" ");
		}
		
		while (!q.empty()) q.pop_back();
		for (i=0; i<n; ++i) {
			if (q.empty()) {
				q.push_back(i);
			} else {
				while (!q.empty() && x[q.back()] <= x[i]) q.pop_back();
				q.push_back(i);
			}
			while (q.front() < i - m + 1 && !q.empty()) q.pop_front();
			if (i >= m - 1) printf("%d%s", x[q.front()], i==n-1?"\n":" ");
		}
	}
	return 0;
}