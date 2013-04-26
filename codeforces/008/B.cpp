#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 256;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool v[MAXN][MAXN];
char s[MAXN];

struct triple {
	int x, y, z;
	triple(int _x=0, int _y=0, int _z=0):x(_x), y(_y), z(_z) {}
};

int main() {
	int x = 111, y = 111;
	scanf("%s", s);
	for (int i=0; s[i]; ++i) {
		v[x][y] = true;
		if (s[i] == 'L') --x;
		else if (s[i] == 'R') ++x;
		else if (s[i] == 'U') ++y;
		else --y;
		if (v[x][y]) {
			puts("BUG");
			return 0;
		}
	}
	v[x][y] = true;
	int tx = x, ty = y;
	queue <triple> q;
	q.push(triple(111, 111, 0));
	v[111][111] = false;
	while (!q.empty()) {	
		triple cc = q.front();
		q.pop();
		x = cc.x, y = cc.y;
		if (x == tx && y == ty) {
			if (cc.z < strlen(s)) {
				puts("BUG");
				return 0;
			}
			break;
		}
		for (int k=0; k<4; ++k) {
			int xx = x + dx[k], yy = y + dy[k];
			if (!v[xx][yy]) continue;
			q.push(triple(xx, yy, cc.z+1));
			v[xx][yy] = false;
		}		
	}
	puts("OK");
	return 0;
}

// 3611922	 Apr 23, 2013 6:38:46 PM	delta_4d	 8B - Obsession with Robots	 GNU C++	Accepted	 15 ms	 100 KB
