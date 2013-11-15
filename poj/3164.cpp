#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 128;
const double INF = 999999999999999999.9;

struct Node {
	int u, v;
	double cost;
} E[M*M];

int pre[M],ID[M],vis[M];
double In[M];
int x[M], y[M];
 
double gao(int root, int NV, int NE) {
	double ret = 0;
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

inline double dis(const int a, const int b) {
	return sqrt(1.0 * (x[a] - x[b]) * (x[a] - x[b]) + 1.0 * (y[a] - y[b]) * (y[a] - y[b]));
}

int main() {
	int i, j, k;
	int m, n;
	int u, v;
	double res;
	
	//freopen("in.txt", "r", stdin);
	while (2 == scanf("%d %d", &n, &m)) {
		for (i=0; i<n; ++i) scanf("%d %d", x+i, y+i);
		for (i=0; i<m; ++i) {
			scanf("%d %d", &u, &v);
			--u, --v;
			E[i].u = u, E[i].v = v, E[i].cost = dis(u, v);
		}
		res = gao(0, n, m);
		if (res < 0) puts("poor snoopy");
		else printf("%.2lf\n", res);
	}
	
	return 0;
}