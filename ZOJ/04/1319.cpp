#include<cstdio>
#include<queue>
#include<stack>

using namespace std;

const int MaxN = 30001;
long a[MaxN];
long u[MaxN];
stack<int>t;
priority_queue<int>s;

int main(void)
{
	long m;
	long n;
	long test_case;
	long i;
	long j;
	long k;
	long ss;
	long temp;
	
	scanf("%ld", &test_case);
	
	for (k=0; k<test_case; ++k)
	{
		scanf("%ld %ld", &m, &n);
		
		for (i=1; i<=m; ++i)
		{
			scanf("%ld", a + i);
		}
		
		for (i=1; i<=n; ++i)
		{
			scanf("%ld", u + i);
		}
		
		while (!s.empty())
		{
			s.pop();
		}
		
		while (!t.empty())
		{
			t.pop();
		}
		
		for (i=1; i<=n; ++i)
		{
			ss = s.size();
			
			if (u[i] < ss)
			{
				for (j=ss; j>u[i]; --j)
				{
					temp = s.top();
					s.pop();
					t.push(temp);
				}
			}
			else if (u[i] > ss)
			{
				for (j=ss+1; j<=u[i]; ++j)
				{
					s.push(a[j]);
				}
			}
			
			for (j=i; j<u[i]; ++j)
			{
				temp = s.top();
				s.pop();
				t.push(temp);
			}
			
			temp = s.top();
			
			printf("%ld\n", temp);
			
			while (!t.empty())
			{
				temp = t.top();
				t.pop();
				s.push(temp);
			}
		}
		
		if (k < test_case - 1)
		{
			printf("\n");
		}
	}
	
	return 0;
}
