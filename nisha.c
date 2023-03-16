#include<stdio.h>
int main()
{

    int a=50;
    int *p;
    p=&a;
    printf("\nvalue of a is:%d",a);
    printf("value of a is:%d",*p);
    printf("value of a is:%p",&a);
    printf("value of a is: %p",p);
    printf("value of a is:%p",&p);
    getch();
}
