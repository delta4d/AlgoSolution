/*2-SAT������*/
/*AC���룺0ms*/
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
int ans[MAXN];//��Ⱦɫ��Ľ��
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
int get_num(char s[15])//���ص��������ʱ�ĺ���
{
	int i,w=0,len=strlen(s);
	for(i=0;i<len-1;i++)
		w=w*10+s[i]-'0';
	if(s[len-1]=='h')
		return w+2*N;
	return w;
}
void Init()//��ͼ
{
	int i,u,v;
	char s1[15],s2[15];
	memset(head,-1,sizeof(head));ecnt=0;
	for(i=1;i<N;i++)//��ʾ���޲�����ͬһ��
	{
		Insert(i,i+3*N);
		Insert(i+3*N,i);
		Insert(i+N,i+2*N);
		Insert(i+2*N,i+N);
	}
	Insert(N,0);//�Լ��涨���������
	Insert(2*N,3*N);//�������ұ�
	for(i=1;i<=M;i++)
	{
		scanf("%s%s",s1,s2);
		u=get_num(s1);v=get_num(s2);
		Insert(u+N,v);//���һ�������ұߣ���һ��ֻ�������
		Insert(v+N,u);
	}
}
bool Sat()//�ж��Ƿ����
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
//����+����ͼ+Topsort+Ⱦɫ
void Solve()
{
	int Q[20000],col[MAXN],in[MAXN],u,v,i;
	memset(head2,-1,sizeof(head2));ecnt2=0;
	memset(in,0,sizeof(in));
	memset(col,0,sizeof(col));
	for(i=0;i<ecnt;i++)//����+����ͼ
	{
		if(Belong[E[i].from]!=Belong[E[i].to])
		{
			Insert2(Belong[E[i].to],Belong[E[i].from]);
			in[Belong[E[i].from]]++;
		}
	}
	//Topsort+Ⱦɫ
	int l=0,r=0;
	for(i=0;i<scc;i++)
	{if(in[i]==0) Q[r++]=i;}
	while(l<r)
	{
		u=Q[l++];
		//����δ��ɫ�ĵ�x����xȾ�ɺ�ɫ��ͬʱ����xì�ܵĵ�cf[x]Ⱦ����ɫ��
		if(col[u]==0)//��ûȾ��ɫ
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
	for(i=0;i<4*N;i++)// 2-sat��һ���͵ȼ���������������ɫΪ��ɫ�ĵ�
		if(col[Belong[i]]==1)
			ans[i]=1;
}
void Output()//���һ����н�
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
