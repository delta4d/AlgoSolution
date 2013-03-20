#include<stdio.h>

#define MaxLen 21000

char f[MaxLen];
char temp[MaxLen];

int main(void)
{
	int i;
	int j;
	int k;
	int min;
	int len;
	int index;
	int test_case;
	
	scanf("%d", &test_case);
	
	for (k=0; k<test_case; ++k)
	{
		scanf("%s", f);
		len = strlen(f);
		
		strcpy(temp, f);
		
		temp[len] = temp[0];
		temp[len + 1] = '\0';
		index = 0;
		j = len + 1;
		
		for (i=1; i<len; ++i)
		{
			if (strcmp(f, temp + j - len) > 0)
			{
				strcpy(f, temp + j - len);
				index = i;
			}
			
			temp[j] = temp[j-len];
			temp[j + 1] = '\0';
			++j;
		}
		
		printf("%d\n", index + 1);
	}
	
	return 0;
}
