#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

char s1[MAXN][MAXN], s2[MAXN][MAXN];

struct node {
	int x, y;
};

typedef vector<node> VN;
typedef VN::iterator VNI;

VN c1, c2;

inline void input(const int n, char s[][MAXN]) {
	int x, y;
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &x, &y);
		s[x][y] = '*';
	}
}

void flood_fill(int x, int y, const int w, const int h, char s[][MAXN]) {
	int i, j, k;
	int tx, ty;
	
	s[x][y] = '#';
	for (k=0; k<4; ++k) {
		tx = x + dx[k], ty = y + dy[k];
		if (0 <= tx && tx < w && 0 <= ty && ty < h && s[tx][ty] == '*') {
			flood_fill(tx, ty, w, h, s);
		}
	}
}

void find_cluster(VN &c, const int w, const int h, char s[][MAXN]) {
	int i, j, k;
	for (i=0; i<w; ++i) {
		for (j=0; j<h; ++j) {
			if (s[i][j] == '*') {
				c.push_back(node(i, j));
				flood_fill(i, j, w, h, s);
			}
		}
	}
}

int main() {
	int i, j, k;
	int w1, h1, n1;
	int w2, h2, n2;
	int x, y;
	int tc;
	
	freopen("d:\\in.txt", "r", stdin);
	
	scanf("%d", &tc);
	while (tc--) {
		c1.clear();
		c2.clear();
		
		memset(s1, '.', sizeof(s1));
		memset(s2, '.', sizeof(s2));
		
		scanf("%d %d %d", &w1, &h1, &n1);
		input(n1, s1);
		scanf("%d %d %d", &w2, &h2, &n2);
		input(n2, s2);
		
		find_cluster(c1, w1, h1, s1);
		find_cluster(c2, w2, h2, s2);
	}
	
	return 0;
}