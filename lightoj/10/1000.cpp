#include <cstdio>
using namespace std;

int main() {
	int tc, cn = 0, a, b;
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d%d", &a, &b);
		printf("Case %d: %d\n", ++cn, a+b);
	}
	return 0;
}

// 252009	2013-08-15 19:54:35	 1000 - Greetings from LightOJ	 C++	 0.000	 1088	Accepted
