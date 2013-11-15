#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef int elem_t;

const int M = 1024;
const int INF = 0x3f3f3f3f;

struct Node {
	int u, v;
	elem_t cost;
}E[M*M];

int pre[M],ID[M],vis[M];
int x[M], y[M], z[M];
int X, Y, Z;
elem_t In[M];
 
elem_t gao(int root, int NV, int NE) {
	elem_t ret = 0;
	while(true) {
		for (int i=0; i<NV; ++i) In[i] = INF;
		for (int i=0; i<NE; ++i) {
			int u = E[i].u;
			int v = E[i].v;
			if(E[i].cost < In[v] && u != v) {
				pre[v] = u;
				In[v] = E[i].cost;
			}
		}
		for (int i=0; i<NV; ++i) {
			if(i == root) continue;
			if(In[i] == INF)	return -1;
		}
		int cntnode = 0;
		memset(ID, -1, sizeof(ID));
		memset(vis, -1, sizeof(vis));
		In[root] = 0;
		for (int i=0; i<NV; ++i) {
			ret += In[i];
			int v = i;
			while(vis[v] != i && ID[v] == -1 && v != root) {
				vis[v] = i;
				v = pre[v];
			}
			if(v != root && ID[v] == -1) {
				for(int u = pre[v] ; u != v ; u = pre[u]) {
					ID[u] = cntnode;
				}
				ID[v] = cntnode ++;
			}
		}
		if(cntnode == 0)	break;
		for (int i=0; i<NV; ++i) if(ID[i] == -1) {
			ID[i] = cntnode ++;
		}
		for (int i=0; i<NE; ++i) {
			int v = E[i].v;
			E[i].u = ID[E[i].u];
			E[i].v = ID[E[i].v];
			if(E[i].u != E[i].v) {
				E[i].cost -= In[v];
			}
		}
		NV = cntnode;
		root = ID[root];
	}
	return ret;
}

inline int ABS(const int x) {
	return x < 0 ? -x : x;
}

inline int dis(const int a, const int b) {
	return ABS(x[a] - x[b]) + ABS(y[a] - y[b]) + ABS(z[a] - z[b]);
}

int calc_cost(const int a, const int b) {
	if (z[a] < z[b]) return dis(a, b) * Y + Z;
	return dis(a, b) * Y;
}

int main() {
	int i, j, k;
	int m, n;
	int tot, t;
	int res;
	
	//freopen("in.txt", "r", stdin);
	while (scanf("%d %d %d %d", &n, &X, &Y, &Z), n||X||Y||Z) {
		for (i=1; i<=n; ++i) scanf("%d %d %d", x+i, y+i, z+i);
		tot = 0;
		for (i=1; i<=n; ++i) E[tot].u = 0, E[tot].v = i, E[tot++].cost = ABS(z[i]) * X;
		for (i=1; i<=n; ++i) {
			scanf("%d", &k);
			for (j=0; j<k; ++j) {
				scanf("%d", &t);
				if (t == i) continue;
				E[tot].u = i, E[tot].v = t, E[tot++].cost = calc_cost(i, t);
			}
		}
		res = gao(0, n+1, tot);
		//if (res < 0) puts("poor XiaoA");
		//else printf("%d\n", res);
		printf("%d\n", res);
	}
	
	return 0;
}