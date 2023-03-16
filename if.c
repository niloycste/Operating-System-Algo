#include<stdio.h>
int main()
{
   int num1,num2,rem,GCD,LCM;
   printf("enter the value of num1 and num2:");
   scanf("%d %d",&num1,&num2);

   while(num2!=0)
   {
       rem=num1%num2;
       num1=num2;
       num2=rem;
   }
   GCD=num1;
   LCM=((num1*num2)/GCD);
   printf("the gcd value is %d\n",GCD);
   printf("the lcm value will be %d",LCM);











   }







