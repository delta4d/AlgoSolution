#include<cstdio>
#include<memory>

using namespace std;

struct square
{
    int top;
    int right;
    int bottom;
    int left;
};

const int MaxN = 25;
bool find;
square buff[MaxN];
int num[MaxN];
int game[MaxN];
int k;
int n;

void dfs(int depth)
{
    int i;
    int x;
    int y;

    if (depth == n * n)
    {
        find = true;
        return;
    }

    for (i=0; i<k; ++i)
    {
        if (num[i] == 0)
        {
        	continue;
		}
		
		if (depth % n != 0)
		{
			if (buff[game[depth-1]].right != buff[i].left)
			{
				continue;
			}
		}
		
		if (depth / n != 0)
		{
			if (buff[game[depth-n]].bottom != buff[i].top)
			{
				continue;
			}
		}
		
		--num[i];
		game[depth] = i;
		
		dfs(depth + 1);
		
		if (find)
		{
			return;
		}
		
		++num[i];
    }
}

int main(void)
{
    int i;
    int j;
    int case_num = 1;
    square temp;

    scanf("%d", &n);

    while (n != 0)
    {
    	k = 0;
    	memset(num, 0 ,sizeof(num));
    	
        for (i=0; i<n*n; ++i)
        {
            scanf("%d %d %d %d", &temp.top, &temp.right, &temp.bottom, &temp.left);
            
            for (j=0; j<k; ++j)
            {
            	if ((buff[j].bottom == temp.bottom) && (buff[j].left == temp.left)
				   &&(buff[j].right == temp.right) && (buff[j].top == temp.top))
            	{
            		++num[j];
            		break;
				}
			}
			
			if (j == k)
			{
				buff[k] = temp;
				++num[k];
				++k;
			}
        }

        find = false;
		
		if (n != 1)
		{
        	dfs(0);
		}
		else
		{
			find = true;
		}
		
        printf("Game %d: ", case_num);
        if (find)
        {
            printf("Possible\n");
        }
        else
        {
            printf("Impossible\n");
        }
        ++case_num;

        scanf("%d", &n);
        
        if (n != 0)
        {
        	printf("\n");
		}
    }

    return 0;
}
