      #include<stdio.h>

      int a[21][21];
      int perimeters;
      int row;
      int column;

     void backtrack(int r, int c)
     {
            a[r][c] = 2;

           if ((r - 1 >= 1) && (c - 1 >= 1))
              {
                      if (a[r-1][c-1] == 1)
                        {
                                 backtrack(r - 1, c - 1);
                        }

              }

            if (r - 1 >= 1)
              {
                      if (a[r-1][c] == 1)
                        {
                                 backtrack(r - 1, c);
                        }
                      else if (a[r-1][c] == 0)
                        {
                                 perimeters++;
                        }

              }
            else
              {
                      perimeters++;
              }

            if ((r - 1 >= 1) && (c + 1 <=column))
              {
                      if (a[r-1][c+1] == 1)
                        {
                                 backtrack(r - 1, c + 1);
                        }

              }

            if (c - 1 >= 1)
              {
                      if (a[r][c-1] == 1)
                        {
                                 backtrack(r, c - 1);
                        }
                      else if (a[r][c-1] == 0)
                       {
                                 perimeters++;
                        }

              }
            else
              {
                      perimeters++;
              }

            if (c + 1 <= column)
              {
                      if (a[r][c+1] == 1)
                        {
                                 backtrack(r, c + 1);
                        }
                      else if (a[r][c+1] == 0)
                        {
                                 perimeters++;
                        }

              }
            else
              {
                      perimeters++;
              }

            if ((r + 1 <= row) && (c - 1 >= 1))
              {
                      if (a[r+1][c-1] == 1)
                        {
                                 backtrack(r + 1, c - 1);
                        }

              }

            if (r + 1 <= row)
              {
                      if (a[r+1][c] == 1)
                        {
                                 backtrack(r + 1, c);
                        }
                      else if (a[r+1][c] == 0)
                        {
                                perimeters++;
                       }

             }
           else
             {
                     perimeters++;
             }

           if ((r + 1 >= 1) && (c + 1 <= column))
             {
                     if (a[r+1][c+1] == 1)
                       {
                                backtrack(r + 1, c + 1);
                       }

             }

    }

    int main()
    {
          int i, j, r, c;
          char ch;

          scanf("%d %d %d %d", &row, &column, &r, &c);

          while (!(row==0 && column==0 && r==0 &&c==0))
           {
                   perimeters = 0;

                   for (i=1; i<=row; i++)
                     {
                             for (j=1; j<=column; j++)
                               {
                                       scanf("%c", &ch);
                                      while (ch == '\n' || ch == ' ')
                                         {
                                                  scanf("%c", &ch);
                                         }

                                       if (ch == '.')
                                         {
                                                  a[i][j] = 0;
                                         }
                                       else
                                         {
                                                  a[i][j] = 1;
                                         }

                               }
                     }

                   backtrack(r, c);

                   printf("%d\n", perimeters);

                   scanf("%d %d %d %d", &row, &column, &r, &c);
           }
    return 0;
    }
