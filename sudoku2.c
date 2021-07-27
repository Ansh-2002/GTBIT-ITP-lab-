#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int N;

int col_check(int sudoku[][10]);
int cube_check(int sudoku[][10]);
void display(int sudoku[][10]);
int row_check(int sudoku[][10]);
void su_display();



int main()
{
    su_display();
    printf("\n\n");
        printf("Enter size of sudoku: ");
        scanf("%d",&N);

        int sudoku[10][10];
        FILE *fp;
         if(N==9)
          fp=fopen("sample.txt","r");
         else if(N==4)
          fp=fopen("sample1.txt","r");

        if(fp==NULL)
        {
            printf("\n\t\t\t  Invalid File\n");
            exit(1);
        }

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                fscanf(fp,"%d",&sudoku[i][j]);
            }
        }
        display(sudoku);
        printf("\n");
        bool br = row_check(sudoku);
        bool bc = col_check(sudoku);
        bool bs= cube_check(sudoku);
        if (br && bc && bs)
        {
            printf("\n\t\t\t     VALID\n");
        }


}

void su_display()
{
    printf("\n  *******   *      *   *****            *****       *    *   *      *");
    printf("\n  *         *      *   *     *        *       *     *   *    *      *");
    printf("\n  *         *      *   *       *     *         *    *  *     *      *");
    printf("\n  *         *      *   *        *   *           *   * *      *      *");
    printf("\n  *******   *      *   *        *   *           *   **       *      *");
    printf("\n        *   *      *   *        *   *           *   * *      *      *");
    printf("\n        *   *      *   *       *     *         *    *  *     *      *");
    printf("\n        *   *      *   *     *        *       *     *   *    *      *");
    printf("\n  *******   ********   *****            *****       *    *   ********");
}


void display(int sudoku[][10])
{
 
 int div;
    if(N == 9)
      div=3;
     else if (N == 4)
     div =2;

    for(int i=0; i<N; i++)
    {
        printf("\t  ");
        for(int j=1; j<N; j++)
        {
            if(i%div==0)
            printf("  __ ");
        }
        printf("\n");
        printf("\t  |");
        for(int j=0; j<N; j++)
        {
            printf(" %d  ",sudoku[i][j]);
            if((j+1)%div==0)
            printf("|");
        }
        printf("\n");
    }

    printf("\t  ");
    for(int j=1; j<N; j++)
    {
        printf("  __ ");
    }
}


int row_check(int sudoku[][10])
{

  int c[10] = {0};
  bool berror=true;
  for (int i=0; i<N; i++)
  {
      for (int j=0; j<N; j++)
      {
          c[ sudoku[i][j] ] ++;
      }
      for (int k=1; k<=N; k++)
      {
       if(c[k] != 1 && c[k]!= 0)
       {
           printf("\n\t\t\t    INVALID");
           printf("\n\t\tThe Value %d came %d times in row %d\n",k,c[k],i+1);
           berror = false;
       }
      }
      for(int k=1;k<=N; k++)
      {
          c[k] = 0;
      }
  }
 return berror;


}


int col_check(int sudoku[][10])
{

  int c[10] = {0};
  bool berror=true;
  for (int i=0; i<N; i++)
  {
      for (int j=0; j<N; j++)
      {
          c[ sudoku[j][i] ] ++;
      }
      for (int k=1; k<=N; k++)
      {
       if(c[k] != 1 && c[k]!= 0)
       {
           printf("\n\t\t\t    INVALID");
           printf("\n\t\tThe Value %d came %d times in coloumn %d\n",k,c[k],i+1);
           berror=false;
       }
      }
      for(int k=1;k<=N; k++)
      {
          c[k] = 0;
      }
  }
 return berror;
}


int cube_check(int sudoku[][10])
{
    int inc=3;
    if (N == 4)
        inc=2;
    int c[10]={0}, count = 0;
    bool berror=true;
     for(int m=0; m<N; m+=inc)
     {
         for(int b=0;b<N; b+=inc)
         {
             for(int i=m; i<m+inc; i++)
             {
                 for(int j=b; j<b+inc; j++ )
                 {
                     c[sudoku[i][j] ]++;
                 }
             }
                count++;
                for(int k=1; k<=N; k++)
                {
                    if( c[k] != 1 && c[k] != 0)
                    {
                        printf("\n\t\t\t    INVALID");
                        printf("\n\t\tThe value %d come %d times in cube %d\n",k,c[k],count);
                        berror=false;
                    }
                }
                for(int k=1; k<=N; k++ )
                {
                    c[k]=0;
                }
             }
         }
   return berror;
}
