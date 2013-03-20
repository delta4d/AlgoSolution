#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace  std;

const int MAXL = 256;
const int MAXN = 30001;
const double base = log(2.0);

int tot;
int timestamp[MAXN];
int E[MAXN<<1]; 	// E[i] is the label of i-th visited node in the tour
int L[MAXN<<1];   	// L[i] is the level of node E[i]
int H[MAXN];  	// the index of the first occurrence of node i in E
//bool visited[MAXN<<1];
char buff[MAXL], child[MAXL], parent[MAXL];
vector<int> graph[MAXN];
map<string, int> ta;

inline int gao(char s[]) {
	map<string, int>::iterator it;
	it = ta.find(string(s));
	if (it == ta.end()) {
		ta.insert(make_pair(string(s), tot));
		return tot++;
	}
	return (*it).second;
}

void DFS(int u, int d, int &k) {
	//visited[u] = true;
	E[k] = u;
	L[k] = d;
	H[u] = k;
	++k;
	int v;
	for (size_t i = 0; i < graph[u].size(); ++i) {
		v = graph[u][i];
		//if (!visited[v]) {
			DFS(v, d + 1, k);
			E[k] = u;
			L[k] = d;
			++k;
		//}
	}
}

int M[MAXN<<1][20];		//´æ´¢µÄË÷Òý
void preprocess(int a[], int n) {
	int i, j;		
	//initialize for the intervals with length 1 
	for (i = 0; i < n; ++i) M[i][0] = i;	
	//compute values from smaller to bigger intervals   
	for (j = 1; 1 << j <= n; ++j) {
		for (i = 0; i + (1 << j) - 1 < n; ++i)
			if (a[M[i][j - 1]] < a[M[i + (1 << (j - 1))][j - 1]])
				M[i][j] = M[i][j - 1];
			else
				M[i][j] = M[i + (1 << (j - 1))][j - 1];
	}
}

int RMQ(int a[], int i, int j) {
	if (i > j) swap(i, j);
	int k;
	k = int (log(j - i + 1) / base);
	if (a[M[i][k]] < a[M[j-(1<<k)+1][k]]) return M[i][k];
	else return M[j - (1 << k) + 1][k];
}

int main() {
	int i, j, k;
	int cn(0);
	int m, n;
	int cid, pid;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%s %d", buff, &n);
	while (true) {
		ta.clear();
		ta.insert(make_pair(string(buff), 0));
		tot = 1;
		for (i=0; i<=n; ++i) graph[i].clear();
		for (i=0; i<n; ++i) {
			scanf("%s %s", child, parent);
			cid = gao(child);
			pid = gao(parent);
			graph[pid].push_back(cid);
		}
		//memset(visited, false, sizeof(visited));
		k = 0;
		DFS(0, 0, k);
		preprocess(L, 2 * n - 1);

		printf("Project %d\n", ++cn);
		scanf("%d", &m);
		for (i=0; i<m; ++i) {
			scanf("%s %s", child, parent);
			cid = gao(child);
			pid = gao(parent);
			printf("%s\n", E[RMQ(L, H[cid], H[pid])]==pid?"Yes":"No");
		}
		if (scanf("%s %d", buff, &n) == EOF) break;
		puts("");
	}
	return 0;
}