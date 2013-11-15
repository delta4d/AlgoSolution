#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge
{
    int y;
    edge *next;
};
struct data
{
    int w;
	int mark;
}d[411];
int n,link[411],cover[411],ans[411];
edge *ls[411];
bool cmp(data x,data y) {
    return x.w > y.w;
}

void add(int x,int y) {
    edge *p=new edge;
    p->y=y;
    p->next=ls[x];
    ls[x]=p;
}

bool dfs(int k) {
    for (edge *t=ls[k]; t; t=t->next)
        if (!cover[t->y]) {
            cover[t->y]=1;
            int q=link[t->y];
            link[t->y]=k;
            if (q==0 || dfs(q)) return true;
            link[t->y]=q;
        }
    return false;
}

int main() {
	int tc, t;
	freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &tc);
	for (t=1; t<=tc; ++t) {
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        ls[i] = NULL;
        scanf("%d",&d[i].w);
        d[i].mark=i;
    }
    for (int i=1; i<=n; i++) {
        int num,x;
        scanf("%d",&num);
        for (int j=1; j<=num; j++) {
            scanf("%d",&x);
            add(i,x);
        }
    }
    sort(&d[1],&d[n+1],cmp);
    for (int now=1; now<=n; now++) {
        memset(cover,0,sizeof(cover));
        dfs(d[now].mark);
    }
    for (int i=1; i<=n; i++)
        if (link[i]) ans[link[i]]=i;
    for (int i=1; i<n; i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
	}
}