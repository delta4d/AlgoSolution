#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100;
const int MAXL = 80;
typedef set<int> SI;
typedef SI::iterator SII;
typedef set<SI> SS;
typedef SS::iterator SSI;
SS s;
SI w[MAXN];
char buff[MAXL];
SI ss;

int main() {
	int i, j, k;
	int P, T;
	int x, y;
	char ch;
	//ss.insert(5); ss.insert(58); ss.insert(73); ss.insert(98);
	freopen("f:\\in.txt", "r", stdin);
	freopen("f:\\out1.txt", "w", stdout);
	while (scanf("%d %d", &P, &T) != EOF) {
		getchar();
		gets(buff);
		for (i=0; i<MAXN; ++i) w[i].clear();
		while (strcmp(buff, "") != 0) {
			sscanf(buff, "%d %d", &x, &y);
			w[x].insert(y);
			if (gets(buff) == NULL) break;
		}
		s.clear();
		for (i=1; i<=T; ++i) {
			if (w[i].size() == 0) continue;
			if (w[i] == ss) printf("zhaodaole: %d\n\n", i);
			s.insert(w[i]);
		}
		SSI it;
		k = 0;
		for (it=s.begin(); it!=s.end(); ++it) {
			SII si;
			for (i=0; i<MAXN; ++i) if (w[i] == *it) break;
			printf("%d: ", i);
			for (si=(*it).begin(); si!=(*it).end(); ++si) {
				printf("%d ", *si);
			}
			puts("");
		}
		printf("%d\n", s.size());
	}
	return 0;
}