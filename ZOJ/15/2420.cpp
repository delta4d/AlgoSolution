#include<stdio.h>

long f[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
				 {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
				 
char week[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
					"Friday", "Saturday", "Sunday"};
					
int leap(long n)
{
	if ((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0))
	{
		return 1;
	}
	
	return 0;
}
				 
int main(void)
{
	long n;
	long year;
	long month;
	long day;
	long date;
	long i;
	long j;
	long k;
	long sub;
	long temp;
	
	scanf("%ld", &n);
	
	while (n != -1)
	{
		++n;
		temp = n;
			
		for (i=0; ; ++i)
		{
			sub = 365;
			
			if (leap(i + 2000))
			{
				++sub;
			}
			
			n -= sub;
			
			if (n <= 0)
			{
				n += sub;
				year = 2000 + i;
				break;
			}
		}
		
		k = 0;
		
		if (leap(i + 2000))
		{
			++k;
		}
		
		for (j=1; ;++j)
		{
			n -= f[k][j];
			
			if (n <= 0)
			{
				n += f[k][j];
				month = j;
				break;
			}
		}
		
		day = n;
		
		date = (temp + 4) % 7;
		
		printf("%ld-%02ld-%02ld %s\n", year, month, day, week[date]);
		
		scanf("%ld", &n);
	}
	
	return 0;
}
