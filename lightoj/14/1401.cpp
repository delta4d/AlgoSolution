#include <cstdio>
using namespace std;

int sg[111<<4];
char s[111];

void init() {
	for (int i=1; i<=100; ++i) {
		for (int l=0; l<3; ++l) for (int r=0; r<3; ++r) {
			int cc = (i << 4) | (l << 2) | r;
			bool v[222] = {false};
			for (int k=0; k<i; ++k) for (int c=1; c<3; ++c) {
				if (k == 0 && c == l) continue;
				if (k == i - 1 && c == r) continue;
				v[sg[(k<<4)|(l<<2)|c] ^ sg[((i-k-1)<<4)|(c<<2)|r]] = true;
			}
			for (int k=0; ; ++k) if (!v[k]) { sg[cc] = k; break; }
		}
	}
}

int main() {
	init();
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%s", s);
		int p = -1, m = 0, t = 0, cc = 0;
		for (int i=0; ; ++i) {
			if (s[i] == 'X') t ^= sg[((i-p-1)<<4)|(m<<2)|1], p = i, m = 1, cc ^= 1;
			else if (s[i] == 'O') t ^= sg[((i-p-1)<<4)|(m<<2)|2], p = i, m = 2, cc ^= 1;
			else if (s[i] == '\0') t ^= sg[((i-p-1)<<4)|(m<<2)|0];
			if (s[i] == '\0') break;
		}
//		printf("%d\n", t);
		printf("Case %d: %s\n", ++cn, (t&&!cc||!t&&cc)?"Yes":"No");
	}
	return 0;
}

// 258398	2013-09-01 20:44:30	 1401 - No More Tic-tac-toe	 C++	 0.012	 1092	Accepted
