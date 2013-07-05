#include <cmath>
#include <cstdio>
#include <cstring> 
#include <algorithm>
using namespace std;

#define MAXN 256 
#define inf 9999999999999.9 

int x[MAXN], y[MAXN];
double mat[MAXN][MAXN*2];
int pre[MAXN];

int c[MAXN*2][MAXN*2],l[MAXN*2],p[MAXN*2];

typedef double elem_t; 
elem_t gao(int n, elem_t mat[][MAXN*2], int *pre){ 
    elem_t ret=0; 
    int m=n,t,i,j,k; 
    for (i=0;i<n;l[i]=i,i++); 
    do{ 
        memset(c,0,sizeof(c)),memset(p,0xff,sizeof(p)); 
        for (t=m,i=0;i<m;c[i][i]=1,i++); 
        for (i=0;i<t;i++) 
            if (l[i]==i&&pre[i]!=-1){ 
                for (j=0;j<m;j++) 
                    if 
(l[j]==j&&i!=j&&mat[j][i]<inf&&(p[i]==-1||mat[j][i]<mat[p[i]][i])) 
                        p[i]=j; 
                if ((pre[i]=p[i])==-1) 
                    return -1; 
                if (c[i][p[i]]){ 
                    for (j=0;j<=m;mat[j][m]=mat[m][j]=inf,j++); 
                    for (k=i;l[k]!=m;l[k]=m,k=p[k]) 
                        for (j=0;j<m;j++) 
                            if (l[j]==j){ 
                                if (mat[j][k]-mat[p[k]][k]<mat[j][m]) 
                                    mat[j][m]=mat[j][k]-mat[p[k]][k]; 
                                if (mat[k][j]<mat[m][j]) 
                                    mat[m][j]=mat[k][j]; 
                            } 
                    c[m][m]=1,l[m]=m,m++; 
                } 
                for (j=0;j<m;j++) 
                    if (c[i][j]) 
                        for (k=p[i];k!=-1&&l[k]==k;c[k][j]=1,k=p[k]); 
            } 
    } 
    while (t<m); 
    for (;m-->n;pre[k]=pre[m]) 
        for (i=0;i<m;i++) 
            if (l[i]==m){ 
                for (j=0;j<m;j++) 
                    if (pre[j]==m&&mat[i][j]==mat[m][j]) 
                        pre[j]=i; 
                if (mat[pre[m]][m]==mat[pre[m]][i]-mat[pre[i]][i]) 
                    k=i; 
            } 
    for (i=0;i<n;i++) 
        if (pre[i]!=-1) 
            ret+=mat[pre[i]][i]; 
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
		for (i=0; i<n; ++i) for (j=0; j<n; ++j) mat[i][j] = inf;
		for (i=0; i<m; ++i) {
			scanf("%d %d", &u, &v);
			--u, --v;
			mat[u][v] = dis(u, v);
		}
		memset(pre, 0, sizeof(pre));
		pre[0] = -1;
		res = gao(n, mat, pre);
		if (res < 0) puts("poor snoopy");
		else printf("%.2lf\n", res);
	}
	
	return 0;
}