#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

const int maxn = 181445;

struct SType {
	int statue[10];
	int place;
	int step;

	SType() {}
	SType(int *a, int p, int s) {
		for (int i = 0; i < 9; i++) {
			statue[i] = a[i];
		}
		place = p;
		step = s;
	}
};

int dirx[] = {-1, 0, 0, 1};
int diry[] = {0, -1, 1, 0};
int poschg[] = {-3, -1, 1, 3};

int move (SType s, SType &e, int optNum) {
	int i, j, tr, tc, tp;

	i = s.place / 3;
	j = s.place % 3;

	tr = i + dirx[optNum];
	tc = j + diry[optNum];
	if (tr >= 0 && tr < 3 && tc >= 0 && tc < 3) {
		e = s;
		tp = e.place;
		e.place += poschg[optNum];
		e.statue[tp] = e.statue[e.place];
		e.statue[e.place] = 0;
		e.step++;
		return 1;
	}

	return 0;
}

int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};

int cantor (SType s) {
	int ans = 0, num = 0, n = 8;
	int flag[10] = {0};
	for (int i = 0; i < 9; i++) {
		int up = s.statue[i];
		flag[up] = 1;
		num = 0;
		for (int k = 0; k < up; k++) if (!flag[k]) num++;
		ans += num * fact[n];
		n--;
	}
	return ans;
}

inline bool isEnd (SType s) {
	if (s.place != 8) return false;
	if (s.statue[0] == 1 && s.statue[1] == 2 && s.statue[2] == 3 &&
		s.statue[3] == 4 && s.statue[4] == 5 && s.statue[5] == 6 &&
		s.statue[6] == 7 && s.statue[7] == 8 && s.statue[8] == 0) {
		return true;
	}
	return false;
}

SType q1[maxn], q2[maxn];
int head1, rear1, head2, rear2, vis[2 * maxn], parent[2 * maxn];
char preOpt[2 * maxn];

void output1 (int code, int scode) {
	if (code == scode) return;
	output1(parent[code], scode);
	putchar(preOpt[code]);
}

void output2 (int code, int ecode) {
	if (code == ecode) return;
	putchar(preOpt[code]);
	output2(parent[code], ecode);
}

void bfs (SType start) {
	char opt1[] = "ulrd", opt2[] = "drlu";
	int estatue[] = {1, 2, 3, 4, 5, 6, 7, 8, 0}, ucode, rcode, ok = 0, 
		scode, ecode;
	SType end(estatue, 8, 0), u;

	scode = cantor(start);
	ecode = cantor(end);
	head1 = rear1 = head2 = rear2 = 0;
	q1[rear1++] = start;
	q2[rear2++] = end;
	vis[scode] = 1;
	vis[ecode] = 2;

	while (1) {
		//????
		if (head1 < rear1) {
			u = q1[head1++];
			ucode = cantor(u);
			for (int i = 0; i < 4; i++) {
				if (move(u, q1[rear1], i)) {
					rcode = cantor(q1[rear1]);
					if (vis[rcode] == 1) continue;
					rear1++;
					if (vis[rcode] == 2 || rcode == ecode) {
						output1(ucode, scode);
						putchar(opt1[i]);
						output2(rcode, ecode);
						return;
					}
					vis[rcode] = 1;
					parent[rcode] = ucode;
					preOpt[rcode] = opt1[i];
				}
			}
		}

		//????
		if (head2 < rear2) {
			u = q2[head2++];
			ucode = cantor(u);
			for (int i = 0; i < 4; i++) {
				if (move(u, q2[rear2], i)) {
					rcode = cantor(q2[rear2]);
					if (vis[rcode] == 2) continue;
					rear2++;
					if (vis[rcode] == 1 || rcode == ecode) {
						output1(rcode, scode);
						putchar(opt2[i]);
						output2(ucode, ecode);
						return;
					}
					vis[rcode] = 2;
					parent[rcode] = ucode;
					preOpt[rcode] = opt2[i];
				}
			}
		}
	}
}

bool isSolveable (SType s) {
	int arr[10], n = 0, num = 0;
	for (int i = 0; i < 9; i++) {
		if (s.statue[i] != 0) arr[++n] = s.statue[i];
	}
	for (int i = 1; i <= 8; i++) {
		for (int j = i + 1; j <= 8; j++) {
			if (arr[i] > arr[j]) num++;
		}
	}
	if (num & 0x1) return false;
	return true;
}

int main () {
	freopen("input.txt", "r", stdin);
	SType start;
	char c;
	while (1) {
		for (int i = 0; i < 9; i++) {
			if (scanf(" %c", &c) == EOF) return 0;
			if (c == 'x') {
				start.statue[i] = 0;
				start.place = i;
			}
			else start.statue[i] = c - '0';
		}
		start.step = 0;
		memset(vis, 0, sizeof(vis));

		if (isSolveable(start)) {
			bfs(start);
			putchar('\n');
		}
		else printf("unsolvable\n");
	}

	return 0;
}
