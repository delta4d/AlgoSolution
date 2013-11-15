#include<stdio.h>

char city[201][31];
int graph[201][201];

int floyd(int x, int y, int n)
{
    int i;
    int j;
    int k;
    int min;


    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
        {
            for (k=1; k<=n; ++k)
            {
                min = graph[i][k] < graph[k][j] ? graph[i][k] : graph[k][j];

                if (graph[i][j] == 0)
                {
                    graph[i][j] = min;
                }
                else
                {
                    graph[i][j] = graph[i][j] > min ? graph[i][j] : min;
                }
            }
        }
    }


    return graph[x][y];
}

int find(int n, char *p)
{
    int i;
    int flag = 0;

    for (i=1; i<n; ++i)
    {
        if (strcmp(city[i], p) == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        return i;
    }
    else
    {
        return 0;
    }
}


int main(void)
{
    int n;
    int r;
    int i;
    int j;
    int k;
    int x;
    int y;
    int len;
    int order = 1;
    int isfound;
    char s[31];
    char t[31];

    scanf("%d %d", &n, &r);

    while (n != 0 || r != 0)
    {
        k = 1;

        for (i=1; i<=n; ++i)
        {
            for (j=1; j<=n; ++j)
            {
                graph[i][j] = 0;
            }
        }

        for (i=0; i<r; ++i)
        {
            scanf("%s %s %d", s, t, &len);

            isfound = find(k, s);

            if (isfound == 0)
            {
                x = k;
                strcpy(city[k], s);
                ++k;
            }
            else
            {
                x = isfound;
            }

            isfound = find(k, t);

            if (isfound == 0)
            {
                y = k;
                strcpy(city[k], t);
                ++k;
            }
            else
            {
                y = isfound;
            }

            graph[x][y] = graph[y][x] = len;
        }

        scanf ("%s %s", s, t);

        x = find(k, s);
        y = find(k, t);

        len = floyd(x, y, n);

        printf("Scenario #%d\n%d tons\n\n", order, len);

        ++order;

        scanf("%d %d", &n, &r);
    }

    return 0;
}
