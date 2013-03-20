#include<stdio.h>
#include<stdlib.h>

struct C
{
	int card[2];
	int position;
}a[5];

int cmp(const void *a, const void *b)
{
	struct C *c = (struct C *)a;
	struct C *d = (struct C *)b;
	
	if (c -> card[1] != d -> card[1])
	{
		return c -> card[1] - d -> card[1];
	}
	else
	{
		return c -> card[0] - d -> card[0];
	}
}

int main(void)
{
	char temp[3];
	int TestCase;
	int off;
	int i;
	int k;
	int x;
	int y;
	int z;
	
	scanf("%d", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		for (i=0; i<4; ++i)
		{
			scanf("%s", temp);
			
			if (temp[0] == 'T')
			{
				a[i].card[0] = 10;
			}
			else if (temp[0] == 'J')
			{
				a[i].card[0] = 11;
			}
			else if (temp[0] == 'Q')
			{
				a[i].card[0] = 12;
			}
			else if (temp[0] == 'K')
			{
				a[i].card[0] = 13;
			}
			else
			{
				a[i].card[0] = temp[0] - '0';
			}
			
			if (temp[1] == 'H')
			{
				a[i].card[1] = 1;
			}
			else if (temp[1] == 'C')
			{
				a[i].card[1] = 2;
			}
			else if (temp[1] == 'D')
			{
				a[i].card[1] = 3;
			}
			else
			{
				a[i].card[1] = 4;
			}
			
			a[i].position = i;
		}
		
		a[4].card[1] = a[0].card[1];
		qsort(a+1, 3, sizeof(a[1]), cmp);
		
		x = a[1].position;
		y = a[2].position;
		z = a[3].position;
		
		if ((x == 1) && (y == 2) && (z == 3))
		{
			off = 1;
		}
		else if ((x == 1) && (y == 3) && (z == 2))
		{
			off = 2;
		}
		else if ((x == 2) && (y == 1) && (z == 3))
		{
			off = 3;
		}
		else if ((x == 3) && (y == 1) && (z == 2))
		{
			off = 4;
		}
		else if ((x == 2) && (y == 3) && (z == 1))
		{
			off = 5;
		}
		else
		{
			off = 6;
		}
		
		if (a[0].card[0] + off > 13)
		{
			a[4].card[0] = a[0].card[0] + off - 13;
		}
		else
		{
			a[4].card[0] = a[0].card[0] + off;
		}
		
		if (a[4].card[0] == 10)
		{
			temp[0] = 'T';
		}
		else if (a[4].card[0] == 11)
		{
			temp[0] = 'J';
		}
		else if (a[4].card[0] == 12)
		{
			temp[0] = 'Q';
		}
		else if (a[4].card[0] == 13)
		{
			temp[0] = 'K';
		}
		else
		{
			temp[0] = '0' + a[4].card[0];
		}
		
		if (a[4].card[1] == 1)
		{
			temp[1] = 'H';
		}
		else if (a[4].card[1] == 2)
		{
			temp[1] = 'C';
		}
		else if (a[4].card[1] == 3)
		{
			temp[1] = 'D';
		}
		else
		{
			temp[1] = 'S';
		}
		
		temp[2] = '\0';
		
		printf("%s\n", temp);
	}

	return 0;
}
