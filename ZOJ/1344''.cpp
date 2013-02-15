#include <cstdio>
#include <cstring>
using namespace std;
const int dx[5] = {-1, 0, 1, 0, 0};
const int dy[5] = {0, 1, 0, -1, 0};

#define maxn 52
#define qLen 52 * 52
int n, m, x0, y0, gx, gy, dogdir, d, order[maxn], nCase(0);
bool f[maxn][maxn][maxn], ok[maxn][maxn][maxn];
int x[qLen], y[qLen], z[qLen];

int solve()
{
    for (int k = 1; k <= d; k++)
    {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ok[k][i][j] = ok[0][i][j]; //Dog Moving
        if (!order[k])
        {
            gx += dx[dogdir];
            gy += dy[dogdir];
        }
        if (order[k] == 1) dogdir = (dogdir + 3) % 4;
        if (order[k] == 2) dogdir = (dogdir + 1) % 4; //Get the Range that man cannot reach at time k
        int tx = gx, ty = gy;
        while (ok[k][tx][ty] = 0, ok[0][tx += dx[dogdir]][ty += dy[dogdir]]);
    }
    int front = -1, rear = 0;
    while (front != rear)
    {
        front++;
        front %= qLen;
        int tz = z[front] + 1;
        tz = tz > d ? tz % d : tz;
        for (int i = 0; i < 5; i++)
        {
            int tx = x[front] + dx[i], ty = y[front] + dy[i];
            if (!ok[tz][tx][ty]) continue;
            if (f[tz][tx][ty]) continue;
            else f[tz][tx][ty] = 1;
            rear++;
            rear %= qLen; /* rear = (rear + 1) % qLen;//???? */
            x[++rear] = tx;
            y[rear] = ty;
            z[rear] = z[front] + 1;
            if (tx == x0 && ty == y0) return z[rear];
        }
    }
    return -1;
}
int main(int argc, char* argv[])
{
    while (scanf("%d %d", &n, &m), (n + m))   // Init Array F which is for memorize the path
    {
        memset(f, 0, sizeof(f));
        scanf("%d %d", &x0, &y0);
        f[0][x0][y0] = 1;
        x[0] = x0;
        y[0] = y0;
        z[0] = 0; // Read Data
        scanf("%d %d %d %d %d", &x0, &y0, &gx, &gy, &d);
        dogdir = 0;
        for (int i = 1; i <= d; i++)
        {
            char c;
            while (scanf("%c", &c), c != 'R' && c != 'L' && c != 'G');
            if (c == 'G') order[i] = 0;
            if (c == 'L') order[i] = 1;
            if (c == 'R') order[i] = 2;
        }
        memset(ok, 0, sizeof(ok));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
            {
                char c;
                while (scanf("%c", &c), c != '*' && c != '.');
                if (c == '*') ok[0][i][j] = 0;
                else ok[0][i][j] = 1;
            }
        int ans = solve(); // Output the Ans
        if (nCase) printf("\n");
        printf("Case %d:\n", ++nCase);
        if (ans < 0) printf("No way out\n");
        else printf("Minimal time is: %d\n", ans);
    }
    return 0;
}
