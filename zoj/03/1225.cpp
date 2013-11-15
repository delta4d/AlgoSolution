#include<cstdio>
#include<cstdlib>
#include<memory>

using namespace std;

const int MaxN = 100;
const int MaxL = 20;

bool is_num[MaxN];
int num[MaxN];
char word[MaxN][MaxL];
char buff[MaxL];

int cmp_num(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int cmp_word(const void *a, const void *b)
{
	char tc;
	char td;
    char *c = (char *)a;
    char *d = (char *)b;
    int lenc = strlen(c);
    int lend = strlen(d);
    int len = lenc < lend ? lenc : lend;
    int i;

    for (i=0; i<len; ++i)
    {
        tc = *(c + i);
		td = *(d + i);
        
        if ((tc <= 'Z') && (tc >= 'A'))
        {
        	tc = tc - 'A' + 'a';
		}
		
		if ((td <= 'Z') && (td >= 'A'))
        {
        	td = td - 'A' + 'a';
		}
		
		if (tc != td)
		{
			return tc - td;
		}
    }
}

int tran_to_num()
{
    int res = 0;
    int i;
    int len = strlen(buff);
    int sgn = 1;
    int offset = 0;
    
    if (buff[0] == '-')
    {
    	sgn = -1;
    	offset = 1;
	}

    for (i=offset; i<len; ++i)
    {
        res = res * 10 + buff[i] - '0';
    }

    return res * sgn;
}

int main(void)
{
    int i;
    int j;
    int k;
    int len;
    int pword;
    int pnum;

    scanf("%s", buff);
    len = strlen(buff);

    while (strcmp(buff, ".") != 0)
    {
        memset(is_num, false, sizeof(is_num));
        pword = 0;
        pnum = 0;
        k = 0;

        while (buff[len-1] != '.')
        {
            buff[len-1] = '\0';

            if ((buff[0] <= '9') && (buff[0] >= '0') || (buff[0] == '-'))
            {
                num[pnum] = tran_to_num();
                ++pnum;
                is_num[k] = true;
            }
            else
            {
                strcpy(word[pword], buff);
                ++pword;
            }

            ++k;

            scanf("%s", buff);
            len = strlen(buff);
        }

        buff[len-1] = '\0';

        if ((buff[0] <= '9') && (buff[0] >= '0') || (buff[0] == '-'))
        {
            num[pnum] = tran_to_num();
            ++pnum;
            is_num[k] = true;
        }
        else
        {
            strcpy(word[pword], buff);
            ++pword;
        }

        ++k;

        qsort(num, pnum, sizeof(num[0]), cmp_num);
        qsort(word, pword, sizeof(word[0]), cmp_word);

        pnum = 0;
        pword = 0;

        for (i=0; i<k-1; ++i)
        {
            if (is_num[i])
            {
                printf("%d, ", num[pnum]);
                ++pnum;
            }
            else
            {
                printf("%s, ", word[pword]);
                ++pword;
            }
        }

        if (is_num[k-1])
        {
            printf("%d.\n", num[pnum]);
        }
        else
        {
            printf("%s.\n", word[pword]);
        }

        scanf("%s", buff);
        len = strlen(buff);
    }

    return 0;
}
