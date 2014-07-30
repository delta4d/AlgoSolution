#include <bits/stdc++.h>
using namespace std;

int const MAXN = 600000 + 10;
int const M = 1e9 + 7;

int sa[MAXN], r[MAXN], cnt[MAXN], tmp[MAXN];
int h[MAXN], height[MAXN];
char s[MAXN], a[MAXN], b[MAXN], c[MAXN];
int rt[MAXN], _a[MAXN], _b[MAXN], _c[MAXN];
int p[MAXN], o[MAXN];

void radix_sort(const int step, const int len) {
	memset(tmp, 0, sizeof(tmp));

	memset(cnt, 0, sizeof(cnt));
	for (int i=1; i<=len; ++i) ++cnt[r[i+step]];
	for (int i=1; i<MAXN; ++i) cnt[i] += cnt[i-1];
	for (int i=len; i>0; --i) tmp[cnt[r[i+step]]--] = i;

	memset(cnt, 0, sizeof(cnt));
	for (int i=1; i<=len; ++i) ++cnt[r[i]];
	for (int i=1; i<MAXN; ++i) cnt[i] += cnt[i-1];
	for (int i=len; i>0; --i) sa[cnt[r[tmp[i]]]--] = tmp[i];
	
	for (int i=1; i<=len; ++i) tmp[i] = r[i];
	r[sa[1]] = 1;
	for (int i=2,p=1; i<=len; ++i) {
		if (tmp[sa[i]] != tmp[sa[i-1]] || tmp[sa[i]+step] != tmp[sa[i-1]+step]) ++p;
		r[sa[i]] = p;
	}
}

void get_sa(char s[], const int len) {
	memset(r, 0, sizeof(r));
	for (int i=0; i<len; ++i) r[i+1] = s[i];
	radix_sort(0, len);
	for (int step=1; step<=len; step<<=1) {
		radix_sort(step, len);
	}
}

void get_height(char s[], const int len) {
	memset(h, 0, sizeof(h));
	for (int i=1; i<=len; ++i) if (r[i] != 1) {
		int p = max(0, h[i-1] - 1), j = sa[r[i] - 1];
		while (i + p - 1 < len && j + p - 1 < len && s[i+p-1] == s[j+p-1]) ++p;
		h[i] = p;
	}
	for (int i=1; i<=len; ++i) height[r[i]] = h[i];
}

int find_root(int x) {
	return rt[x] < 0 ? x : rt[x] = find_root(rt[x]);
}

int main() {
	scanf("%s%s%s", a, b, c);
	int len = 0, la, lb, lc;
	for (int i=0; a[i]; ++i) s[len++] = a[i]; s[len++] = 0, la = len;
	for (int i=0; b[i]; ++i) s[len++] = b[i]; s[len++] = 1, lb = len;
	for (int i=0; c[i]; ++i) s[len++] = c[i]; s[len++] = 2, lc = len;
	get_sa(s, len), get_height(s, len);
	for (int i=1; i<=len; ++i) {
		if (sa[i] < la) _a[i] = 1;
		else if (sa[i] < lb) _b[i] = 1;
		else if (sa[i] < lc) _c[i] = 1;
		p[i] = i;
	}
	memset(rt, -1, sizeof(rt));
	sort(p+1, p+len+1, [&](int a,int b){return height[a]>height[b];});
	int mn = min({la,lb-la,lc-lb}) - 1;
	for (int k=mn,i=1,tot=0; k>0; --k) {
		for (; i<=len && height[p[i]]>=k; ++i) {
			int x = p[i] - 1, y = p[i];
			int rx = find_root(x), ry = find_root(y);
			tot = (tot - 1ll * _a[rx] * _b[rx] * _c[rx]) % M;
			tot = (tot - 1ll * _a[ry] * _b[ry] * _c[ry]) % M;
			_a[rx] += _a[ry], _b[rx] += _b[ry], _c[rx] += _c[ry];
			rt[rx] += rt[ry], rt[ry] = rx;
			tot = (tot + 1ll * _a[rx] * _b[rx] * _c[rx]) % M;
		}
		o[k] = tot<0?tot+M:tot;
	}
	for (int i=1; i<=mn; ++i) printf("%d ", o[i]);
	return 0;
}

// 7285984	2014-07-29 18:54:53	delta_4d	E - Three strings	GNU C++0x	Accepted	265 ms	32400 KB
