#include <queue>
#include <cstdio>
#include <vector> 
#include <cstring> 
#include <algorithm>
using namespace std; 

#define MP(i,j) make_pair(i, j) 
#define MAXN 2048
int dfn[MAXN], low[MAXN], id[MAXN], num, st[MAXN], top, in[MAXN], tot; 
vector <int> E[MAXN], F[MAXN], out;
int n;
int opp[MAXN], d[MAXN], color[MAXN];
bool mat[MAXN][MAXN];
queue <int> q;
 
struct seg {
	int x, y;
	
	seg() {}
	seg(int _x, int _y):x(_x), y(_y) {}
	bool intersect(const seg &a) {
		return a.x < y && y <= a.y || a.x <= x && x < a.y ||
		       x < a.y && a.y <= y || x <= a.x && a.x < y;
	}
	void output() {
		printf("%02d:%02d %02d:%02d\n", x/60, x%60, y/60, y%60);
	}
};

struct node {
	int x, y, z;
	
	void input() {
		int hx, mx, hy, my;
		scanf("%d:%d %d:%d %d", &hx, &mx, &hy, &my, &z);
		x = hx * 60 + mx, y = hy * 60 + my;
	}
	seg begin() {
		seg ret(x, x+z);
		return ret;
	}
	seg end() {
		seg ret(y-z, y);
		return ret;
	}
} f[MAXN>>1];

inline bool cmp(const int a, const int b) {
	return (a < n ? a : a - n) < (b < n ? b : b - n);
}

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

void insert(const int a, const int b) {
	int i, j, k;
	if (f[a].begin().intersect(f[b].begin())) {
		E[a].push_back(b+n);
		E[b].push_back(a+n);
	}
	if (f[a].begin().intersect(f[b].end())) {
		E[a].push_back(b);
		E[b+n].push_back(a+n);
	}
	if (f[a].end().intersect(f[b].begin())) {
		E[a+n].push_back(b+n);
		E[b].push_back(a);
	}
	if (f[a].end().intersect(f[b].end())) {
		E[a+n].push_back(b);
		E[b+n].push_back(a);
	}
}

void build_map() {
	int i, j, k;
	int x, y;
	
	memset(d, 0, sizeof(d));
	memset(mat, false, sizeof(mat));
	for (i=0; i<2*n; ++i) F[i].clear();
	for (i=0; i<2*n; ++i) {
		for (j=0; j<E[i].size(); ++j) {
			x = id[i], y = id[E[i][j]];
			if (x != y && !mat[y][x]) {
				mat[y][x] = true;
				F[y].push_back(x);
				++d[x];
			}
		}
	}
	for (i=0; i<n; ++i) opp[id[i]] = id[i+n], opp[id[i+n]] = id[i];
}

void tsort() {
	int i, j, k;
	int x, y;
	
	memset(color, -1, sizeof(color));
	while (!q.empty()) q.pop();
	for (i=0; i<num; ++i) if (d[i] == 0) q.push(i);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (color[x] == -1) color[x] = 1, color[opp[x]]= 0;
		for (i=0; i<F[x].size(); ++i) if (--d[F[x][i]] == 0) q.push(F[x][i]);
	}
}

void output_single(int x) {
	if (x < n) f[x].begin().output();
	else f[x-n].end().output();
}

void output() {
	int i, j, k;
	
	out.clear();
	for (i=0; i<2*n; ++i) if (color[id[i]] == 1) out.push_back(i);
	sort(out.begin(), out.end(), cmp);
	for (i=0; i<out.size(); ++i) output_single(out[i]);
}

int main() {
	int i, j, k;
	int x, y;
	int cnt;
	
	//freopen("d:\\in.txt", "r", stdin);
	while (1 == scanf("%d", &n)) {
		for (i=0; i<n; ++i) f[i].input();
		for (i=0; i<2*n; ++i) E[i].clear();
		for (i=0; i<n; ++i) for (j=i+1; j<n; ++j) insert(i, j);
		//for (i=0; i<2*n; ++i) {
		//	printf("%d:", i);
		//	for (j=0; j<E[i].size(); ++j) printf("%d ", E[i][j]);
		//	puts("");
		//}
		Components(n<<1);
		for (i=0; i<n; ++i) if (id[i] == id[i+n]) break;
		if (i < n) {
			puts("NO");
		} else {
			puts("YES");
			build_map();
			tsort();
			output();
		}
	}
	
	return 0;
}