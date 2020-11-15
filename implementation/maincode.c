#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "functions.h"

int main()
	{
	  char ch;
	  system("cls");
	  printf("\n\n\t***** WELCOME TO PUBLIC DISTRIBUTION BILLING SYSYTEM *****\n\n");
	  printf("\n\t=================================================\n");
	  printf("\n\t\t1:    ADD ACCOUNT\n");
	  printf("\t\t2:    SEARCH AND UPDATE\n");
	  printf("\t\t3:    BILLING\n");
	  printf("\t\t4:    PRICE UPDATE\n");
	  printf("\t\t5:    EXIT\n");
	  printf("\n\t=================================================\n");
	  do{
	       printf("\n\tselect what do you want to do?");
	       ch=getch();
	  }while(ch<'0' && ch>'5');

	  switch(ch){
		case '1':
			system("cls");
			add_consumer();
			main();
		case '2':
			system("cls");
			read();
			getch();
			main();
		case '3':
		    system("cls");
			billing();
			main();
        case '4':
            system("cls");
            pricechange();
            main();

		case '5':
            system("cls");
			Sleep(3000);
			printf("\nA PROJECT BY S.SATHYA VIKAS");
			Sleep(3000);
			exit(1);

	  }
 }

