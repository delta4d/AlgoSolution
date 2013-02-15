#include <set>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXL = 80;
set<int> mark;
char buff[MAXL];

struct node {
	string s;
	int x;
	node(string s="", int x=0):s(s), x(x) {}
};
vector<node> v;

bool operator<(const string &a, const string &b) {
	int lena(a.length()), lenb(b.length());
	if (lena != lenb) return lena < lenb;
	for (int i=0; i<lena; ++i) if (a[i] != b[i]) return a[i] < b[i];
}

bool cmp(const node &a, const node &b) {
	return a.s < b.s;
}

bool build_tree() {
	int i, j, k, len;
	vector<node>::iterator it;
	mark.clear();
	mark.insert(1);
	if (v[0].s != "") return false;
	for (i=1; i!=v.size(); ++i) {
		//cout << it->s << ' ' << it->x << endl;
		string x(v[i].s);
		len = x.length();
		k = 1;
		for (j=0; j<len-1; ++j) {
			k <<= 1;
			k += x[j] == 'L' ? 0 : 1;
			if (mark.find(k) == mark.end()) return false;
		}
		k <<= 1;
		k += x[j] == 'L' ? 0 : 1;
		if (mark.find(k) != mark.end()) return false;
		mark.insert(k);
	}
	return true;
}

bool input() {
	int i, j, k;
	int len;
	char c;
	char temp[MAXL];
	bool legal(true);
	v.clear(); mark.clear();
	if (scanf("%s", buff) == EOF) return false;
	while (strcmp(buff, "()") != 0) {
		sscanf(buff, "%*c %d %c %s", &k, &c, temp);
		temp[strlen(temp)-1] = '\0';
		if (legal) {
			if (mark.find(k) != mark.end()) {
				legal = false;
				goto next;
			}
			string x(temp);
			v.push_back(node(x, k));
		}
	next:	
		scanf("%s", buff);
	}
	if (!legal) {
		puts("not complete");
	} else {
		sort(v.begin(), v.end(), cmp);
		if (!build_tree()) {
			puts("not complete");
		} else {
			vector<node>::iterator it;
			cout << v.begin()->x;
			for (it=v.begin()+1; it!=v.end(); ++it) {
				cout << ' ' << it->x;
			}
			puts("");
		}
	}
	return true;
}

int main() {
	int i, j, k;
	int n, m;
	//freopen("f:\\in.txt", "r", stdin);
	while (input()) {}
	return 0;
}