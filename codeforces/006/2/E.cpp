#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <pair<int, int> > seg;
deque <pair<int, int> > mx, mn;

int main() {
	ios_base::sync_with_stdio(false);

	int n, k, h;
	int len = 0, p = 1;

	cin >> n >> k;
	for (int i=1; i<=n; ++i) {
		cin >> h;

		while (!mx.empty() && h > mx.back().first) mx.pop_back();
		mx.push_back(make_pair(h, i));
		while (!mn.empty() && h < mn.back().first) mn.pop_back();
		mn.push_back(make_pair(h, i));

		while (mx.front().first - mn.front().first > k) {
			while (!mn.empty() && mn.front().second <= p) mn.pop_front();
			while (!mx.empty() && mx.front().second <= p) mx.pop_front();
			++p;
		}	

		if (i - p > len) {
			len = i - p;
			seg.clear();
		}
		if (i - p == len) {
			seg.push_back(make_pair(p, i));
		}
	}

	cout << len + 1 << ' ' << seg.size() << endl;
	for (int i=0; i<(int)seg.size(); ++i) cout << seg[i].first << ' ' << seg[i].second << endl;

	return 0;
}

// 3479016	 Apr 6, 2013 11:36:25 AM	delta_4d	 E - Exposition	 GNU C++	Accepted	78 ms	1584 KB
