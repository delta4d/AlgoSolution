#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair <int, int> PII;
typedef long long LL;
const int MAXN = 55555;

priority_queue <PII> q;
char s[MAXN];

int main() {
	LL i, j, k;
	LL a, b;
	LL st;

	scanf("%s", s);
	for (k=st=i=0; s[i]; ++i) {
		if (s[i] == '(') {
			++st;
		} else if (s[i] == ')') {
			--st;
		} else {
			scanf("%I64d%I64d", &a, &b);
			q.push(make_pair(b-a, i));
			s[i] = ')';
			--st;
			k += b;
		}
		if (st < 0) {
			if (q.empty()) break; 
			PII tt = q.top();
			q.pop();
//			printf("--- %d %d %d\n", i, tt.first, tt.second);
			k -= tt.first;
			s[tt.second] = '(';
			++st, ++st;
		}
	}
	if (st != 0) puts("-1");
	else printf("%I64d\n%s\n", k, s);
	return 0;
}

//#		When	Who	Problem	Lang	Verdict	Time	Memory
//2906786	 Jan 12, 2013 10:04:51 AM	delta_4d	 D - Least cost bracket sequence	 GNU C++	Accepted	 31 ms	 600 KB
