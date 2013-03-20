#include<stdio.h>
#include<memory.h>

char name[16][32];
double p[16][16];
double pos[32][16];

void play(int a, int b, int c)
{
	int i;
	int j;
	memset(pos[c], 0, sizeof(pos[c]));
	
	for (i=0; i<16; ++i)
	{
		for (j=0; j<16; ++j)
		{
			pos[c][i] += pos[a][i] * pos[b][j] * p[i][j];
			pos[c][j] += pos[a][i] * pos[b][j] * p[j][i];
		}
	}
}

int main(void)
{
	int i;
	int j;
	int k;
	
	for (i=0; i<16; ++i)
	{
		scanf("%s", name[i]);
	}
	
	memset(pos, 0, sizeof(pos));
	
	for (i=0; i<16; ++i)
	{
		for (j=0; j<16; ++j)
		{
			scanf("%lf", &p[i][j]);
			p[i][j] /= 100.0;
		}
		
		pos[i][i] = 1.0;
	}
	
	play(0,1,16);
    play(2,3,17);
    play(4,5,18);
    play(6,7,19);
    play(8,9,20);
    play(10,11,21);
    play(12,13,22);
    play(14,15,23);
    play(16,17,24);
    play(18,19,25);
    play(20,21,26);
    play(22,23,27);
    play(24,25,28);
    play(26,27,29);
    play(28,29,30);
    
    for (i=0; i<16; ++i)
	{
		printf("%-10s p=%.2lf%%\n", name[i], pos[30][i]*100);
	}
	
	return 0;
}
