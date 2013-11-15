#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXL = 80;
const int w[] = {0, 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2, 1};
const int sd[2][13] = {
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

char s[MAXL];
int f[MAXL], out[MAXL];
int cnt;

inline int leap(int x) {
	if (x % 100 != 0 && x % 4 == 0 || x % 400 == 0) return 1;
	return 0;
}

inline int single_diff(int x, int y) {
	int sum(0);
	for (int i=0; i<4; ++i) {
		if (x % 10 != y % 10) ++sum;
		x /= 10, y /= 10;
	}
	return sum;
}

inline int diff(int y1, int m1, int d1, int y2, int m2, int d2) {
	return single_diff(y1, y2) + single_diff(m1, m2) + single_diff(d1, d2);
}

inline int check_sum(int a[]) {
	int sum(0);
	for (int i=1; i<18; ++i) sum += a[i] * w[i];
	return (12 - (sum % 11)) % 11;
}

void gao15() {
	int i, j, k;
	int m, n;
	int y1, m1, d1;
	int y2, m2, d2;
	int cdiff;

	y1 = 10 * f[7] + f[8], m1 = 10 * f[9] + f[10], d1 = 10 * f[11] + f[12];

	// 1900-1999
	for (y2=0; y2<=99; ++y2) {
		k = leap(1900+y2);
		for (m2=1; m2<=12; ++m2) {
			for (d2=1; d2<=sd[k][m2]; ++d2) {
				cdiff = diff(y1, m1, d1, y2, m2, d2);
				if (cdiff < cnt) {
					cnt = cdiff;
					out[0] = y2;
					out[1] = m2;
					out[2] = d2;
				}
			}
		}
	}
	// 2000-2010
	for (y2=0; y2<=10; ++y2) {
		k = leap(2000+y2);
		for (m2=1; m2<=12; ++m2) {
			for (d2=1; d2<=sd[k][m2]; ++d2) {
				cdiff = diff(y1, m1, d1, y2, m2, d2);
				if (cdiff < cnt) {
					cnt = cdiff;
					out[0] = y2;
					out[1] = m2;
					out[2] = d2;
				}
			}
		}
	}
	//2011/1/1 - 2011/3/31
	y2 = 11;
	k = leap(2000+y2);
	for (m2=1; m2<=3; ++m2) {
		for (d2=1; d2<=sd[k][m2]; ++d2) {
			cdiff = diff(y1, m1, d1, y2, m2, d2);
			if (cdiff < cnt) {
				cnt = cdiff;
				out[0] = y2;
				out[1] = m2;
				out[2] = d2;
			}
		}
	}
	//2011/4/1 - 2011/4/2
	y2 = 11, m2 = 4;
	for (d2=1; d2<=2; ++d2) {
		cdiff = diff(y1, m1, d1, y2, m2, d2);
		if (cdiff < cnt) {
			cnt = cdiff;
			out[0] = y2;
			out[1] = m2;
			out[2] = d2;
		}
	}
	// output the result
	for (i=1; i<=6; ++i) printf("%d", f[i]);
	for (i=0; i<=2; ++i) printf("%02d", out[i]);
	for (i=13; i<=15; ++i) printf("%d", f[i]);
	puts("");
}

void gao18() {
	int i, j, k;
	int m, n;
	int cdiff;
	int y1, m1, d1;
	int y2, m2, d2;
	int cs;
	int a[MAXL];
	char buff[MAXL];

	y1 = 1000 * f[7] + 100 * f[8] + 10 * f[9] + f[10], m1 = 10 * f[11] + f[12], d1 = 10 * f[13] + f[14];
	out[3] = f[18];
	for (i=1; i<=18; ++i) a[i] = f[i];
	//1900/1/1 - 2010/12/31
	for (y2=1900; y2<=2010; ++y2) {
		k = leap(y2);
		for (m2=1; m2<=12; ++m2) {
			for (d2=1; d2<=sd[k][m2]; ++d2) {
				cdiff = diff(y1, m1, d1, y2, m2, d2);
				int t = y2;
				for (i=3; i>=0; --i) {
					a[7+i] = t % 10;
					t /= 10;
				}
				t = m2;
				for (i=1; i>=0; --i) {
					a[11+i] = t % 10;
					t /= 10;
				}
				t = d2;
				for (i=1; i>=0; --i) {
					a[13+i] = t % 10;
					t /= 10;
				}
				cs = check_sum(a);		
				if (cs != f[18]) ++cdiff;
				if (cdiff < cnt) {
					cnt = cdiff;
					out[0] = y2;
					out[1] = m2;
					out[2] = d2;
					out[3] = cs;
				}
			}
		}
	}
	//2011/1/1 - 2011/3/31
	y2 = 2011;
	k = leap(y2);
	for (m2=1; m2<=3; ++m2) {
		for (d2=1; d2<=sd[k][m2]; ++d2) {	
			cdiff = diff(y1, m1, d1, y2, m2, d2);
			int t = y2;
			for (i=3; i>=0; --i) {
				a[7+i] = t % 10;
				t /= 10;
			}
			t = m2;
			for (i=1; i>=0; --i) {
				a[11+i] = t % 10;
				t /= 10;
			}
			t = d2;
			for (i=1; i>=0; --i) {
				a[13+i] = t % 10;
				t /= 10;
			}

			cs = check_sum(a);		
			if (cs != f[18]) ++cdiff;
			if (cdiff < cnt) {
				cnt = cdiff;
				out[0] = y2;
				out[1] = m2;
				out[2] = d2;
				out[3] = cs;
			}
		}
	}
	//2011/4/1 - 2011/4/2
	y2 = 2011, m2 = 4;
	for (d2 = 1; d2<=2; ++d2) {	
		cdiff = diff(y1, m1, d1, y2, m2, d2);
		int t = y2;
		for (i=3; i>=0; --i) {
			a[7+i] = t % 10;
			t /= 10;
		}
		t = m2;
		for (i=1; i>=0; --i) {
			a[11+i] = t % 10;
			t /= 10;
		}
		t = d2;
		for (i=1; i>=0; --i) {
			a[13+i] = t % 10;
			t /= 10;
		}
		cs = check_sum(a);		
		if (cs != f[18]) ++cdiff;
		if (cdiff < cnt) {
			cnt = cdiff;
			out[0] = y2;
			out[1] = m2;
			out[2] = d2;
			out[3] = cs;
		}
	}
	// output the result
	for (i=1; i<=6; ++i) printf("%d", f[i]);
	printf("%d", out[0]);
	for (i=1; i<=2; ++i) printf("%02d", out[i]);
	for (i=15; i<=17; ++i) printf("%d", f[i]);
	if (out[3] == 10) printf("X");
	else printf("%d", out[3]);
	puts("");
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int len;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", s+1);
		len = strlen(s+1);
		for (i=1; i<=len; ++i) {
			if ('0' <= s[i] && s[i] <= '9') f[i] = s[i] - '0';
			else if (s[i] == 'X') f[i] = 10;
			else throw "input letter error !";
		}
		cnt = INF;
		if (len == 15) gao15();
		else if (len == 18) gao18();
		else throw "input length error !";
	}

	return 0;
}

