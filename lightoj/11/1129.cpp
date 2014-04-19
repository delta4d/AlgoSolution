/**
#include <set>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

set <string> st;
string s[10000 + 86];

int main() {
	ios_base::sync_with_stdio(false);
	int tc, cn = 0, n;
	for (cin>>tc; tc--; ) {
		st.clear();
		cin >> n;
		for (int i=0; i<n; ++i) {
			cin >> s[i];
			st.insert(s[i]);
		}
		bool ok = true;
		for (int i=0; ok&&i<n; ++i) {
			st.erase(s[i]);
			int len = s[i].length();
			for (int k=0; ok&&k<len; ++k) {
				if (st.find(s[i].substr(0, k+1)) != st.end()) ok = false;
			}
			st.insert(s[i]);
		}
		printf("Case %d: %s\n", ++cn, ok?"YES":"NO");
	}
	return 0;
}

// 296842	2013-12-08 21:28:32	 1129 - Consistency Checker	 C++	 0.988	 2820	Accepted
**/

#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Trie {
	map <char, Trie> node;

	void clear() { node.clear(); }
	bool empty() { return node.empty(); }
	int size() { return node.size(); }
	void insert(char s[], int c) {
		if (s[c] == '\0') return;
		node[s[c]].insert(s, c+1);
	}
	bool pre(char s[], int c) {
		if (s[c+1] == '\0') return !node[s[c]].empty();
		return node[s[c]].pre(s, c+1);
	}
} T;
char s[10000 +86][12];

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		T.clear();
		bool ok = true;
		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			scanf("%s", s[i]);
			T.insert(s[i], 0);
		}
		for (int i=0; ok&&i<n; ++i) ok = ok && !T.pre(s[i], 0);
		printf("Case %d: %s\n", ++cn, ok?"YES":"NO");
	}
	return 0;
}

// 296850	2013-12-08 22:02:26	 1129 - Consistency Checker	 C++	 0.796	 6484	Accepted
