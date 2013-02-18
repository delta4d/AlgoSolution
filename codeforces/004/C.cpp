#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class database {
private:
	map <string, int> mp;
	
public:
	void init() {
		mp.clear();
	}
	void insert(const string &a) {
		if (mp.count(a)) {
			char sub[32];
			sprintf(sub, "%d", mp[a]);
			puts((a+sub).c_str());
			++mp[a];
		} else {
			++mp[a];
			puts("OK");
		}
	}
} db;

int main() {
	int i, j, k;
	int m, n;
	string name;
	
	scanf("%d", &n);
	while (n--) {
		cin >> name;
		db.insert(name);
	}
	return 0;
}

//#	When	Who	Problem	Lang	Verdict	Time	Memory
//911500	 Nov 30, 2011 5:03:06 PM	delta_4d	 C - Registration System	 GNU C++	Accepted	 530 ms	 2200 KB
