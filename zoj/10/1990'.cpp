#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string ord[2];
char len[2][3005];

string dfs(string tmp)
{
    int i ;
    if(tmp == "01")
        return tmp ;
    tmp = tmp.substr(1, tmp.length()-2);
    int flag = 0;
    vector<string>subtree;
	//subtree.clear ();
    int start, end;
    for(i = 0, start = 0; i < tmp.size(); ++i)
    {
        if(tmp[i] == '0')
            flag ++ ;
        else
            flag -- ;
        if(!flag)
        {
            subtree.push_back(dfs(tmp.substr(start,i - start + 1)));
            start = i + 1;
        }
    }
    sort(subtree.begin(),subtree.end());
    string ret = "0";
    for(i = 0 ; i < subtree.size () ; i ++)
        ret += subtree[i];
    ret += "1";
    return ret;

}

int main()
{
    int test;
    freopen("f:\\in.txt", "r", stdin);
    scanf("%d",&test);
    while(test --)
    {
        len[0][0] = len[1][0] = '0';
        scanf("%s%s",len[0] + 1,len[1] + 1);
        //cin >> ( len[0]+1 ) >> ( len[1]+1 ) ;
        ord[0] = string(len[0]) + "1" ;
        ord[1] = string(len[1]) + "1" ;

        if (dfs(ord[0]) == dfs(ord[1]))
            printf("same\n");
        else
            printf("different\n");

    }
    return 0 ;
}