#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MAXN = 1000086;

int euler[MAXN + 1], plist[MAXN + 1];
LL f[MAXN+1];

int doEuler(int n = MAXN) {
    int num = 0;
    memset(euler, 0, sizeof(euler));
    euler[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!euler[i]) plist[num++] = i, euler[i] = i - 1;
        for (int j = 0; j < num && i * plist[j] <= n; j++) {
            if (i % plist[j] == 0)
                euler[i * plist[j]] = euler[i] * plist[j];
            else
                euler[i * plist[j]] = euler[i] * (plist[j] - 1);
            if (i % plist[j] == 0) break;
        }
    }
    return num;
}

void init() {
	int i, j, k;
	
	doEuler();
	for (i=2; i<MAXN; ++i) {
		f[i] = f[i-1] + euler[i];
	}
}

int main() {
	int i, j, k;
	int m, n;
	LL tot;

	init();
	while (scanf("%d", &n), n) {
		printf("%lld\n", f[n]);
	}
	return 0;
}