#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

set <LL> out;
LL ten[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int main() {
	int i, j, k;
	int m, n;
	LL x, y, z, s, t;
	
	//freopen("in.txt", "r", stdin);
	while (scanf("%I64d", &n), n) {
		out.clear();
		for (k=0; k<=9; ++k) {
			if (n < ten[k]) break;
			for (i=0; i<2; ++i) {
				s = n / ten[k] - i;
				if (s == 0) continue;
				t = n - s * ten[k];
				if (t & 1) continue;
				z = t >> 1;
				y = s % 11;
				x = s / 11;
				if (y >= 10) continue;
				if (x * ten[k+1] + y * ten[k] + z + x * ten[k] + z == n) 
					out.insert(x * ten[k+1] + y * ten[k] + z);
			}
		}
		if (out.empty()) {
			puts("No solution.");
		} else {
			i = 0;
			for (set<LL>::iterator it=out.begin(); it!=out.end(); ++it,++i) printf("%I64d%s", *it, i==out.size()-1?"\n":" ");
		}
	}
	return 0;
}