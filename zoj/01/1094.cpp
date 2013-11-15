#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

struct matrix
{
	long r;
	long c;
	char name;
	
	matrix (long r, long c, char name) : r(r), c(c), name(name) {}
};

stack<matrix>f;
long x[26];
long y[26];
long res;
bool flag;

void check()
{
	if (f.size() == 1)
	{
		return;
	}
	
	matrix last = f.top();
	f.pop();
	matrix temp = f.top();
	
	if (temp.name == 'a')
	{
		if (temp.c != last.r)
		{
			flag = false;
			return;
		}
		else
		{
			res += temp.r * temp.c * last.c;
			temp.c = last.c;
			f.pop();
			f.push(temp);
			
			check();
		}
	}
	else
	{
		f.push(last);
		return;
	}
}

int main(void)
{
	long n;
	long i;
	long j;
	long len;
	char name;
	char ex[100];
	
	cin >> n;
	
	for (i=0; i<n; ++i)
	{
		cin >> name;
		cin >> x[name - 'A'] >> y[name - 'A'];		
	}
	
	while (cin >> ex)
	{		
		/*while (f.size() != 0)
		{
			f.pop();
		}*/
		
		stack<matrix>().swap(f);
		
		res = 0;
		flag = true;
		len = strlen(ex);
		
		if (ex[0] == '(')
		{
			f.push(matrix(0, 0, '('));
		}
		else
		{
			f.push(matrix(x[ex[0]-'A'], y[ex[0]-'A'], 'a'));
		}
		
		for (i=1; i<len; ++i)
		{
			if (ex[i] == '(')
			{
				f.push(matrix(0, 0, '('));
			}
			else if (ex[i] == ')')
			{
				matrix temp = f.top();
				f.pop();
				f.pop();
				f.push(temp);
				
				check();
			}
			else
			{
				f.push(matrix(x[ex[i]-'A'], y[ex[i]-'A'], 'a'));
				
				check();
			}
			
			if (!flag)
			{
				break;
			}
		}
		
		if (flag)
		{
			cout << res << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	
	return 0;
}
