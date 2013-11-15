#include<iostream>
#include<string>
using namespace std;
#define maxn 1005
#define Inf 2000000000
string t[maxn];
int n,m,tot,low=Inf,high=-Inf,now;
struct Component {                                          //把cin改成scanf即可避免TLE 
    int type,cost,quality;
    void Readin() {
        int i;
        char tmp[30];
        scanf("%s",tmp);                                    //这里 
        string str(tmp);
        for (i=0; i<tot; i++) if (t[i]==str) break;
        type=i;
        if (i==tot) t[tot++]=str;
        scanf("%s",tmp);                                    //这里 
        scanf("%d%d",&cost,&quality);
        low=min(low, quality),high=max(high, quality);
    }
} c[maxn];

inline int Compare(const void *a,const void *b) {
    return ((Component*)a)->type-((Component*)b)->type;
}

void Init() {
    tot=0;
    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) c[i].Readin();
    qsort(c,n,sizeof(Component),Compare);
}

bool Can() {
    int i=0,j,money=0,min_cost;
    while (i<n) {
        j=i,min_cost=Inf;
        while (j<n && c[j].type==c[i].type) {
            if (c[j].quality>=now) min_cost=min(min_cost, c[j].cost);
            j++;
        }
        if (min_cost==Inf) return false;
        money+=min_cost;
        if (money>m) return false;
        i=j;
    }
    return true;
}

int main() {
    //freopen("i","r",stdin);
    //freopen("o","w",stdout);
    int test;
    for (scanf("%d",&test); test; test--) {
        Init();
        low--,high++;
        while (low+1<high) {
            now=(low+high)/2;
            if (Can()) low=now;
            else high=now;
        }
        printf("%d\n",low);
    }
    return 0;
}

