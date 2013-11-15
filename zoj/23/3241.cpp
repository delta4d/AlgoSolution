#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN=22000, MAXM=440000;
struct Dinic {
	struct edge {
		int x, y;			//�������� 
		int c;				//���� 
		int f;				//��ǰ���� 
		edge *next, *back;	//��һ���ߣ������ 
		edge(int x, int y, int c, edge *next):x(x), y(y), c(c), f(0), next(next), back(0) {}
		void *operator new(size_t, void *p) {return p;}
	} *E[MAXN], *data;		//E[i]���涥��i�ı߱�
	char storage[2*MAXM*sizeof(edge)];
	int S, T;				//Դ����
	
	int Q[MAXN];			//DFS�õ���queue
	int D[MAXN];			//�����ţ�-1��ʾ���ɴ�
	void DFS() {
		memset(D, -1, sizeof(D));
		int head=0, tail=0;
		Q[tail++] = S;
		D[S] = 0;
		for(;;) {
			int i = Q[head++];
			for(edge *e=E[i]; e; e=e->next) {
				if(e->c == 0) continue;
				int j = e->y;
				if(D[j] == -1) {
					D[j] = D[i] + 1;
					Q[tail++] = j;
					if(j == T)return;
				}
			}
			if(head == tail)break;
		}
	}
	edge *cur[MAXN];//��ǰ��
	edge *path[MAXN];//��ǰ�ҵ�������·
	int flow() {
		int res = 0;//������������� 
		int path_n;//path�Ĵ�С
		for(;;) {
			DFS();
			if(D[T] == -1) break;
			memcpy(cur, E, sizeof(E));
			path_n = 0;
			int i = S;
			for(;;) {
				if(i == T) {//���ҵ�һ������·������֮ 
					int mink = 0;
					int delta = 0x3f3f3f3f;
					for(int k=0; k<path_n; ++k) {
						if(path[k]->c < delta) {
							delta = path[k]->c;
							mink = k;
						}
					}
					for(int k=0;k<path_n;++k) {
						path[k]->c -= delta;
						path[k]->back->c += delta;
					}
					path_n = mink;//���� 
					i = path[path_n]->x;
					res += delta;
				}
				edge *e;
				for(e=cur[i]; e; e=e->next){
					if(e->c == 0)continue;
					int j = e->y;
					if(D[i]+1 == D[j]) break;//�ҵ�һ�������ӵ�·���� 
				}
				cur[i] = e;//��ǰ���ṹ�����ʹ��Ĳ�������Ļ������ٷ���
				if(e) {
					path[path_n++] = e;
					i = e->y;
				} else {//�ýڵ���û���κο�����Ļ�����ͼ��ɾȥ������һ�� 
					D[i] = -1;
					if(path_n == 0) break;
					path_n--;
					i = path[path_n]->x;
				}
			}
		}
		return res;
	}
	int cut(int* s) {
		int rst = 0;
		for(int i=0; i<MAXN; ++i)
			if(D[i]==-1 && E[i])
				s[rst++] = i;
		return rst;
	}
	void init(int _S, int _T) {
		S =_S, T =_T;
		data = (edge *)storage; 
		memset(E, 0, sizeof(E));
	}
	void add_edge(int x, int y, int w) {//�ӽ�һ��x��y����Ϊw�ıߣ���Ҫ��֤0<=x,y<MAXN��0<w<=INT_MAX 
		E[x] = new((void *)data++) edge(x, y, w, E[x]);
		E[y] = new((void *)data++) edge(y, x, 0, E[y]);
		E[x]->back = E[y];
		E[y]->back = E[x];
	}
};

Dinic dinic;
int cut[MAXN];
int x[MAXN], y[MAXN];
int res[MAXM];
bool v[MAXN];

int main() {
	int i, j, k;
	int s, t;
	int w;
	int m, n, f;
	int tc, cn(0);
	int tot, vt;
	int p;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &n, &m, &f);
		s = 1, t = n + 1;
		dinic.init(s, t);
		for (i=0; i<m; ++i) {
			scanf("%d %d %d", x+i, y+i, &w);
			dinic.add_edge(x[i], y[i], w);
		}
		vt = 0;
		for (i=0; i<f; ++i) {
			scanf("%d %d", &k, &w);
			dinic.add_edge(k, t, w);
			vt += w;
		}
		tot = dinic.flow();
		vt -= tot;
		printf("Case %d: %d\n", ++cn, vt);
		k = dinic.cut(cut);
		for (i=0; i<=t; v[i++]=false);
		for (i=0; i<k; v[cut[i++]]=true);
		p = 0;
		for (i=0; i<m; ++i) {
			if (!v[x[i]] && v[y[i]]) res[p++] = i + 1;
		}
		printf("%d", p);
		for (i=0; i<p; ++i) printf(" %d", res[i]);
		puts("");
	}
	return 0;
}
