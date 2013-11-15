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
char op[16];
 
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
	int x, y, z;
	
	while (2 == scanf("%d %d", &n, &m)) {
		for (i=0; i<n; ++i) E[i].clear();
		for (i=0; i<m; ++i) {
			scanf("%d %d %d %s", &x, &y, &z, op);
			if (op[0] == 'A') {
				if (z == 0) {
					E[x+n].push_back(y);
					E[y+n].push_back(x);
				} else {
					E[x].push_back(x+n);
					E[y].push_back(y+n);
				}
			} else if (op[0] == 'O') {
				if (z == 0) {
					E[x+n].push_back(x);
					E[y+n].push_back(y);
				} else {
					E[x].push_back(y+n);
					E[y].push_back(x+n);
				}
			} else {
				if (z == 0) {
					E[x].push_back(y);
					E[y].push_back(x);
					E[x+n].push_back(y+n);
					E[y+n].push_back(x+n);
				} else {
					E[x].push_back(y+n);
					E[y].push_back(x+n);
					E[x+n].push_back(y);
					E[y+n].push_back(x);
				}
			}
		}
		Components(n<<1);
		for (i=0; i<n; ++i) if (id[i] == id[i+n]) break;
		if (i < n) puts("NO");
		else puts("YES");
	}
	
	return 0;
}