/*
ID: delta 4d
PROG: preface
LANG: C++
*/

#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

map <char, int> cc;
map <int, char> mp;

void init() {
	mp[1] = 'I';
	mp[5] = 'V';
	mp[10] = 'X';
	mp[50] = 'L';
	mp[100] = 'C';
	mp[500] = 'D';
	mp[1000] = 'M';
}

int main() {
#ifndef __DELTA__
	freopen("preface.in", "r", stdin);
	freopen("preface.out", "w", stdout);
#endif
	init();	
	return 0;
}
