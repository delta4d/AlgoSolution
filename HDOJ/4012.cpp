#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

queue <pair<int, int> > q;
int n;
bool visit[1<<16];
char s[16];

int gao() {
	int i, j, k;
	int state, step;
	int next;
	int final = (1 << (n << 1)) - 1;
	
	while (!q.empty()) q.pop();
	memset(visit, false, sizeof(visit));
	q.push(make_pair(0, 0));
	visit[0] = true;
	while (!q.empty()) {
		state = q.front().first, step = q.front().second;
		q.pop();
		if (state == final) return step;
		for (i=0; i<(n<<1); ++i) {
			if (state & (1 << i)) continue;
			if (i < n) {
				// single
				next = 0;
				for (j=i; j<n; ++j) { // to right
					if (state & (1 << j)) break;
					if (s[j] == s[i]) next |= (1 << j);
				}
				for (j=i-1; j>=0; --j) { // to left
					if (state & (1 << j)) break;
					if (s[j] == s[i]) next |= (1 << j);
				}
				for (j=next; j; j=next&(j-1)) {
					if (visit[j|state]) continue;
					visit[j|state] = true;
					q.push(make_pair(j|state, step+1));
				}
				// double
				next = 0;
				for (j=i; j<n; ++j) { // to right
					if ((state & (1 << j)) || (state & (1 << (j + n)))) break;
					if (s[j] == s[i]) next |= (1 << j);
					if (s[j+n] == s[i]) next |= (1 << (j + n));
				}
				for (j=i-1; j>=0; --j) { // to left
					if ((state & (1 << j)) || (state & (1 << (j + n)))) break;
					if (s[j] == s[i]) next |= (1 << j);
					if (s[j+n] == s[i]) next |= (1 << (j + n));
				}
				for (j=next; j; j=next&(j-1)) {
					if (visit[j|state]) continue;
					visit[j|state] = true;
					q.push(make_pair(j|state, step+1));
				}
			} else {
				// single
				next = 0;
				for (j=i; j<(n<<1); ++j) { // to right
					if (state & (1 << j)) break;
					if (s[j] == s[i]) next |= (1 << j);
				}
				for (j=i-1; j>=n; --j) { // to left
					if (state & (1 << j)) break;
					if (s[j] == s[i]) next |= (1 << j);
				}
				for (j=next; j; j=next&(j-1)) {
					if (visit[j|state]) continue;
					visit[j|state] = true;
					q.push(make_pair(j|state, step+1));
				}
			}
		}
	}
	throw "gao() error !";
}

int main() {
	int i, j, k;
	int tc, cn(0);
	
//	freopen("in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		scanf("%s%s", s, s+n);
		printf("Case #%d: %d\n", ++cn, gao());
	}
	return 0;
}