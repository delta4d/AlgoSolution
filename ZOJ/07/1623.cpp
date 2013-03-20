#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 100000;
char out[MAXL];
char buff[128];

inline bool lower(const char x) {
	return x <= 'z' && x >= 'a';
}

inline void gao(const int s, const int t) {
	int i;
	for (i=s; i<=t; ++i) if (lower(out[i])) out[i] = out[i] - 'a' + 'A';
}

inline int gao(int start, char* s, char* t) {
    int len(strlen(s));
    char *p(strstr(s+start, t));
    return p == NULL ? -1 : p - s;
}

inline void gao() {
	int len = strlen(out);
    int count = 0;
    int start = 0;
    while(true) {
        int p1 = gao(start, out, "/*");
        int p2 = gao(start, out, "//");
        int p3 = gao(p1+2, out, "*/");
        if((p1 != -1 && p3 != -1) && (p2 == -1 || p2 > p1)) {
            ++count;
            gao(p1, p3);
            start = p3 + 2;
        } else if(p2 != -1) {
            int last = gao(p2+1, out, "\n");
            ++count;
            gao(p2, last);
            start = last + 1;
        } else {
            printf("%d\n", count);
            puts(out);
            return;
        }
    }
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int len;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		out[0] = '\0';
		scanf("%d", &n); gets(buff);
		for (i=0; i<n; ++i) {
			gets(buff);
			len = strlen(buff);
			buff[len] = '\n';
			buff[len+1] = '\0';
			strcat(out, buff);
		}
		gao();
	}
	return 0;
}