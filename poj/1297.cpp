#include <cstdio>
#include <cstring>
using namespace std;
double a[100];
int b[100], n, m, mx, tmx;

int main()
{
 int i, k;
 //freopen("in.txt", "r", stdin);
 while(scanf("%d %d", &n, &m) && n)
 {
  memset(a, 0, sizeof(a));
  for(i = 0; i < n; i ++)
  {
   scanf("%d", &b[i]);
  }
  mx = 0, tmx = mx;
  for(i = 0; i < m; i ++)
  {
   int ti; double td;
   scanf("%d %lf", &ti, &td);
   mx = tmx;
   for(k = mx; k >= 0; k --)
   {
    if(ti == b[k])
    {
     if(a[k] == 0 || a[k - 1] + td < a[k])
     {
      a[k] = td + a[k - 1];
      if(k == mx && mx < n - 1)
       tmx = mx + 1;
     }
    }
   }
  }
  if(a[n - 1] != 0)
   printf("%0.2f\n", a[n - 1]);
  else
   printf("Impossible\n");
 }
 return 0;
}

