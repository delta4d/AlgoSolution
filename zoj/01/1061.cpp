#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void)
{
	stack<string>forward;
	stack<string>backward;
	string cur;
	string order;
	int TestCase;
	int k;
	int i;
	
	cin >> TestCase;
	
	for (k=0; k<TestCase; ++k)
	{
		while (!forward.empty())
		{
			forward.pop();
		}
		
		while (!backward.empty())
		{
			backward.pop();
		}
		
		cin >> order;
		
		cur = "http://www.acm.org/";
		
		while (order != "QUIT")
		{
			if (order == "BACK")
			{				
				if (!backward.empty())
				{
					forward.push(cur);
					cur = backward.top();
					backward.pop();
					cout << cur << endl;
				}
				else
				{
					cout << "Ignored" << endl;
				}
			}
			else if (order == "FORWARD")
			{				
				if (!forward.empty())
				{
					backward.push(cur);
					cur = forward.top();
					forward.pop();
					cout << cur << endl;
				}
				else
				{
					cout << "Ignored" << endl;
				}
			}
			else
			{				
				backward.push(cur);
				
				cin >> cur;
				
				while (!forward.empty())
				{
					forward.pop();
				}
				
				cout << cur << endl;
			}
			
			cin >> order;
		}
		
		if (k < TestCase - 1)
		{
			cout << endl;
		}
	}
	
	return 0;
}
