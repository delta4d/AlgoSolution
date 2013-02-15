#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int res;
int t[6][3];
int o[6];
bool visit[6];

inline int next(const int x) {
	return (x + 1) % 3;
}

inline int pre(const int x) {
	return (x + 2) % 3;
}

inline void judge() {
	int i[6];
	for (i[0]=0; i[0]<3; ++i[0]) {
		for (i[1]=0; i[1]<3; ++i[1]) {
			for (i[2]=0; i[2]<3; ++i[2]) {
				for (i[3]=0; i[3]<3; ++i[3]) {
					for (i[4]=0; i[4]<3; ++i[4]) {
						for (i[5]=0; i[5]<3; ++i[5]) {
							if (t[o[0]][next(i[0])] == t[o[1]][pre(i[1])] &&
								t[o[1]][next(i[1])] == t[o[2]][pre(i[2])] &&
								t[o[2]][next(i[2])] == t[o[3]][pre(i[3])] &&
								t[o[3]][next(i[3])] == t[o[4]][pre(i[4])] &&
								t[o[4]][next(i[4])] == t[o[5]][pre(i[5])] &&
								t[o[5]][next(i[5])] == t[o[0]][pre(i[0])]) {
								res = max(res, t[o[0]][i[0]] + t[o[1]][i[1]] + 
								t[o[2]][i[2]] + t[o[3]][i[3]] + t[o[4]][i[4]] + t[o[5]][i[5]]);	
							}
						}
					}
				}
			}
		}
	}
}

void dfs(int d) {
	int i, j, k;
	if (d == 6) {
		judge();
		return;
	}
	for (i=0; i<6; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			o[d] = i;
			dfs(d+1);
			visit[i] = false;
		}
	}
}

int main() {
	int i, j, k;
	char buff[2];
	//freopen("f:\\in.txt", "r", stdin);
	while (true) {
		for (i=0; i<6; ++i) for (j=0; j<3; ++j) scanf("%d", t[i]+j);
		res = -INF;
		memset(visit, false, sizeof(visit));
		visit[0] = true;
		dfs(1);
		if (res == -INF) puts("none");
		else printf("%d\n", res);
		scanf("%s", buff);
		if (buff[0] == '$') break;
	}
	return 0;
}