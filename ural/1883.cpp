#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;
const int MAXN = 1024;
const int INF = 0x6fffffff;

struct Point {
	int x, y;
	int idx;
} buf[MAXN], p[MAXN];

vector <Point> tt;
int m, n;

inline bool zero(double x) {
	return ((x > 0 ? x : -x) < EPS);
}

//¼ÆËãcross product (P1 - P0)x(P2 - P0)
inline double xmult(const Point & p1, const Point & p2, const Point & p0) {
	return 1.0 * (p1.x - p0.x) * (p2.y - p0.y) - 1.0 * (p2.x - p0.x) * (p1.y - p0.y);
}

bool cmp(const Point& a, const Point& b) {
	return zero(a.y - b.y) ? (a.x > b.x + EPS) : (a.y > b.y + EPS);
}

int graham(int n, Point p[], Point ch[], bool maxsize = false) {
	const double e1 = maxsize ? EPS : -EPS;
	int i, j, k;
	if (n < 3) {
		for(i = 0; i < n; i++) {
			ch[i] = p[i];
		}
		return n;
	}
	sort(p, p + n, cmp);
	ch[0] = p[0];
	ch[1] = p[1];
	for (i = j = 2; i < n; ch[j++] = p[i++]) {
		while (j > 1 && xmult(ch[j - 2], p[i], ch[j - 1]) > e1) {
			j--;
		}
	}
	ch[k = j++] = p[n - 2];
	for (i = n - 3; i > 0; ch[j++] = p[i--]) {
		while (j > k && xmult(ch[j - 2], p[i], ch[j - 1]) > e1) {
			j--;
		}
	}
	while (j > k && xmult(ch[j - 2], ch[0], ch[j - 1]) > e1) {
		j--;
	}
	return j;
}

bool equ() {
	int i, j, k;
	for (i=2; i<n; ++i) if (!zero(xmult(buf[i], buf[1], buf[0]))) return false;
	return true;
}

inline bool cmpx(const Point &a, const Point &b) {
	return a.x < b.x;
}

inline bool cmpy(const Point &a, const Point &b) {
	return a.y < b.y;
}

int main() {
	int i, j, k;
	int tot;
	int mn, idx;
	int x, y;
	int x1, y1, x2, y2;
	int x3, y3;
	int s, t;
	
//	freopen("in.txt", "r", stdin);
	while (2 == scanf("%d %d", &n, &k)) {
		for (i=0; i<n; ++i) {
			scanf("%d %d", &buf[i].x, &buf[i].y);
			buf[i].idx = i;
		}
		if (k >= 3) {
			if (equ()) {
			//	throw "";
				printf("%d\n", 4);
				if (buf[0].x != buf[1].x) {
				//	throw "";
					sort(buf, buf+n, cmpx);
					printf("%d %d\n", buf[0].x, buf[0].y);
					printf("%d %d\n", buf[k-1].x, buf[k-1].y);
					printf("%d %d\n", buf[k-1].x, buf[k-1].y+1);
					printf("%d %d\n", buf[0].x, buf[0].y+1);	
				} else {
					sort(buf, buf+n, cmpy);
					printf("%d %d\n", buf[0].x, buf[0].y);
					printf("%d %d\n", buf[k-1].x, buf[k-1].y);
					printf("%d %d\n", buf[k-1].x-1, buf[k-1].y);
					printf("%d %d\n", buf[0].x-1, buf[0].y);	
				}
			} else {
			//	throw "";
				for (i=0; i<n-k; ++i) {
					tot = graham(n-i, buf, p);
					tt.clear();
					//printf("%d %d\n", p[s].x, p[s].y);
					for (j=0; j<n-i; ++j) {
						if (buf[j].idx == p[0].idx) continue;
						tt.push_back(buf[j]);
					}
					for (j=0; j<tt.size(); ++j) buf[j] = tt[j];
				}
				printf("%d\n", tot=graham(n-i, buf, p));
				for (i=0; i<tot; ++i) printf("%d %d\n", p[i].x, p[i].y);
			}
		} else if (k == 2) {
		//	throw "";
	 		tot = graham(n, buf, p, true);
	 		x1 = p[0].x, y1 = p[0].y;
	 		x2 = p[1].x, y2 = p[1].y;
	 		if (y2 > y1) x3 = x + 1, y3 = y2;
	 		else if (y2 < y1) x3 = x - 1, y3 = y2;
	 		else if (x2 < x1) x3 = x2, y3 = y2 + 1;
	 		else x3 = x2, y3 = y2 - 1;
	 		buf[0].x = x1, buf[0].y = y1;
	 		buf[1].x = x2, buf[1].y = y2;
	 		buf[2].x = x3, buf[2].y = y3;
	 		graham(3, buf, p);
	 		printf("%d\n", 3);
	 		for (i=0; i<3; ++i) printf("%d %d\n", p[i].x, p[i].y);
		} else {
		//	throw "";
			mn = INF;
			for (i=0; i<n; ++i) if (buf[i].x < mn) mn = buf[i].x, idx = i;
			printf("%d\n", 3);
			x = buf[idx].x, y = buf[idx].y;
			printf("%d %d\n", x, y);
			printf("%d %d\n", x - 1, y + 1);
			printf("%d %d\n", x - 1, y - 1);
		}
	}
	return 0;
}