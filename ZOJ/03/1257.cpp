#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL = 21;

struct lot {
	int p[MAXL];
	int w[MAXL];
	
	lot() {
		memset(p, -1, sizeof(p));
		memset(w, -1, sizeof(w));
	}
	void reset() {
		memset(p, -1, sizeof(p));
		memset(w, -1, sizeof(w));
	}
	int pre(const int pos) {
		return pos == 1 ? 20 : pos - 1;
	}
	int nxt(const int pos) {
		return pos == 20 ? 1 : pos + 1;
	}
	int sh(const int cur, const int off) {
		int k((cur + off) % 20);
		return k == 0 ? 20 : k;
	}
	void wait(const int pos) {
		w[pos] = pos;
	}
	void leave(const int pos) {
		int i, j, k;
		int cnt(0);
		for (i=pos; cnt<20; ++cnt,i=pre(i)) {
			if (w[i] != -1) break;
		}
		if (cnt == 20) {
			p[i] = 0;
			return;
		}
		p[pos] = w[i];
		w[i] = -1;
		k = pos - i;
		if (k < 0) k += 20;
		int buff[MAXL];
		for (i=1; i<MAXL; ++i) buff[sh(i, k)] = w[i];
		for (i=1; i<MAXL; ++i) w[i] = buff[i];		
	}
	void output(const int pos) {
		int i, j, k;
		for (i=1; i<MAXL; ++i) if (p[i] == pos) {
			printf("Original position %d parked in %d\n", pos, i);
			return;
		}
		printf("Original position %d did not park\n", pos);
	}
};

int main() {
	int i, j, k;
	int f[MAXL];
	int fp(0);
	lot park;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &k);
	while (k != 99) {
		f[fp++] = k;
		park.wait(k);
		scanf("%d", &k);
	}
	while (scanf("%d", &k) != EOF) {
		park.leave(k);
	}
	for (i=0; i<fp; ++i) park.output(f[i]);
	return 0;
}