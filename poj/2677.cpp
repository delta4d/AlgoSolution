#include<iostream>
#include<cmath>
#define REP(i,n) for(int i=0;i<n;i++)
#define INF 100000000
using namespace std;
double dp[100][100];
double x[100],y[100];
double dis(int i,int j) {
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int n;
int main() {
	//freopen("f:\\in.txt", "r", stdin);
    while(scanf("%d",&n)!=EOF&&n) {
        REP(i,n)
            scanf("%lf%lf",&x[i], &y[i]);
        REP(i,n)
            fill_n(dp[i], n, INF);
        dp[1][0]=dis(0,1);
        REP(i,n)
            REP(j,i) {
                dp[i+1][i] = min(dp[i+1][i], dp[i][j]+dis(j,i+1));
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+dis(i,i+1));
            }
        double res=INF;
        REP(i,n-1)
            res=min(res,dp[n-1][i]+dis(i,n-1));
        printf("%.2lf\n",res);
    }
    return 0;
}