#include<stdio.h>

int main(void)
{
    int n;
    int k;
    int i;
    int num;
    FILE *fp;
    
    fp = fopen("f:\\output1.txt", "w");

    //scanf("%d", &n);
	n = 1;
	
    while (n != 33)
    {
        k = n % 4;

        fprintf(fp, "Printing order for %d pages:\n", n);

        if (k != 0)
        {
            num = (n + 4 - k) / 4;
        }
        else
        {
            num = n / 4;
        }

        if (k == 0)
        {
            for (i=1; i<=num; ++i)
            {
                fprintf(fp, "Sheet %d, front: %d, %d\n", i, n + 2 - 2 * i, 2 * i - 1);
                fprintf(fp, "Sheet %d, back : %d, %d\n", i, 2 * i, n + 1 - 2 * i);
            }
        }
        else if (k == 1)
        {
            if (num == 1)
            {
				fprintf(fp, "Sheet 1, front: Blank, 1\n");
            }
            else
            {
                for (i=1; i<=num; ++i)
                {
                    if (i == 1)
                    {
                        fprintf(fp, "Sheet 1, front: Blank, 1\n");
                        fprintf(fp, "Sheet 1, back : 2, Blank\n");
                    }
                    else if (i == 2)
                    {
						fprintf(fp, "Sheet 2, front: Blank, 3\n");
						fprintf(fp, "Sheet 2, back : 4, %d\n", n);
                    }
                    else
                    {
						fprintf(fp, "Sheet %d, front: %d, %d\n", i, n + 5 - 2 * i, 2 * i - 1);
						fprintf(fp, "Sheet %d, back : %d, %d\n", i, 2 * i, n + 4 - 2 * i);
                    }
                }
            }
        }
        else if (k == 2)
        {
			fprintf(fp, "Sheet 1, front: Blank, 1\n");
			fprintf(fp, "Sheet 1, back : 2, Blank\n");
			
			for (i=2; i<=num; ++i)
			{
				fprintf(fp, "Sheet %d, front: %d, %d\n", i, n + 4 - 2 * i, 2 * i - 1);
				fprintf(fp, "Sheet %d, back : %d, %d\n", i, 2 * i, n + 3 - 2 * i);
			}
        }
        else
        {
			fprintf(fp, "Sheet 1, front: Blank, 1\n");
			fprintf(fp, "Sheet 1, back : 2, %d\n", n);
			
			for (i=2; i<=num; ++i)
			{
				fprintf(fp, "Sheet %d, front: %d, %d\n", i, n + 3 - 2 * i, 2 * i - 1);
				fprintf(fp, "Sheet %d, back : %d, %d\n", i, 2 * i, n + 2 - 2 * i);
			}
        }

        //scanf("%d", &n);
        fprintf(fp, "\n");
        ++n;
    }

    return 0;
}
