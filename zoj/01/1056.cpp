#include<stdio.h>
#include<memory.h>

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int f[52][52];
int head[2];
int tail[2];
char move[101];

void init()
{
    int i;

    memset(f, 0, sizeof(f));

    for (i=11; i<=30; ++i)
    {
        f[25][i] = 1;
    }

	for (i=0; i<52; ++i)
	{
		f[0][i] = 2;
		f[i][0] = 2;
		f[51][i] = 2;
		f[i][51] = 2;
	}

    head[0] = 25;
    tail[0] = 25;
    head[1] = 30;
    tail[1] = 11;

    return;
}

int main(void)
{
    int n;
    int i;
    int j;
    int into_flag;
    int off_flag;


    scanf("%d", &n);

    while (n != 0)
    {
        scanf("%s", move);

        init();

        into_flag = 0;
        off_flag = 0;

        for (i=0; i<n; ++i)
        {
            for (j=0; j<4; ++j)
            {
                if ((f[tail[0]+dx[j]][tail[1]+dy[j]] == 1) && (tail[0] +dx[j] != head[0] || tail[1] + dy[j] != head[1]))
                {
                    break;
                }
            }

            f[tail[0]][tail[1]] = 0;
            tail[0] = tail[0] + dx[j];
            tail[1] = tail[1] + dy[j];

            if (move[i] == 'W')
            {
				head[0] += dx[0];
				head[1] += dy[0];
            }
            else if (move[i] == 'N')
            {
				head[0] += dx[1];
				head[1] += dy[1];
            }
            else if (move[i] == 'E')
            {
				head[0] += dx[2];
				head[1] += dy[2];
            }
            else
            {
				head[0] += dx[3];
				head[1] += dy[3];
            }
            
            if (f[head[0]][head[1]] == 1)
            {
            	into_flag = 1;
            	break;
			}
			
			if (f[head[0]][head[1]] == 2)
			{
				off_flag = 1;
				break;
			}
			
			f[head[0]][head[1]] = 1;
        }
        
        if (off_flag == 1)
        {
        	printf("The worm ran off the board on move %d.\n", i + 1);
		}
		else if (into_flag == 1)
		{
			printf("The worm ran into itself on move %d.\n", i + 1);
		}
		else
		{
			printf("The worm successfully made all %d moves.\n", n);
		}

        scanf("%d", &n);
    }

    return 0;
}
