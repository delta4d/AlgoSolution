#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int> d1, d2;
char s[5000+10];

int main() {
	scanf("%s", s);
	int n = (int)strlen(s);
	for (int i=0; i+3<n; ++i) {
		if (s[i] == 'b' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'r') {
			d1.push_back(i), d2.push_back(i+3);
			i += 3;
		}
	}
	int tot = 0, m = (int)d1.size();
	for (int i=0; i<n; ++i) for (int j=i+3; j<n; ++j) {
		int a = lower_bound(begin(d1), end(d1), i) - begin(d1);
		int b = upper_bound(begin(d2), end(d2), j) - begin(d2) - 1;
		if (0 <= a && a <= b && b < m) ++tot;
	}
	printf("%d\n", tot);
	return 0;
}

// 6580395	 May 10, 2014 6:43:31 AM	delta_4d	 B - Bear and Strings	 GNU C++0x	Accepted	 436 ms	 0 KB
