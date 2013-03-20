#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#define debug 0
#define cnt 0

const int MaxL = 100001;
char num[MaxL];
int len;
int x;

inline int gao1() {
	return 9;
}

inline int gao2() {
	int t(num[len-1] - '0');
	t %= 2;
	t += 8;
	return t;
}

inline int gao3() {
	int t(0);
	for (int i=0; i<len; ++i) {
		t += num[i] - '0';
	}
	t %= 3;
	t += 6;
	return t < 7 ? t + 3 : t;
}

inline int gao4() {
	int t(num[len-1] - '0');
	if (len > 1) {
		t += (num[len-2] - '0') * 10;
	}
	t %= 4;
	t += 4;
	return t < 6 ? t + 4 : t;
}

inline int gao5() {
	int t(num[len-1] - '0');
	t %= 5;
	t += 5;
	return t < 5 ? t + 5 : t;
}

inline int gao6() {
	int t;
	int t2(gao2()%2);
	int t3(gao3()%3);
	switch (t3*10+t2) {
		case  0: t = 0; break;
		case  1: t = 3; break;
		case 10: t = 4; break;
		case 11: t = 1; break;
		case 20: t = 2; break;
		case 21: t = 5; break;
		default: throw "gao6() error !!!!"; break;
	}
	return t < 4 ? t + 6 : t;
}

inline int gao7() {
	int t(0);
	int a(0);
	int sgn(1);
	for (int i=len-1; i>=0; i-=3) {
		if (i == 0) {	
			t += sgn * (num[i] - '0');
		} else if (i == 1) {		
			t += sgn * ((num[i-1] - '0') * 10 + (num[i] - '0'));
		} else {
			t += sgn * ((num[i-2] - '0') * 100 + (num[i-1] - '0') * 10 + (num[i] - '0'));
		}
		sgn *= -1;
	}
	t %= 7;
	t += 7;
	t %= 7;
	return t < 3 ? t + 7 : t;
}

inline int gao8() {
	int t(num[len-1] - '0');
	if (len == 2) {
		t += (num[len-2] - '0') * 10;
	} else if (len > 2) {
 		t += (num[len-3] - '0') * 100 + (num[len-2] - '0') * 10;
	}
	t %= 8;
	return t < 2 ? t + 8 : t;
}

inline int gao9() {
	int t(0);
	for (int i=0; i<len; ++i) {
		t += num[i] - '0';
	}
	t %= 9;
	return t < 1 ? t + 9 : t;
}

int gao() {
	switch (10 - x) {
		case 1: return gao1();
		case 2: return gao2();
		case 3: return gao3();
		case 4: return gao4();
		case 5: return gao5();
		case 6: return gao6();
		case 7: return gao7();
		case 8: return gao8();
		case 9: return gao9();
		default: throw "gao() error !!!!"; break;
	}
}

int main(void) {
	while (scanf("%s", num) != EOF) {
		len = strlen(num);
		for (x=1; x<10; ++x) {
			if (len == 1)
				printf("%s", num);
			else
				printf("%d", gao());
			if (x < 9)
				printf(" ");
			else
				printf("\n");		
		}
	}
	return 0;
}
