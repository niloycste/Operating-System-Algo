#include<stdio.h>
#include<string.h>
#define max 10
void Sent_Message();
int Add_Message(char queue[max][100], int *r, char data[100]);
void Receive_Message();
int Remove_Message(char queue[max][100], int *f, int *r, char data[100]);
void Display(int m,char queue[max][100], int *r, int *f);
void Display_by_name(int id);
struct Application_Attribute{
 int a_id;
 char messages_Queue[10];
 int f;
 int r;
} Application[10];
int num;

int main()
{
    int choice,i,id;
    while(1)
    {
    printf("Enter How many Application You Want to Create:");
    scanf("%d",&num);
    if(num>0 && num <=10)
    {
        printf("Application created successfully\n\tApplication ID\n");
        for( i=0;i<num;i++)
            {
                Application[i].a_id=i+1;
                Application[i].r=-1;
                Application[i].f=-1;
                printf("\t %d \n",i+1);
            }
            while(1)
            {
                printf("\n------Menu---------\n1.Sent Message\n2.Receive Message\n3.List Message by queue name\n4.List All Queue\n5.Has Message\nEnter Your Choice:");
                scanf("%d",&choice);
                if(choice==1)
                {
                    Sent_Message();
                }
                else if(choice==2)
                {
                    Receive_Message();
                }
                else if(choice==3)
                {
                    printf("Enter Application ID:");
                    scanf("%d",&id);
                    Display_by_name(id);
                    //List Message single queue
                }
                else if(choice==4)
                {

                    for( i=0; i<num; i++)
                    {
                        if(Application[i].r != Application[i].f)
                        {
                            printf("------------------------------------\n");
                            Display(i+1,Application[i].messages_Queue,&Application[i].r,&Application[i].f);
                        }
                    }
                }
                else if(choice==5)
                {
                    printf("Application ID: \t");
                    scanf("%d",&id);
                    if(Application[id-1].f!=Application[id-1].r)
                    {
                        printf("True\n");
                    }
                    else
                    {
                        printf("False\n");
                    }
                    //Check weather queue empty or not
                }
            }
    }
    else
    {
        printf("\nSorry Maximum number of process should be 10\nTry again!!\n");
    }
    }
    return 0;
}
void Sent_Message()
{
    int s,d;
    int *rear;
    char data[100];
    printf("Enter Source Application:");
    scanf("%d",&s);
    printf("Enter Destination Application:");
    scanf("%d",&d);
    if((s>=1 && s<=num) && (d>=1 && d<=num) && (s!=d))
    {
        printf("Enter your Message:");
        //scanf("%s",data);
        fflush(stdin);
        gets(data);
        printf("%s",data);
        int check= Add_Message(Application[d-1].messages_Queue,&Application[d-1].r, data);
        if(check == -1)
        {
            printf("Queue is full\n");
        }
        else
        {
            printf("Message is sent from Application %d to %d Application\n",s,d);
        }
    }
        else if(s==d)
    {
        printf("\tWarning!! \nSource and Destination should not be same\nTry again\n");
    }
    else
    {
        printf("Wrong ID of Source or Destination Application\n");
    }
}
int Add_Message(char queue[max][100], int *r, char data[100])
{
    if(*r == max-1)
    {
        return(-1);
    }
    else
        {
            *r = *r + 1;
            strcpy(queue[*r], data);
            return(1);
      }
}

void Receive_Message()
{
    int d,check;
	char data[100];
	printf("Enter Application ID:");
	scanf("%d",&d);
	check = Remove_Message(Application[d-1].messages_Queue,&Application[d-1].f, &Application[d-1].r, data);
	if( check == -1 )
    {
        printf("\nQueue is Empty \n");
    }
    else
    {
        printf("\n Received Message from Application %d Queue is : %s\n\n",d, data);
    }
}


int Remove_Message(char queue[max][100], int *f, int *r, char data[100])
{
    if(*f == *r)
    {
        return(-1);
        printf("Hi");
    }
    else
    {
        *f+=1;
        strcpy(data, queue[*f]);
        return(1);
    }
}


void Display(int m,char queue[max][100], int *r, int *f)
{
    int j;
    if(*f == *r)
        {
            printf("No message\n");
        }
    else
    {
        printf("Message queue of Application %d\n",m );
        for((j = *f+1); j<= *r; j++)
            {
                printf("%s\t",queue[j] );
            }
    }
    printf("\n");
}

void Display_by_name(int id)
{
	Display(id,Application[id-1].messages_Queue, &Application[id-1].r, &Application[id-1].f);
}
