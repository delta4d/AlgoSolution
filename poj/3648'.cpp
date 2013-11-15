/*2-SAT第六题*/
/*AC代码：0ms*/
#include <iostream>
#include <string.h>
#define MAXN 200
using namespace std;
struct edge
{
	int from,to,next;
};
struct edge E[2000000],E2[2000000];
int head[MAXN],ecnt,head2[MAXN],ecnt2;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
bool Instack[MAXN];
int Index,scc,top,N,M;
int opp[MAXN];//what a opposite;
int ans[MAXN];//存染色后的结果
void Insert(int from,int to)
{
	E[ecnt].from=from;
	E[ecnt].to=to;
	E[ecnt].next=head[from];
	head[from]=ecnt++;
}
void Insert2(int from,int to)
{
	E2[ecnt2].from=from;
	E2[ecnt2].to=to;
	E2[ecnt2].next=head2[from];
	head2[from]=ecnt2++;
}
void Tarjan(int u)
{
	int i,v;
	Low[u]=DFN[u]=++Index;
	Stack[++top]=u;
	Instack[u]=true;
	for(i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;
		if(!DFN[v])
		{
			Tarjan(v);
			if(Low[u]>Low[v])
				Low[u]=Low[v];
		}
		else if(Instack[v]&&Low[u]>DFN[v])
			Low[u]=DFN[v];
	}
	if(Low[u]==DFN[u])
	{
		scc++;
		do{
			v=Stack[top--];
			Instack[v]=false;
			Belong[v]=scc;
		}while(u!=v);
	}
	return;
}
int get_num(char s[15])//返回的是坐左边时的号码
{
	int i,w=0,len=strlen(s);
	for(i=0;i<len-1;i++)
		w=w*10+s[i]-'0';
	if(s[len-1]=='h')
		return w+2*N;
	return w;
}
void Init()//构图
{
	int i,u,v;
	char s1[15],s2[15];
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<N;i++)//表示夫妻不能坐同一边
	{
		Insert(i,i+3*N);
		Insert(i+3*N,i);
		Insert(i+N,i+2*N);
		Insert(i+2*N,i+N);
	}
	Insert(N,0);//自己规定新娘坐左边
	Insert(2*N,3*N);//新郎坐右边
	for(i=1;i<=M;i++)
	{
		scanf("%s%s",s1,s2);
		u=get_num(s1);v=get_num(s2);
		Insert(u+N,v);//如果一个坐了右边，另一个只能坐左边
		Insert(v+N,u);
	}
}
bool Sat()//判断是否可行
{
	int i;
	memset(Instack,false,sizeof(Instack));
	memset(DFN,0,sizeof(DFN));
	memset(Low,0,sizeof(Low));
	Index=scc=top=0;
	for(i=0;i<4*N;i++)
	{if(!DFN[i]) Tarjan(i);}
	for(i=0;i<2*N;i++)
	{
		if(Belong[i]==Belong[i+2*N])
			return false;
		opp[Belong[i]]=Belong[i+2*N];
		opp[Belong[i+2*N]]=Belong[i];
	}
	return true;
}
//缩点+反向建图+Topsort+染色
void Solve()
{
	int Q[20000],col[MAXN],in[MAXN],u,v,i;
	memset(head2,-1,sizeof(head2));ecnt2=0;
	memset(in,0,sizeof(in));
	memset(col,0,sizeof(col));
	for(i=0;i<ecnt;i++)//缩点+反向建图
	{
		if(Belong[E[i].from]!=Belong[E[i].to])
		{
			Insert2(Belong[E[i].to],Belong[E[i].from]);
			in[Belong[E[i].from]]++;
		}
	}
	//Topsort+染色
	int l=0,r=0;
	for(i=0;i<scc;i++)
	{if(in[i]==0) Q[r++]=i;}
	while(l<r)
	{
		u=Q[l++];
		//对于未着色的点x，将x染成红色，同时将与x矛盾的点cf[x]染成蓝色。
		if(col[u]==0)//若没染过色
		{
			col[u]=1;
			col[opp[u]]=-1;
		}
		v=head2[u];
		while(v!=-1)
		{
			if(--in[E2[v].to]==0)
				Q[r++]=E2[v].to;
			v=E2[v].next;
		}
	}
	memset(ans,0,sizeof(ans));
	for(i=0;i<4*N;i++)// 2-sat的一组解就等价于所有缩点后点颜色为红色的点
		if(col[Belong[i]]==1)
			ans[i]=1;
}
void Output()//输出一组可行解
{
	int i;
	for(i=1;i<N;i++)
	{
		if(ans[i])
			printf("%dw ",i);
	}
	for(i=2*N;i<3*N;i++)
	{
		if(ans[i])
			printf("%dh",i-2*N);
	}
	printf("\n");
}
int main()
{
	freopen("d:\\in.txt", "r", stdin);
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		if(N==0&&M==0) break;
		Init();
		if(!Sat())
			printf("bad luck\n");
		else
		{
			Solve();
			Output();
		}
	}
	return 0;
} 
