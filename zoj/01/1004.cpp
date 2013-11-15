#include<iostream>
#include<memory>
#include<stack>
using namespace std;

const int MaxN = 100;
int len;
int a[26];
char path[2*MaxN];
char src[MaxN];
char dst[MaxN];
bool done;
stack<char>f;

void dfs(int cur, int clen, int opi)
{
    if (clen == len)
    {    	
        for (int i=0; i<opi; ++i)
        {
            cout << path[i] << ' ';
        }
        
        cout << endl;

        return;
    }

    if (cur < len)
    {
        f.push(src[cur]);
        path[opi] = 'i';
        dfs(cur + 1, clen, opi + 1);
        f.pop();
    }

	char ch;

    if ((!f.empty()) && ((ch = f.top()) == dst[clen]))
    {
        f.pop();
        path[opi] = 'o';
        dfs(cur, clen + 1, opi + 1);
        f.push(ch);
    }
}

int main(void)
{
    int i;

    while (cin >> src >> dst)
    {
        if (strlen(src) != strlen(dst))
        {
            cout << '[' << endl << ']' << endl;
        }
        else
        {
        	len = strlen(src);
        	
            while (f.size() != 0)
            {
                f.pop();
            }

			cout << '[' << endl;

            dfs(0, 0, 0);
            
            cout << ']' << endl;
        }
    }

	return 0;
}
