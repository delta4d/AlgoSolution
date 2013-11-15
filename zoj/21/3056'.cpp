#include <ctype.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10086;
const int MAXL  = 64;

char word[MAXN][MAXL], sword[MAXN][MAXL];
char buff[128], token[MAXL];

inline int find_word() {
	for (int i=0; ; ++i) if (strcmp(sword[i], token) == 0) return i;
}

int main() {
	int i, j, k;
	int m, n(0), len;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", word[n]), word[n][0]!='D') {
		strcpy(sword[n], word[n]);
		if ((len = strlen(sword[n])) > 2) sort(sword[n]+1, sword[n]+len-1);
		++n;
	}
	gets(buff);
	while (gets(buff)) {
		//buff[strlen(buff)+1] = '$';
		for (i=k=0; ; ++i) {
			if (islower(buff[i])) {
				token[k++] = buff[i];
			} else {
				if (k > 0) {
					token[k] = '\0';
					if (k > 2) sort(token+1, token+k-1);
					printf("%s", word[find_word()]);
				}
				if (buff[i] == '\0') break;
				printf("%c", buff[i]);
				k = 0;
			}
		}
		puts("");
	}
	return 0;
}