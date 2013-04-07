nclude <cstdio>
using namespace std;

const int MAXN = 5000000 + 86;
const unsigned int SEED = 0xFFFFFFFB;

char s[MAXN];
int f[MAXN];

int main() {
	scanf("%s", s);
	unsigned int x = 0, y = 0, p = 1;
	int tot = 0;
	
	for (int i=0; s[i]; ++i) {
		x = x * SEED + s[i];
		y = y + s[i] * p;
		p = p * SEED;
		if (x == y) {
			f[i] = i ? f[(i-1)/2] + 1 : 1;
			tot += f[i];
		}
	}

	printf("%d\n", tot);

	return 0;	
}

// 3480597	 Apr 6, 2013 9:06:39 PM	delta_4d	 D - Palindrome Degree	 GNU C++	Accepted	 109 ms	 24400 KB
