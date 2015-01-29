/**************************************************************
    Problem: 2818
    User: delta
    Language: C++
    Result: Accepted
    Time:5620 ms
    Memory:89164 kb
****************************************************************/
 
#include <iostream>
using namespace std;
 
typedef long long ll;
int const N = 1e7 + 10;
 
ll f[N];
bool v[N];
 
ll dfs(int n) {
    if (f[n]) return f[n];
    ll ret = (ll)n * n;
    for (int i=2; i<=n; ++i) ret -= dfs(n/i);
    return f[n] = ret;
}
 
int main() {
    f[1] = 1, v[1] = true;
    int n;
    cin >> n;
    dfs(n);
    ll tot = 0;
    for (ll i=2; i*i<=n; ++i) for (ll j=i*i; j<=n; j+=i) v[j] = true;
    for (int i=2; i<=n; ++i) if (!v[i]) tot += f[n/i];
    cout << tot << endl;
    return 0;
}
