££i nclude <iostream>
££i nclude <string>
using namespace std;

int main()
{
    int N, a[110], aa[2][2100], p;
    
    for (cin >> N; N >= 0; cin >> N)
    {
        for (int i = 0; i < N; i ++)
            cin >> a[i];
            
        memset(aa, -1, sizeof(aa));
        
        aa[1][0] = 0;
        p = 0;
        
        for (int i = 0, end = 0; i < N; i ++, p = 1 - p)
        {
            memcpy(aa[p], aa[1 - p], sizeof(aa[p]));
            end += a[i];
            
            for (int j = 0; j <= end; j ++)
            {
                if (j + a[i] <= end && aa[1 - p][j] >= 0 && aa[p][j + a[i]] < aa[1 - p][j] + a[i])
                    aa[p][j + a[i]] = aa[1 - p][j] + a[i];
                    
                int k = abs(j - a[i]);
                
                if (k <= end && aa[1 - p][j] >= 0 && aa[p][k] < aa[1 - p][j] + a[i])
                    aa[p][k] = aa[1 - p][j] + a[i];
            }
        }
        
        if (aa[1 - p][0])
            cout << aa[1 - p][0] / 2 << endl;
        else cout << "Sorry" << endl;
    }
    
    return 0;
}
