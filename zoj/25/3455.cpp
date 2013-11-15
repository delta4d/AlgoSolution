#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500001;
const int MAXL = 100;

class node {
public:
	char s[MAXN];
	int cnt[MAXL];
	int ccnt[MAXN];
	
	bool __input() {
		return scanf("%s", s) == 1;
	}
	
	void __init(const int len) {
		int i, j, k;
		memset(cnt, 0, sizeof(cnt));
		memset(ccnt, 0, sizeof(ccnt));
		for (i=0; i<len; ++i) ++cnt[s[i]-'!'];
		for (i=0; i<MAXL; ++i) ++ccnt[cnt[i]];
	}
	
	int __length() {
		return strlen(s);
	}
	
	int __at(const int k) {
		return s[k] - '!';
	}
	
	void __insert(const int x) {
		--ccnt[cnt[x]];
		++cnt[x];
		++ccnt[cnt[x]];
	}
	
	void __delete(const int x) {
		--ccnt[cnt[x]];
		--cnt[x];
		++ccnt[cnt[x]];
	}
	
	bool __match(const node &a) {
		int i, j, k;
		for (i=0; i<MAXL; ++i) {
			if (a.cnt[i] == 0) continue;
			if (ccnt[cnt[i]] != a.ccnt[a.cnt[i]]) return false;
		}
		return true;
	}
	
	void __output(const node &a, const int src, const int dst) {
		int i, j, k(0);
		int temp[MAXL];
		for (i=src; i<dst; ++i) if (s[i] != a.s[i-src]) temp[k++] = i;
		for (i=0; i<k; ++i) printf("%s%d", i?" ":"", temp[i]);
		puts("");
	}
};

int main() {
	int i, j, k;
	int len1, len2, len;
	int s, t;
	node a, b;
	freopen("f:\\in.txt", "r", stdin);
	while (a.__input() && b.__input()) {
		len1 = a.__length();
		len2 = b.__length();
		a.__init(len2);
		b.__init(len2);
		len = len1 - len2;
		for (i=0; i<len; ++i) {
			if (a.__match(b)) break;
			a.__insert(a.__at(i+len2));
			a.__delete(a.__at(i));
		}
		if (i == len) {
			puts("No");
		} else {
			puts("Yes");
			a.__output(b, i, i+len2);
		}
	}
	return 0;
}