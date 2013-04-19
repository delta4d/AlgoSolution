#include <set>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100086;

char s[MAXN];

int main() {
	int i, j, k;
	int m, n;
	int c0(0), c1(0), off(0);
	int len;
	int diff;
	
//	freopen("in.txt", "r", stdin);
	
	scanf("%s", s);
	len = strlen(s);
	for (i=0; i<len; ++i) {
		if (s[i] == '0') ++c0;
		else if (s[i] == '1') ++c1;
		else ++off;
	}
	if (len % 2 == 1) ++c0;
	if (off == 0) {
		if (c0 > c1) {
			puts("00");
		} else if (c1 > c0) {
			puts("11");
		} else {
			if (s[len-1] == '0') puts("10");
			else puts("01");
		}
	} else {
		if (c0 > c1 + off) {
			puts("00");
		} else if (c1 > c0 + off) {
			puts("11");
		} else if (c0 == c1 + off) {
			if (s[len-1] == '0') {
				puts("00");
				puts("10");
			} else if (s[len-1] == '1') {
				puts("00");
				puts("01");
			} else {
				puts("00");
				puts("01");
				//puts("10");
			}
		} else if (c1 == c0 + off) {
			if (s[len-1] == '0') {
				puts("10");
				puts("11");
			} else if (s[len-1] == '1') {
				puts("01");
				puts("11");
			} else {
				//puts("01");
				puts("10");
				puts("11");
			}
		} else {
			if ((c1 - c0 + off) % 2 == 0) {
				if (s[len-1] == '0') {
					puts("00");
					puts("10");
					puts("11");
				} else if (s[len-1] == '1') {
					puts("00");
					puts("01");
					puts("11");
				} else {
					puts("00");
					puts("01");
					puts("10");
					puts("11");
				}
			} else {
				puts("01");
				puts("10");
			}
		}
	}
	return 0;
}

// 943645	 Dec 9, 2011 8:10:27 PM	delta_4d	 C - Zero-One	 GNU C++	Accepted	 30 ms	 1400 KB
