#include <cstdio>
#include <cstring>
using namespace std;

const char suit[4][10] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const int MAXN = 101;

struct node {
	int x;
	int c;
	node(int _x=0, int _c=0):x(_x), c(_c) {}
	void print() {
		if (x == 1) printf("Ace of ");
		else if (x == 11) printf("Jack of ");
		else if (x == 12) printf("Queen of ");
		else if (x == 13) printf("King of ");
		else printf("%d of ", x);
		printf("%s\n", suit[c]);
	}
} deck[53], temp[53];
int shuffle[100][53];

inline void init() {
	int i, j, k;
	for (i=1; i<=52; ++i) {
		k = i + 1;
		k %= 13;
		if (k == 0) k = 13;
		deck[i].x = k, deck[i].c = (i - 1) / 13;
	}
}

int main() {
	int m, n;
	int i, j, k;
	int t;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	init();
	scanf("%d", &n);
	for (i=1; i<=n; ++i) for (j=1; j<=52; ++j) scanf("%d", &shuffle[i][j]);
	while (scanf("%d", &k) != EOF) {
		for (i=1; i<=52; ++i) temp[i] = deck[shuffle[k][i]];
		for (i=1; i<=52; ++i) deck[i] = temp[i];
		for (i=1; i<=52; ++i) deck[i].print();
		puts("");
	}
	return 0;
}