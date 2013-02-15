#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 301;
// (x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1), (x - 1, y - 1), (x + 1, y - 1), (x - 1, y + 1), (x + 1, y + 1) 
const int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
const char alp[26][4][7][18] = {
"111111MMM1111111",
"11111MM1MM111111",
"1111MM111MM11111",
"111MMMMMMMMM1111",
"11MM1111111MM111",
"1MMM11111111MM11",
"1MM1111111111MM1",

"1111111MMM111111",
"111111MM1MM11111",
"11111MM111MM1111",
"1111MMMMMMMMM111",
"111MM1111111MM11",
"11MM11111111MMM1",
"1MM1111111111MM1",

"1MM1111111111MM1",
"11MM11111111MMM1",
"111MM1111111MM11",
"1111MMMMMMMMM111",
"11111MM111MM1111",
"111111MM1MM11111",
"1111111MMM111111",

"1MM1111111111MM1",
"1MMM11111111MM11",
"11MM1111111MM111",
"111MMMMMMMMM1111",
"1111MM111MM11111",
"11111MM1MM111111",
"111111MMM1111111",

"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM11111111MM111",
"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM11111111MM111",
"1MMMMMMMMMMM1111",

"1111MMMMMMMMMMM1",
"111MM11111111MM1",
"111MM11111111MM1",
"1111MMMMMMMMMMM1",
"111MM11111111MM1",
"111MM11111111MM1",
"1111MMMMMMMMMMM1",

"1111MMMMMMMMMMM1",
"111MM11111111MM1",
"111MM11111111MM1",
"1111MMMMMMMMMMM1",
"111MM11111111MM1",
"111MM11111111MM1",
"1111MMMMMMMMMMM1",

"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM11111111MM111",
"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM11111111MM111",
"1MMMMMMMMMMM1111",

"11111MMMMMMMM111",
"111MM1111111MM11",
"11MM111111111MM1",
"11MM111111111111",
"11MM111111111MM1",
"111MM1111111MM11",
"11111MMMMMMMM111",

"111MMMMMMMM11111",
"11MM1111111MM111",
"1MM111111111MM11",
"111111111111MM11",
"1MM111111111MM11",
"11MM1111111MM111",
"111MMMMMMMM11111",

"111MMMMMMMM11111",
"11MM1111111MM111",
"1MM111111111MM11",
"111111111111MM11",
"1MM111111111MM11",
"11MM1111111MM111",
"111MMMMMMMM11111",

"11111MMMMMMMM111",
"111MM1111111MM11",
"11MM111111111MM1",
"11MM111111111111",
"11MM111111111MM1",
"111MM1111111MM11",
"11111MMMMMMMM111",

"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",

"1111MMMMMMMMMMM1",
"11MM111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"11MM111111111MM1",
"1111MMMMMMMMMMM1",

"1111MMMMMMMMMMM1",
"11MM111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"11MM111111111MM1",
"1111MMMMMMMMMMM1",

"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",

"1MMMMMMMMMMMM111",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMM111",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMM111",

"111MMMMMMMMMMMM1",
"1111111111111MM1",
"1111111111111MM1",
"111MMMMMMMMMMMM1",
"1111111111111MM1",
"1111111111111MM1",
"111MMMMMMMMMMMM1",

"111MMMMMMMMMMMM1",
"1111111111111MM1",
"1111111111111MM1",
"111MMMMMMMMMMMM1",
"1111111111111MM1",
"1111111111111MM1",
"111MMMMMMMMMMMM1",

"1MMMMMMMMMMMM111",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMM111",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMM111",

"1MMMMMMMMMMMMM11",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMMM11",
"1MM1111111111111",
"1MM1111111111111",
"1MM1111111111111",

"11MMMMMMMMMMMMM1",
"1111111111111MM1",
"1111111111111MM1",
"11MMMMMMMMMMMMM1",
"1111111111111MM1",
"1111111111111MM1",
"1111111111111MM1",

"1111111111111MM1",
"1111111111111MM1",
"1111111111111MM1",
"11MMMMMMMMMMMMM1",
"1111111111111MM1",
"1111111111111MM1",
"11MMMMMMMMMMMMM1",

"1MM1111111111111",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMMM11",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMMM11",

"11111MMMMMMMM111",
"111MM1111111MM11",
"11MM111111111MM1",
"11MM111111111111",
"11MM111111MMMMM1",
"111MM1111111MM11",
"11111MMMMMMMMM11",

"111MMMMMMMM11111",
"11MM1111111MM111",
"1MM111111111MM11",
"111111111111MM11",
"1MMMMM111111MM11",
"11MM1111111MM111",
"11MMMMMMMMM11111",

"11MMMMMMMMM11111",
"11MM1111111MM111",
"1MMMMM111111MM11",
"111111111111MM11",
"1MM111111111MM11",
"11MM1111111MM111",
"111MMMMMMMM11111",

"11111MMMMMMMMM11",
"111MM1111111MM11",
"11MM111111MMMMM1",
"11MM111111111111",
"11MM111111111MM1",
"111MM1111111MM11",
"11111MMMMMMMM111",

"1MM111111111MM11",
"1MM111111111MM11",
"1MM111111111MM11",
"1MMMMMMMMMMMMM11",
"1MM111111111MM11",
"1MM111111111MM11",
"1MM111111111MM11",

"11MM111111111MM1",
"11MM111111111MM1",
"11MM111111111MM1",
"11MMMMMMMMMMMMM1",
"11MM111111111MM1",
"11MM111111111MM1",
"11MM111111111MM1",

"11MM111111111MM1",
"11MM111111111MM1",
"11MM111111111MM1",
"11MMMMMMMMMMMMM1",
"11MM111111111MM1",
"11MM111111111MM1",
"11MM111111111MM1",

"1MM111111111MM11",
"1MM111111111MM11",
"1MM111111111MM11",
"1MMMMMMMMMMMMM11",
"1MM111111111MM11",
"1MM111111111MM11",
"1MM111111111MM11",

"11111MMMMMM11111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"11111MMMMMM11111",

"11111MMMMMM11111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"11111MMMMMM11111",

"11111MMMMMM11111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"11111MMMMMM11111",

"11111MMMMMM11111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"11111MMMMMM11111",

"1111MMMMMMMM1111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"111MM11MM1111111",
"111MMM1MM1111111",
"11111MMMM1111111",

"1111MMMMMMMM1111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM11MM111",
"1111111MM1MMM111",
"1111111MMMM11111",

"1111111MMMM11111",
"1111111MM1MMM111",
"1111111MM11MM111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111MMMMMMMM1111",

"11111MMMM1111111",
"111MMM1MM1111111",
"111MM11MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111MMMMMMMM1111",

"11MM111111MMM111",
"11MM11111MMM1111",
"11MM111MMM111111",
"11MMMMM111111111",
"11MM111MMM111111",
"11MM11111MMM1111",
"11MM111111MMMM11",

"111MMM111111MM11",
"1111MMM11111MM11",
"111111MMM111MM11",
"111111111MMMMM11",
"111111MMM111MM11",
"1111MMM11111MM11",
"11MMMM111111MM11",

"11MMMM111111MM11",
"1111MMM11111MM11",
"111111MMM111MM11",
"111111111MMMMM11",
"111111MMM111MM11",
"1111MMM11111MM11",
"111MMM111111MM11",

"11MM111111MMMM11",
"11MM11111MMM1111",
"11MM111MMM111111",
"11MMMMM111111111",
"11MM111MMM111111",
"11MM11111MMM1111",
"11MM111111MMM111",

"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MMMMMMMMMMMM11",

"111111111111MM11",
"111111111111MM11",
"111111111111MM11",
"111111111111MM11",
"111111111111MM11",
"111111111111MM11",
"11MMMMMMMMMMMM11",

"11MMMMMMMMMMMM11",
"111111111111MM11",
"111111111111MM11",
"111111111111MM11",
"111111111111MM11",
"111111111111MM11",
"111111111111MM11",

"11MMMMMMMMMMMM11",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",

"1MM1111111111MM1",
"1MMMM111111MMMM1",
"1MM1MM1111MM1MM1",
"1MM11MMMMM111MM1",
"1MM1111M11111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",

"1MM1111111111MM1",
"1MMMM111111MMMM1",
"1MM1MM1111MM1MM1",
"1MM111MMMMM11MM1",
"1MM11111M1111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",

"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM11111M1111MM1",
"1MM111MMMMM11MM1",
"1MM1MM1111MM1MM1",
"1MMMM111111MMMM1",
"1MM1111111111MM1",

"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111M11111MM1",
"1MM11MMMMM111MM1",
"1MM1MM1111MM1MM1",
"1MMMM111111MMMM1",
"1MM1111111111MM1",

"1MMM111111111MM1",
"1MMMM11111111MM1",
"1MM1MM1111111MM1",
"1MM11MM111111MM1",
"1MM1111MM1111MM1",
"1MM111111MMM1MM1",
"1MM11111111MMMM1",

"1MM111111111MMM1",
"1MM11111111MMMM1",
"1MM1111111MM1MM1",
"1MM111111MM11MM1",
"1MM1111MM1111MM1",
"1MM1MMM111111MM1",
"1MMMM11111111MM1",

"1MMMM11111111MM1",
"1MM1MMM111111MM1",
"1MM1111MM1111MM1",
"1MM111111MM11MM1",
"1MM1111111MM1MM1",
"1MM11111111MMMM1",
"1MM111111111MMM1",

"1MM11111111MMMM1",
"1MM111111MMM1MM1",
"1MM1111MM1111MM1",
"1MM11MM111111MM1",
"1MM1MM1111111MM1",
"1MMMM11111111MM1",
"1MMM111111111MM1",

"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM111111MMM11",
"111MMM1111MMM111",
"11111MMMMMM11111",

"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM111111MMM11",
"111MMM1111MMM111",
"11111MMMMMM11111",

"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM111111MMM11",
"111MMM1111MMM111",
"11111MMMMMM11111",

"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM111111MMM11",
"111MMM1111MMM111",
"11111MMMMMM11111",

"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",
"1MM1111111111111",
"1MM1111111111111",

"1111MMMMMMMMMMM1",
"11MM111111111MM1",
"1MM1111111111MM1",
"11MM111111111MM1",
"1111MMMMMMMMMMM1",
"1111111111111MM1",
"1111111111111MM1",

"1111111111111MM1",
"1111111111111MM1",
"1111MMMMMMMMMMM1",
"11MM111111111MM1",
"1MM1111111111MM1",
"11MM111111111MM1",
"1111MMMMMMMMMMM1",

"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",

"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM1MMMM1MMM11",
"111MMM11MMMMM111",
"111111MMMM1MMMM1",

"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM1MMMM1MMM11",
"111MMMMM11MMM111",
"1MMMM1MMMM111111",

"1MMMM1MMMM111111",
"111MMMMM11MMM111",
"11MMM1MMMM1MMM11",
"1MM1111111111MM1",
"11MMM111111MMM11",
"111MMM1111MMM111",
"11111MMMMMM11111",

"111111MMMM1MMMM1",
"111MMM11MMMMM111",
"11MMM1MMMM1MMM11",
"1MM1111111111MM1",
"11MMM111111MMM11",
"111MMM1111MMM111",
"11111MMMMMM11111",

"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM111111111MMM1",

"1111MMMMMMMMMMM1",
"11MM111111111MM1",
"1MM1111111111MM1",
"11MM111111111MM1",
"1111MMMMMMMMMMM1",
"111MM11111111MM1",
"1MMM111111111MM1",

"1MMM111111111MM1",
"111MM11111111MM1",
"1111MMMMMMMMMMM1",
"11MM111111111MM1",
"1MM1111111111MM1",
"11MM111111111MM1",
"1111MMMMMMMMMMM1",

"1MM111111111MMM1",
"1MM11111111MM111",
"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",

"1111MMMMMMMM1111",
"111MM1111111MM11",
"11MMM1111111MMM1",
"1111MMMMM1111111",
"1MMM111MMMM11111",
"111MMM11111MMM11",
"11111MMMMMMM1111",

"1111MMMMMMMM1111",
"11MM1111111MM111",
"1MMM1111111MMM11",
"1111111MMMMM1111",
"11111MMMM111MMM1",
"11MMM11111MMM111",
"1111MMMMMMM11111",

"1111MMMMMMM11111",
"11MMM11111MMM111",
"11111MMMM111MMM1",
"1111111MMMMM1111",
"1MMM1111111MMM11",
"11MM1111111MM111",
"1111MMMMMMMM1111",

"11111MMMMMMM1111",
"111MMM11111MMM11",
"1MMM111MMMM11111",
"1111MMMMM1111111",
"11MMM1111111MMM1",
"111MM1111111MM11",
"1111MMMMMMMM1111",

"11MMMMMMMMMMMM11",
"11MMMMMMMMMMMM11",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",

"11MMMMMMMMMMMM11",
"11MMMMMMMMMMMM11",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",

"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"11MMMMMMMMMMMM11",
"11MMMMMMMMMMMM11",

"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"11MMMMMMMMMMMM11",
"11MMMMMMMMMMMM11",

"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MMM11111111MMM1",
"1MMM11111111MMM1",
"111MMMMMMMMMM111",

"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MMM11111111MMM1",
"1MMM11111111MMM1",
"111MMMMMMMMMM111",

"111MMMMMMMMMM111",
"1MMM11111111MMM1",
"1MMM11111111MMM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",

"111MMMMMMMMMM111",
"1MMM11111111MMM1",
"1MMM11111111MMM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",

"1MMMM111111MMMM1",
"11MMM111111MMM11",
"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"11111MM11MM11111",
"111111MMMM111111",

"1MMMM111111MMMM1",
"11MMM111111MMM11",
"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"11111MM11MM11111",
"111111MMMM111111",

"111111MMMM111111",
"11111MM11MM11111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"11MMM111111MMM11",
"1MMMM111111MMMM1",

"111111MMMM111111",
"11111MM11MM11111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"11MMM111111MMM11",
"1MMMM111111MMMM1",

"1MM1111111111MM1",
"1MM1111111111MM1",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM1MM11MM1MM11",
"111MMM1111MMM111",

"1MM1111111111MM1",
"1MM1111111111MM1",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM1MM11MM1MM11",
"111MMM1111MMM111",

"111MMM1111MMM111",
"11MM1MM11MM1MM11",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM111MM111MM11",
"1MM1111111111MM1",
"1MM1111111111MM1",

"111MMM1111MMM111",
"11MM1MM11MM1MM11",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM111MM111MM11",
"1MM1111111111MM1",
"1MM1111111111MM1",

"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11",

"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11",

"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11",

"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11",

"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",

"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",

"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"111111MMMM111111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11",

"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"111111MMMM111111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11",

"111MMMMMMMMMM111",
"1111111111MM1111",
"111111111MM11111",
"11111111MM111111",
"111111MM11111111",
"11111MM111111111",
"111MMMMMMMMMMM11",

"111MMMMMMMMMM111",
"1111MM1111111111",
"11111MM111111111",
"111111MM11111111",
"11111111MM111111",
"111111111MM11111",
"11MMMMMMMMMMM111",

"11MMMMMMMMMMM111",
"111111111MM11111",
"11111111MM111111",
"111111MM11111111",
"11111MM111111111",
"1111MM1111111111",
"111MMMMMMMMMM111",

"111MMMMMMMMMMM11",
"11111MM111111111",
"111111MM11111111",
"11111111MM111111",
"111111111MM11111",
"1111111111MM1111",
"111MMMMMMMMMM111"
};

