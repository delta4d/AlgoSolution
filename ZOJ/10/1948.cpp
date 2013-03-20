#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000;
const int MAXT = 1000;
int f[MAXN];
queue<int> team[MAXT];

int main() {
	int x;
	int i, j, k;
	int m, n;
	int cn(0);
	int first_team, team_num;
	queue<int> team_order;
	char op[16];
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n), n) {
		//memset(f, -1, sizeof(f));
		for (i=0; i<n; ++i) {
			scanf("%d", &m);
			for (j=0; j<m; ++j) {
				scanf("%d", &k);
				f[k] = i;
			}
			while (!team[i].empty()) team[i].pop();
		}
		printf("Scenario #%d\n", ++cn);
		while (!team_order.empty()) team_order.pop();
		scanf("%s", op);
		while (op[0] != 'S') {
			if (op[0] == 'E') {
				scanf("%d", &x);
				team_num = f[x];
				if (team[team_num].size() == 0) {
					team_order.push(team_num);
				}
				team[team_num].push(x);
			} else if (op[0] == 'D') {
				first_team = team_order.front();
				k = team[first_team].front();
				team[first_team].pop();
				if (team[first_team].empty()) team_order.pop();
				printf("%d\n", k);
			} else {
				throw "input error !";
			}
			scanf("%s", op);
		}
		puts("");
	}
	return 0;
}