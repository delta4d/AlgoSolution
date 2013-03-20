#include<cstdio>
#include<map>
using namespace std;
#define MAXLINE 120010
#define sf      scanf
#define pf      printf

int encr[MAXLINE];
int lenE,lenK;
int key[30];

int CountPart(int start, int len, int &mostCh, int enc[], int lenN)
{
    int Hash[200],re=-1,id;

    memset(Hash,0,sizeof(Hash));

    for(int i = 0 ; (id=start+i*len) < lenN; i ++)
    {
        int cur = enc[id];
        if (Hash[cur]>=1)
        {
            Hash[cur]++;
            if(re < Hash[cur])
            {
                mostCh= cur;
                re=Hash[cur];
            }
        }
        else
        {
            Hash[cur]=1;    //donot have
            if(re == -1)mostCh=cur;
        }
    }
    return re;
}


int CountSame(int len,int enc[],int lenN)
{
    int start,AllSum=0;
    int mostCh;

    for(start=0; start<len; start++)
    {
        AllSum += CountPart(start, len, mostCh, enc, lenN);
    }
    return AllSum;
}

int GetKeylen(int enc[], int lenN)
{
    int start,maxSame=0,bestLen,len;
    for(len = 29<lenN?29:lenN; len>0; len--)
    {
        int count = CountSame(len,enc,lenN);
        if(count >= maxSame)
        {
            bestLen = len;
            maxSame = count;
        }
    }
    return bestLen;
}

void Decode(int enc[], int lenN)
{
    int j,i;
    for(i = 0 ; i < lenN ; i ++)
    {
        enc[i]^=key[i%lenK];
    }
}

void Input()
{
    while(scanf("%d",&encr[lenE++])!=EOF);
}

void Output()
{
    for(int i = 0 ; i < lenE-1; i ++)
        pf("%c",encr[i]);
}

void MakeupKey(int enc[], int lenN)
{
    int k,mostCh;

    for(k=0; k<lenK; k++)
    {
        CountPart(k, lenK, mostCh, enc, lenN);
        key[k]= mostCh^' ';
    }
}

void Decryption()
{
    for (int num=0; num < 4; num++)
    {
        lenK=GetKeylen(encr+num*30000, 30000);
        MakeupKey(encr+num*30000, 30000);
        Decode(encr+num*30000, 30000);
    }
}

int main()
{
    freopen("f:\\in.txt","r",stdin);
     freopen("f:\\out.txt","w",stdout);
    lenE=0;
    Input();
    Decryption();
    Output();
    return 0;
}