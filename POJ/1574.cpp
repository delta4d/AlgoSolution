#include <cstdio>
#include <algorithm>
using namespace std;

inline int next(const int x) {
	return (x + 1) % 3;
}

inline int pre(const int x) {
	return (x + 2) % 3;
}

int main() {
	const int INF = 0x3f3f3f3f;
	int i[6], j, k;
	int t[6][3];
	int o[6];
	int res;
	char buff[2];
	//freopen("f:\\in.txt", "r", stdin);
	for (;;) {
		for (k=0; k<6; ++k) {
			for (j=0; j<3; ++j) scanf("%d", t[k]+j);
		}
		res = -INF;
		for (o[0]=0; o[0]<6; o[0]++) {
			for (o[1]=0; o[1]<6; ++o[1]) {
				if (o[1] == o[0]) continue;
				for (o[2]=0; o[2]<6; ++o[2]) {
					if (o[2] == o[0] || o[2] == o[1]) continue;
					for (o[3]=0; o[3]<6; ++o[3]) {
						if (o[3] == o[0] || o[3] == o[1] || o[3] == o[2]) continue;
						for (o[4]=0; o[4]<6; ++o[4]) {
							if (o[4] == o[3] || o[4] == o[2] || o[4] == o[1] || o[4] == o[0]) continue;
							for (o[5]=0; o[5]<6; ++o[5]) {
								if (o[5] == o[4] || o[5] == o[3] || o[5] == o[2]) continue;
								if (o[5] == o[1] || o[5] == o[0]) continue;
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
						}
					}
				}
			}
		}
		if (res == -INF) puts("none");
		else printf("%d\n", res);
		scanf("%s", buff);
		if (buff[0] == '$') break;
	}
	
	return 0;
}