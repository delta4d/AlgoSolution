#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10000000 + 1;

bool v[MAXN];
vector <int> p;

int main() {
	for (int i=2; i<MAXN; ++i) if (!v[i]) {
		p.push_back(i);
		for (int j=i<<1; j<MAXN; j+=i) v[j] = true;
	}
	//printf("%d\n", p.size());
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i) printf("%d ", p[i]);
	return 0;
}

// 4011734	 Jul 4, 2013 4:36:55 PM	* delta_4d	 B - Hungry Sequence	 GNU C++	Accepted	 859 ms	 16500 KB
