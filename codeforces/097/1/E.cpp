#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
const int MAXN = 1000086;

LL f[MAXN];
LL k, w;

LL expow(LL x, LL e) {
	LL ret(1);
	while (e) {
		if (e & 1) ret = ret * x % MOD;
		e >>= 1;
		x = x * x % MOD;
	}
	return ret;
}

LL ex_gcd(LL a,LL b,LL *x,LL *y) {
	LL r,ra,rb,aa=1,ab=0,ba=0,bb=1;
	while(b) {
		r=a%b,ra=aa-a/b*ba,rb=ab-a/b*bb;
		a=b,aa=ba,ab=bb;
		b=r,ba=ra,bb=rb;
	}
	*x=aa,*y=ab;
	return a;
}

LL rev(LL a,LL m) {
	LL x,y;
	ex_gcd(a,m,&x,&y);
	if (x<0) x+=m;
	return x;
}

LL A(LL n, LL m) {
	if (n == 0) return 1;
	return f[n] * rev(f[n-m], MOD) % MOD;
}

void init() {
	f[0] = 1;
	for (LL i=1; i<=k; ++i) f[i] = (f[i-1] * i) % MOD;
}

int main() {
	LL i, j;
	LL tot(0);
	LL s, t;
	LL cc;
	
//	freopen("in.txt", "r", stdin);
//	freopen("d:\\out.txt", "w", stdout);
	
	scanf("%I64d %I64d", &k, &w);
	if (w == 1) { puts("0"); return 0; }
	init();
	for (i=1; i<=k; ++i) {
		if (i == w) {
			cc = 2 * A(k, w) * w % MOD;
			cc = cc * A(k-1, w-1) % MOD;
			s = A(k-1, w-1);
			s = ((s * s % MOD)* (k % MOD)) % MOD;
			t = A(k-2, w-2);
			t = ((t * t % MOD) * ((w - 1) * (w - 1) % MOD)) % MOD;
			t = t * A(k, 2) % MOD;
			cc = (cc - s - t) % MOD;
			tot = (tot + cc) % MOD;
		} else if (i < w) {
			s = i * A(k-1, i-1) % MOD, t = A(k, i);
			cc = s * expow(k, w-i) % MOD;
			cc = cc * ((2 * t - s) % MOD) % MOD;
			tot = (tot + cc) % MOD;
		} else {
			cc = 2 * (A(k, i) * w % MOD) * A(k-i+w-1, w-1) % MOD;
			s = A(k-i+w-1, w-1);
			s = s * s % MOD;
			s = s * A(k, i-w+1) % MOD;
			t = (w - 1) * A(k-i+w-2, w-2) % MOD;
			t = t * t % MOD;
			t = t * A(k, i-w+2) % MOD;
			cc = (cc - s - t) % MOD;
			if (cc < 0) cc += MOD;
			tot = (tot + cc) % MOD;
		}
		if (tot < 0) tot += MOD;
//		printf("%I64d %I64d\n", i, tot);
	}
	printf("%I64d\n", tot);
	return 0;
}

// 952898	 Dec 12, 2011 5:55:18 PM	delta_4d	 E - Weak Subsequence	 GNU C++	Accepted	 2980 ms	 9200 KB
