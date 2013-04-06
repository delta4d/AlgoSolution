#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;
typedef long long LL;
typedef pair <int, int> PII;
#define MP make_pair

vector <PII> st;
int h[MAXN];
bool v[MAXN];

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	LL tot = 0;

	cin >> n;
	for (int i=0; i<n; ++i) cin >> h[i];
	rotate(h, max_element(h, h+n), h+n);
	st.push_back(MP(h[0], 1));
	for (int i=1; i<n; ++i) {
		PII p;
		while (st.back().first < h[i]) {
			tot += st.back().second;
			st.pop_back();
		}
		if (st.back().first == h[i]) {
			p = st.back();
			tot += p.second;
			++p.second;
			st.pop_back();
		} else {
			p = MP(h[i], 1);
		}
		if (!st.empty()) ++tot;
		st.push_back(p);
	}
	for (int i=1,j=0; i<n; ++i) if (h[i] >= j) v[i] = true, j = h[i];
	for (int i=n-1,j=0; !v[i]&&i>0; --i) if (h[i] >= j) ++tot, j = h[i];
	cout << tot << endl;

	return 0;
}

// 3477557	 Apr 5, 2013 8:45:32 PM	delta_4d	 E - Bindian Signalizing	 GNU C++	Accepted	 250 ms	 17800 
