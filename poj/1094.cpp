#include<cstdio>
#include<memory>

using namespace std;

#define debug 0

const int MaxN = 26;
bool visit[MaxN];
bool graph[MaxN][MaxN];
int din[MaxN];
int d[MaxN];
int f[MaxN];
char buff[4];
bool inc;
bool find;
bool already;

bool check(int n)
{
    int i;
    int j;
    int index;
    bool flag;

    memcpy(d, din, sizeof(din));

    for (j=0; j<n; ++j)
    {
        flag = false;

        for (i=0; i<n; ++i)
        {
            if (d[i] == 0 && visit[i])
            {
                if (flag)
                {
                    flag = false;
                    break;
                }
                flag = true;
                index = i;
                --d[i];
            }
        }
		
		if (!flag)
		{
			break;
		}
		
        f[j] = index;

        for (i=0; i<n; ++i)
        {
            if (graph[index][i])
            {
                --d[i];
            }
        }
    }

    return j == n;
}

int main(void)
{
    int m;
    int n;
    int i;
    int j;
    int k;
    int s;
    int t;
    int inc_num;
    int find_num;
    
#if debug
	freopen("f:\\in.txt", "r", stdin);
#endif	    

    scanf("%d %d", &n, &m);

    while (n != 0 || m != 0)
    {
        inc = false;
        find = false;
        already = false;
        memset(visit, false, sizeof(visit));
        memset(din, 0, sizeof(din));
        memset(graph, false, sizeof(graph));

        for (i=0; i<m; ++i)
        {
            scanf("%s", buff);

            if (!inc && !find)
            {
                s = buff[0] - 'A';
                t = buff[2] - 'A';
                visit[s] = visit[t] = true;
                if (graph[t][s])
                {
                    inc = true;
                    inc_num = i + 1;
                }
                else if (!graph[s][t])
                {
                    graph[s][t] = true;
                    ++din[t];
                    for (j=0; j<n; ++j)
                    {
                        if (graph[j][s])
                        {
                            if (graph[t][j])
                            {
                                inc = true;
                                inc_num = i + 1;
                            }
                            else if (!graph[j][t])
                            {
                                graph[j][t] = true;
                                ++din[t];
                            }
                        }
                        
                        if (graph[t][j])
                        {
                            if (graph[j][s])
                            {
                                inc = true;
                                inc_num = i + 1;
                            }
                            else if (!graph[s][j])
                            {
                                graph[s][j] = true;
                                ++din[j];
                            }
                        }
                    }
                }
            }
			    
            if (!find)
            {
            	find = check(n);
			}
			if (!already && find)
			{
				already = true;
				find_num = i + 1;
			}
        }

        if (inc)
        {
            printf("Inconsistency found after %d relations.\n", inc_num);
        }
        else if (find)
        {
            printf("Sorted sequence determined after %d relations: ", find_num);
            for (i=0; i<n; ++i)
            {
                printf("%c", f[i] + 'A');
            }
            printf(".\n");
        }
        else
        {
            printf("Sorted sequence cannot be determined.\n");
        }

        scanf("%d %d", &n, &m);
    }

    return 0;
}