#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <stack>

using namespace std;

//#define fin cin
//#define fout cout
ifstream fin ("test.in");
ofstream fout ("test.out");

int p[16];
int * res[15];
bool marked[32768];
int x;

bool dfs(int idx)
{
    if (idx > p[x] - x)
    {
        for (int i = idx; i < p[x]; i++)
        {
            res[x][i] = (res[x][i - 1] << 1) % p[x];
            if (marked[res[x][i]])
                return false;
        }
        return true;
    }

    int temp = (res[x][idx - 1] << 1) % p[x];
    if (!marked[temp])
    {
        res[x][idx] = temp;
        marked[res[x][idx]] = true;
        if (dfs(idx + 1))
        {
            return true;
        }
        marked[res[x][idx]] = false;
    }
    if (!marked[temp + 1])
    {
        res[x][idx] = temp + 1;
        marked[res[x][idx]] = true;
        if (dfs(idx + 1))
        {
            return true;
        }
        marked[res[x][idx]] = false;
    }
    return false;
}

void com()
{
    res[x] = new int[p[x]];
    fill (marked, marked + p[x], false);

    res[x][0] = 0;
    marked[0] = true;

    dfs(1);
}

void compute()
{
    p[0] = 1;
    for (int i = 1; i < 16; i++)
        p[i] = p[i - 1] * 2;

    for (int i = 1; i < 16; i++)
    {
        x = i;
        com();
    }
}

int main ()
{
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

    compute();

    int n, k;
    while (scanf("%d%d", &n, &k) != EOF && !(n == 0 && k == 0))
    {
        printf("%d\n", res[n][k]);
    }

    return 0;
}
