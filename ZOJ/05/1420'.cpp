构图：
s[i]数组保存从原点（可以设为是24时刻）到 i时刻的雇佣人数
t[i]数组保存i时刻能够上班的人数 
r[i]数组记录i时刻的需求人数 
有如下的不等式：
    第i时刻比第i－1时刻的雇佣人数不会少 如是有s[i]>=s[i-1];
    第i时刻比第i－1时刻的雇佣人数不会多于i时刻能够上班的人数 s[i]-s[i-1]<=t[i];
    因为一旦上班可以连续工作8个小时 
    设x[i]为i时刻工作的人数则
    x[i-7]+x[i-6]+x[i-5]+x[i-4]+x[i-3]+x[i-2]+x[i-1]+x[i] >=r[i];
    即 s[i]-s[i-8]>=r[i]         8<=i<=23
    s[23]-(s[i+16]-s[i])>=r[i]
    s[i]-s[i+16]>=r[i]-s[23]     0<=i<=7

最短路 
s[i-1]<=s[i]
s[i]<=s[i-1]+t[i]
s[i-8]<=s[i]-r[i]                   8<=i<=23
s[i+16]<=s[i]-(r[i]-result)          0<=i<=7 
s[23]-s[24]>=result
 

Code〔最短路求解〕
＃i nclude <iostream>
using namespace std;
const int maxn= 25;
const int mx= 1000;
int r[maxn];
int s[maxn];
int t[maxn];
int d[maxn];
typedef struct
{
    int u,v,w;
}E;
E edge[mx];
int edno;
bool Bellman_Ford(int sum)
{
    int i,j,t;
    bool change;
    int m=edno;
    for(i=0;i<=7;i++){
        edge[m].u=i;
        edge[m].v=i+16;
        edge[m++].w=-(r[i]-sum);
    }
    edge[m].u=23;
    edge[m].v=24;
    edge[m++].w=-sum;
    for(i=0;i<=24;i++)d[i]=0;
    d[24]=0;
    for(i=0;i<=24;i++){
        change=false;
        for(j=0;j<m;j++){
            t=d[edge[j].u]+edge[j].w;
            if(d[edge[j].v]>t){
                d[edge[j].v]=t;
                change=true;
            }
        }
    }
    if(change) return false;
    return true;
}

int main()
{
    int ncase,i,n,tmp,left,right,mid,res;
    cin>>ncase;
    while(ncase--){
        for(i=0;i<24;i++)cin>>r[i];
        edno=0;
        memset(t,0,sizeof(t));
       cin>>n;
        for(i=0;i<n;i++){
            cin>>tmp;
            t[tmp]++;
        }
        edge[edno].u=24;
        edge[edno].v=0;
        edge[edno++].w=t[0];
        for(i=1;i<=23;i++){
            edge[edno].u=i-1;
            edge[edno].v=i;
            edge[edno++].w=t[i];
        }
        for(i=8;i<=23;i++){
            edge[edno].u=i;
            edge[edno].v=i-8;
            edge[edno++].w=-r[i];
        }
        left=0;right=n;
        res=-1;
        while(left<right){
            mid=(left+right)/2;
            if(Bellman_Ford(mid)){
                res=mid;
                right=mid;
            }
            else {
                left=mid+1;
            }
        }
        if(res==-1) cout<<"No Solution"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
