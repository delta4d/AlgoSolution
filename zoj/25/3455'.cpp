#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500010;
const int MAXL = 128;

int temp[MAXL];
int cnt1[MAXL], cnt2[MAXL];
int ccnt1[MAXN], ccnt2[MAXN];
char s1[MAXN], s2[MAXN];
vector<int> res;

inline void init(const int len, const char s[], int cnt[], int ccnt[]) {
	int i, j, k;
	for (i=0; i<MAXL; cnt[i++]=0);
	for (i=0; i<MAXN; ccnt[i++]=0);
	for (i=0; i<len; ++cnt[int(s[i++])]);
	for (i=0; i<MAXL; ++ccnt[cnt[i++]]);
}

inline bool match() {
	int i, j, k;
	for (i=0; i<MAXL; ++i) {
		if (cnt2[i] == 0) continue;
		if (ccnt2[cnt2[i]] != ccnt1[cnt2[i]]) return false;
	}
	return true;
}

inline void in(const int k) {
	--ccnt1[cnt1[k]];
	++cnt1[k];
	++ccnt1[cnt1[k]];
}

inline void out(const int k) {
	--ccnt1[cnt1[k]];
	--cnt1[k];
	++ccnt1[cnt1[k]];
}

int main() {
	int len1, len2, len;
	int i, j, k;
	int p;
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s %s", s1, s2) != EOF) {
		len1 = strlen(s1);
		len2 = strlen(s2);
		init(len2, s1, cnt1, ccnt1);
		init(len2, s2, cnt2, ccnt2);
		len = len1 - len2;
		res.clear();
		for (i=0; i<=len; ++i) {
			if (match()) res.push_back(i);
			in(int(s1[i+len2]));
			out(int(s1[i]));
		}
		if (len == 0 && match()) res.push_back(0);
		if (res.size() == 0) {
			puts("No");
		} else {
			puts("Yes");
			for (i=0; i!=res.size(); ++i) printf("%d%c", res[i], i+1==res.size()?'\n':' ');
		}
	}
	return 0;
}