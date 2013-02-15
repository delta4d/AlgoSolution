#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 26;

struct entity {
	char index;
	bool right[MAXN];
	char out[MAXN+1];
	void init() {
		memset(right, false, sizeof(right));
	}
	void increase(char x[]) {
		for (int i=0; x[i]; ++i) right[x[i]-'a'] = true;
	}
	void decrease(char x[]) {
		for (int i=0; x[i]; ++i) right[x[i]-'a'] = false;
	}
	void equal(char x[]) {
		init();
		for (int i=0; x[i]; ++i) right[x[i]-'a'] = true;
	}
	void genout() {
		int p(0);
		for (int i=0; i<MAXN; ++i) if (right[i]) out[p++] = i + 'a';
		out[p] = '\0';
	}
	void output() {
		printf("%s", out);
	}
	bool eout(entity &x) {
		return strcmp(out, x.out) == 0;
	}
	bool empty() {
		genout();
		return strcmp(out, "") == 0;
	}
} f[MAXN];

char s[80], buff[54];

int main() {
	int i, j, k;
	int n, m;
	int cn(0);
	char *cp;
	vector<entity> res;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", s), s[0]!='#') {
		for (i=0; i<MAXN; ++i) {
			f[i].init();
			f[i].index = i + 'A';
		}
		cp = strtok(s, ",\n");
		while (cp != NULL) {
			for (k=0; cp[k]!='-'&&cp[k]!='+'&&cp[k]!='='; ++k);
			for (i=0; i<k; ++i) {
				if (cp[k] == '+') f[cp[i]-'A'].increase(cp+k+1);
				else if (cp[k] == '-') f[cp[i]-'A'].decrease(cp+k+1);
				else if (cp[k] == '=') f[cp[i]-'A'].equal(cp+k+1);
				else throw "error";
			}
			cp = strtok(NULL, ",\n");	
		}
		res.clear();
		for (i=0; i<MAXN; ++i) if (!f[i].empty()) res.push_back(f[i]);
		printf("%d:", ++cn);
		if (res.size() > 0) {
			for (i=0; i!=res.size(); ++i) {
				if (i == 0) {
					printf("%c", res[i].index);
				} else {
					if (!res[i].eout(res[i-1])) res[i-1].output();
					printf("%c", res[i].index);
				}
			}
			res[i-1].output();
		}
		puts("");
	}
	return 0;
}