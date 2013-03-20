#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

long long num[100001], sum;
int main()
{
      int N;
      freopen("f:\\in.txt", "r", stdin);
      while(cin >> N)
      {
          sum = 0;
          num[0] = 0;
          for(int i = 0; i < N; i++)
          {
              cin >> num[i];
          }
          sort(num, num+N);
          N--;
          while(N > 2)
          {
              // the fisrt two person take the last two person to the across the bridge cooperatively.
              long long t1 = num[0] + 2*num[1] + num[N];
              // don't foget the first person take the last two person respectively.
              long long t2 = 2*num[0] + num[N] + num[N-1];
              // choose the min time of the two cases;
              sum += t1 < t2 ? t1 : t2; 
              N -= 2;
          }
          if(N == 2) sum += num[0] + num[1] + num[2];
          else if(N == 1) sum += num[1];
          else sum += num[0];
          cout << sum << endl;
      }
      return 0;
}
