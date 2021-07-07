#include<stdio.h>

char s[20];
//function declaration
int strleng(char s[]);
void concat();
void reverse();
void cpy();


int main (void)
{  int ch=0;
    printf("Enter the string: ");
    scanf("%s",s);
  printf("Press \n1 to find length of the string \n2 to concatinate two strings ");
  printf("\n3 to reverse the string \n4 to copy string\n");
  scanf("%i", &ch);
  
  switch (ch)
 {    case 1: printf("Length: %i\n", strleng(s));
      break;
      case 2: concat();
      break;
      case 3: reverse();
      break;
      case 4: cpy();
      break;
    default : printf("Wrong choice");
 }
}

int strleng(char a[])
{  int len=0;
    for(int i=0; a[i] != '\0'; i++)
    {
        len = len + 1;
    }
  return len;
}

void concat()
{
    char s2[20];
    printf("Enter the second string: ");
    scanf("%s",s2);
    char conc[40];
    int l = strleng(s), l2 = strleng(s2);
      for (int i=0; i<l;i++ )
        conc[i] = s[i];
      for (int j=0; j<l2; j++)
         {
             conc[l] = s2[j];
             l++;
         }
    printf("%s\n",conc);
}

void reverse()
{
    char rev[20];
     int end = strleng(s) - 1;
    int begin,count =strleng(s);
   for (begin = 0; begin < count; begin++)
   {
      rev[begin] = s[end];
      end--;
   }
   rev[begin] = '\0';
   printf("Reverse: %s\n",rev);
}

void cpy()
{
    char copy[20];
    int l=strleng(s);
    for(int i=0; i<l; i++)
     copy[i] = s[i];
printf("Copy: %s\n",copy);
}