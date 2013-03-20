#include <map>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

map<string, int> db;
vector<pair<string, int> > f;

inline bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	char buff[81], word[3];
	int i, j, k;
	int m, n;
	int sum;
	string s;
	map<string, int>::iterator it;
	//freopen("f:\\in.txt", "r", stdin);
	word[2] = '\0';
	while (scanf("%d", &n), n) {
		db.clear();
		getchar();
		s.clear();
		for (i=0; i<n; ++i) {
			gets(buff);
			s += string(buff);
		}
		for (i=0; s[i+1]; ++i) {
			word[0] = s[i], word[1] = s[i+1];
			string w(word);
			if (db.find(w) == db.end()) db[w] = 1;
			else ++db[w];
		}
		sum = 0;
		f.clear();
		for (it=db.begin(); it!=db.end(); ++it) {
			sum += (it->second);
			f.push_back(*it);
		}
		sort(f.begin(), f.end(), cmp);
		for (k=0; k<5; ++k) {
			printf("%s %d %.6lf\n", f[k].first.c_str(), f[k].second, double(f[k].second)/sum);
		}
		puts("");
	}
	return 0;
}