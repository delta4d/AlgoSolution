#include <iostream>
#include <fstream>
#include <sstream>
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
#include <bitset>
#include <list>

using namespace std;

//#define fin cin
//#define fout cout
ifstream fin ("test.in");
ofstream fout ("test.out");

char s[72][72];
string dp[72][72];
string dp0[72][72];
int w, h;
string best;

inline string maxStr(const string& a, const string& b)
{
    if (a.size() > b.size() || (a.size() == b.size() && a > b))
        return a;
    return b;
}

int main ()
{
    freopen("f:\\in.txt", "r", stdin);
    freopen("f:\\res.txt", "w", stdout);

    while (scanf("%d%d", &w, &h) != EOF)
    {
        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++)
        {
            scanf("%s", s[i]);
        }

        for (int i = 0; i <= h; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = dp0[i][j] = "";
            }
        }

        for (int i = h - 1; i >= 0; i--)
        {
            for (int j = w - 1; j >= 0; j--)
            {
                if (s[i][j] > '0' && s[i][j] <= '9')
                {
                    dp0[i][j] = "";
                    dp[i][j] = s[i][j] + maxStr(maxStr(dp0[i + 1][j], dp0[i][j + 1]), maxStr(dp[i + 1][j], dp[i][j + 1]));
                }
                else if (s[i][j] == '0')
                {
                    dp[i][j] = "";
                    dp0[i][j] = "0" + maxStr(maxStr(dp0[i + 1][j], dp0[i][j + 1]), maxStr(dp[i + 1][j], dp[i][j + 1]));
                }
                else
                {
                    dp[i][j] = dp0[i][j] = "";
                }
            }
        }

        best = "";
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                best = maxStr(best, dp[i][j]);
            }
        }

        printf("%s\n", best.c_str());
    }

    return 0;
}


