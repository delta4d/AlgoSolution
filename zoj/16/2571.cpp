#include <stack>
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define DIGIT 0
#define BRACKT 1
#define ALPHA 2

stack<string> s;
stack<string> temp;
vector<string> f;
char buff[256], word[256];

inline int get_state(const char x) {
	if ('0' <= x && x <= '9') return DIGIT;
	if (x == '(' || x == ')') return BRACKT;
	return ALPHA;
}

inline bool is_digit(string s) {
	return get_state(s[0]) == DIGIT;
}

inline int to_digit(string s) {
	char buff[10];
	int x;
	strcpy(buff, s.c_str());
	sscanf(buff, "%d", &x);
	return x;
}

int main() {
	int i, j, k;
	int m, n, tc;
	int prev, next;
	int len;
	string ss;
	//freopen("f:\\in.txt", "r", stdin);
	//freopen("f:\\out.txt", "w", stdout);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", buff);
		f.clear();
		k = 0;
		len = strlen(buff);
		prev = get_state(buff[0]);
		for (i=0; buff[i]; ++i) {
			next = get_state(buff[i]);
			if (next == prev && prev == DIGIT) {
				word[k++] = buff[i];
			} else {
				if (k > 0) {
					word[k] = '\0';
					f.push_back(string(word));
					k = 0;
				}
				word[0] = buff[i], word[1] = '\0';
				f.push_back(string(word));
			}
			prev = next;
		}
		if (k > 0) {
			word[k] = '\0';
			f.push_back(string(word));
		}
		//for (i=0; i!=f.size(); ++i) puts(f[i].c_str()); puts("");
		while (!s.empty()) s.pop();
		for (i=0; i!=f.size(); ++i) {
			if (s.empty()) {
				s.push(f[i]);
			} else {
				if (f[i] == "(") {
					s.push(f[i]);
				} else if (f[i] == ")") {
					string t("");
					while (!temp.empty()) temp.pop();
					while (true) {
						ss = s.top();
						s.pop();
						if (ss == "(") break;
						temp.push(ss);
					}
					while (!temp.empty()) {
						t += temp.top();
						temp.pop();
					}
					if (!s.empty()) {
						ss = s.top();
						if (is_digit(ss)) {
							s.pop();
							string tt("");
							len = to_digit(ss);
							for (k=0; k<len; ++k) tt += t;
							s.push(tt);
						}
					}
				} else if (is_digit(f[i])) {
					s.push(f[i]);
				} else {
					ss = s.top();
					if (is_digit(ss)) {
						s.pop();
						string tt("");
						len = to_digit(ss);
						for (k=0; k<len; ++k) tt += f[i];
						s.push(tt);
					} else {
						s.push(f[i]);
					}
				}
			}
		}
		ss.clear();
		while (!temp.empty()) temp.pop();
		while (!s.empty()) {
			temp.push(s.top());
			s.pop();
		}
		while (!temp.empty()) {
			ss += temp.top();
			temp.pop();
		}
		puts(ss.c_str());
	}
	return 0;
}