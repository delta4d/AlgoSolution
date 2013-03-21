#include <cstdio>
using namespace std;

const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, 1, -1, 0, 0};

int main() {
	int x[3][3]={0};
	
	for (int i=0,k; i<3; ++i) for (int j=0; j<3; ++j) {
		scanf("%d", &k), k &= 1;
		if (!k) continue;
		for (int t=0; t<5; ++t) {
			int ii = i + dx[t], jj = j + dy[t];
			if (0 <= ii && ii < 3 && 0 <= jj && jj < 3) x[ii][jj] ^= 1;
		}
	}
	for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) printf("%d%s", x[i][j]^1, j==2?"\n":"");

	return 0;
}

// 3361645	 Mar 20, 2013 8:25:50 PM	delta_4d	 275A - Lights Out	 GNU C++	Accepted	15 ms	0 KB
