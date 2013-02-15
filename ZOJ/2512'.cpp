#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string s;
int len;

inline bool sym(int x, int y) {
	int i, j, k(len>>1);
	x += len, y += len;
	for (i=0; i<=k; ++i) {
		if (s[x-i] != s[y+i]) return false;
	}
	return true;
}

int main() {
	int i, j, k;
	//freopen("f:\\in.txt", "r", stdin);
	while (cin >> s) {
		len = s.length();
		s += s, s += s;
		for (i=0; i<len; ++i) {
			if (sym(i, i)) {
				printf("Symmetric\n");
				printf("%d\n", i+1);
				break;
			}
			if (sym(i, i+1)) {
				printf("Symmetric\n");
				printf("%d-%d\n", i+1, i+2);
				break;
			}
		}
		if (i == len) puts("Not symmetric");
	}
	return 0;
}