#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int INF = 0x3f3f3f3f;

struct node {
	string s;
	
	void input() {
		cin >> s;
	}
	void output() {
		puts(s.c_str());
	}
	bool legal(char x) {
		return '0' <= x && x <= '9' || 'a' <= x && x <= 'z' || 'A' <= x && x <= 'Z'; 
	} 
	int rightmost() {
		int len(s.length()-1);
		for (int i=len; i>=0; --i) if (legal(s[i])) return i;
		return len;
	}
	int single_next(char &x) {
		if (legal(x)) {
			if ('0' <= x && x <= '9') {
				if (x == '9') {
					x = '0';
					return 1;
				} else {
					++x;
				}
			} else if ('a' <= x && x <= 'z') {
				if (x == 'z') {
					x = 'a';
					return 1;
				} else {
					++x;
				}
			} else {
				if (x == 'Z') {
					x = 'A';
					return 1;
				} else {
					++x;
				}
			}
		} else {
			++x;
		}
		return 0;
	}
	int left(int p) {
		int i, j, k;
		for (i=p; i>=0; --i) if (legal(s[i])) return i;
		return -1;
	}
	void next() {
		int i, j, k;
		int p, q;
		int c;
		string t;
		p = rightmost();
		c = single_next(s[p]);
		while (c == 1) {
			q = left(p-1);
			//printf("%s\n", s.c_str());
			if (q == -1) {
				if ('0' <= s[p] && s[p] <= '9') {
					t = "1";
					s = s.insert(p, t);
				} else if ('a' <= s[p] && s[p] <= 'z') {
					t = "a";
					s = s.insert(p, t);
				} else {
					t = "A";
					s = s.insert(p, t);
				}
				c = 0;
			} else {
				c = single_next(s[q]);
				p = q;
			}
		}
	}

} x;


int main() {
	int i, j, k;
	int m, n;
	int tc;
	
	scanf("%d", &tc);
	while (tc--) {
		x.input();
		scanf("%d", &n);
		for (i=0; i<n; ++i) {
			x.next();
			x.output();
		}
		puts("");
	}

	return 0;
}
