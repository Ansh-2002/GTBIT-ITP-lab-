//WAP to find divisor or factorial of a given number
#include<stdio.h>
int main (void)
{  int n,i,f=1;
 printf("Enter a number: ");    
  scanf("%d",&n);
for ( i=1; i<=n; i++)
{
  f = f*i;
}
 printf("Factorial: %d\n",f);
  return 0;
}