#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m, n;
int tot;

void dfs(long long cc) {
    if (cc > n) return;
    ++tot;
    dfs(cc*10);
    dfs(cc*10+1);
}

int main() {
    int i, j, k;
    
    scanf("%d", &n);
    dfs(1);
    printf("%d\n", tot);
    return 0;
}

// 954985	 Dec 14, 2011 1:57:57 PM	delta_4d	 C - Hexadecimal's Numbers	 GNU C++	Accepted	 30 ms	 1300 KB
