#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

vector<char> tree[26];
map<string, int> rec;
char buff[80];
char temp[80];

struct node {
	string s;
	int cnt;
	node(string s, int c):s(s), cnt(c) {}
};

vector<node> v;

bool cmp(const node &a, const node &b) {
	return a.s < b.s;
}

void gen_tree() {
	int i;
	for (i=0; i<3; ++i) tree[i].push_back('2');
	for (; i<6; ++i) tree[i].push_back('3');
	for (; i<9; ++i) tree[i].push_back('4');
	for (; i<12; ++i) tree[i].push_back('5');
	for (; i<15; ++i) tree[i].push_back('6');
	tree[i].push_back('7'); tree[i+2].push_back('7'); tree[i+3].push_back('7'); i += 4;
	for (; i<22; ++i) tree[i].push_back('8');
	for (; i<25; ++i) tree[i].push_back('9');
}

void dfs(int d) {
	int i, j, k(buff[d]-'A');
	int lim;
	if (d == 8) {
		temp[d] = '\0';
		string s(temp);
		if (rec.find(s) != rec.end()) ++rec[s];
		else rec.insert(map<string, int>::value_type(s, 1));
		return;
	}
	if (d == 3) {
		temp[d] = '-';
		dfs(d+1);
	} else if (buff[d] <= '9' && buff[d] >= '0') {
		temp[d] = buff[d];
		dfs(d+1);
	} else {
		lim = tree[k].size();
		for (i=0; i<lim; ++i) {
			temp[d] = tree[k][i];
			dfs(d+1);
		}
	}
}

int main() {
	int t, tc;
	int m, n;
	int i, j, k, len;
	map<string, int>::iterator it;
	//freopen("f:\\in.txt", "r", stdin);
	gen_tree();
	scanf("%d", &tc);
	for (t=0; t<tc; ++t) {
		rec.erase(rec.begin(), rec.end());
		scanf("%d", &n);
		for (i=0; i<n; ++i) {
			scanf("%s", temp);
			len = strlen(temp);
			k = 0;
			for (j=0; j<len; ++j) {
				if (temp[j] != '-') {
					buff[k] = temp[j];
					++k;
					if (k == 3) {
						buff[k] = '-';
						++k;
					}
				}
			}
			dfs(0);
		}
		v.clear();
		for (it=rec.begin(); it!=rec.end(); ++it) {
			if (it->second > 1) {
				v.push_back(node(it->first, it->second));
			}
		}
		sort(v.begin(), v.end(), cmp);
		if (v.empty()) {
			puts("No duplicates.");
		} else {
			vector<node>::iterator vit;
			for (vit=v.begin(); vit!=v.end(); ++vit) {
				cout << vit->s << ' ' << vit->cnt << endl;
			}
		}
		if (t != tc - 1) puts("");
	}
	return 0;
}