#include<stdio.h>
#include<memory.h>

#define MaxN 1000

int f[MaxN];

int find_root(int n)
{
    if (f[n] == -1)
    {
        return n;
    }

    return f[n] = find_root(f[n]);
}

int main(void)
{
    int s;
    int t;
    int i;
    int tree;
    int case_num = 1;
    int root;
    int cur_root;
    int max;

    scanf ("%d %d", &s, &t);

    while ((s >= 0) || (t >= 0))
    {
        tree = 1;

        memset(f, 0, sizeof(f));

        while ((s != 0) || (t != 0))
        {
            if (tree == 1)
            {
                if (f[t] > 0)
                {
                    tree = 0;
                }
                else
                {
                    if (f[s] == 0)
                    {
                        f[s] = -1;
                    }

                    if (f[t] == 0)
                    {
                    	f[t] = find_root(s);
					}
					else if (find_root(t) == find_root(s))
					{
						tree = 0;
					}
					else
					{
						f[t] = find_root(s);
					}
                }
            }
            scanf ("%d %d", &s, &t);
        }

        if (tree == 1)
        {
            for (i=1; i<MaxN; ++i)
            {
                if (f[i] == -1)
                {
                    root = i;
                    break;
                }
            }

            for (i=1; i<MaxN; ++i)
            {
                if (f[i] == -1)
                {
                    if (i != root)
                    {
                        tree = 0;
                        break;
                    }
                }
                else if (f[i] > 0)
                {
                    cur_root = find_root(i);
                    if (cur_root != root)
                    {
                        tree = 0;
                        break;
                    }
                }
            }

            if (tree == 1)
            {
                printf("Case %d is a tree.\n", case_num);
            }
            else
            {
                printf("Case %d is not a tree.\n", case_num);
            }
        }
        else
        {
            printf("Case %d is not a tree.\n", case_num);
        }

        ++case_num;
        scanf ("%d %d", &s, &t);
    }

    return 0;
}
