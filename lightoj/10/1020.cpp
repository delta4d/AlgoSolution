#include <cstdio>
using namespace std;

int main() {
	int tc, cn = 0, n;
	for (scanf("%d", &tc); tc--; ) {
		char name[10];
		scanf("%d%s", &n, name);
		printf("Case %d: ", ++cn);
		if (name[0] == 'A') printf("%s\n", n%3==1?"Bob":"Alice");
		else printf("%s\n", n%3==0?"Alice":"Bob");
	}
	return 0;
}

// 253092	2013-08-18 23:28:02	 1020 - A Childhood Game	 C++	 0.008	 1088	Accepted
