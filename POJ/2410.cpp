#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define STA 0
#define LDA 1
#define BEQ 2
#define NOP 3
#define DEC 4
#define INC 5
#define JMP 6
#define HLT 7

const int MAXN = 32;
const int MAXL = 9;

char buff[MAXL];
char mem[MAXN][MAXL];
unsigned char accu, pc;

inline bool input() {
	int i, j, k;
	if (scanf("%s", mem[0]) == EOF) return false;
	for (i=1; i<MAXN; scanf("%s", mem[i++]));
	return true;
}

inline void output(unsigned char x) {
	int i, j, k;
	for (i=7; i>=0; --i) {
		buff[i] = (x & 0x1) + '0';
		x >>= 1;
	}
	buff[8] = '\0';
	puts(buff);
}

inline unsigned	char gao(const int k) {
	unsigned char x(0);
	for (int i=0; i<3; ++i) x = (x << 1) + (mem[k][i] - '0');
	return x;
}

inline int read(const int k) {
	int add(0);
	int i, j;
	for (i=3; i<8; ++i) add = (add << 1) + mem[k][i] - '0';
	return add;
}

inline unsigned char load(const int add) {
	int i, j, k;
	int x(0);
	for (i=0; i<8; ++i) x = (x << 1) + mem[add][i] - '0';
	return x;
}

inline void store(const int add, unsigned char x) {
	int i, j, k;
	for (i=7; i>=0; --i) {
		mem[add][i] = (x & 0x1) + '0';
		x >>= 1;
	}
}

void gao() {
	int op, add;
	int i, j, k;
	accu = 0, pc = 0;
	while (true) {
		op = gao(pc);
		++pc;
		pc %= 32;
		if (op == STA) {
			add = read(pc-1);
			store(add, accu);
		} else if (op == LDA) {
			add = read((pc+31)%32);
			accu = load(add);
		} else if (op == BEQ) {
			if (accu == 0) pc = read((pc+31)%32);
		} else if (op == NOP) {
			continue;
		} else if (op == DEC) {
			--accu;
		} else if (op == INC) {
			++accu;
		} else if (op == JMP) {
			pc = read((pc+31)%32);
		} else if (op == HLT) {
			output(accu);
			return;
		} else {
			throw "gao() error !";
		}
	}
}

int main() {
	int i, j, k;
	int m, n;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (input()) gao();
	return 0;
}