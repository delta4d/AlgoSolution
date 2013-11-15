#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 19931117
#define max(a,b) ((a)>(b)?(a):(b))

int tian[1100], qi[1100], n;
int dyna[1100][1100];

int cmp(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

int compare (int t, int q) {
    if (tian[t - 1] > qi[q - 1]) return 200;
    else if (tian[t - 1] == qi[q - 1]) return 0;
    else return -200;
}

int main () {
    int i, j, ans;
    //freopen("f:\\in.txt", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (i = 0; i < n; i++)
            scanf("%d", &tian[i]);
        for (i = 0; i < n; i++)
            scanf("%d", &qi[i]);
        dyna[0][0] = 0;
        ans = -MAX;
        qsort(tian, n, sizeof(tian[0]), cmp);
        qsort(qi, n, sizeof(qi[0]), cmp);
        for (i = 1; i <= n; i++)
        {
            dyna[i][i] = dyna[i - 1][i - 1] + compare(i, i);
            dyna[i][0] = dyna[i - 1][0] + compare(n - i + 1, i);
            for (j = 1; j < i; j++)
                dyna[i][j] = max(dyna[i - 1][j] + compare(n - i + j + 1, i), dyna[i - 1][j - 1] + compare(j, i));
        }
        for (i = 0; i <= n; i++)
            ans = max(ans, dyna[n][i]);
        printf("%d\n", ans);
    }
    return 0;
}
