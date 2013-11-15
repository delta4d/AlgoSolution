#include<stdio.h>

int main(void)
{
	char url[61];
	int i;
	int j;
	int k;
	int n;
	int len;
	int TestCase;
	
	scanf("%d", &TestCase);
	
	for (k=1; k<=TestCase; ++k)
	{
		scanf("%s", url);
		
		len = strlen(url);
		
		printf("URL #%d\n", k);
		
		printf("Protocol = ");
		
		for (i=0; url[i]!=':'; ++i)
		{
			printf("%c", url[i]);
		}
		
		printf("\n");
		
		n = i + 3;

		printf("Host     = ");

		for (i=n; (url[i]!=':') && (url[i]!='/') && (i<len); ++i)
		{
			printf("%c", url[i]);
		}

		printf("\n");
		
		printf("Port     = ");
		
		if (url[i] == ':')
		{
			n = i + 1;
			
			for (i=n; (url[i]!='/')&&(i<len); ++i)
			{
				printf("%c", url[i]);
			}
			
			printf("\n");
			
			if (i==len)
			{
				printf("Path     = <default>\n");
			}
			else
			{
				printf("Path     = %s\n", url+i+1);
			}
		}
		else if (url[i] == '/')
		{
			printf("<default>\n");
			
			printf("Path     = %s\n", url+i+1);
		}
		else
		{
			printf("<default>\n");
			printf("Path     = <default>\n");
		}
		
		printf("\n");
	}
	
	return 0;
}
