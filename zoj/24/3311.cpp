#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 101;
char s[MAXL];

inline bool gao() {
	int i, j, k;
	int len(strlen(s));
	int head(0), tail(len-1);
	for (; s[head]=='O'; ++head); if (s[head] != 'Z') return false;
	for (; s[tail]=='O'; --tail); if (s[tail] != 'J' || tail == len - 1) return false;
	++head, --tail;
	if (tail - head + 1 <= 0) return false;
	for (i=head; i<=tail; ++i) if (s[i] != 'O') return false;
	if (len + head < (tail << 1) + 3) return false;
	return true;
}

int main() {
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", s) != EOF) puts(gao()?"Accepted":"Wrong Answer");
	return 0;
}