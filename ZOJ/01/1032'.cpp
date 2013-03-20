#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
using namespace std;
struct dot
{
    int x;
    int y;
    dot operator= (dot d)
    {
        x = d.x;
        y = d.y;
        return (*this);
    }
};
int dotNum;        //�������
inline double FindY(dot d1, dot d2, int x);
int CommonDividor(int a, int b);   //��a��b�����Լ��
int main()
{
    int i, j, t = 0;
    int dx, dy, boardDot, inDot;   //boardDotΪ�ڱ��ϵĵ������
    double area;              //���
    dot d, d0;
    d0.x = d0.y = 0;
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &dotNum);
        boardDot = area = 0.0;
        for(i = 1; i <= dotNum; i++)
        {
            scanf("%d%d", &dx, &dy);
            d.x = d0.x + dx;
            d.y = d0.y + dy;
            boardDot += CommonDividor(abs(dx), abs(dy));
            area += (d0.x * d.y - d0.y * d.x);
            d0 = d;
            //printf("(%d, %d)\n", d.x, d.y);
        }
        area = fabs(area / 2);
        inDot = int(area + 1 - (double)boardDot / 2); //��ʽ��Ȼ��˼��
        printf("Scenario #%d:\n%d %d %.1lf\n\n", ++t, inDot, boardDot, area);

    }
    return 0;
}


int CommonDividor(int a, int b)
{
    if(!b)
        return a;
    return CommonDividor(b, a % b);
}