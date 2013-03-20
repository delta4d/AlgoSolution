#include <cstdio>
#include <cstring>
using namespace std; 

const int oo = (~0u)>>1;
const int MAXV = 1000000;
const int MAXE = 1000000;
typedef struct struct_edge* edge;
struct struct_edge {
	int v, c;
	edge n, b;
};
struct_edge pool[MAXE];
edge top;
int S,T,V;
edge adj[MAXV];
int d[MAXV];
int q[MAXV];
int head,tail;
void add_edge(int u,int v,int c) {
     top->v=v,top->c=c,top->n=adj[u],adj[u]=top++;
     top->v=u,top->c=0,top->n=adj[v],adj[v]=top++;
     adj[u]->b=adj[v],adj[v]->b=adj[u];
}

bool relabel() {
     for (int i=0;i<V;d[i++]=oo) ;
     d[q[head=tail=0]=T]=0;
     while (head<=tail) {
           int u=q[head++];
           for (edge i=adj[u];i;i=i->n)
               if (i->b->c&&d[i->v]==oo)
                  d[q[++tail]=i->v]=d[u]+1;
           if (d[S]!=oo) return true;
     }
     return false;
}

int augment(int u,int e) {
    if (u==T) return e;
    int f=0;
    for (edge i=adj[u];i&&e;i=i->n)
        if (i->c&&d[u]==d[i->v]+1)
           if (int df=augment(i->v,e<i->c?e:i->c))
              i->c-=df,i->b->c+=df,e-=df,f+=df;
    return f;
}

int dinic() {
    int f = 0;
    while (relabel()) f += augment(S, oo);
    return f;
}
 
const int MAXL = 1000;
int n, m, l;
int a[MAXL], b[MAXL], c[MAXL];
 
int main() {
    for (;;) {
        scanf("%d %d %d", &n, &m, &l);
        if (!n) break;
        top = pool;
        S = n + m + 1, T = 0, V = n + m + 2;
        for (int i=0; i<V; adj[i++]=0) ;
        for (int i=0; i<l; i++)
            scanf("%d %d %d", a+i, b+i, c+i),
            add_edge(a[i], b[i], c[i]);
        for (int i=1; i<=n; i++) add_edge(S, i, oo);
        int flow = dinic();
        bool first = true;
        for (int i=0; i<l; i++) {
            add_edge(a[i], b[i], oo);
            if (relabel()) if (first) printf("%d", i+1), first=false;
                           else printf(" %d", i+1);
            adj[a[i]] = adj[a[i]]->n; top--;
            adj[b[i]] = adj[b[i]]->n; top--;
        }
        printf("\n");
    }
}