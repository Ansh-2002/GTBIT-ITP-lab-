#include<stdio.h>
#define N 4
#define true 1
#define false 0

//function declaration
void display();
int row_check();
int col_check();

/*
int sudoku[9][9]={ {6,9,3,7,1,2,5,8,4},
                   {4,5,7,9,3,8,2,1,6},
                   {2,8,1,4,5,6,7,9,3},
                   {5,4,6,3,8,9,1,2,7},
                   {3,2,8,6,7,1,4,5,9},
                   {7,1,9,5,2,4,6,3,8},
                   {1,6,4,2,9,3,8,7,5},
                   {9,7,2,8,4,5,3,6,1},
                   {8,3,5,1,6,7,9,4,2}};
*/
    int  sudoku[N][N]={ {3,2,4,1},
                        {1,4,3,2},
                        {2,3,1,4},
                        {4,1,2,3} };
                    
void display()
{
    printf("\n  *******   *      *   *****            *****       *    *   *      *"
           "\n  *         *      *   *     *        *       *     *   *    *      *"
           "\n  *         *      *   *       *     *         *    *  *     *      *"
           "\n  *         *      *   *        *   *           *   * *      *      *"
           "\n  *******   *      *   *        *   *           *   **       *      *"
           "\n        *   *      *   *        *   *           *   * *      *      *"
           "\n        *   *      *   *       *     *         *    *  *     *      *"
           "\n        *   *      *   *     *        *       *     *   *    *      *"
           "\n  *******   ********   *****            *****       *    *   ********  \n\n\n" );
    
    //printf("\t");
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

int row_check()
{ 
  int c[10] = {0};
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
           printf("\n NOT VALID\nThe Value %d came %d times in %d row\n",k,c[k],i+1);
           return false;
       }
      }
      for(int k=1;k<=N; k++) 
         c[k] = 0;
  }
 return true; 
}

int col_check()
{ 
  int c[N+1] = {0};
  for (int i=0; i<N; i++)//col
  {
      for (int j=0; j<N; j++)//row
      {
          c[ sudoku[j][i] ] ++;
      }
      for (int k=1; k<=N; k++)
      {
       if(c[k] != 1 && c[k]!= 0)
       {
           printf("\nNOT VALID\nThe Value %d came %d times in %d column\n",k,c[k],i+1);
           return false;
       }
      }
      for(int k=1;k<=N; k++) 
         c[k] = 0;
  }
 return true; 
}
int cube_check()
{    
    int c[N+1]={0}, count = 0;  
    int inc;
    if (N ==9 )
       inc=3;
    else if (N == 4)   
        inc=2;
        
        
     for(int m=0; m<N; m+=inc)
     {
         for(int b=0;b<N; b+=inc)
         {
//calc no of cubes             
             for(int i=m; i<m+inc; i++)
             {
                 for(int j=b; j<b+inc; j++ )
                     c[ sudoku[i][j] ]++;
             }     
                count++;
                for(int k=1; k<=N; k++)
                  if( c[k] != 1 )
                 { 
                     printf("The vale %d come %d times in box %d",k,c[k],count);
                     return false;
                 }
                for(int k=1; k<=N; k++ )
                   c[k]=0;
             }
         }
         
     
   return true; 
} 
int main()
{
    display();
    
    if( row_check() == true && col_check() == true && cube_check() == true  )
         printf("\nVALID\n");
 
    return 0;
}




/*
int error=0;
 int main()
{
    //int sudoku[9][9]={{6,9,3,7,1,2,5,8,4},{4,5,7,9,3,8,2,1,6},{2,8,1,4,5,6,7,9,3},{5,4,6,3,8,9,1,2,7},{3,2,8,6,7,1,4,5,9},{7,1,9,5,2,4,6,3,8},{1,6,4,2,9,3,8,7,5},{9,7,2,8,4,5,3,6,1},{8,3,5,1,6,7,9,4,2}};
   
    printf("\n\n\n");
    display();
    printf("\n");
    for (int i=0;i<9;i++)
    {
        //printf("\nFor Row %d",i);
        for (int j=0;j<9;j++)
        {
            //printf("%d  ",sudoku[i][j]);
            rowcheck(sudoku[i][j],i,j);
            //printf("\n");
            colcheck(sudoku[i][j],i,j);
            //printf("\n");
            squarecheck(sudoku[i][j],i,j);
            //printf("\n");
            //printf("\n\terror=%d",error);
        }
    }
    //printf("\n\terror=%d",error);
    if (error==0)
    {
        printf("\n\t\t\tNO ERROR");
    }
    printf("\n");
}

*/


/*
void fscan()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            scanf("%d",&sudoku[i][j]);
    }
}


int rowcheck(a,row,col)
{
    //printf("\nError=%d",error);
    //printf("\nIn Row Check ");
    //printf("\nrow (i)=%d",row);
    //printf("A=%d",A);
    //printf("\n");
    //int error[9]={0,0,0,0,0,0,0,0,0};
    //int error;
    for (int i=0;i<9;i++)
    {
        if (col==i)//|| col==error)
        {
            continue;
        }
        //if (i==error[i])
        //{
        //   printf("");
       //   }
        else
        {
            if (sudoku[row][i]==a)
            {
                printf("\n\t\t\tERROR");
                printf("\n\t\t%d repeated in %d%d and %d%d",a,row,col,row,i);
                error=error+1;
                //error[i]=col;
            }
        }
    }
return 0;
}



int colcheck(a,row,col)
{
    for (int i=0;i<9;i=i+1)
    {
        if (row==i)
        {
            continue;
        }
        else
        {
            if (sudoku[i][col]==a)
            {
                printf("\n\t\t\tERROR");
                printf("\n\t\t%d repeated in %d%d and %d%d",a,row,col,i,col);
                error=error+1;
            }
        }
    }
return 0;
}


int squarecheck(a,row,col)
{
    int rowcorner=3*(row/3);
    int colcorner=3*(col/3);
    int rl=rowcorner+3;
    int cl=colcorner+3;
    //printf("\ni=%d  j=%d",row,col);
    //printf("\ncorner %d  %d",rowcorner,colcorner);
    //printf("\na=%d",a);
    //printf("\nrl=%d   cl=%d",rl,cl);
    //printf("\n");
    for (int i=rowcorner;i<rl;i=i+1)
    {
        for (int j=colcorner;j<cl;j=j+1)
        {
            if (row==i || col==j)
            {
                continue;
            }
            else
            {
                if (sudoku[i][j]==a)
                {
                    printf("\n\t\t\tERROR");
                    printf("\n\t\t%d repeated in %d%d and %d%d",a,row,col,i,j);
                    error=error+1;
                }
            }
        }
    }

    return 0;
}
*/

