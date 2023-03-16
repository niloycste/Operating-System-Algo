 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<string.h>
int wait(int);
int signal(int);

void dispaly1();
void clean();

void producer1();
void consumer1();
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()

int lock=1,full=0,empty=10,x=0;
int y=0;
int BUFFER_SIZE=10;
char ch='j';
char boundedBuffer[10][100];
void *consumer(void *vargp)
{
for(int i=0;i<3;i++){
	if((full!=0))	{

    sleep(1);
   // printf("Printing GeeksQuiz from Thread11111111 \n");
   	lock=wait(lock);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumes item %d\n",y+1);
//	strcpy(boundedBuffer[x],"consymer consumes the item: ");
	y=(y+1)%BUFFER_SIZE;
	lock=signal(lock);}
	else{

		printf("\n\nBuffer is empty!!");
		 sleep(1); }
	}
    return NULL;
}
void *producer(void *vargp)
{  for(int i=0;i<5;i++){
     if((empty!=0)){



    sleep(1);
    //printf("Printing GeeksQuiz from Thread \n");
    lock=wait(lock);
	full=signal(full);
	empty=wait(empty);
	strcpy(boundedBuffer[x],"Producer produces the item: ");
	printf("\nProducer produces the item: %d\n",x+1);
	x=(x+1)%BUFFER_SIZE;


	lock=signal(lock);}
	else
	 	printf("\n\nBuffer is full!!\n");
	}
    return NULL;
}

int wait(int s)
{
	return (--s);
}

int signal(int s)
{
	return(++s);
}
 void clean(){
	full=0;
	empty=BUFFER_SIZE;
	x=0;y=0;
	printf("The Buffer is cleaned and the semaphores are removed!!!!!!!!\n");
}
void dispaly(){
	int temp=full;
	int i=y;
	if(full==0){
		printf("The Buffer is empty");
	}
		while(temp > 0){
		printf(boundedBuffer[i]);
		printf("  %d\n",i+1);
		temp--;
		i=(i+1)%BUFFER_SIZE;
	}

}
int main()
{
int n;

    pthread_t thread_id1,thread_id2;
    pthread_create(&thread_id2, NULL, consumer, NULL);
    pthread_create(&thread_id1, NULL, producer, NULL);

    pthread_join(thread_id2, NULL);
    pthread_join(thread_id1, NULL);
    printf("\n1. For Producer\n2. For Consumer\n3. For Display \n4. For cleanUp\n");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((lock==1)&&(empty!=0))
						producer1();
					else
						printf("Buffer is full!!");
					break;
			case 2:	if((lock==1)&&(full!=0))
						consumer1();
					else
						printf("Buffer is empty!!");
					break;
			case 3:
					dispaly1();
					break;
			case 4:
					clean();
					break;
		}
	}
   // display();
    clean();
    exit(0);
}
void producer1()
{
	lock=wait(lock);
	full=signal(full);
	empty=wait(empty);
	strcpy(boundedBuffer[x],"Producer produces the item: ");
	x=(x+1)%BUFFER_SIZE;
	printf("Producer produces the item: %d",x);

	lock=signal(lock);
}
void dispaly1(){
	int temp=full;
	int i=y;
	if(full==0){
		printf("The Buffer is empty");
	}
	while(temp > 0){
		printf(boundedBuffer[i]);
		printf("  %d\n",i+1);
		temp--;
		i=(i+1)%BUFFER_SIZE;
	}

}
void consumer1()
{
	lock=wait(lock);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumes item %d",y+1);
//	strcpy(boundedBuffer[x],"consymer consumes the item: ");
	y=(y+1)%BUFFER_SIZE;
	lock=signal(lock);
}
