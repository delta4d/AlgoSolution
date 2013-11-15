#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 16;
LL res[17];

bool legal(LL x, int base) {
	int buff[80], k(0);
	do {
		buff[k++] = x % base;
		x /= base;
	} while (x != 0);
	for (int i=0; i<k-1; ++i) if (buff[i] >= buff[i+1]) return false;
	return true;
}

bool prime(LL x) {
	for (int i=2; i*i<=x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}

LL reverse(LL x) {
	LL y(0);
	do {
		y = y * 10 + (x % 10);
		x /= 10;
	} while (x != 0);
}

int gen() {
	LL x = 0x7fffffffffffffffll, y;
	int i, j, k;
	int base;
	int cnt(MAXN-1);
	//printf("%lld\n", x);
	memset(res, -1, sizeof(res));
	while (cnt) {
		for (base=MAXN; base>=2; --base) {
			if (res[base] > 0) continue;
			if (legal(x, base)) {
				y = reverse(x);
				if (legal(y, base) && prime(y) && prime(x)) res[base] = x, --cnt;
			}
		}
		--x;
	}
}

void print_base(LL x, int base) {
	int buff[80], k(0);
	do {
		buff[k++] = x % base;
		x /= base;
	} while (x);
	for (int i=k-1; i>=0; --i) printf("%c", buff[i]<10?buff[i]+'0':buff[i]+'A'-10);
	printf(", ");
}

int main() {
	freopen("out", "w", stdout);
	gen();
	for (int i=2; i<=MAXN; ++i) print_base(res[i], i);
	return 0;
}