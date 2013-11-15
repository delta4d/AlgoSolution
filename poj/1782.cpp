#include <cstdio>
#include <cstring>
using namespace std;
#define debug 0
const int MaxL = 1024;
char s[MaxL];

int main()
{
    int i;
    int j;
    int cnt;
    int len;
    char cur;
    char pre;
    char bak;
    bool single;
#if debug
    freopen("f:\\in.txt", "r", stdin);
    freopen("f:\\out.txt", "w", stdout);
#endif
    while (gets(s))
    {
        len = strlen(s);
        single = false;
        cnt = 1;
        for (i=0; i<len; ++i)
        {
        	cur = s[i];
        	bak = s[i+1];
        	if (cur != bak)
        	{  		
        		if (cnt == 1)
        		{
        			if (!single) printf("1");
        			if (cur == '1')
        			{
        				printf("11");
					}
					else
					{
						printf("%c", cur);
					}
					cnt = 1;
					single = true;
				}
				else
				{
					if (single) printf("1");
					printf("%d%c", cnt, cur);
					cnt = 1;
					single = false;
				}
			}
			else
			{
				if (cnt == 9)
				{
					if (single) printf("1");
					printf("9%c", cur);
					cnt = 1;
					single = false;
				}
				else
				++cnt;
			}
		}
        if (single) printf("1");
        printf("\n");
    }

    return 0;
}