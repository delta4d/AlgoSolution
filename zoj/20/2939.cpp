#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char buff[80], out[80];

inline int to_dec() {
	int res(0);
	int i, j, k(1);
	int len(strlen(buff));
	for (i=len-1; i>=0; --i) {
		if (buff[i] == 'I') {
			res += k;
			k = 1;
		} else if (buff[i] == 'X') {
			res += 10 * k;
			k = 1;
		} else if (buff[i] == 'C') {
			res += 100 * k;
			k = 1;
		} else if (buff[i] == 'V') {
			res += 5;
			k = -1;
		} else if (buff[i] == 'L') {
			res += 50;
			k = -1;
		} else if (buff[i] == 'D') {
			res += 500;
			k = -1;
		} else if (buff[i] == 'M') {
			res += 1000;
			k = -1;
		}
	}
	return res;
}

inline void to_roman(int n) {
	int i, j, k;
	printf("%d\n", n);
}

int main() {
	int i, j, k;
	int m, n;
	int sum;
	freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		sum = 0;
		for (i=0; i<n; ++i) {
			scanf("%s", buff);
			sum += to_dec();
		}
		to_roman(sum);
	}
	return 0;
}