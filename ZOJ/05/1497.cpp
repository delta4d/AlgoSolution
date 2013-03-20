#include <cstdio>
using namespace std;

const int MAXN = 30;

int d[MAXN];
bool visit[MAXN];

int main() {
	int i, j, k;
	int n, m;
	int pre, cur;
	int cnt, rem;
	int temp;
	char buff[2];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		scanf("%d", &k);
		for (i=0; i<n; ++i) {
			scanf("%s", buff);
			d[i] = buff[0] == 'L' ? -1 : 1;
		}
		pre = 0, cur = (k - 1 + n) % n, cnt = 1, rem = n - 1;
		for (i=0; i<n; visit[i++]=false);
		visit[cur] = true;
		while (rem > 0) {
			if (pre == (cur + n - 1) % n && d[cur] == 1) {
				d[cur] *= -1;
				temp = cur;
				cur = (cur + 1) % n;
				pre = temp;
			} else if (pre == (cur + 1) % n && d[cur] == -1) {
				d[cur] *= -1;
				temp = cur;
				cur = (cur + n - 1) % n;
				pre = temp;
			} else {
				temp = cur;
				cur = (pre + d[cur] + n) % n;
				pre = temp;
				d[pre] *= -1;
			}
			if (!visit[cur]) visit[cur] = true, --rem;
			++cnt;
		}
		printf("Classmate %d got the ball last after %d tosses.\n", cur+1, cnt);
		scanf("%d", &n);
	}
	return 0;
}