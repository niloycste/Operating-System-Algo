#include <stdio.h>

#include <unistd.h>

#include<string.h>

#include <stdlib.h>

int counterthread = 0;
int n;
int counterprocessor = 0;
int tid[0];
int pws[0];
int gotid[0];
int gopswid[0];
int processid;
void MainMenu() {

  int menu;
  printf("**OS Manager**********\n");
  printf("**Main  Menu**********\n");
  printf("1- Create Thread\n");
  printf("2- Create Processor\n");
  printf("3- Show Thread\n");
  printf("4- Show Processor\n");
  printf("5- Go\n");
  printf("6- Unwait\n");
  printf("7- EOQUANTUM\n");
  printf("8- EOLIFE\n");
  printf("9- WAIT\n");
  printf("Enter a Menu Number from 1 to 9");
  scanf("%d", & menu);
  if (menu == 1) {
    if (counterprocessor == 0) {
      printf("Please Create First processor At lest One processor");
      MainMenu();
    } else {
      Createthread();
    }
  }
  if (menu == 2) {
    createProcess();
  }

  if (menu == 3) {
    Showthread();
  }

  if (menu == 4) {
    ShowProcess();
  }

  if (menu == 5) {
    Go();
  }
  if (menu == 6) {
    Unwait();
  }
  if (menu == 7) {
    EOQUANTUM();
  }
  if (menu == 8) {
    EOLIFE();
  }
  if (menu == 9) {
    WAIT();
  }
}

void Createthread() {

  printf("Enter the Id for procces which you assign Thread");
  scanf("%d", & processid);

  counterthread = counterthread + 1;
  tid[counterthread];
  tid[counterthread] = counterthread;
  printf("Thread Create Successfull\n");

  //printf("%d\n", counterthread);
  //for (int i = 0; i < counterthread; i++) {
  //printf(" Total Thread %d\n", tid[i]);
  //}
  MainMenu();

}

void Showthread() {
  printf("counterthread %d\n", counterthread);












































































































for (int i = 0; i < counterthread; i++)
  {
    printf(" total Thread tid%d\n", tid[i]);
  }
  MainMenu();
}
void createProcess() {
  printf("How many Process want to create\n");
  scanf("%d", & counterprocessor);
  printf(" %d Process create Successfull \n", counterprocessor);

  pws[counterprocessor];

  //for (int i = 0; i < counterprocessor; i++) {
  //pws[i] =i;
  //}

  MainMenu();
}

void ShowProcess() {
  printf("counterprocessor %d\n", counterprocessor);
  for (int i = 0; i < counterprocessor; i++) {
    printf(" Total process  psw%d\n", pws[i]);
  }
  MainMenu();
}

void Go() {
  printf("Go Fuction");
  MainMenu();
}

void WAIT() {
  printf("WAIT Fuction");
  MainMenu();
}

void Unwait() {
  printf("Unwait Fuction");
  MainMenu();
}

void EOQUANTUM() {
  printf("EOQUANTUM");
  MainMenu();
}
void EOLIFE() {
  printf("EOLIFE");
  MainMenu();
}
int main() {

  MainMenu();

  return 0;
}
