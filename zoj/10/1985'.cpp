#include <cstdio>
using namespace std;
const int MAX = 100005;
long long h[MAX];
long long left[MAX], right[MAX];        //left[i] = j表示第i个矩形以它的高度到达最左边的下标
int n;

bool Input ()
{
    scanf("%d", &n);
    if ( n == 0 )
        return false;
    int i;
    for (i=1; i<=n; i++)
        scanf("lld", &h[i]);
    h[0] = h[n+1] = -1;
    return true;
}

void Solve ()
{
    int i;
    long long temp, max;
    
    for (i=1; i<=n; i++)
    {
        left[i] = right[i] = i;
    }

    for (i=1; i<=n; i++)
    {
        while ( h[left[i]-1] >= h[i] )
            left[i] = left[left[i]-1];
    }
    
    for (i=n; i>0; i--)
    {
        while ( h[right[i]+1] >= h[i] )
            right[i] = right[right[i]+1];
    }

    max = 0;
    
    for (i=1; i<=n; i++)
    {
        temp = h[i] * (right[i] - left[i] + 1);
        if ( temp > max )
            max = temp;
    }

    printf("%lld\n", max);
}

int main ()
{
    while ( Input() )
    {
        Solve();
    }

    return 0;
}
