#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char hive[23][23] = {
"         _",
"       _/ \\_",
"     _/ \\_/ \\_",
"   _/ \\_/ \\_/ \\_",
" _/ \\_/ \\_/ \\_/ \\_",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"/ \\_/ \\_/ \\_/ \\_/ \\",
"\\_/ \\_/ \\_/ \\_/ \\_/",
"  \\_/ \\_/ \\_/ \\_/",
"    \\_/ \\_/ \\_/",
"      \\_/ \\_/",
"        \\_/",
};

const int limit[9] = {7, 8, 9, 10, 11, 10, 9, 8, 7};
const int start[9] = {17, 18, 19, 20, 21, 20, 19, 18, 17};

struct hive_t {
	int p[9];
	int candy_num;
	char candy[9][23];
	char thive[23][23];
	
	void init() {
		memset(p, 0, sizeof(p));
		candy_num = 0;
	}
	void deal(char op[]) {
		int t(op[0] - 'A');
		if (p[t] >= limit[t]) return;
		if (p[t] != 0 && candy[t][p[t]-1] == op[1]) --p[t], ++candy_num;
		else candy[t][p[t]] = op[1], ++p[t];
	}
	void output() {
		int i, j, k;
		memcpy(thive, hive, sizeof(hive));
		for (i=0; i<9; ++i) {
			for (j=0; j<p[i]; ++j) {
				thive[start[i]-2*j][i*2+1] = candy[i][j];
			}
		}
		printf("The number of candy is %d.\n", candy_num);
		for (i=0; i<23; ++i) printf("%s\n", thive[i]);
	}
};

int main() {
	int i, j, k;
	int n;
	char buff[3];
	hive_t x;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		x.init();
		for (i=0; i<n; ++i) {
			scanf("%s", buff);
			x.deal(buff);
		}
		x.output();
	}
	return 0;
}