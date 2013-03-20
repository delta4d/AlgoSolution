#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

inline int judge(char *cp) {
	if (strcmp(cp, "negative") == 0) return -1;
	if (strcmp(cp, "zero") == 0) return 0;
	if (strcmp(cp, "one") == 0) return 1;
	if (strcmp(cp, "a") == 0) return 1;
	if (strcmp(cp, "two") == 0) return 2;
	if (strcmp(cp, "three") == 0) return 3;
	if (strcmp(cp, "four") == 0) return 4;
	if (strcmp(cp, "five") == 0) return 5;
	if (strcmp(cp, "six") == 0) return 6;
	if (strcmp(cp, "seven") == 0) return 7;
	if (strcmp(cp, "eight") == 0) return 8;
	if (strcmp(cp, "nine") == 0) return 9;
	if (strcmp(cp, "ten") == 0) return 10;
	if (strcmp(cp, "eleven") == 0) return 11;
	if (strcmp(cp, "twelve") == 0) return 12;
	if (strcmp(cp, "thirteen") == 0) return 13;
	if (strcmp(cp, "fourteen") == 0) return 14;
	if (strcmp(cp, "fifteen") == 0) return 15;
	if (strcmp(cp, "sixteen") == 0) return 16;
	if (strcmp(cp, "seventeen") == 0) return 17;
	if (strcmp(cp, "eighteen") == 0) return 18;
	if (strcmp(cp, "nineteen") == 0) return 19;
	if (strcmp(cp, "twenty") == 0) return 20;
	if (strcmp(cp, "thirty") == 0) return 30;
	if (strcmp(cp, "forty") == 0) return 40;
	if (strcmp(cp, "fifty") == 0) return 50;
	if (strcmp(cp, "sixty") == 0) return 60;
	if (strcmp(cp, "seventy") == 0) return 70;
	if (strcmp(cp, "eighty") == 0) return 80;
	if (strcmp(cp, "ninety") == 0) return 90;
	if (strcmp(cp, "hundred") == 0) return 100;
	if (strcmp(cp, "thousand") == 0) return 1000;
	if (strcmp(cp, "million") == 0) return 1000000;
}

int main() {
	char buff[81], *cp;
	int i, j, k;
	int unit[10], value[10];
	int p;
	int sign;
	int res;
	int tv, tu;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (gets(buff)) {
		cp = strtok(buff, " \n");
		sign = 1;
		res = 0;
		p = 0;
		memset(value, 0, sizeof(value));
		while (cp != NULL) {
			k = judge(cp);
			if (k == -1) {
				sign = -1;
			} else if (k < 100) {
				value[p] += k;
			} else {
				unit[p++] = k;
			}
			cp = strtok(NULL, " \n");
		}
		if (k < 100) unit[p++] = 1;
		value[p] = 0, unit[p] = 1;
		tv = 0;
		for (i=0; i<=p; ++i) {
			if (i == 0 || unit[i] > unit[i-1]) {
				tv += value[i];
				tv *= unit[i];
			} else {
				res += tv;
				tv = value[i] * unit[i];
			}
		}
		printf("%d\n", sign*res);
	}
	return 0;
}