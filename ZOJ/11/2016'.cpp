#include <iostream>
#include <string>
using namespace std;

bool use[26];
int root[26];
int rank[26];
int in[26];
int out[26];

int getroot(int x)
{
    if (root[x]==x)
        return x;
    else return root[x]=getroot(root[x]);
}

void Union(int x,int y)
{
    int i,j;
    i=getroot(x);
    j=getroot(y);
    if (i==j)
        return;
    if (rank[i]>=rank[j])
    {
        root[j]=i;
        rank[i]+=rank[j];
    }
    else
    {
        root[i]=j;
        rank[j]+=rank[i];
    }
}

int main()
{
//freopen("debug\\in.txt","r",stdin);
    int i,j,k,m,repeat;
    string s;
    cin>>repeat;
    while (repeat--)
    {
        for (i=0;i<26;i++)
        {
            in[i]=out[i]=0;
            rank[i]=0;
            root[i]=i;
            use[i]=false;
        }
        cin>>m;
        for (i=1;i<=m;i++)
        {
            cin>>s;
            Union(s[0]-'a',s[s.size()-1]-'a');
            use[s[0]-'a']=use[s[s.size()-1]-'a']=true;
            out[s[0]-'a']++;
            in[s[s.size()-1]-'a']++;
        }

        int ff=1;
        for (i=0;i<26;i++)
            if (use[i])
            {
                for (j=i+1;j<26;j++)
                    if (use[j]&&getroot(j)!=getroot(i))
                        ff=0;
                break;
            }
        if (!ff)
        {
            cout<<"The door cannot be opened."<<endl;
            continue;
        }
        ff=1;
        int odd=0;
        for (i=0;i<26;i++)
        {
            if (in[i]-out[i]>1||out[i]-in[i]>1)
            {
                ff=0;
                break;
            }
            if (in[i]!=out[i])
                odd++;
        }
        if (!ff)
        {
            cout<<"The door cannot be opened."<<endl;
            continue;
        }
        if (odd==0||odd==2)
            cout<<"Ordering is possible."<<endl;
        else cout<<"The door cannot be opened."<<endl;

    }

    return 0;
}
