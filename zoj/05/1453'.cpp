#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define  MAX  100
struct node {
    double x, y;
}p[MAX], ch[MAX];

void  swap(struct node &a,  struct node &b) {
    struct node c;
    c = a; a = b; b = c;
}

double dis(struct node  a,  struct node b) {
    return  sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double  calc(struct node a, struct node b, struct node c) {//叉积计算判断转向
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int cmp(const void *a, const void *b) {    //凸包快排比较 
    struct node *c = (node *)a;
    struct node *d = (node *)b;
    if(calc(p[0], *c, *d) < 0) return 1;
    else if(calc(p[0], *c, *d) < 1e-8 && dis(p[0],*c) > dis(p[0], *d))
        return 1;
    else return -1;
}

double  graham(int  n) {
    int  top = 3, i;
    qsort(p+1, n-1, sizeof(p[0]), cmp);
    for(i = 0; i < n; i++) {
        if(i < 3){ ch[i] = p[i];  continue;}
        while(calc(ch[top-2], ch[top-1], p[i]) <= 0)  //如果右转则出栈
            top--;
        ch[top++] = p[i];
    }
    double  ans = dis(ch[0], ch[top-1]);
    for(i = 0; i < top-1; i++)
        ans += dis(ch[i], ch[i+1]);
    return  ans;
}

int main() {
    int  n;
    int  i;
    freopen("f:\\in.txt", "r", stdin);
    while(scanf("%d", &n) && n) {
        double  minx = 65536;
        int  t = -1;
        for(i = 0; i < n; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            if(p[i].x < minx || (p[i].x == minx && p[i].y < p[t].y)) {
                minx = p[i].x;
                t = i;
            }
        }
        swap(p[0], p[t]);
        if(n == 1) printf("0.00\n");
        else if(n == 2) printf("%.2lf\n", dis(p[0], p[1])*2);
        else  printf("%.2lf\n", graham(n));
    }
    return  0;
}
