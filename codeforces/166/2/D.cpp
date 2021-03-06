#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long LL;
const int MAXN = 1500 + 86;
const LL SEED = 0x7FFFFFFFFFFFE7ll;

set <LL> h;
char s[MAXN], v[32];
int k;

int main() {
	scanf("%s%s%d", s, v, &k);	
	for (int i=0; s[i]; ++i) {
		LL hh = 0;
		for (int j=0,b=0; s[i+j]; ++j) {
			if (v[s[i+j]-'a'] == '0') ++b;
			if (b > k) break;
			hh = hh * SEED + s[i+j];
			h.insert(hh);	
		}
	}
	printf("%d\n", h.size());
	return 0;
}

// 3475592	 Apr 5, 2013 11:10:15 AM	delta_4d	 271D - Good Substrings	 GNU C++	Accepted	1078 ms	35300 KB
