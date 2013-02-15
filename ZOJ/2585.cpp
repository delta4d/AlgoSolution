#include<stdio.h>
#include<math.h>
#include<memory.h>

int main(void)
{
	long f[26];
	long TestCase;
	long i;
	long j;
	long k;
	long len;
	long res;
	char s1[48];
	char s2[48];
	
	scanf("%ld", &TestCase);
	getchar();
	
	for (k=0; k<TestCase; ++k)
	{
		memset(f, 0, 26*sizeof(long));
		
		gets(s1);
		gets(s2);
		
		len = strlen(s1);
		
		for (i=0; i<len; ++i)
		{
			++f[s1[i]-'a']; 
		}
		
		len = strlen(s2);
		
		for (i=0; i<len; ++i)
		{
			--f[s2[i]-'a'];
		}
		
		res = 0;
		for (i=0; i<26; ++i)
		{
			res += (long)fabs(f[i]);
		}
		
		printf("Case #%ld:  %ld\n", k+1, res);
	}
	
	return 0;
}
