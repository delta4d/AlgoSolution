#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef map<string, int> MSI;
typedef MSI::iterator MSII;

const int MAXL = 80;

MSI cc;
char buff[MAXL];

int main() {
	int m, n;
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	gets(buff);
	while (true) {
		cc.clear();
		n = 0;
		while (strcmp(buff, "") != 0) {
			string s(buff);
			if (cc.find(s) == cc.end()) cc.insert(MSI::value_type(s, 1));
			else ++cc[s];
			++n;
			if (!gets(buff)) break;
		}
		MSII it;
		for (it=cc.begin(); it!=cc.end(); ++it) {
			printf("%s %.4lf\n", (it->first).c_str(), 100.0*(it->second)/double(n));
		}
		if (!gets(buff)) break;
		puts("");
	}
	return 0;
}