#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 80;

int pos[5];

struct board {
	char s[MAXN];
	
	board() {
		memset(s, '\0', sizeof(s));
	}
	void input() {
		scanf("%s", s);
	}
	bool play(int player, char deck[]) {
		int i, j, k;
		int len(strlen(deck));
		for (i=pos[player]+1; s[i]; ++i) {
			if (s[i] == deck[0]) --len;
			if (len == 0) {
				pos[player] = i;
				//s[i] = player + '0';
				return s[i+1];
			}
		}
		return false;
	}
};

inline int next(int x, const int n) {
	return x == n ? 1 : x + 1;
}

int main() {
	int i, j, k;
	int pn, dn, turn;
	int win;
	char deck[3];
	bool decide;
	board cboard;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d %*d %d", &pn, &dn), pn) {
		memset(pos, -1, sizeof(pos));
		cboard.input();
		turn = 1;
		decide = false;
		for (i=0; i<dn; ++i) {
			scanf("%s", deck);
			if (decide) continue;
			if (!cboard.play(turn, deck)) {
				decide = true;
				win = turn;
				k = i + 1;
			}
			turn = next(turn, pn);
		}
		if (!decide) printf("No player won after %d cards.\n", dn);
		else printf("Player %d won after %d cards.\n", win, k);
	}
	return 0;
}