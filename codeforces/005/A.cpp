#include <set>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class database {
private:
	set <string> names;
	int tot;

public:
	void init() {
		names.clear();
		tot = 0;
	}
	bool recieve() {
		int i, j, k;
		char buff[128];
		string s;
		
		while (gets(buff)) {
			s = buff;
			if (s[0] == '+') {
				names.insert(s.substr(1));
			} else if (s[0] == '-') {
				names.erase(names.find(s.substr(1)));
			} else {
				for (i=0; s[i]!=':'; ++i);
				tot += (s.length() - i - 1) * names.size();
			}
		}
	}
	int get_tot() {
		return tot;
	}
} db;

int main() {
//	freopen("in.txt", "r", stdin);
	db.init();
	db.recieve();
	printf("%d\n", db.get_tot());
	return 0;
}

// 911518	 Nov 30, 2011 5:30:34 PM	delta_4d	 A - Chat Servers Outgoing Traffic	 GNU C++	Accepted	 30 ms	 1400 KB