set<char> out;
char f[MAXN][MAXN];
pair<int, int> cc[26][4];
vector<pair<int, int> > tt;
int m, n;

inline void init() {
	int i, j, k, t;
	for (k=0; k<26; ++k) {
		for (t=0; t<4; ++t) {
			for (i=0; i<7; ++i) {
				for (j=0; j<16; ++j) {
					if (alp[k][t][i][j] == 'M') break;
				}
				if (j < 16) break;
			}
			cc[k][t] = make_pair(i, j);
		}
	}
}

inline bool in(const int x, const int y) {
	return 0 <= x && x < m && 0 <= y && y < n;
}

void floodfill(int x, int y, const char find_char, const char replace_char) {
	int i, j, k;
	int tx, ty;
	
	f[x][y] = replace_char;
	for (k=0; k<8; ++k) {
		tx = x + dx[k], ty = y + dy[k];
		if (in(tx, ty) && f[tx][ty] == find_char) floodfill(tx, ty, find_char, replace_char);
	}
}

inline bool same(const int ww, const int x, const int y) {
	int i, j, k;
	int cx, cy;
	int tx, ty;
	char rep(f[x][y]);
	bool ok(true);
	
	for (k=0; k<4; ++k) {
		for (i=0; i<7; ++i) {
			for (j=-16; j<16; ++j) {
				//i = 4, j = 5;
				cx = x + i, cy = y + j;
				tx = cc[ww][k].first + i, ty = cc[ww][k].second + j;
				if (in(cx, cy)) {
					if (0 <= tx && tx < 7 && 0 <= ty && ty < 16) {
						if (f[cx][cy] == rep && alp[ww][k][tx][ty] == 'M') continue;
						if (f[cx][cy] != rep && alp[ww][k][tx][ty] == '1') continue;
						break;
					} else {
						if (f[cx][cy] == rep) break;
					}
				}
				if (0 <= tx && tx < 7 && 0 <= ty && ty < 16) {
					if (in(cx, cy)) {
						if (alp[ww][k][tx][ty] == 'M' && f[cx][cy] == rep) continue;
						if (alp[ww][k][tx][ty] == '1' && f[cx][cy] != rep) continue;
						break;
					} else {
						if (alp[ww][k][tx][ty] == 'M') break;
					}
				}
			}
			if (j < 16) break;
		}
		if (i == 7 && j == 16) {
			//printf("----%d\n", k);
			return true;
		}
	} 
	return false;
}

