#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
const int MAXL = 101;

#define EXTRA 1
#define LOSE -1
#define DST 100

int step[MAXN];
int to_where[MAXL];
int extra_lose[MAXL];

inline bool input_step(int &n) {
	int x;
	n = 0;
	if (scanf("%d", &x) != 1) return false;
	while (x != 0) {
		step[n++] = x;
		scanf("%d", &x);
	}
	return true;
}

inline void input_to_where() {
	int s, t;
	memset(to_where, 0, sizeof(to_where));
	scanf("%d %d", &s, &t);
	while (s != 0 || t != 0) {
		to_where[s] = t;
		scanf("%d %d", &s, &t);
	}
}

inline void input_extra_lose() {
	int x;
	memset(extra_lose, 0, sizeof(extra_lose));
	scanf("%d", &x);
	while (x != 0) {
		extra_lose[x>0?x:-x] = x > 0 ? EXTRA : LOSE;
		scanf("%d", &x);
	}
}

inline int next(const int pn, const int cur) {
	return cur == pn ? 1 : cur + 1;
}

inline int next_position(int cur_pos, int step) {
	int np(cur_pos+step);
	if (np > DST) return cur_pos;
	if (to_where[np]) return to_where[np];
	return np;
}

void play(const int n, const int pn) {
	int i(0), j, k;
	int turn(1);
	int pos[10];
	int next_pos;
	bool lose_chance[10];
	memset(pos, 0, sizeof(pos));
	memset(lose_chance, false, sizeof(lose_chance));
	while(i < n) {
		//printf("player: %d  position: %d\n", turn, pos[turn]);
		if (lose_chance[turn]) {
			lose_chance[turn] = false;
		} else {
			pos[turn] = next_position(pos[turn], step[i++]);
			if (pos[turn] == DST) {
				printf("%d\n", turn);
				return;
			}
			if (extra_lose[pos[turn]] == LOSE) {
				lose_chance[turn] = true;
			} else {
				while (extra_lose[pos[turn]] == EXTRA) {
					pos[turn] = next_position(pos[turn], step[i++]);
					if (pos[turn] == DST) {
						printf("%d\n", turn);
						return;
					}
				}
				if (extra_lose[pos[turn]] == LOSE) lose_chance[turn] = true;
			}
		}
		turn = next(pn, turn);
	}
}

int main() {
	int i, j, k;
	int m, n;
	int player_num;
	//freopen("f:\\in.txt", "r", stdin);
	input_step(n);
	while (scanf("%d", &player_num), player_num) {
		input_to_where();
		input_extra_lose();
		play(n, player_num);
	}
	return 0;
}