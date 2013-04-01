#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

bool operator<(string a, string b) {
	int la(a.length()), lb(b.length());
	if (la != lb) return la < lb;
	int pa(0), pb(0);
	while (pa < la && pb < lb) {
		if (a[pa] != b[pb]) return a[pa] < b[pb];
		++pa, ++pb;
	}
	return false;
}

int main() {
	string a = "128";
	string b = "32768";
	string c = "2147483648";
	string d = "9223372036854775808";
	string x;
	cin >> x;
	if (x < a) puts("byte");
	else if (x < b) puts("short");
	else if (x < c) puts("int");
	else if (x < d) puts("long");
	else puts("BigInteger");
	return 0;
}

// 328070	 Mar 8, 2011 6:25:26 AM	delta_4d	 A - Petya and Java	 GNU C++	Accepted	 30 ms	 1400 