void gao() {
	int i, j, k;
	int sz(tt.size());
	int x, y;
	int cx, cy, tx, ty;
	
	for (k=0; k<sz; ++k) {
		for (i=0; i<26; ++i) {
			//i = 2;
			if (same(i, tt[k].first, tt[k].second)) { 
				out.insert(i+'A');
				//printf("%c\n", i+'A');
				break;
			}
		}
	}
	
	k = out.size();
	set<char>::iterator it=out.begin();
	for (i=0; i<k; ++it, ++i) printf("%c%s", *it, i==k-1?"\n":"");
}

int main() {
	int i, j, k;
	char x;
	
	//freopen("c:\\in.txt", "r", stdin);
	init();
	while (2 == scanf("%d %d", &m, &n)) {
		for (i=0; i<m; ++i) scanf("%s", f[i]);
		tt.clear();
		x = 'a';
		for (i=0; i<m; ++i) {
			for (j=0; j<n; ++j) {
				if (f[i][j] == 'M') {
					if (x == 'M') ++x;
					tt.push_back(make_pair(i, j));
					floodfill(i, j, 'M', x);
					++x;
				}
			}
		}
		//for (i=0; i!=tt.size(); ++i) printf("(%d, %d)\n", tt[i].first, tt[i].second);
		//for (i=0; i<m; ++i) puts(f[i]);
		out.clear();
		gao();
	}

	return 0;
}