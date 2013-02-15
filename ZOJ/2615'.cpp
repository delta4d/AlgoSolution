#include <iostream>
using namespace std;

int n, pc, rc;
int pre[20000001], rev[20000001], edge[300001];
int p[300001], e[300001];

void dfs(int s){
    int top = 1;
    p[1] = s;
    pc = rc = 0;
    while (top) {
        head: pre[p[top]] = ++pc;
        for (e[top]=edge[p[top]]; e[top]<edge[p[top]+1]; ++e[top]) {            
            if (e[top] < n) {
                p[top+1] = e[top];
                top++;
                goto head;
            } else {
                pre[e[top]] = ++pc;
                rev[e[top]] = ++rc;
            }
            body:;
        }
        rev[p[top]] = ++rc;
        if(--top) goto body;
    }
}

int main(){
    int t, k, x, y, test(0);
    freopen("f:\\in.txt", "r", stdin);
    scanf("%d", &t);
    while(t--){
        test++;
        scanf("%d", &n);
        edge[0]=1;
        for(int i=0; i<n; ++i){
            scanf("%d", &k);
            edge[i+1] = edge[i] + k;
        }
        dfs(0);
        printf("Case %d:\n", test);
        scanf("%d", &k);
        for(int i=0; i<k; ++i){
            scanf("%d %d", &x, &y);
            if(pre[y] > pre[x] && rev[y] < rev[x]) puts("Yes");
			else puts("No");
        }
        if(t) puts("");
    }
}