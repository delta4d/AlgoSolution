#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 201;

char f[MAXN];
int __set[MAXN][MAXN], __list[MAXN][MAXN];

bool is_set(int, int);

bool is_element(int s, int t) {
	if (s == t) return true;
	return is_set(s, t);	
}

bool is_list(int s, int t) {
	int i, j, k;
	if (__list[s][t] != -1) return __list[s][t];
	if (is_element(s, t)) return __list[s][t] = 1;
	for (i=s; i<=t; ++i) {
		if (f[i] == ',') {
			if (is_element(s, i-1) && is_list(i+1, t)) return __list[s][t] = 1;
		}
	}
	return __list[s][t] = 0;
}

bool is_set(int s, int t) {
	int i, j, k;
	if (__set[s][t] != -1) return __set[s][t];
	if (s >= t) return __set[s][t] = 0;
	if (f[s] != '{' || f[t] != '}') return __set[s][t] = 0;
	if (s + 1 == t) return __set[s][t] = 1;
	return __set[s][t] = is_list(s+1, t-1);
}

int main() {
	int i, j, k;
	int m, n;
	int tc, cn;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (cn=0; cn<tc; ++cn) {
		scanf("%s", f);
		memset(__set, -1, sizeof(__set));
		memset(__list, -1, sizeof(__list));
		printf("Word #%d: %s\n", cn+1, is_set(0, strlen(f)-1)?"Set":"No Set");
	}
	return 0;
}