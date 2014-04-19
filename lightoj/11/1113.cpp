#include <stack>
#include <cstdio>
#include <string>
using namespace std;

stack <string> back, forward;
char op[60];
string cur;

int main() {
	int tc, cn = 0;
	for (scanf("%d", &tc); tc--; ) {
		printf("Case %d:\n", ++cn);
		while (!back.empty()) back.pop();
		while (!forward.empty()) forward.pop();
		cur = "http://www.lightoj.com/";
		while (true) {
			scanf("%s", op);
			if (op[0] == 'Q') break;
			if (op[0] == 'V') {
				scanf("%s", op);
				back.push(cur);
				cur = op;
				while (!forward.empty()) forward.pop();
				puts(cur.c_str());
			} else if (op[0] == 'B') {
				if (back.empty()) {
					puts("Ignored");
				} else {
					forward.push(cur);
					cur = back.top();
					back.pop();
					puts(cur.c_str());
				}
			} else {
				if (forward.empty()) {
					puts("Ignored");
				} else {
					back.push(cur);
					cur = forward.top();
					forward.pop();
					puts(cur.c_str());
				}
			}
		}
	}
	return 0;
}

// 252267	2013-08-16 19:20:11	 1113 - Discover the Web	 C++	 0.004	 1244	Accepted
