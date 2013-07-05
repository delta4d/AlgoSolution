#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000086;

char s[MAXN];
vector <pair<char, int> > ss;

int main() {
	int i, j, k;
	int p, tc;
	char op[16], c[16];
	
//	freopen("in.txt", "r", stdin);
	while (1 == scanf("%s", s)) {
		scanf("%d", &tc);
		ss.clear();
		while (tc--) {
			scanf("%s", op);
			if (op[0] == 'I') {
				scanf("%s %d", c, &p);
				ss.push_back(make_pair(c[0], p-1));
			} else {
				scanf("%d", &p);
				for (--p,i=ss.size()-1; i>=0; --i) {
					if (ss[i].second < p) {
						--p;
					} else if (ss[i].second == p) {
						printf("%c\n", ss[i].first);
						break;
					}
				}
				if (i == -1) printf("%c\n", s[p]);
			}
		}
	}
	return 0;
}