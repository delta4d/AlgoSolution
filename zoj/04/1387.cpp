#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<memory>

using namespace std;

const int MaxN = 10001;
string code;
string word[MaxN];
typedef map<char, string>M;
M morse;
int n;
int f[MaxN];

void gen_morse(void)
{
	morse.insert(M :: value_type('A', ".-"));
	morse.insert(M :: value_type('B', "-..."));
	morse.insert(M :: value_type('C', "-.-."));
	morse.insert(M :: value_type('D', "-.."));
	morse.insert(M :: value_type('E', "."));
	morse.insert(M :: value_type('F', "..-."));
	morse.insert(M :: value_type('G', "--."));
	morse.insert(M :: value_type('H', "...."));
	morse.insert(M :: value_type('I', ".."));
	morse.insert(M :: value_type('J', ".---"));
	morse.insert(M :: value_type('K', "-.-"));
	morse.insert(M :: value_type('L', ".-.."));
	morse.insert(M :: value_type('M', "--"));
	morse.insert(M :: value_type('N', "-."));
	morse.insert(M :: value_type('O', "---"));
	morse.insert(M :: value_type('P', ".--."));
	morse.insert(M :: value_type('Q', "--.-"));
	morse.insert(M :: value_type('R', ".-."));
	morse.insert(M :: value_type('S', "..."));
	morse.insert(M :: value_type('T', "-"));
	morse.insert(M :: value_type('U', "..-"));
	morse.insert(M :: value_type('V', "...-"));
	morse.insert(M :: value_type('W', ".--"));
	morse.insert(M :: value_type('X', "-..-"));
	morse.insert(M :: value_type('Y', "-.--"));
	morse.insert(M :: value_type('Z', "--.."));
}

void dp(int len)
{
	int i;
	int j;
	int k;
	int t;
	memset(f, 0, sizeof(f));
	f[0] = 1;
	
	for (k=0; k<len; ++k)
	{
		if (f[k] == 0)
		{
			continue;
		}
		
		for (i=0; i<n; ++i)
		{
			t = word[i].length();
			
			if ((k + t <= len) && (word[i] == code.substr(k, t)))
			{
				f[k+t] += f[k];
			}
		}
	}
}

int main(void)
{
	int i;
	int j;
	int k;
	int len;
	int res;
	int test_case;
	string temp;
	string :: iterator it;
	
	gen_morse();
	
	cin >> test_case;
	
	for (k=0; k<test_case; ++k)
	{
		cin >> code;
		cin >> n;
		
		for (i=0; i<n; ++i)
		{
			cin >> temp;
			word[i].clear();
			//word[i] = "";
			
			for (it=temp.begin(); it!=temp.end(); ++it)
			{
				word[i] += morse[*it];
			}
			
			//cout << word[i] << endl;
		}
		
		len = code.length();
		
		dp(len);
		
		cout << f[code.length()] << endl;
	}
		
	return 0;
}
