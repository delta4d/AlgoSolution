/*
ID: delta 4d
PROG: calfflac
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 20001;
char buff[MAXN];
char temp[128];
int len;

inline bool alp(const char x) {
	return x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z';
}

inline bool equ(const char x, const char y) {
	return x == y || x - 'a' + 'A' == y || x == y - 'a' + 'A';
}

inline int left(const int k) {
	for (int i=k; i>=0; --i) if (alp(buff[i])) return i;
	return -1;
}

inline int right(const int k) {
	for (int i=k; i<len; ++i) if (alp(buff[i])) return i;
	return len;
}

inline void gao(int i, int j, int &s, int &t, int &cnt) {
	int ss, tt;
	while (i >= 0 && j < len) {
		//i = left(i), j = right(j);
		//printf("i: %d j: %d\n", i, j);
		//printf("l: %c r: %c\n", buff[i], buff[j]);
		if (!equ(buff[i], buff[j])) break;
		ss = i, tt = j;
		cnt += 2;
		i = left(i-1), j = right(j+1);
	}
	s = ss, t = tt;
}

inline void gao(int &cnt, int &s, int &t) {
	int i, j, k;
	int p;
	int ss, tt;
	int cc;
	s = 0, t = -1, cnt = 0;
	for (k=0; k<len; ++k) {
		//k = 22;
		if (alp(buff[k])) {
			cc = 1;
			gao(left(k-1), right(k+1), ss, tt, cc); //printf("ss: %d tt: %d\n", ss, tt);
			if (cc > cnt) s = ss, t = tt, cnt = cc;
			cc = 0;
			gao(left(k), right(k+1), ss, tt, cc); //printf("ss: %d tt: %d\n", ss, tt);
			if (cc > cnt) s = ss, t = tt, cnt = cc;	
		}
		//break;
	}
}

int main() {
	int i, j, k;
	int m, n;
	int s, t, cnt;
	int tlen;
	freopen("calfflac.in", "r", stdin);
	freopen("calfflac.out", "w", stdout);
	buff[0] = '\0';
	while (gets(temp)) {
		tlen = strlen(buff);
		buff[tlen] = '\n';
		buff[tlen+1] = '\0'; 
		strcat(buff, temp);
	}
	len = strlen(buff);
	gao(cnt, s, t);
	printf("%d\n", cnt);
	for (i=s; i<=t; ++i) printf("%c", buff[i]);
	puts("");
	return 0;
}