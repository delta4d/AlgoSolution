#include <cstdio>
#include <vector>
#include <memory>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<int>::iterator VII;
VI prime, catalan;
int n;

void gao(VI &factor, int tot) {
	int i, j;
	int n((tot<<1)-2), m(tot-1);
	LL res(1);
	LL temp(1);
	VII it;
	for (i=0; i<m; ++i) res = res * (n - i) / (i + 1);
	res /= tot;
	for (it=factor.begin(); it!=factor.end(); ++it) {
		for (i=1; i<=(*it); ++i) {
			temp = temp * tot / i;
			--tot;
		}
	}
	res *= temp;
	printf("%lld\n", res);
}

void gao() {
	int i, j;
	int cnt(0), tot(0);
	int t(n);
	VII it;
	VI factor;
	for (it=prime.begin(); (*it)*(*it)<=t; ++it) {
		if (t % (*it) == 0) {
			cnt = 0;
			while (t % (*it) == 0) {
				t /= *it;
				++cnt;
			}
			tot += cnt;
			factor.push_back(cnt);
		}	
	}
	if (t != 1) {
		factor.push_back(1);
		++tot;
	}
	gao(factor, tot);
}

void gen() {
	int i, j;
	const int MAX = 1 << 15 + 1;
	bool is_prime[MAX];
	//generate prime numbers
	memset(is_prime, true, sizeof(is_prime));
	for (i=2; i<MAX; ++i) {
		for (j=2; i*j<MAX; ++j) is_prime[i*j] = false;
	}
	for (i=2; i<MAX; ++i)
		if (is_prime[i]) prime.push_back(i);
	//for (VII it=prime.begin(); it!=prime.end(); ++it) printf("%d ", *it);
}

int main() {
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	gen();
	while (scanf("%d", &n) != EOF) gao();
	return 0;
}
