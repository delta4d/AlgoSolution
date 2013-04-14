#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, tc;
	char s[26];

	scanf("%d", &tc);
	while (tc--) {
		int cc[26];
		fill(cc, cc+26, 0x3f3f3f3f);
		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			scanf("%s", s);	
			int cnt[26]={0};
			for (int k=0; s[k]; ++k) ++cnt[s[k]-'A'];
			for (int k=0; k<26; ++k) cc[k] = min(cc[k], cnt[k]);
		}
		for (int i=0; i<26; ++i) for (int j=0; j<cc[i]; ++j) printf("%c", i+'A');
		puts("");
	}

	return 0;
}
