#include<stdio.h>
#define N 100

char a[N][N]; 
int n,m;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int c;

void backtrack(int x,int y)
{
 int k=0,px,py;
 while(k<8)
 {
  px=x+dx[k];
  py=y+dy[k];
  if((px<0||px>=n||py<0||py>=m||a[px][py]=='.')&&k%2==0) c++;
  if(px>=0&&px<n&&py>=0&&py<m&&a[px][py]=='X')
  {
   a[px][py]='A';
   backtrack(px,py); 
      } 
  k++;
 } 
}

int main()
{
 int x1,y1,i;
 scanf("%d %d %d %d",&n,&m,&x1,&y1);
 while(n!=0||m!=0||x1!=0||y1!=0)
 {
  for(i=0;i<n;i++)
   scanf("%s",a[i]);
  c=0;
  a[x1-1][y1-1]='A';
  backtrack(x1-1,y1-1);
  printf("%d\n",c);
  scanf("%d %d %d %d",&n,&m,&x1,&y1); 
 }


 return 0; 
}
