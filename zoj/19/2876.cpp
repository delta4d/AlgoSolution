#include <set>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

set<string> prefix;
vector<string> plist;

int main() {
	int i, j, k;
	int n, m;
	int tc;
	char s[12], buff[12];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		prefix.clear();
		plist.clear();
		scanf("%d", &n);
		for (i=0; i<n; ++i) {
			scanf("%s", s);
			plist.push_back(string(s));
			k = strlen(s);
			for (j=0; j<k-1; ++j) {
				buff[j] = s[j];
				buff[j+1] = '\0';
				prefix.insert(string(buff));
			}
		}
		for (i=0; i<n; ++i) {
			if (prefix.find(plist[i]) != prefix.end()) break;
		}
		puts(i==n?"YES":"NO");
	}
	return 0;
}