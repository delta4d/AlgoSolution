#include <cctype>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[32];

int gao() {
    int i, j, k(strlen(s));
    for (i=0; i<k; ++i) {
        if (!isalpha(s[i])) break;
    }
    for (++i; i<k; ++i) if (isalpha(s[i])) return 1;
    return 0;
}

// excel type
void gao0() {
    int i, x(0);
    for (i=0; isalpha(s[i]); ++i) {
        x = x * 26 + (s[i] - 'A' + 1);
    }
    printf("R%sC%d\n", s+i, x);
}

// rc type
void gao1() {
    int i, j, k; 
    int r(0), c(0);
    char buff[32];
    for (i=1; s[i]!='C'; ++i) r = r * 10 + s[i] - '0';
    for (++i; s[i]; ++i) c = c * 10 + s[i] - '0';
    k = 0;
    do {
        buff[k++] = (j = c % 26) == 0 ? 'Z' : j + 'A' - 1;
        c -= j == 0 ? 26 : j;
        c /= 26;
    } while (c);
    for (--k; k>=0; --k) printf("%c", buff[k]);
    printf("%d\n", r);
}

int main() {
    int i, j, k;
    int tc;
    
    scanf("%d", &tc);
    while (tc--) {
        scanf("%s", s);
        if (gao() == 0) gao0();
        else gao1();
    }
    
    return 0;
}

//#          When	                    Who	         Problem	         Lang	    Verdict	    Time	Memory
//2849812	 Dec 28, 2012 7:57:33 PM	delta_4d	 B - Spreadsheet	 GNU C++	Accepted	140 ms	0 KB
