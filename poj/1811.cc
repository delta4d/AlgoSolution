#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

// 求出最大公约数
ULL gcd(ULL A, ULL B) {
	while (A != 0LL) {
		ULL C = B % A;
		B = A;
		A = C;
	}
	return B;
}

// 求a*b%c，要求:a,b的范围在ULL范围的一般以内, 在ULL为unsigned __int64时, a,b需要是__int64能表示的数
ULL productMod(ULL a, ULL b, ULL c) {
	ULL ret = 0LL;
	for (ULL add = a; b > 0LL; b >>= 1) {
		if (b & 1LL) ret = (ret + add) % c;
		add = (add << 1) % c;
	}
	return ret;
}

// 求a^b%c，要求: a,b的范围在ULL范围的一般以内, 在ULL为unsigned __int64时, a,b需要是__int64能表示的数
ULL powerMod(ULL a, ULL b, ULL c) {
	ULL ret = 1LL;
	for (ULL mul = a; b > 0LL; b >>= 1) {
		if (b & 1LL) ret = productMod(ret, mul, c);
		mul = productMod(mul, mul, c);
	}
	return ret;
}

// rabinmiller方法测试n是否为质数
const int MAXPRIME = 10;
const int PRIME[MAXPRIME] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

bool millerRabin(ULL n) {
	if (n < 2LL) return false;
	if (n == 2LL) return true;
	if((n & 1LL) == 0LL) return false;
	ULL k = 0, m, a; 
	m = n - 1; 
	while ((m & 1LL) == 0LL) {
		m >>= 1;
		k++; 
	}
	for (int i = 0; i < MAXPRIME; i++) {
		if (PRIME[i] >= n) return true;
		a = powerMod((ULL)PRIME[i], m, n); 
		if (a == 1LL) continue;
		int j = 0;
		for (; j < k; j++) {
			if (a == n - 1LL) break;
			a = productMod(a, a, n); 
		}
		if (j < k) continue;
		return false;
	} 
	return true; 
} 

// pollard_rho分解，给出N的一个非1因数，返回N时为一次没有找到
ULL pollardRho(ULL c, ULL n) {
	int i = 1;
	ULL x = rand() % n, y = x, k = 2LL;
	do {
		i++;
		ULL d = gcd(n + y - x, n);
		if (d != 1LL && d != n) return d;
		if (i == k) {
			y = x;
			k <<= 1;
		}
		x = (productMod(x, x, n) + n - c) % n;
	} while (x != y);
	return n;
}

// 找出N的最小质因数
ULL rho(ULL n) {
	if (millerRabin(n)) return n;
	while (true) {
		ULL fac = pollardRho(rand() % (n - 1) + 1, n);
		if (fac < n) {
			ULL a = rho(fac), b = rho(n / fac);
			if (a < b) return a;
			return b;
		}
	}
}

int main() {
	int tc;
	ULL x;
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%llu", &x);
		if (millerRabin(x)) puts("Prime");
		else printf("%llu\n", rho(x));
	}
	return 0;
}