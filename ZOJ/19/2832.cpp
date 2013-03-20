#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

map<string, string>f;
typedef map<string, string> tp;
tp :: iterator iter;
vector<string> buff;

string find_root(string s)
{
	if (f[s] == "\0")
	{
		return s;
	}
	
	return f[s] = find_root(f[s]);
}

int main(void)
{	
	string s;
	string t;
	int n;
	int m;
	int i;
	int j;
	int k;	
	
	cin >> n;
	
	while (1)
	{
		f.clear();
		
		for (j=0; j<n; ++j)
		{
			cin >> s;
			cin >> m;
			iter = f.find(s);
			
			if (iter == f.end())
			{
				f[s] = "\0";
			}
			
			for (i=0; i<m; ++i)
			{
				cin >> t;
				f[t] = find_root(s);
			}						
		}
		
		buff.clear();
		
		for (iter=f.begin(); iter!=f.end(); ++iter)
		{
			if ((*iter).second == "\0")
			{
				buff.push_back((*iter).first);
			}
		}
				
		vector<string> :: iterator p;
		
		sort(buff.begin(), buff.end());
		
		for (p=buff.begin(); p!=buff.end(); ++p)
		{
			cout << *p << endl;
		}
		
		if (cin >> n)
		{
			cout << endl;
		}
		else
		{
			break;
		}
	}
	
	return 0;
}
