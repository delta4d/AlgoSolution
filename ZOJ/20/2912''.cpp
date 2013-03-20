#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
struct node {
    int x;
	int y;
	int w;
} c[10001];
vector<int> b[10001];
int num[10001];
int flag[10001];

void dfs(int s) {
    int i;
    for(i=0; i<b[s].size(); i++) //结点S的连接点的个数.size();
    {
  		int t = b[s][i];
        if(!flag[t])//减枝,不重复走
        {
            flag[t]=1;
            num[t]=1;
            dfs(t);
            num[s]+=num[t];//结点S的一边有多少个结点
        }
    }
}

int main()
{
    int test,n,i,a1,b1,c1;
    freopen("f:\\in.txt", "r", stdin);
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        for(i=0; i<n; i++) b[i].clear();
        memset(flag, 0, sizeof(flag));
        memset(num, 0, sizeof(num));
        for(i=0; i<n-1; i++) {
            scanf("%d %d %d", &a1, &b1, &c1);
            c[i].x = a1;
            c[i].y = b1;
            c[i].w = c1;;
            b[a1].push_back(b1); //a1的一边有个b1
            b[b1].push_back(a1);
        }
        flag[0]=1;
        dfs(0);
        double total=0.0;
        for(i=0; i<n-1; i++) {
            int m=num[c[i].x]<num[c[i].y]?num[c[i].x]:num[c[i].y];
            total+=1.0*m*(n-m)*c[i].w;
        }
        printf("%.3lf\n",(total*2.0)/((double )n*(n-1)));
    }
    return 0;
}