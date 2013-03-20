#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 20000;

struct bignum {
	int num[MAXL];
	int len;
	
	void set_inf() {
		for (int i=0; i<MAXL; ++i) num[i] = 9;
		len = MAXL;
	}
	void set_void() {
		len = 0;
	}
	bool less(const bignum &a) {
		int i, j, k;
		if (len < a.len) return true;
		if (len > a.len) return false;
		for (i=len-1; i>=0; --i) {
			if (num[i] < a.num[i]) return true;
			if (num[i] > a.num[i]) return false;
		}
		return false;
	}
	void output() {
		for (int i=len-1; i>=0; --i) printf("%d", num[i]);
		puts("");
	}
} c, r;

bool visit[10][MAXL];

int main() {
	int tc;
	int i, j, k;
	int p, t;
	int cbit, carry;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &k);
		r.set_inf();
		c.set_void();
		for (i=1; i<10; ++i) {
			cbit = i, carry = 0, p = 0;
			memset(visit, false, sizeof(visit));
			while (!visit[cbit][carry]) {
				visit[cbit][carry] = true;
				t = cbit * k + carry;
				cbit = t % 10, carry = t / 10;
				c.num[p++] = cbit;
			}
			if (cbit == i && carry == 0) c.len = p;
			else continue;
			if (c.less(r)) r = c;
		}
		r.output();
		if (tc) puts("");
	}
	return 0;
}