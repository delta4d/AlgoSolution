#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

map <int, int> mp;
vector <int> cc;

int main() {
	int n, m, k;
	int x;

	scanf("%d%d%d", &n, &m, &k);
	for (int i=0; i<n; ++i) {
		scanf("%d", &x);
		++mp[x];
	}
	for (int i=0; i<m; ++i) {
		scanf("%d", &x);
		--mp[x];
	}
	for (map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it) cc.push_back(it->second);	
	int cnt = 0;
	for (int i=cc.size()-1; i>=0; --i) {
		cnt += cc[i];	
		if (cnt > 0) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");

	return 0;
}

// 3566425	 Apr 19, 2013 7:49:54 PM	delta_4d	 B - Fish Weight	 GNU C++	Accepted	 218 ms	 8500 KB
