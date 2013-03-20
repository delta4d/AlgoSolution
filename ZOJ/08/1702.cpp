#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXL = 80;

char buff[21*MAXL];

struct table {
	int row, col;
	int limit[21];
	char head[MAXL];
	char s[21][21][MAXL];
	
	void init(char headline[]) {
		row = 0, col = strlen(headline);
		strcpy(head, headline);
		for (int i=0; i<21; limit[i++]=-INF);
	}
	void deal(char record[]) {
		int i, j, k(0);
		char buff[MAXL];
		for (i=0; i<col; ++i) {
			sscanf(record+k, "%[^&\n]", buff);
			strcpy(s[row][i], buff);
			//puts(buff);
			j = strlen(buff);
			limit[i] = max(limit[i], j);
			k += j + 1;
		}
		++row;
	}
	void print(const int len, const char x) {
		for (int i=0; i<len; ++i) printf("%c", x);
	}
	void output() {
		int i, j, k;
		int left, right;
		// @----------------------------------------@
		print(1, '@');
		for (i=0; i<col; ++i) {
			print(limit[i]+2, '-');
			print(1, i==col-1?'@':'-');
		}
		print(1, '\n');
		// | value | value |
		for (i=0; i<col; ++i) {
			print(1, '|');
			if (head[i] == '<') {
				printf(" %s", s[0][i]);
				print(limit[i]-strlen(s[0][i])+1, ' ');	
			} else if (head[i] == '>') {
				print(limit[i]-strlen(s[0][i])+1, ' ');
				printf("%s ", s[0][i]);
			} else if (head[i] == '=') {
				left = (k = (limit[i] - strlen(s[0][i]))) >> 1;
				right = k - left;
				print(left+1, ' ');
				printf("%s", s[0][i]);
				print(right+1, ' ');
			} else {
				throw "error";
			}
		}
		print(1, '|');
		print(1, '\n');
		// |-----+--------+--------+--------+-------|
		print(1, '|');
		for (i=0; i<col; ++i) {
			print(limit[i]+2, '-');
			print(1, i==col-1?'|':'+');
		}
		print(1, '\n');
		
		
		// | value | value |
		for (j=1; j<row; ++j) {
			for (i=0; i<col; ++i) {
				print(1, '|');
				if (head[i] == '<') {
					printf(" %s", s[j][i]);
					print(limit[i]-strlen(s[j][i])+1, ' ');	
				} else if (head[i] == '>') {
					print(limit[i]-strlen(s[j][i])+1, ' ');
					printf("%s ", s[j][i]);
				} else if (head[i] == '=') {
					left = (k = (limit[i] - strlen(s[j][i]))) >> 1;
					right = k - left;
					print(left+1, ' ');
					printf("%s", s[j][i]);
					print(right+1, ' ');
				} else {
					throw "error";
				}
			}
			print(1, '|');
			print(1, '\n');
		}
		
		// @----------------------------------------@
		print(1, '@');
		for (i=0; i<col; ++i) {
			print(limit[i]+2, '-');
			print(1, i==col-1?'@':'-');
		}
		print(1, '\n');
	}
};

inline bool head(const char x) {
	return x == '<' || x == '=' || x == '>' || x == '*';
}

int main() {
	int i, j, k;
	int m, n;
	int len;
	table x;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	gets(buff);
	while (true) {
		x.init(buff);
		while (true) {
			gets(buff);
			if (head(buff[0])) break;
			x.deal(buff);
		}
		x.output();
		if (buff[0] == '*') break;
	}
	return 0;
}