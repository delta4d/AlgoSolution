#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 86;

char s[MAXN];

struct bignum {
	char num[MAXN];
	int len;

	void flip() {
		for (int i=0; i*2<len; ++i) swap(num[i], num[len-1-i]);
	}

	void init(char s[], int len) {
		this->len = len;
		for (int i=0; i<len; ++i) num[i] = s[i];
		num[len] = '0';
		flip();
	}

	void next() {
		++num[0];
		for (int i=0; i<len&&num[i]>'9'; ++i) {
			num[i+1] += (num[i] - '0') / 10;
			num[i] = (num[i] - '0') % 10 + '0';
		}
		if (num[len] > '0') num[++len] = '0';
	}

	bool lt(const bignum &a) {
		for (int i=len-1; i>=0; --i) if (num[i] != a.num[i]) return num[i] < a.num[i];
		return false;
	}

	void to_s() {
		for (int i=len-1; i>=0; --i) printf("%c", num[i]);
	}
} x, y, xx;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", s);
		printf("Case %d: ", ++cn);
		int len = strlen(s), l = (len + 1) >> 1;
		x.init(s, l);
		y.init(s+len-l, l);
		xx.init(s, l);
		xx.flip();
		if (y.lt(xx)) {
			if (len & 1) --xx.len;
		} else {
			x.next();
			int c = len;
			if (x.len > l) {
				++c;
				if (2 * x.len - c > 1) {
					x.flip();
					--x.len;
					x.flip();
				}
			}
			xx = x;
			xx.flip();
			if (c & 1) --xx.len;
		}
		x.to_s();
		xx.to_s();
		puts("");
	}
	return 0;
}

// 277044	2013-10-23 01:20:55	 1396 - Palindromic Numbers (III)	 C++	 0.104	 1480	Accepted
