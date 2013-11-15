#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const char res[3][20] = {"Black wins.", "White wins.", "Tie."};

struct poker {
	int value;
	char suit;
	
	bool input() {
		char buff[3];
		if (scanf("%s", buff) == EOF) return false;
		if (buff[0] >= '0' && buff[0] <= '9') value = buff[0] - '0';
		else if (buff[0] == 'T') value = 10;
		else if (buff[0] == 'J') value = 11;
		else if (buff[0] == 'Q') value = 12;
		else if (buff[0] == 'K') value = 13;
		else if (buff[0] == 'A') value = 14;
		else throw "input error !";
		suit = buff[1];
		return true;
	}
};

inline bool value_cmp(const poker &a, const poker &b) {
	if (a.value != b.value) return a.value > b.value;
	return a.suit < b.suit;
}

inline bool suit_cmp(const poker &a, const poker &b) {
	if (a.suit != b.suit) return a.suit < b.suit;
	return a.value > b.value;
}

struct hands {
	poker p[5];	
	
	bool input() {
		for (int i=0; i<5; ++i) {
			if (!p[i].input()) return false;
		}
		return true;
	}
	void order_by_suit() {
		sort(p, p+5, suit_cmp);
	}
	void order_by_value() {
		sort(p, p+5, value_cmp);	
	}
	bool is_straight_flush(int ret[]) {
		int i, j, k;
		for (i=0; i<4; ++i) {
			if (p[i].suit != p[i+1].suit) return false;
		}
		order_by_value();
		for (i=0; i<4; ++i) {
			if (p[i].value != p[i+1].value + 1) return false;
		}
		ret[0] = p[0].value;
		return true;
	}
	bool is_four_of_a_kind(int ret[]) {
		int i, j, k;
		order_by_value();
		for (i=0; i<2; ++i) {
			for (j=0; j<3; ++j) {
				if (p[i+j].value != p[i+j+1].value) break;
			}
			if (j < 3) continue;
			ret[0] = p[i].value;
			return true;
		}
		return false;
	}
	bool is_full_house(int ret[]) {
		int i, j, k;
		order_by_value();
		for (i=0; i<4; i+=2) {
			if (p[i].value == p[i+1].value && p[i+1].value == p[i+2].value) {
				if (i == 0) {
					if (p[3].value == p[4].value) {
						ret[0] = p[i].value;
						return true;
					}
				} else if (i == 2) {
					if (p[0].value == p[1].value) {
						ret[0] = p[i].value;
						return true;
					}
				}
			}
		}
		return false;
	}
	bool is_flush(int ret[]) {
		int i, j, k;
		for (i=0; i<4; ++i) {
			if (p[i].suit != p[i+1].suit) return false;
		}
		order_by_value();
		for (i=0; i<5; ++i) ret[i] = p[i].value;
		return true;
	}
	bool is_straight(int ret[]) {
		int i, j, k;
		order_by_value();
		for (i=0; i<4; ++i) {
			if (p[i].value != p[i+1].value + 1) return false;
		}
		ret[0] = p[0].value;
		return true;
	}
	bool is_three_of_a_kind(int ret[]) {
		int i, j, k;
		for (i=0; i<3; ++i) {
			for (j=0; j<2; ++j) {
				if (p[i+j].value != p[i+j+1].value) break;
			}
			if (j < 2) continue;
			ret[0] = p[i].value;
			return true;
		}
		return false;
	}
	bool is_two_pairs(int ret[]) {
		int i, j, k;
		order_by_value();
		if (p[1].value == p[2].value && p[3].value == p[4].value) {
			ret[0] = max(p[1].value, p[3].value);
			ret[1] = p[1].value + p[3].value - ret[0];
			ret[2] = p[4].value;
			return true;
		}
		if (p[0].value == p[1].value && p[3].value == p[4].value) {
			ret[0] = max(p[0].value, p[3].value);
			ret[1] = p[0].value + p[3].value - ret[0];
			ret[2] = p[2].value;
			return true;
		}
		if (p[0].value == p[1].value && p[2].value == p[3].value) {
			ret[0] = max(p[0].value, p[2].value);
			ret[1] = p[0].value + p[2].value - ret[0];
			ret[2] = p[4].value;
			return true;
		}
		return false;
	}
	bool is_pair(int ret[]) {
		int i, j, k;
		order_by_value();
		for (i=0; i<4; ++i) {
			if (p[i].value == p[i+1].value) {
				ret[0] = p[i].value;
				k = 1;
				for (j=0; j<5; ++j) {
					if (j == i || j == i + 1) continue;
					ret[k++] = p[j].value;
				}
				return true;
			}
		}
		return false;
	}
	void high_order(int ret[]) {
		order_by_value();
		for (int i=0; i<5; ++i) ret[i] = p[i].value;
	}
	int decide_type(int ret[]) {
		if (is_straight_flush(ret)) return 0;
		if (is_four_of_a_kind(ret)) return 1;
		if (is_full_house(ret)) return 2;
		if (is_flush(ret)) return 3;
		if (is_straight(ret)) return 4;
		if (is_three_of_a_kind(ret)) return 5;
		if (is_two_pairs(ret)) return 6;
		if (is_pair(ret)) return 7;
		high_order(ret);
		return 8;
	}
	int compare(hands &a) {
		int i, j, k;
		int ret1[5], ret2[5];
		int t1, t2;
		memset(ret1, 0, sizeof(ret1));
		memset(ret2, 0, sizeof(ret2));
		t1 = decide_type(ret1);
		t2 = a.decide_type(ret2);
		if (t1 < t2) return 0;
		if (t1 > t2) return 1;
		for (i=0; i<5; ++i) {
			if (ret1[i] > ret2[i]) return 0;
			if (ret1[i] < ret2[i]) return 1;
		}
		return 2;
	}
};

int main() {
	int i, j, k;
	hands a, b;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	while (a.input()) {
		b.input();
		puts(res[a.compare(b)]);
	}
	return 0;
}