#include <iostream>
#include <algorithm>
using namespace std;

double a1[202];
double a2[202];
double b1[202];
double b2[202];

double t1[404];
double t2[404];

int main()
{
    int d;
    int t;
    int y = 0;
    cout.precision(2);
    while (cin >> d )
    {
        if ( d == 0)  break;
        t = 0;
        cout << "Test case #" << ++y << endl;
        cout << "Total explored area: ";
        for (int i = 0;i < d;i++)
        {
            cin >> a1[i] >> b1[i] >> a2[i] >> b2[i];
            t1[t] = a1[i];
            t2[t] = b1[i];
            t++;
            t1[t] = a2[i];
            t2[t] = b2[i];
            t++;
        }

        sort(t1,t1+t);
        sort(t2,t2+t);

        double areaa = 0;
        for ( int i = 0;i < t-1;i++ )
        {
            for ( int j = 0;j < t-1;j++)
            {
                for ( int k = 0;k < d;k++)
                {
                    if ( (t1[i] >= a1[k]) && (t2[j] >= b1[k]) && (t1[i+1] <= a2[k]) && (t2[j+1] <= b2[k]) )
                    {
                        areaa += (t1[i+1] - t1[i])*(t2[j+1]-t2[j]);
                        break;
                    }
                }
            }
        }
        cout << fixed << areaa << endl;
        cout << endl;
    }

    return 0;
}
