#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MP(x, y) make_pair((x), (y))
typedef pair <int, int> PII;
typedef vector <PII> VPII;
typedef map <int, int> MII;
typedef MII::iterator MIII;
typedef map <int, VPII> MIVPII;
typedef MIVPII::iterator MIVPIII;

MIVPII row, col;
MII rr, cc;

#define FIND(xx, n, m) for (MIII it=xx.begin(); it!=xx.end(); ++it) if ((it->second ^ tot) < it->second) { \
					i = it->first, j = it->second - (it->second ^ tot); \
					break; \
                 } \
					if (i == -1 && (n ^ tot) < n) { \
						for (k=1; k<m; ++k) if (!xx.count(k)) { \
							i = k, j = n - (n ^ tot); \
							break; \
						} \
					}


bool INSECT(int x1, int y1, int x2, int y2) {
	return x1 <= x2 && x2 <= y1 || x1 <= y2 && y2 <= y1 || 
		   x2 <= x1 && x1 <= y2 || x2 <= y1 && y1 <= y2;
}

int SEG(VPII &x) {
	int a(x[0].first), b(x[0].second), tot(0);	
	VPII tmp;
	for (int i=0; i<x.size(); ++i) {
		if (INSECT(a, b, x[i].first, x[i].second)) {
			a = min(a, x[i].first), b = max(b, x[i].second);
		} else {
			tmp.push_back(MP(a, b));
			tot += b - a;
			a = x[i].first, b = x[i].second;
		}
	}
	tmp.push_back(MP(a, b));
	tot += b - a;
	x.swap(tmp);
	return tot;
}

void UNIQ(MIVPII &xx, MII &yy, const int n) {
	for (MIVPIII it=xx.begin(); it!=xx.end(); ++it) {
		sort(it->second.begin(), it->second.end());
		it->second.erase(unique(it->second.begin(), it->second.end()), it->second.end());
		yy[it->first] = n - SEG(it->second);
	}
}

void GAO(bool foo, MIVPII xx, const int n, int i, int j) {
	int st(0), ed, sum(0);
	VPII tmp(xx[i]);

//	printf("ROW? %d SIZE: %d NO: %d LEFT: %d\n", foo, n, i, j);
	if (tmp.empty()) {
		ed = j;
	} else {
		tmp.push_back(MP(0, 0));
		tmp.push_back(MP(n, n));
		sort(tmp.begin(), tmp.end());
//		puts("=====");
//		for (int k=0; k<tmp.size(); ++k) printf("[%d, %d]", tmp[k].first, tmp[k].second); puts("");
		for (int k=0; k+1<tmp.size(); ++k) {
			if (sum + tmp[k+1].first - tmp[k].second >= j) {
				ed = tmp[k].second + j - sum;	
				break;
			} else {
				sum += tmp[k+1].first - tmp[k].second;
			}
		}
	}
	if (foo) printf("%d %d %d %d\n", st, i, ed, i);
	else printf("%d %d %d %d\n", i, st, i, ed);
}

int main() {
	int i, j, k;
	int m, n;
	int xb, yb, xe, ye;
	int tot(0);

	scanf("%d%d%d", &n, &m, &k);
	for (i=0; i<k; ++i) {
		scanf("%d%d%d%d", &xb, &yb, &xe, &ye);
		if (xb == xe) col[xb].push_back(MP(min(yb, ye), max(yb, ye)));
		else row[yb].push_back(MP(min(xb, xe), max(xb, xe)));
	}

	UNIQ(row, rr, n);
	UNIQ(col, cc, m);

//	puts("ROW");
//	for (MII::iterator it=rr.begin(); it!=rr.end(); ++it) printf("%d %d\n", it->first, it->second);
//	puts("COL");
//	for (MII::iterator it=cc.begin(); it!=cc.end(); ++it) printf("%d %d\n", it->first, it->second);

	for (MIII it=rr.begin(); it!=rr.end(); ++it) tot ^= it->second;
	if ((m - 1 - rr.size()) & 1) tot ^= n;
	for (MIII it=cc.begin(); it!=cc.end(); ++it) tot ^= it->second;
	if ((n - 1 - cc.size()) & 1) tot ^= m;

//	printf("tot: %d\n", tot);

	if (tot == 0) {
		puts("SECOND");
	} else {
		puts("FIRST");
		i = -1, j = -1;
		FIND(rr, n, m)
			if (i != -1) GAO(true, row, n, i, j);
			else { FIND(cc, m, n) GAO(false, col, m, i, j); }
	}

	return 0;
}

// 3228259	 Mar 2, 2013 9:30:10 AM	delta_4d	 277C - Game	 GNU C++	Accepted	 312 ms	 14300 KB
