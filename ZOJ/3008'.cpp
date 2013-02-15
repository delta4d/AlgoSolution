#include<stdio.h>
#include<math.h>
#include<string.h>

int a[5005],len=0;
bool chkp[40000];
int result;
int n,m,l;
int factor[100]={0};
int yinshu[100]={0};

void Make_DB() {
 	int i, j;
 	memset(chkp,false,sizeof(chkp));
 	chkp[1]=true;
 	for(i=2;i<39000;i++){
  		if(!chkp[i]){
   			a[len++]=i;
   			for(j=i*2; j<39000; j+=i) chkp[j] = true;
  		}
 	}
}

void DFS(int t,long long re) {
 	if(t==l){
  		if(re<=n) result++;
  		return;
 	}
 	int i;
 	DFS(t+1, re);
 	for(i=1; i<=factor[t]; i++) {
  		re *= yinshu[t];
  		if(re <= n) DFS(t+1, re);
  		else break;
 	}
}

int main(){
    int i;
 	Make_DB();
 	freopen("f:\\in.txt", "r", stdin);
 	//freopen("f:\\res.txt", "w", stdout);
    while(scanf("%d%d",&n,&m)==2){
  		memset(yinshu,0,sizeof(yinshu));
 		memset(factor,0,sizeof(factor));
  		int nn=n;
  		int j=0;
        for(i=0;nn>1&&i<len;i++){
            while(nn%a[i]==0&&nn>1){
    		factor[j]++;
    		nn/=a[i];
      		}
            if(factor[j]!=0){
    			yinshu[j]=a[i];
    			j++;
   			}
   		}
        if(nn!=1){
   			factor[j]++;
   			yinshu[j++]=nn;
  		}
        result=0;
  		for(i=0;i<j;i++) factor[i]*=m;
  		l=j;
  		//for (i=0; i<l; ++i) printf("%ld %ld\n", yinshu[i], factor[i]);
        DFS(0,1);
  		printf("%d\n",result);
 	}
    return 0;
}