#include <cstdio>
#include <vector> 
#include <cstring> 
#include <algorithm>
using namespace std; 

#define MP(i,j) make_pair(i, j) 
#define MAXN 10024 
int dfn[MAXN], low[MAXN], id[MAXN], num, st[MAXN], top, in[MAXN], tot; 
vector <int> E[MAXN];
int x[MAXN], y[MAXN];
 
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

bool intersect(int a, int b) {
	return x[a] < x[b] && x[b] < y[a] && y[a] < y[b] ||
		   x[a] < y[b] && y[b] < y[a] && x[b] < x[a] ||
		   x[b] < x[a] && x[a] < y[b] && y[b] < y[a] ||
		   x[b] < y[a] && y[a] < y[b] && x[a] < x[b];
}

int main() {
	int i, j, k;
	int m, n;
	
	//freopen("d:\\in.txt", "r", stdin);
	while (2 == scanf("%d %d", &n, &m)) {
		for (i=0; i<m; ++i) {
			scanf("%d %d", x+i, y+i);
			if (x[i] > y[i]) swap(x[i], y[i]);
		}
		for (i=0; i<(m<<1); ++i) E[i].clear();
		for (i=0; i<m; ++i) {
			for (j=i+1; j<m; ++j) {
				if (intersect(i, j)) {
					E[i].push_back(j+m);
					E[j].push_back(i+m);
					E[i+m].push_back(j);
					E[j+m].push_back(i);
				}
			}
		}
		Components(m<<1);
		for (i=0; i<m; ++i) if (id[i] == id[i+m]) break;
		if (i < m) puts("the evil panda is lying again");
		else puts("panda is telling the truth...");
	}
	
	return 0;
}