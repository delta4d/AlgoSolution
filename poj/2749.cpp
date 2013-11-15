#include <queue>
#include <cstdio>
#include <vector> 
#include <cstring> 
#include <algorithm>
using namespace std; 

#define MP(i,j) make_pair(i, j) 
#define MAXN 2048
int dfn[MAXN], low[MAXN], id[MAXN], num, st[MAXN], top, in[MAXN], tot; 
vector <int> E[MAXN];
int x[MAXN], y[MAXN];
int sx1, sy1, sx2, sy2;
int len1[MAXN], len2[MAXN];
int hx[MAXN], hy[MAXN];
int fx[MAXN], fy[MAXN];

void tarjan(int now){ 
	in[st[top++] = now] = true; 
    dfn[now] = low[now] = ++tot;
	int i; 
    for (int ii = E[now].size() - 1; ii >= 0; --ii){ 
        i = E[now][ii]; 
        if (!dfn[i]){ 
            tarjan(i); 
            low[now] = min(low[now], low[i]);
        }
		else if (in[i]) 
            low[now] = min(low[now], dfn[i]); 
    }
	if (dfn[now] == low[now]){
    	do{
        	i = st[--top];
        	in[i] = false;
        	id[i] = num;
     	}while (i != now);
     	++num;
	}
}

void Components(int N){ 
    memset(dfn, 0, sizeof(dfn)); 
    memset(low, 0, sizeof(low)); 
	memset(in, 0, sizeof(in)); 
	memset(id, 0xff, sizeof(id)); 
    for (int i = top = num = tot = 0; i < N; ++i) if (!dfn[i]) tarjan(i); 
}

inline int _abs(const int x) {
	return x >= 0 ? x : -x;
}

inline int dis(const int x1, const int y1, const int x2, const int y2) {
	return _abs(x1 - x2) + _abs(y1 - y2);
}

int main() {
	int i, j, k;
	int cnt;
	int n, A, B;
	int a, b;
	int left, right, mid;
	int len;
	
	//freopen("d:\\in.txt", "r", stdin);
	while (3 == scanf("%d %d %d", &n, &A, &B)) {
		scanf("%d %d %d %d", &sx1, &sy1, &sx2, &sy2);
		for (i=0; i<n; ++i) {
			scanf("%d %d", x+i, y+i);
			len1[i] = dis(x[i], y[i], sx1, sy1);
			len2[i] = dis(x[i], y[i], sx2, sy2);
		}
		for (i=0; i<A; ++i) scanf("%d %d", hx+i, hy+i), --hx[i], --hy[i];
		for (i=0; i<B; ++i) scanf("%d %d", fx+i, fy+i), --fx[i], --fy[i];
		left = 0, right = 7000000, k = -1;
		len = dis(sx1, sy1, sx2, sy2);
		while (left <= right) {
			mid = (left + right) >> 1;
			for (i=0; i<2*n; ++i) E[i].clear();
			for (i=0; i<n; ++i) {
				for (j=i+1; j<n; ++j) {
					if (len1[i] + len + len2[j] > mid) {
						E[i].push_back(j);
						E[j+n].push_back(i+n);
					}
					if (len2[i] + len + len1[j] > mid) {
						E[i+n].push_back(j+n);
						E[j].push_back(i);
					}
					if (len1[i] + len1[j] > mid) {
						E[i].push_back(j+n);
						E[j].push_back(i+n);
					}
					if (len2[i] + len2[j] > mid) {
						E[i+n].push_back(j);
						E[j+n].push_back(i);
					}
				}
			}
			for (i=0; i<A; ++i) {
				E[hx[i]].push_back(hy[i]+n);
				E[hy[i]].push_back(hx[i]+n);
				E[hx[i]+n].push_back(hy[i]);
				E[hy[i]+n].push_back(hx[i]);
			}
			for (i=0; i<B; ++i) {
				E[fx[i]].push_back(fy[i]);
				E[fy[i]].push_back(fx[i]);
				E[fx[i]+n].push_back(fy[i]+n);
				E[fy[i]+n].push_back(fx[i]+n);
			}
			Components(n<<1);
			for (i=0; i<n; ++i) if (id[i] == id[i+n]) break;
			if (i < n) left = mid + 1;
			else k = mid, right = mid - 1;
		}
		printf("%d\n", k);
	}
	
	return 0;
}