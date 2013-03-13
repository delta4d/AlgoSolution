#include <cstdio>
using namespace std;

int cc[26];

int main() {
	int tot(0);
	char s[1024];

	scanf("%s", s);
	for (int i=0; s[i]; ++i) ++cc[s[i]-'a'];
	for (int i=0; i<26; ++i) tot += cc[i] & 1;
	if (!tot || tot & 1) puts("First");
	else puts("Second");

	return 0;
}

// 3295590	 Mar 12, 2013 8:23:15 PM	delta_4d	 276B - Little Girl and Game	 GNU C++	Accepted	15 ms	0 KB
