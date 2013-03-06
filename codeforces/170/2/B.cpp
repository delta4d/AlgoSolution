#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const ULL SEED = 131;

set <ULL> st;

ULL h(char s[], int a, int b) {
	ULL ret(0);
	for (int i=a; i<=b; ++i) ret = ret * SEED + s[i];
	return ret;
}

int main() {
	char s[32];
	int n;
	
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		for (int i=0; s[i]; ++i) for (int j=i; s[j]; ++j) st.insert(h(s, i, j));
	}
//	for (set<ULL>::iterator it=st.begin(); it!=st.end(); ++it) cout << *it << ' '; cout << endl;
	int k = 0;
	memset(s, '\0', sizeof(s));
	s[0] = 'a';
	while (st.find(h(s, 0, k)) != st.end()) {
//		cout << "cccccc: " << h(s, 0, k) << endl;
//		puts(s);
		int re = 0, i;
		++s[k];
		for (i=k; i>=0; --i) {
			if (s[i] <= 'z') break;
			re = s[i] - 'a' - 25;
			s[i] -= 26;
			if (i > 0) s[i-1] += re;
		}
		if (i == -1) {
			for (int j=0; j<=k+1; ++j) s[j] = 'a';
			++k;
		}
	}
	puts(s);

	return 0;
}
