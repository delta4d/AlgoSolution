#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps =  1e-7;

typedef set<pair<int, int> > SII;
typedef SII::iterator SIII;
typedef map<int, int> MII;
typedef MII::iterator MIII;

SII iset;
MII mp;

inline int xmult(int x1, int y1, int x2, int y2) {
	return x1 * y2 - x2 * y1;
}

inline int xmult(int xo, int yo, int x1, int y1, int x2, int y2) {
	return xmult(xo-x1, yo-y1, xo-x2, yo-y2);
}

inline int dotmult(int x1, int y1, int x2, int y2) {
	return x1 * x2 + y1 * y2;
}

inline int dotmult(int xo, int yo, int x1, int y1, int x2, int y2) {
	return dotmult(xo-x1, yo-y1, xo-x2, yo-y2);
}

inline bool one_line(int xo, int yo, int x1, int y1, int x2, int y2) {
	return xmult(xo, yo, x1, y1, x2, y2) == 0;
}

inline double dis2(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

inline double angel(int xo, int yo, int x1, int y1, int x2, int y2) {
	double a(dis2(xo, yo, x1, y1)), b(dis2(xo, yo, x2, y2)), c(dis2(x1, y1, x2, y2));
	return acos((a + b - c) / sqrt(4.0 * a * b));
}

struct triangel {
	int x[3], y[3];
	
	bool input() {
		for (int i=0; i<3; ++i) if (2 != scanf("%d %d", x+i, y+i)) return false;
		return true;
	}
		
	bool in(int xo, int yo) {
		int i, j, k;
		double tot(0.0);
		
		for (i=0; i<3; ++i) if (one_line(xo, yo, x[i], y[i], x[(i+1)%3], y[(i+1)%3])) return false;
		for (i=0; i<3; ++i) tot += angel(xo, yo, x[i], y[i], x[(i+1)%3], y[(i+1)%3]);
		return fabs(fabs(tot)-2*PI) < eps;
	}
	
	void gao() {
		int i, j, k;
		int xmin(INF), ymin(INF);
		int xmax(-INF), ymax(-INF);
		int xxmin(INF), yymin(INF);
		int xxmax(-INF), yymax(-INF);
		
		for (i=0; i<3; ++i) xmin = min(xmin, x[i]), xmax = max(xmax, x[i]), ymin = min(ymin, y[i]), ymax = max(ymax, y[i]);
		iset.clear();
		mp.clear();
		for (i=xmin; i<=xmax; ++i) for (j=ymin; j<=ymax; ++j) if (in(i, j)) iset.insert(make_pair(i, j));
		//printf("%d\n", iset.size());
		for (SIII it=iset.begin(); it!=iset.end(); ++it) {
			if (!mp.count(it->second)) mp[it->second] = it->first;
			else mp[it->second] = max(mp[it->second], it->first);
			xxmin = min(xxmin, it->first), xxmax = max(xxmax, it->first);
			yymin = min(yymin, it->second), yymax = max(yymax, it->second);
		}
		for (j=yymax; j>=yymin; --j) {
			if (!mp.count(j)) {
				puts("");
			} else {
				k = mp[j];
				for (i=xxmin; i<=k; ++i) {
					if (iset.find(make_pair(i, j)) == iset.end()) {
						printf("         ");
					} else {
						printf("(%2d, %2d)%s", i, j, i==k?"\n":" ");
					}
				}
			}
		}
		puts("");
	}
} xxx;

int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	
	puts("Program 4 by team X");
	while (xxx.input()) xxx.gao();
	puts("End of program 4 by team X");

	return 0;
}