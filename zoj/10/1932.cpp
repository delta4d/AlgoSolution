#include <cstdio>
using namespace std;
double const CPG[5] = {9.0, 4.0, 4.0, 4.0, 7.0};
double cal;
double sum;
double fat;
double tot;
double ratio;
char buff[16];

inline double tran(int k, int &c)
{
	int i;
    double res(0.0);
    for (i=0; buff[i]<='9'&&buff[i]>='0'; ++i) res = res * 10 + buff[i] - '0';
    switch (buff[i])
    {
    case 'C':
        c = 0;
        break;
    case 'g':
        res *= CPG[k];
        c = 1;
        break;
    case '%':
        c = 2;
        break;
    default :
        printf("error !!!\n");
        break;
    }
    return res;
}

int main()
{
    int i;
    int j;
    int k;
    int c;
    double want;
    double first;
    double temp;
    bool is_fat;
    //freopen("f:\\in.txt", "r", stdin);
    scanf("%s", buff);
    while (buff[0] != '-')
    {
    	cal = sum = 0;
        while (buff[0] != '-')
        {
        	fat = ratio = 0;
            temp = tran(0, c);
            if (c == 2) {first = ratio = temp; is_fat = false;}
            else {want = fat = temp; is_fat = true;}			
            for (i=1; i<=4; ++i)
            {
            	scanf("%s", buff);
                temp = tran(i, c);
                if (c == 2) ratio += temp;
                else fat += temp;
            }
            ratio /= 100.0;
            if (is_fat)
            {
            	cal += want;
            	sum += fat / (1.0 - ratio);
			}
			else
			{
				cal += fat / (1.0 - ratio) * first / 100.0;
				sum += fat / (1.0 - ratio);
			}
            scanf("%s", buff);
        }
        printf("%.0lf%%\n", (cal/sum)*100.0);
        scanf("%s", buff);
    }
    return 0;
}
