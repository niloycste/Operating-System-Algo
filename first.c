#include<stdio.h>
#include<conio.h>


int a[5],b[5],n,r,q,i,j;

void main()
{

 clrscr();

 printf("\ncreate the process:");
 scanf("%d",&n);
 printf("\nEnter time for each process...\n");
 for( i=1;i<=n;i++)
 {
  printf("\nProcess ID.%d: ",i);
  scanf("%d",&b[i]); a[i]=b[i];
  printf("process %dcreated",i);
 }


 printf("\nEnter the processing time :");
 scanf("%d",&q);

 tt();


 getch();

}
tt()
{ int max=0;
 max=b[1];
	for( j=1;j<=n;j++)
	   if(max<=b[j])
	max=b[j];

 if((max%q)==0)
   r=(max/q);
 else
  r=(max/q)+1;
   for(i=1;i<=r;i++)
   {
      printf("\nprocessing state %d\n",i);
      for(j=1;j<=n;j++)
	{
	  if(b[j]>0)
	    {
	     b[j]=b[j]-q;

	     if(b[j]<=0)
		{
		b[j]=0;
	     printf("\nprocess %d is completly terminated\n",j);
		}
	     else
	     printf("\nprocess %d is waiting to complete the process %d",j,b[j]);
	    }
	 }
	 delay(1000);
   }
   getch();

}
