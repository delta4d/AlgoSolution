#include <cstdio>
#include <vector> 
#include <cstring> 
#include <algorithm>
using namespace std; 

#define MP(i,j) make_pair(i, j) 
#define MAXN 512 
#define MAXM 10086
int dfn[MAXN], low[MAXN], id[MAXN], num, st[MAXN], top, in[MAXN], tot; 
int a[MAXM], b[MAXM], c[MAXM];
vector <int> E[MAXN];
 
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

int main() {
	int i, j, k;
	int m, n;
	int tc;
	int left, right, mid;
	
	//freopen("d:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &m);
		for (i=0; i<m; ++i) scanf("%d %d %d", a+i, b+i, c+i);
		left = 0, right = m;
		while (left <= right) {
			mid = (right + left) >> 1;
			for (i=0; i<2*n; ++i) E[i].clear();
			for (i=0; i<mid; ++i) {
				if (c[i] == 0) {
					E[a[i]].push_back(b[i]+n);
					E[b[i]].push_back(a[i]+n);
				} else if (c[i] == 1) {
					E[a[i]].push_back(b[i]);
					E[b[i]].push_back(a[i]);
					E[a[i]+n].push_back(b[i]+n);
					E[b[i]+n].push_back(a[i]+n);
				} else {
					E[a[i]+n].push_back(b[i]);
					E[b[i]+n].push_back(a[i]);
				}
			}
			Components(n<<1);
			for (i=0; i<n; ++i) if (id[i] == id[i+n]) break;
			if (i < n) right = mid - 1;
			else k = mid, left = mid + 1;
		}
		printf("%d\n", k);
	}
	
	return 0;
}