#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1024;

map <string, int> f1, f2;
char s[MAXN][33];
int v[MAXN];

int main() {
    int i, j, k;
    int m, n;
    int mx;
    
    scanf("%d", &n);
    for (i=0; i<n; ++i) {
        scanf("%s %d", s[i], v+i);
        f1[string(s[i])] += v[i];
    }
    for (mx=i=0; i<n; ++i) mx = max(f1[string(s[i])], mx);
    //printf("%d\n", mx);
    for (i=0; i<n; ++i) {
        f2[s[i]] += v[i];
        //printf("%s %d\n", s[i], v[i]);
        if (f1[string(s[i])] == mx && f2[string(s[i])] >= mx) break;
    }
    puts(s[i]);
    
    return 0;
}

//#		When					Who			 Problem	 Lang		Verdict		 Time	 Memory
//637109	Aug 24, 2011 6:14:04 PM	delta_4d	 A - Winner	 GNU C++	Accepted	 30 ms	 1400 KB
