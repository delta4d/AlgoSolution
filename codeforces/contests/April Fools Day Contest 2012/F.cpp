/**#include <cstdio>

char mp[256];
char buf[256];

void init() {
    for (int i=0; i<256; ++i) mp[i] = i;
    mp['y'] = 'i';
    mp['d'] = 'n';
    mp['j'] = 't';
    mp['u'] = 'e';
    mp['w'] = 'g';
    mp['h'] = 'r';
    mp['q'] = 'a';
    mp['e'] = 'o';
    mp['k'] = 'u';
    mp['f'] = 'p';
    mp['c'] = 'm';
    mp['r'] = 'b';
    mp['x'] = 'h';
    mp['i'] = 's';
    mp['m'] = 'w';
    mp['b'] = 'l';
    mp['l'] = 'v';
    mp['o'] = 'y';
    mp['a'] = 'k';
    
}

int main() {
    int i, j, k;
    
    init();
    freopen("in.txt", "r", stdin);
    while (gets(buf)) {
        for (i=0; buf[i]; ++i) printf("%c", mp[buf[i]]);
        puts("");
    }
    return 0;
}**/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int LIM = 11184;
const int MAXN = 10000000;

bool isp[MAXN];
vector <int> out;

inline int rev(int x) {
    int ret(0);
    while (x) ret = ret * 10 + x % 10, x /= 10;
    return ret;
}

void init() {
    memset(isp, true, sizeof(isp));
    isp[0] = isp[1] = false;
    for (int i=2; i<MAXN; ++i) if (isp[i]) {
        for (int j=i<<1; j<MAXN; j+=i) isp[j] = false;
    }
    for (int i=2; out.size()<=LIM; ++i) {
        if (i != rev(i) && isp[i] && isp[rev(i)]) out.push_back(i);
    }
}

int main() {
    int i, j, k;
    
    init();
    scanf("%d", &k);
    printf("%d\n", out[k-1]);
    
    return 0;
}


// 1465248	 Apr 2, 2012 6:43:48 PM	delta_4d	 F - ucyhf	 GNU C++	Accepted	 1010 ms	 11300 
