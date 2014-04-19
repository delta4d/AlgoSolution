#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int END = (0 << 0) + (1 << 3) + (2 << 6) + (3 << 9) + (4 << 12) + (5 << 15) + (6 << 18) + (7 << 21);
const bool is_prime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0};
int x[8];

struct state {
	int x, s, p;
	
	state(int _x=0, int _s=0, int _p=0):x(_x), s(_s), p(_p) {}

	void init(int c[]) {
		x = 0, s = 0, p = 0;
		for (int i=0; i<8; ++i) {
			x |= ((abs(c[i]) - 1) << (i * 3));
			if (c[i] < 0) s |= (1 << i);
		}
	}
	int value_at(int i) {
		i *= 3;
		return ((x & (7 << i)) >> i) + 1;
	}
	int sign_at(int i) {
		return (s & 1 << i) ? -1 : 1;
	}
	void set_value_at(int i, int v) {
		i *= 3, --v;
		x |= (7 << i);
		x ^= (7 << i);
		x |= (v << i);
	}
	void set_sign_at(int i, int sgn) {
		sgn = sgn < 0 ? 1 : 0;
		s |= (1 << i);
		s ^= (1 << i);
		s |= (sgn << i);
	}
	void swap_left(int i) {
		if (i == 0) return;
		int a = value_at(i - 1), b = value_at(i);
		set_value_at(i, a); set_value_at(i-1, b);
		int sa = sign_at(i - 1), sb = sign_at(i);
		set_sign_at(i, sa); set_sign_at(i-1, sb);
	}
	void swap_right(int i) {
		if (i == 7) return;
		int a = value_at(i), b = value_at(i + 1);
		set_value_at(i, b); set_value_at(i+1, a);
		int sa = sign_at(i), sb = sign_at(i + 1);
		set_sign_at(i, sb); set_sign_at(i+1, sa);
	}
	void move_to(int from, int to) {
		if (from > to) for (int i=from; i>to; --i) swap_left(i);
		else for (int i=from; i<to; ++i) swap_right(i);
	}
	bool can_dance(int i, int j) {
		if (i == j) return false;
		if (sign_at(i) * sign_at(j) > 0) return false;
		return is_prime[value_at(i) + value_at(j)];
	}
	void to_s() {
		for (int i=0; i<8; ++i) printf("%d ", value_at(i) * sign_at(i)); puts("");
	}
} st;
bool v[END+1];
queue <state> q;

void _move(state &cc, int i, int j) {
	if (i == j) return;
	state nxt = cc;
	++nxt.p;
	nxt.move_to(i, j);
	if (!v[nxt.x]) {
		v[nxt.x] = true;
		q.push(nxt);
	}
}

int gao() {
	while (!q.empty()) q.pop();
	memset(v, false, sizeof(v));
	q.push(st); v[st.x] = true;
	while (!q.empty()) {
		state cc = q.front(); q.pop();
		int x = cc.x, p = cc.p;
		if (x == END) return p;
		for (int i=0; i<8; ++i) {
			for (int j=0; j<8; ++j) if (cc.can_dance(i, j)) {
				_move(cc, i, j);
				if (j > i) _move(cc, i, j-1);
				else _move(cc, i, j+1);
			}
		}
	}
	return -1;
}

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		for (int i=0; i<8; ++i) scanf("%d", x+i);
		st.init(x);
		printf("Case %d: %d\n", ++cn, gao());
	}
	return 0;
}

// 308334	2014-01-06 23:07:07	 1165 - Digit Dancing	 C++	 1.212	 17296	Accepted
