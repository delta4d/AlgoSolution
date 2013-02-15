#include<cstdio>

using namespace std;

int peg[4][11];
int p[4];

int main()
{
	int TestCase;
	int i;
	int j;
	int k;
	int disk;
	int move;
	int sd;
	int td;
	int invalid;
	int finish;
	
	scanf("%d", &TestCase);
	
	for (k=0; k<TestCase; ++k)
	{
		scanf("%d %d", &disk, &move);
		
		invalid = 0;
		finish = 0;
		
		for (i=1; i<=disk; ++i)
		{
			peg[1][i] = disk - i + 1;
			peg[2][i] = peg[3][i] = 0;
		}
		
		peg[1][0] = peg[2][0] = peg[3][0] = disk + 1;
		
		p[1] = disk;
		p[2] = 0;
		p[3] = 0;
		
		for (i=1; i<=move; ++i)
		{
			scanf("%d %d", &sd, &td);
			
			if ((invalid == 0) && (finish == 0))
			{
				if ((p[sd] > 0) && (peg[sd][p[sd]] < peg[td][p[td]]))
				{
					peg[td][p[td]+1] = peg[sd][p[sd]];
					--p[sd];
					++p[td];
					
					if ((p[1] == 0) && (p[2] == 0))
					{
						finish = 1;
						printf("%d\n", i);
					}
				}
				else
				{
					invalid = 1;
					
					printf("-%d\n", i);
				}
			}
		}
		
		if ((invalid == 0) && (finish == 0))
		{
			printf("0\n");
		}
	}
	
	return 0;
}
