#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MOD = 1000000007;
const int MAXN = 100000 + 86;

char s[MAXN], t[MAXN];

inline int add(int a, int b) {
	if (b < 0) b += MOD;
	a += b;
	return a >= MOD ? a - MOD : a;
}

inline int mul(int a, int b) {
	return (LL)a * (LL)b % MOD;
}

int gao(char s[]) {
	int F[2]={0}, K[2]={1}, S[2]={0}, T[2]={0}, AK[2]={0}, A1[2]={0};	
	int cur = 0, nxt = 0;
	
	for (int i=0; s[i]; ++i, cur=nxt) {
		nxt = cur ^ 1;	
		F[nxt] = add(mul(add(F[cur], T[cur]), 100), mul(S[cur], 220));
		F[nxt] = add(add(F[nxt], mul(56, K[cur]-1)), mul(70, AK[cur]-A1[cur]));
		K[nxt] = mul(K[cur], 2);
		S[nxt] = add(mul(S[cur], 20), mul(K[cur]-1, 11));
		T[nxt] = add(add(mul(T[cur], 200), mul(S[cur], 220)), mul(K[cur]-1, 65));
		AK[nxt] = add(mul(AK[cur], 10), s[i]-'0');
		A1[nxt] = add(mul(A1[cur], 10), 4);
		if (s[i] == '7') {
			int t = mul(AK[cur], 10);
			F[nxt] = add(F[nxt], mul(t+4, t+7));	
			S[nxt] = add(S[nxt], t+4);
			T[nxt] = add(T[nxt], mul(t+4, t+4));
		} else {
			K[nxt] = add(K[nxt], -1);
		}
	}
	return F[nxt];
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> s >> t;
	cout << (gao(t) - gao(s) + MOD) % MOD << endl;

	return 0;
}

// 3473427	 Apr 4, 2013 6:41:47 PM	delta_4d	 288E - Polo the Penguin and Lucky Numbers	 GNU C++	Accepted	62 ms	200 KB
