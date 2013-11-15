#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, vector<string> > cc;
map<char, char> f;
set<string> legal;
char buff[80];

void gen() {
	int i;
	for (i=0; i<3; ++i) {
		f.insert(map<char, char>::value_type('a'+i, '2'));
		f.insert(map<char, char>::value_type('A'+i, '2'));
	}
	for (i=0; i<3; ++i) {
		f.insert(map<char, char>::value_type('d'+i, '3'));
		f.insert(map<char, char>::value_type('D'+i, '3'));
	}
	for (i=0; i<3; ++i) {
		f.insert(map<char, char>::value_type('g'+i, '4'));
		f.insert(map<char, char>::value_type('G'+i, '4'));
	}
	for (i=0; i<3; ++i) {
		f.insert(map<char, char>::value_type('j'+i, '5'));
		f.insert(map<char, char>::value_type('J'+i, '5'));
	}
	for (i=0; i<3; ++i) {
		f.insert(map<char, char>::value_type('m'+i, '6'));
		f.insert(map<char, char>::value_type('M'+i, '6'));
	}
	for (i=0; i<4; ++i) {
		if (i == 1) continue;
		f.insert(map<char, char>::value_type('p'+i, '7'));
		f.insert(map<char, char>::value_type('P'+i, '7'));
	}
	for (i=0; i<3; ++i) {
		f.insert(map<char, char>::value_type('t'+i, '8'));
		f.insert(map<char, char>::value_type('T'+i, '8'));
	}
	for (i=0; i<3; ++i) {
		f.insert(map<char, char>::value_type('w'+i, '9'));
		f.insert(map<char, char>::value_type('W'+i, '9'));
	}
	f.insert(map<char, char>::value_type('q', '0'));
	f.insert(map<char, char>::value_type('Q', '0'));
	f.insert(map<char, char>::value_type('z', '0'));
	f.insert(map<char, char>::value_type('Z', '0'));
}

int main() {
	int i, j, k;
	int len, n, m;
	gen();
	//freopen("f:\\in.txt", "r", stdin);
	while (*gets(buff) != '#') {
		string x("");
		string s(buff);
		for (char *p=buff; *p!='\0'; ++p) x += f[*p];
		if (cc.find(x) == cc.end()) { //not find x
			vector<string> a;
			cc.insert(map<string, vector<string> >::value_type(x, a));
			cc[x].clear();
			cc[x].push_back(s);
			continue;
		}
		vector<string>::iterator vsi;
		for (vsi=cc[x].begin(); vsi!=cc[x].end(); ++vsi) {
			if (*vsi == s) continue; // if s already exits
		}
		cc[x].push_back(s);
	}
	map<string, vector<string> >::iterator it;
	for (it=cc.begin(); it!=cc.end(); ++it) {
		sort((it->second).begin(), (it->second).end());
	}
	string s;
	while (cin >> s) {
		it = cc.find(s);
		if (it == cc.end()) {
			puts("NONE");
		} else {
			cout << *(it->second).begin();
			for (i=1; i!=(it->second).size(); ++i) {
				cout << ' ' << (it->second)[i];
			}
			puts("");
		}
	}
	return 0;
}