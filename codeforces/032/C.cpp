#include <cstdio>
using namespace std;

typedef long long LL;

int main() {
LL n, m, s;
LL x, y, res, rx, ry;
//freopen("f:\\in.txt", "r", stdin);
while (scanf("%I64d %I64d %I64d", &n, &m, &s) != EOF) {
 x = (n - 1) / s + 1;
 y = (m - 1) / s + 1;
 rx = n - (x - 1) * s;
 ry = m - (y - 1) * s;
 res = x * y * rx * ry;
  printf("%I64d\n", res);
}
return 0;
}

// 139975	2010-10-03 09:41:40	delta_4d	C - Flea	GNU C++	Accepted	30 ms	1300 KB
