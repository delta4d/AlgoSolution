#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int i, j, k;
	int maxn;
	char buff[81], *cp;
	map<string, int> f;
	map<string, int>::iterator it;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", buff) != EOF) {
		cp = strtok(buff, " ,.;\\'`\"()/:-");
		while (cp != NULL) {
			if (strlen(cp) != 0) {
				for (i=0; cp[i]; ++i) cp[i] = (isalpha(cp[i]) ? tolower(cp[i]) : cp[i]);
				if (f.find(string(cp)) == f.end()) f[string(cp)] = 1;
				else ++f[string(cp)];
			}
			cp = strtok(NULL, ",.;\\'`\"()/:-");
		}
	}
	//puts("read end");
	maxn = -1;
	for (it=f.begin(); it!=f.end(); ++it) {
		if (it->second > maxn) {
			maxn = it->second;
		}
	}
	printf("%d occurrences\n", maxn);
	for (it=f.begin(); it!=f.end(); ++it) {
		if (it->second == maxn) {
			printf("%s\n", (it->first).c_str());
		}
	}
	return 0;
}