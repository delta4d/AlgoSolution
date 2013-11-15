#include<stdio.h>

char lc[24][97];

void writea(int x, int y, int s)
{
	int i;
	
	for (i=x+1; i<=x+s; ++i)
	{
		lc[i][y] = '|';
	}
	
	return;
}

void writeb(int x, int y, int s)
{
	int i;
	
	for (i=x+s+2; i<=x+2*s+1; ++i)
	{
		lc[i][y] = '|';
	}
	
	return;
}

void writec(int x, int y, int s)
{
	int i;
	
	for (i=y+1; i<=y+s; ++i)
	{
		lc[x+2*s+2][i] = '-';
	}
	
	return;
}

void writed(int x, int y, int s)
{
	int i;
	
	for (i=x+s+2; i<=x+2*s+1; ++i)
	{
		lc[i][y+s+1] = '|';
	}
	
	return;
}

void writee(int x, int y, int s)
{
	int i;
	
	for (i=x+1; i<=x+s; ++i)
	{
		lc[i][y+s+1] = '|';
	}
	
	return;
}

void writef(int x, int y, int s)
{
	int i;
	
	for (i=y+1; i<=y+s; ++i)
	{
		lc[x][i] = '-';
	}
	
	return;
}

void writeg(int x, int y, int s)
{
	int i;
	
	for (i=y+1; i<=y+s; ++i)
	{
		lc[x+s+1][i] = '-';
	}
	
	return;
}

int main(void)
{
	int x;
	int y;
	int s;
	int i;
	int j;
	int k;
	int len;
	char num[10];
	
	scanf("%d %s", &s, num);
	
	while (s != 0 || strcmp(num, "0") != 0)
	{
		len = strlen(num);
		
		for (i=1; i<=2*s+3; ++i)
		{
			for (j=1; j<=len*(s+2); ++j)
			{
				lc[i][j] = ' ';
			}
		}
		
		for (k=0; k<len; ++k)
		{
			x = 1;
			y = k * (s + 2) + 1;		
			
			if (num[k] == '0')
			{
				writea(x, y, s);
				writeb(x, y, s);
				writec(x, y, s);
				writed(x, y, s);
				writee(x, y, s);
				writef(x, y, s);
			}
			else if (num[k] == '1')
			{
				writee(x, y, s);
				writed(x, y, s);
			}
			else if (num[k] == '2')
			{
				writeb(x, y, s);
				writec(x, y, s);
				writee(x, y, s);
				writef(x, y, s);
				writeg(x, y, s);
			}
			else if (num[k] == '3')
			{
				writef(x, y, s);
				writee(x, y, s);
				writeg(x, y, s);
				writed(x, y, s);
				writec(x, y, s);
			}
			else if (num[k] == '4')
			{
				writea(x, y, s);
				writeg(x, y, s);
				writee(x, y, s);
				writed(x, y, s);
			}
			else if (num[k] == '5')
			{
				writef(x, y, s);
				writea(x, y, s);
				writeg(x, y, s);
				writed(x, y, s);
				writec(x, y, s);
			}
			else if (num[k] == '6')
			{
				writef(x, y, s);
				writea(x, y, s);
				writeb(x, y, s);
				writec(x, y, s);
				writed(x, y, s);
				writeg(x, y, s);
			}
			else if (num[k] == '7')
			{
				writef(x, y, s);
				writee(x, y, s);
				writed(x, y, s);
			}
			else if (num[k] == '8')
			{
				writea(x, y, s);
				writeb(x, y, s);
				writec(x, y, s);
				writed(x, y, s);
				writee(x, y, s);
				writef(x, y, s);
				writeg(x, y, s);
			}
			else
			{
				writef(x, y, s);
				writea(x, y, s);
				writeg(x, y, s);
				writee(x, y, s);
				writed(x, y, s);
				writec(x, y, s);
			}
		}
		
		for (i=1; i<=2*s+3; ++i)
		{
			for (j=1; j<=len*(s+2); ++j)
			{
				printf("%c", lc[i][j]);
				
				if ((j % (s+2) == 0) && (j<len*(s+2)))
				{
					printf(" ");
				}
			}
			
			printf("\n");
		}
		
		printf("\n");
		
		scanf("%d %s", &s, num);
	}
	
	return 0;
}
