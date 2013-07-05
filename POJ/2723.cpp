#include <cstdio>
#include <vector> 
#include <cstring> 
#include <algorithm>
using namespace std; 

#define MP(i,j) make_pair(i, j) 
#define MAXN 2048
int dfn[MAXN], low[MAXN], id[MAXN], num, st[MAXN], top, in[MAXN], tot; 
vector <int> E[MAXN];
int key[MAXN];
int dx[MAXN], dy[MAXN];
 
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
	int x, y;
	int left, right, mid;
	
	while (scanf("%d %d", &n, &m), n||m) {
		for (i=0; i<n; ++i) {
			scanf("%d %d", &x, &y);
			key[x] = y;
			key[y] = x;
		}
		for (i=0; i<m; ++i) scanf("%d %d", dx+i, dy+i);
		left = 0, right = m;
		while (left <= right) {
			mid = (left + right) >> 1;
			for (i=0; i<n*2; ++i) E[i].clear();
			for (i=0; i<mid; ++i) {
				E[dx[i]].push_back(key[dy[i]]);
				E[dy[i]].push_back(key[dx[i]]);
			}
			Components(n);
			for (i=0; i<n; ++i) if (id[i] == id[key[i]]) break;
			if (i < n) right = mid - 1;
			else k = mid, left = mid + 1;
		}
		printf("%d\n", k);
	}
	
	return 0;
}