#include<stdio.h>
int main()
{
    int a,b,c;

    scanf("value of a is %d",&a);
    scanf("value of b is %d",&b);
    scanf("value of c is %d",&c);
    scanf("%d %d %d",&a,&b,&c);




    if((a+b)>c && (b+c)>a && (c+a)>b){
        printf("its Triangle");
    }
    else{
    printf("not triangle");
        }

    }





