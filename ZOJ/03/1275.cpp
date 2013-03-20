#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10000000;
const int MAXL = 10000;
int f[MAXL];
int fp;

bool judge_suc(int n) {
	int i, j, k;
	int curr;
	int len;
	char buff[10];
	bool visit[10];
	
	sprintf(buff, "%d", n);
	memset(visit, false, sizeof(visit));
	
	for (i=0; buff[i]; ++i) {
		k = buff[i] - '0';
		if (visit[k]) return false;
		visit[k] = true;
	}
	memset(visit, false, sizeof(visit));
	len = strlen(buff);
	curr = 0;
	for (i=0; i<len; ++i) {
		if (visit[curr]) break;
		visit[curr] = true;
		k = buff[curr] - '0';
		curr = (curr + k) % len;
	}
	return i == len && curr == 0;
}

void gen() {
	int i, j, k;
	for (i=10; i<MAXN; ++i) {
		if (judge_suc(i)) f[fp++] = i;		
	}
	--fp;	
}

int gao(const int n) {
	int i, j, k;
	int left, right, mid;
	left = 0, right = fp;
	mid = (left + right) >> 1;
	while (left <= right) {
		if (n > f[mid]) left = mid + 1;
		else right = mid - 1;
		mid = (left + right) >> 1;
	}
	return f[left];
}

int main() {
	int i, j, k;
	int n, cn(0);
	gen();
	freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	while (n != 0) {
		printf("Case %d: %d\n", ++cn, gao(n));
		scanf("%d", &n);
	}
	return 0;
}