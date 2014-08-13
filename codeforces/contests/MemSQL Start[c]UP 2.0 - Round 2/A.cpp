#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 10;
const char o[3][2]={"<", "=", ">"};

char s[N];
int a[N];

int main() {
	scanf("%s", s);
	int n = (int)strlen(s);
	for (int i=0; i<n; ++i) a[n-1-i] += s[i] - '0';
	scanf("%s", s);
	n = (int)strlen(s);
	for (int i=0; i<n; ++i) a[n-1-i] -= s[i] - '0';
	for (bool f=true; f; ) {
		f = false;
		for (int i=0; i+2<N; ++i) {
			if (a[i] == -1 && a[i+1] == -1 && a[i+2] != -1) {
				a[i] = 0, a[i+1] = 0;
				--a[i+2];
				f = true;
			}
		}
		for (int i=N-3; i>=0; --i) {
			if (a[i] == -1 && a[i+1] == -1) {
				a[i] = 0, a[i+1] = 0;
				--a[i+2];
				f = true;
			}
		}
	}
	for (bool f=true; f; ) {
		f = false;
		for (int i=0; i+2<N; ++i) {
			if (a[i] == 1 && a[i+1] == 1 && a[i+2] != 1) {
				a[i] = 0, a[i+1] = 0;
				++a[i+2];
				f = true;
			}
		}
		for (int i=N-3; i>=0; --i) {
			if (a[i] == 1 && a[i+1] == 1) {
				a[i] = 0, a[i+1] = 0;
				++a[i+2];
				f = true;
			}
		}
	}
	int r = 0;
	for (int i=N-1; i>=0&&!(r=a[i]); --i);
	puts(o[r+1]);
	return 0;
}

// 7424059	2014-08-11 10:16:16	delta_4d	A - Golden System	GNU C++0x	Accepted	31 ms	500 KB
