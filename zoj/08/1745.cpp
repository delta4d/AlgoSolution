#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int i, j, k;
	int pos, next, dst;
	int pstep, nstep;
	char buff[80], *cp;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &dst);
	while (true) {
		gets(buff);
		pos = 0;
		cp = strtok(buff, " ");
		while (cp != NULL) {
			if (strlen(cp) != 0) {
				sscanf(cp, "%d", &next);
				pstep = abs(dst - pos);
				nstep = abs(dst - next);
				if (nstep == 0) printf("Moving from %d to %d: found it!\n", pos, next);
				else if (nstep > pstep) printf("Moving from %d to %d: colder.\n", pos, next);
				else if (nstep < pstep) printf("Moving from %d to %d: warmer.\n", pos, next);
				else printf("Moving from %d to %d: same.\n", pos, next);
				pos = next;
			}
			cp = strtok(NULL, " ");
		}
		scanf("%d", &dst);
		if (dst == 5280) break;
		puts("");
	}
	return 0;
}