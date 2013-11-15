#include <stdio.h>
struct move
{
    int start,end;
    char c;
};
move d[1000];
int rows,cols,n,matrix[100][100];
int isValid(int row,int col,int k)
{
    if(k>n)
        return 1;
    int num,i;
    if(d[k-1].c=='R')
    {
        for(num=d[k-1].start; num<=d[k-1].end; num++)
        {
            if(col+num>=cols)    //移动路径超出矩阵范围
                break;
            for(i=1; i<=num; i++)
                if(matrix[row][col+i])
                    break;
            if(i<=num)      //移动路径上有障碍
                break;
            if(isValid(row,col+num,k+1)) //已经找到
                return 1;
        }
        return 0;
    }
    else if(d[k-1].c=='L')
    {
        for(num=d[k-1].start; num<=d[k-1].end; num++)
        {
            if(col-num<0)
                break;
            for(i=1; i<=num; i++)
                if(matrix[row][col-i])
                    break;
            if(i<=num)
                break;
            if(isValid(row,col-num,k+1))
                return 1;
        }
        return 0;
    }
    else if(d[k-1].c=='D')
    {
        for(num=d[k-1].start; num<=d[k-1].end; num++)
        {
            if(row+num>=rows)
                break;
            for(i=1; i<=num; i++)
                if(matrix[row+i][col])
                    break;
            if(i<=num)
                break;
            if(isValid(row+num,col,k+1))
                return 1;
        }
        return 0;
    }
    else
    {
        for(num=d[k-1].start; num<=d[k-1].end; num++)
        {
            if(row-num<0)
                break;
            for(i=1; i<=num; i++)
                if(matrix[row-i][col])
                    break;
            if(i<=num)
                break;
            if(isValid(row-num,col,k+1))
                return 1;
        }
        return 0;
    }
}
int main()
{
    freopen("f:\\in.txt", "r", stdin);
    freopen("f:\\out.txt", "w", stdout);
    int caseNum,i,j,m;
    scanf("%d",&caseNum);
    while(caseNum--)
    {
        scanf("%d %d",&rows,&cols);
        for(i=0; i<rows; i++)
            for(j=0; j<cols; j++)
                scanf("%d",&matrix[i][j]);
        n=0;
        while(scanf("%d %d",&d[n].start,&d[n].end))
        {
            if(d[n].start==0&&d[n].end==0)
                break;
            scanf(" %c",&d[n].c);
            n++;
        }
        m=0;
        for(i=0; i<rows; i++)
            for(j=0; j<cols; j++)
                if(matrix[i][j]==0&&isValid(i,j,1))
                {
                    //可能的起始位置
                    m++;
                    printf("%d %d\n", i, j);
                }
        printf("%d\n",m);
    }
    return 0;
}