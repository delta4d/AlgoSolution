#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct edge
{
    int x;
	int y;
	int d;
};

edge a[101];
int d[101];

int main()
{
    freopen("f:\\in.txt","r",stdin);
    int m,n,i,j,k,x,y;
    int MAX=100000000;
    string s;
    while (cin>>m&&m!=0)
    {
        cin>>n;
        for (i=1;i<=n;i++)
        {
            cin>>x>>y>>s>>k;
            if (s=="gt")
            {
                a[i].x=x+y;
                a[i].y=x-1;
                a[i].d=k+1;
            }
            else
            {
                a[i].x=x-1;
                a[i].y=x+y;
                a[i].d=-k+1;
            }

        }
        for (i=0;i<=m;i++)
            d[i]=-MAX;

        bool circle;
        for (i=0;i<=m;i++)
        {
            circle=false;
            for (j=1;j<=n;j++)
            {
                if (d[a[j].y]+a[j].d>d[a[j].x])
                {
                    d[a[j].x]=d[a[j].y]+a[j].d;
                    circle=true;
                }
            }
        }
        if (circle)
            cout<<"successful conspiracy"<<endl;
        else cout<<"lamentable kingdom"<<endl;
    }

    return 0;
}
