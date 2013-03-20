#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char digit[11][8][10] = {
{"  XXXX  ",  
 " XX  XX ", 
 " XX  XX ", 
 " XX  XX ", 
 " XX  XX ", 
 " XX  XX ", 
 " XX  XX ", 
 "  XXXX  " },
 
{"   XX   ",   
 " XXXX   ",   
 "   XX   ",   
 "   XX   ", 
 "   XX   ", 
 "   XX   ", 
 "   XX   ", 
 " XXXXXX "},
  
{"  XXXX  ",  
 " XX  XX ", 
 " XX  XX ",
 "     XX ",
 "    XX  ",
 "   XX   ",
 "  XX    ",
 " XXXXXX "},
 
{"  XXXX  ",  
 " X   XX ",
 "     XX ",
 "   XXX  ",
 "     XX ",
 "     XX ",
 " X   XX ",
 "  XXXX  "},
 
{"    XX  ",
 "   XXX  ",
 "   XXX  ",
 "  X XX  ",
 " X  XX  ",
 " XXXXXX ",
 "    XX  ",
 "  XXXXX "},
 
{"  XXXXX ",
 "  XX    ",
 "  XXXX  ",
 "  X  XX ",
 "     XX ",
 "     XX ",
 " X   XX ",
 "  XXXX  "},
  
{"   XXXX ",
 "  XX    ",
 " XX     ",
 " XXXXX  ",
 " XX  XX ",
 " XX  XX ",
 " XX  XX ",
 "  XXXX  "},
 
{" XXXXXX ", 
 " X   XX ", 
 "     XX ", 
 "    XX  ",
 "    XX  ", 
 "    XX  ", 
 "   XX   ", 
 "   XX   "},
 
{"  XXXX  ",
 " XX  XX ", 
 " XX  XX ", 
 "  XXXX  ", 
 " XX  XX ", 
 " XX  XX ", 
 " XX  XX ", 
 "  XXXX  "},
 
{"  XXXX  ", 
 " XX  XX ", 
 " XX  XX ", 
 " XX  XX ", 
 "  XXXXX ", 
 "     XX ", 
 "    XX  ", 
 " XXXX   "},
 
{"        ",
 "   X    ", 
 "   X    ", 
 "   X    ", 
 "XXXXXXX ", 
 "   X    ", 
 "   X    ", 
 "   X    "}};

char s[8][80];
char temp[8][512];
char buff[10][9]; 

inline bool is_me(const int x) {
	int i, j, k;
	for (i=0; i<8; ++i) if (strcmp(digit[x][i], buff[i])) return false;
	return true;
}

inline int which_one() {
	int i, j, k;
	for (i=0; i<10; ++i) if (is_me(i)) return i;
	return -1;
}

inline void output(int x) {
	int i, j, k;
	int out[10], p(0);
	do {
		out[p++] = x % 10;
		x /= 10;
	} while(x != 0);
	for (i=0; i<8; ++i) {
		for (j=p-1; j>=0; --j) printf("%s", digit[out[j]][i]);
		//sout(out[j], i);
		puts("");
	}
}

inline bool col_blank(const int c) {
	int i, j, k;
	for (i=0; i<8; ++i) if (temp[i][c] != ' ') return false;
	return true;
}

inline int gens() {
	int i, j, k;
	int p(0);
	int len(-1);
	for (i=0; i<8; ++i) len = max(len, (int)strlen(temp[i]));
	for (i=0; i<8; ++i) {
		for (k=strlen(temp[i]),j=0; j+k<len; ++j) temp[i][k+j] = ' ';
		temp[i][j+k] = '\0';
	}
	//????????????
	for (i=0; temp[0][i]; ++i) {
		if (col_blank(i)) continue;
		for (k=0; k<8; ++k) s[k][p] = temp[k][i];
		++p;
	}
	for (i=0; i<8; ++i) s[k][p] = '\0';
	return p;
}

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int a, b;
	int t;
	char turn;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	for (i=0; i<8; ++i) buff[i][0] = buff[i][7] = ' ', buff[i][8] = '\0';
	scanf("%d", &tc);
	while (tc--) {
		scanf("%*[\n]");
		for (i=0; i<8; ++i) {
			gets(temp[i]);
			for (k=strlen(temp[i]),j=0; j<8; ++j) temp[i][k+j] = ' ';
			temp[i][k+j] = '\0';
		}
		n = gens();
		a = b = 0;
		turn = 'a';
		for (i=0; i<n; i+=6) {
			for (j=0; j<8; ++j) {
				for (k=0; k<6; ++k) {
					buff[j][k+1] = s[j][i+k];
				}
			}
			t = which_one();
			if (t == -1) {
				turn = 'b';
				++i;
				continue;
			}
			if (turn == 'a') a = a * 10 + t;
			else b = b * 10 + t;
		}
		//printf("%d %d\n", a, b);
		output(a+b);
		if (tc) puts("");
		//if (tc) puts("-------------");
	}
	//freopen("f:\\out.txt", "w", stdout);
	//output(123456789);
	return 0;
}