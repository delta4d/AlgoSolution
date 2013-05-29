#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 16;

char s[MAXN], t[MAXN];
char buf[MAXN];

int main() {
	int i, j, k;
	int len;
	
	scanf("%s %s", buf, t);
	len = strlen(buf);
	for (i=0,j=0,k=0; buf[i]; ++i) k += (buf[i] == '0');
	memset(s, '0', sizeof(s));
	for (j=i=0; buf[i]; ++i) if (buf[i]-'0') s[k+(j++)] = buf[i];
	sort(s+k, s+len);
	swap(s[0], s[k]);
	s[len] = '\0';
//	printf("%s %s\n", s, t);
	printf("%s\n", strcmp(s, t)?"WRONG_ANSWER":"OK");
	return 0;
}

// 953898	 Dec 13, 2011 3:56:37 PM	delta_4d	 B - Correct Solution?	 GNU C++	Accepted	 30 ms	 1300 KB
