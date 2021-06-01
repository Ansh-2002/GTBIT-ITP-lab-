#include <stdio.h>
int main(){
   float a ,r;
   int n = 5;
   printf("First term(a): ");
   scanf("%f",&a);
   printf(" Common ratio(r): ");
   scanf("%f",&r);
   printf("Number of terms(n): ");
   scanf("%d",&n);
   float sum = 0;
   for (int i = 0; i < n; i++)
   {
      sum = sum + a;
      a = a * r;
   }
   printf("Sum of GP: %f", sum );
   return 0;
}
