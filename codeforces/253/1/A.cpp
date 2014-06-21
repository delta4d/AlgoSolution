#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

int f[5][5];
char buf[80];
vector <int> a;

int r(char c) {
	if (c == 'R') return 0;
	if (c == 'G') return 1;
	if (c == 'B') return 2;
	if (c == 'Y') return 3;
	if (c == 'W') return 4;
	throw "";
}

bool ok(int a, int b) {
	unordered_set <int> al(::a.begin(), ::a.end()), r[5], c[5];
	for (int i=0; i<5; ++i) if (a & 1 << i) {
		vector <int> ee;
		for (auto k: al) {
			int x = k / 10, y = k % 10;
			if (x == i) {
				r[i].insert(y);
				ee.push_back(k);
			}
		}
		for (auto c: ee) al.erase(c);
	}
	for (int i=0; i<5; ++i) if (b & 1 << i) {
		vector <int> ee;
		for (auto k: al) {
			int x = k / 10, y = k % 10;
			if (y == i) {
				c[i].insert(x);
				ee.push_back(k);
			}
		}
		for (auto c: ee) al.erase(c);
		for (int j=0; j<5; ++j) {
			if (r[j].find(i) != r[j].end()) r[j].erase(i);
		}
	}
	if ((int)al.size() > 1) return false;
	for (int i=0; i<5; ++i) {
		if ((int)r[i].size() > 1) return false;
		if ((int)c[i].size() > 1) return false;
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s", buf);
		int x = r(buf[0]), y = buf[1] - '1';
		++f[x][y];
	}
	for (int i=0; i<5; ++i) for (int j=0; j<5; ++j) if (f[i][j]) a.push_back(i*10+j);
	int mn = 100;
	for (int i=0; i<32; ++i) for (int j=0; j<32; ++j) {
//		printf("-- %d %d\n", i, j);
		if (ok(i, j)) mn = min(mn, __builtin_popcount(i)+__builtin_popcount(j));
	}
	printf("%d\n", mn);
	return 0;
}

// 6919559	 2014-06-19 20:48:05	delta_4d	 A - Borya and Hanabi	 GNU C++0x	Accepted	 30 ms	 100 KB
