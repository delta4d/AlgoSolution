#include <queue>
#include <cstdio>
#include <vector> 
#include <cstring> 
#include <algorithm>
using namespace std; 

#define MP(i,j) make_pair(i, j) 
#define MAXN 256
int dfn[MAXN], low[MAXN], id[MAXN], num, st[MAXN], top, in[MAXN], tot; 
vector <int> E[MAXN], F[MAXN];
bool mat[MAXN][MAXN];
bool used[MAXN];
int color[MAXN];
int d[MAXN];
int opp[MAXN];
int order[MAXN];
vector <int> out;
queue<int> q;
 
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

int get_id(const int n) {
	int x;
	char s[16];
	scanf("%d%s", &x, s);
	return s[0] == 'w' ? x : x + (n << 1);
}

void tsort() {
	int i, j, k;
	int cnt(0);
	
	while (!q.empty()) q.pop();
	for (i=0; i<num; ++i) if (d[i] == 0) q.push(i);
	while (!q.empty()) {
		k = q.front();
		q.pop();
		//order[cnt++] = k;
		if (color[k] == -1) color[k] = 1, color[opp[k]] = 0;
		for (i=0; i<F[k].size(); ++i) {
			if (--d[F[k][i]] == 0) q.push(F[k][i]);
		}
	}
}

void dfs(int root) {
	int i, j, k;
	
	color[root] = 0;
	for (i=0; i<F[root].size(); ++i) {
		if (color[F[root][i]] == -1) dfs(F[root][i]);
	}
}

int main() {
	int i, j, k;
	int m, n;
	int x, y;
	int cnt;
	
	//freopen("d:\\in.txt", "r", stdin);
	while (scanf("%d %d", &n, &m), n||m) {
		for (i=0; i<4*n; ++i) E[i].clear();
		E[n].push_back(0);
		E[2*n].push_back(3*n);
		for (i=0; i<n; ++i) {
			E[i].push_back(i+3*n);
			E[i+n].push_back(i+2*n);
			E[i+2*n].push_back(i+n);
			E[i+3*n].push_back(i);
		}
		for (i=0; i<m; ++i) {
			x = get_id(n), y = get_id(n);
			E[x+n].push_back(y);
			E[y+n].push_back(x);
		}
		Components(n<<2);
		for (i=0; i<n; ++i) if (id[i] == id[i+2*n] || id[i+n] == id[i+3*n]) break;
		if (i < n) {
			puts("bad luck");
		} else {
			for (i=0; i<4*n; ++i) F[i].clear();
			memset(d, 0, sizeof(d));
			memset(mat, false, sizeof(mat));
			for (i=0; i<4*n; ++i) {
				for (j=0; j<E[i].size(); ++j) {
					x = id[i], y = id[E[i][j]];
					if (x != y && !mat[y][x]) {
						mat[y][x] = true;
						F[y].push_back(x);
						++d[x];
					}
				}
			}
			/*for (i=0; i<num; ++i) {
				printf("%d---", i);
				for (j=0; j<F[i].size(); ++j) printf("%d ", F[i][j]);
				puts("");
			}*/
			for (i=0; i<2*n; ++i) opp[id[i]] = id[i+2*n], opp[id[i+2*n]] = id[i];
			memset(color, -1, sizeof(color));
			tsort();
			//for (i=0; i<num; ++i) {
			//	if (color[order[i]] == -1) {
			//		color[order[i]] = 1;
			//		dfs(opp[order[i]]);
			//	}
			//}
			out.clear();
			for (i=1; i<n; ++i) if (color[id[i]] == 1) out.push_back(i);
			for (i=1; i<n; ++i) if (color[id[i+2*n]] == 1) out.push_back(i+2*n);
			for (i=0; i<out.size(); ++i) {
				if (out[i] < n) printf("%dw", out[i]);
				else printf("%dh", out[i]-2*n);
				if (i + 1 == out.size()) puts("");
				else printf(" ");
			}
		}
	}
	
	return 0;
}