#include <cstdio>
using namespace std;

const int x[] = {1, 0, 18, 0, 1800, 0, 670320, 0, 734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", x[n-1]);
	return 0;
}

// 3412134	 Mar 27, 2013 5:41:42 PM	delta_4d	 285D - Permutation Sum	 GNU C++	Accepted	15 ms	0 KB
