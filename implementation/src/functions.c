#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "functions.h"

typedef struct
{
 float ri;
 float wh;
 float su;
 float dh;
}rate;
struct type1
{   float wheat;
    float sugar;
    float balwheat1;
    float balsugar1;
};
struct type2
{  float rice2;
   float sugar2;
   float dhal2;
   float wheat2;
   float balrice2;
   float balsugar2;
   float baldhal2;
   float balwheat2;
};

typedef struct {
	char headname[25];
	int adultcount;
	int childrencount;
	int annualincome;
	char mobile_no[20];
	char street[50];
	char city[50];
	char acct_type;
	struct type1 white_card;
	struct type2 green_card;
	char day[50];
}account;

account consumer;
rate price;


 void greencalc()
 {
    consumer.green_card.rice2=3*consumer.adultcount+1.5*consumer.childrencount;
    consumer.green_card.sugar2=1*consumer.adultcount+1*consumer.childrencount;
    consumer.green_card.dhal2=1*consumer.adultcount+0.5*consumer.childrencount;
    consumer.green_card.wheat2=2*consumer.adultcount+1*consumer.childrencount;
    consumer.green_card.balrice2=consumer.green_card.rice2;
    consumer.green_card.balsugar2=consumer.green_card.sugar2;
    consumer.green_card.baldhal2=consumer.green_card.dhal2;
    consumer.green_card.balwheat2=consumer.green_card.wheat2;

 }
 void whitecalc()
 {
    consumer.white_card.wheat=(2*(consumer.adultcount))+ (1*(consumer.childrencount));
    consumer.white_card.sugar=(1*(consumer.adultcount))+ (.5*(consumer.childrencount));
    consumer.white_card.balwheat1=consumer.white_card.wheat;
    consumer.white_card.balsugar1=consumer.white_card.sugar;
 }

 void add_consumer()
 {
    FILE *fp;
    fp=fopen("cons.txt","ab");
    printf("\n\t**********************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************        ADD DETAILS        **********************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t**********************************************************************");

    fflush(stdin);
    if(fp==NULL)
      {
        printf("can't create file");
        getch();
        exit(1);
      }
	  printf("\n\tName:");
	  gets(consumer.headname);
	  printf("\n\tHouse No & Street:");
      gets(consumer.street);
      printf("\n\tCity:");
      gets(consumer.city);
      fflush(stdin);
	  printf("\n\tmobile no:");
	  scanf("%s",consumer.mobile_no);
      printf("\n\tadult count:");
	  scanf("%d",&consumer.adultcount);
      printf("\n\tChildren count:");
	  scanf("%d",&consumer.childrencount);
      printf("\n\tAnnual income:");
	  scanf("%d",&consumer.annualincome);
	  if(consumer.annualincome<=150000)
      {
      consumer.acct_type = 'G';
      greencalc();
      }
      if(consumer.annualincome>150000)
      {
      consumer.acct_type = 'W';
      whitecalc();
      }
      fwrite(&consumer,sizeof(consumer),1,fp);
      fflush(stdin);
      fclose(fp);
      main();
}


void output()
{   printf("\n\t**********************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************    CONSUMER INFORMATION   **********************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t**********************************************************************\n");
    printf("\n\t Name              : %s",consumer.headname);
    printf("\n\t adult count       : %d",consumer.adultcount);
    printf("\n\t children count    : %d",consumer.childrencount);
    printf("\n\t annual income     : %d",consumer.annualincome);
    printf("\n\t mobile no         : %s",consumer.mobile_no);
    printf("\n\t House no & Street : %s",consumer.street);
    printf("\n\t City              : %s",consumer.city);
    printf("\n\t Card type         : %c",consumer.acct_type);
    printf("\n\t last purchase     : %s",consumer.day);
    printf("\n\n\t ============ALLOTED QUANTITY============\n");
    if(consumer.acct_type =='W')
    {
    system("color 0F");
    printf("\n\t SUGAR       = %.2f kgs \n\t WHEAT       = %.2f kgs ",consumer.white_card.sugar,consumer.white_card.wheat);
    }
    if(consumer.acct_type =='G')
    {
    system("color 0A");
    printf("\n\t RICE         = %.2f kgs \n\t SUGAR        = %.2f kgs \n\t DHAL         = %.2f kgs \n\t WHEAT        = %.2f kgs",consumer.green_card.rice2,consumer.green_card.sugar2,consumer.green_card.dhal2,consumer.green_card.wheat2);
}
}


void read()
{
    printf("\n\t**********************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************      SEARCH & UPDATE      **********************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t**********************************************************************\n");
    char num[20];
    int flag=1;
    printf("Enter the number:\n");
    scanf("\n%s",num);
    long int size=sizeof(consumer);
    FILE *fp;
    fp=fopen("cons.txt","r+b");
    if(fp==NULL)
    {
    printf("can't read file");
    getch();
    exit(1);
    }
    while(fread(&consumer,sizeof(consumer),1,fp)==1)
    {
    if(strcmp(consumer.mobile_no,num)==0)
    {
    flag=0;
    output();
    int choice;
    {
printf("\n\n\tENTER THE FIELDS TO BE CHANGED");
printf("\n\t 1.Name change\n\t 2.Mobile number change\n\t 3.address change\n\t 4.family modification\n\t 5.income modification\n\t 6.back to menu");
        do{
	       printf("\n\tselect the option");
	       choice=getch();
	       }while(choice<='1' && choice>='6');
      fflush(stdin);
	  switch(choice){
		case '1':
			printf("\n%s",consumer.headname);
			printf("\n enter new name");
			gets(consumer.headname);
			printf("\n\nUPDATED SUCESSFULLY");
			Sleep(400);
			fseek(fp,-size,SEEK_CUR);
            fwrite(&consumer,sizeof(consumer),1,fp);
            fflush(stdin);
			break;
		case '2':
			printf("\n%s",consumer.mobile_no);
			printf("\n enter new number");
			scanf("\n%s",consumer.mobile_no);
			printf("\n\nUPDATED SUCESSFULLY");
			Sleep(400);
			break;
		case '3':
		    printf("\n%s",consumer.street);
			printf("\n%s",consumer.city);
			printf("\n\t enter new house no & street");
			scanf("\n%s",consumer.street);
			printf("\n\t enter new city ");
			scanf("\n%s",consumer.city);
			printf("\n\nUPDATED SUCESSFULLY");
			Sleep(400);
			break;
		case '4':
			printf("\n\tno of adults=%d",consumer.adultcount);
			printf("\n\tno of children=%d",consumer.childrencount);
			printf("\n\tenter new details");
			printf("\n\tno of adults");
			scanf("\n\t%d",&consumer.adultcount);
			printf("\n\tno of children");
			scanf("\nt\t%d",&consumer.childrencount);
			if(consumer.acct_type=='G')
            {
             greencalc();
            }
            if(consumer.acct_type=='W')
            {
             whitecalc();
            }
            printf("\n\nUPDATED SUCESSFULLY");
			Sleep(400);
			break;

        case '5':
			printf("\n%d",consumer.annualincome);
			printf("\n enter new details\n");
			scanf("\n%d",&consumer.annualincome);
			if(consumer.annualincome<150000)
            {
            consumer.acct_type='G';
            greencalc();
            }
            else
            {
            consumer.acct_type ='W';
            whitecalc();
            }
            printf("\n\nUPDATED SUCESSFULLY");
			Sleep(400);
			break;

        case '6':
            main();
            }
    fseek(fp,-size,SEEK_CUR);
    fwrite(&consumer,sizeof(consumer),1,fp);
    fflush(stdin);
    }
    }
    }
    if(flag==1)
    {
        printf("\n\ndata not found");
    }
    fclose(fp);
}

void billing()
{   printf("\n\t**********************************************************************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t*********************          BILLING          **********************");

    printf("\n\t                     ***************************                  ");

    printf("\n\t**********************************************************************\n");
    float r=0,w=0,d=0,s=0;
    int confirm=0,reset=0;
    char num[20];
    int flag=1;
    printf("\n\tEnter the number\n\n");
    scanf("\n\n\t\t%s",num);
    long int size=sizeof(consumer);
    FILE *fp;
    FILE *fr;
    fr=fopen("price.txt","r+b");
    fp=fopen("cons.txt","r+b");
    if(fp==NULL||fr==NULL)
      {
      printf("\ncan't read file");
      getch();
      exit(1);
      }
    while(fread(&consumer,sizeof(consumer),1,fp)==1)
    {
      if(strcmp(consumer.mobile_no,num)==0)
        {
         flag=0;
         output();
         printf("\n\npress 1 to reset the value or press 0 to proceed");
         scanf("%d",&reset);
         if(reset==1)
          {
           if(consumer.acct_type=='W')
           whitecalc();
           else
           greencalc();
           printf("\n\nupdated sucessfully");
           fseek(fp,-size,SEEK_CUR);
           fwrite(&consumer,sizeof(consumer),1,fp);
           fflush(stdin);
           }
    system("cls");
    if(consumer.acct_type=='W')
     {
        printf("\nenter the amount of wheat\n available = %.2f\n",consumer.white_card.balwheat1);
        scanf("%f",&w);
        while(w>consumer.white_card.balwheat1)
        {
        printf("\nenter the value within specified limit\n");
        scanf("%f",&w);
        }
        printf("\nenter the amount of sugar\n available = %.2f\n",consumer.white_card.balsugar1);
        scanf("%f",&s);
        while(s>consumer.white_card.balsugar1)
        {
        printf("enter the value within specified limit\n");
        scanf("%f",&s);
        }
        break;
     }
    if(consumer.acct_type=='G')
      {
        printf("\nenter the amount of wheat\n available = %.2f\n",consumer.green_card.balwheat2);
        scanf("%f",&w);
        while(w>consumer.green_card.balwheat2)
        {
        printf("enter the value within specified limit\n");
        scanf("%f",&w);
        }
        printf("\nenter the amount of sugar\n available = %.2f\n",consumer.green_card.balsugar2);
        scanf("%f",&s);
        while(s>consumer.green_card.balsugar2)
        {
        printf("enter the value within specified limit\n");
        scanf("%f",&s);
        }
        printf("\nenter the amount of DHAL\n available = %.2f\n",consumer.green_card.baldhal2);
        scanf("%f",&d);
        while(d>consumer.green_card.baldhal2)
        {
        printf("enter the value within specified limit\n");
        scanf("%f",&d);
        }
        printf("\nenter the amount of RICE\n available = %.2f\n",consumer.green_card.balrice2);
        scanf("%f",&r);
        while(r>consumer.green_card.balrice2)
        {
        printf("enter the value within specified limit\n");
        scanf("%f",&r);
        }
        break;
       }

     }

    }

    if(flag==1)
    {
    printf("\nwrong number");
    getch();
    fclose(fp);
    main();
    }
    fread(&price,sizeof(price),1,fr);
    float a1,a2,a3,a4;
    a1=price.dh;
    a2=price.ri;
    a3=price.wh;
    a4=price.su;
    system("cls");
    printf("\n\n\t\t*************INVOICE*************\t\t\t");
    printf("\n\nITEM \t\t\tQUANTITY\t\t\t PRICE");
    printf("%f",price.dh);
    if(d>0)printf("\n\nDHAL \t\t\t%.2fkgs\t\t\t\t₹ %.2f",d,a1*d);
    if(r>0)printf("\n\nRICE \t\t\t%.2fkgs\t\t\t\t₹ %.2f",r,a2*r);
    if(w>0)printf("\n\nWHEAT\t\t\t%.2fkgs\t\t\t\t₹ %.2f",w,a3*w);
    if(s>0)printf("\n\nSUGAR\t\t\t%.2fkgs\t\t\t\t₹ %.2f",s,a4*s);
    printf("\n\n\nTOTAL\t\t\t\t\t\t\t₹%.2f",(price.dh*d+price.ri*r+price.wh*w+price.su*s));
    Sleep(500);
    printf("\n\npress 1 to confirm billing or press 0 to abort billing");
    scanf("%d",&confirm);
    if(confirm =='y'||'Y')
    {
        time_t current_time;
        char * c_time_string;
        current_time=time(NULL);
        c_time_string=ctime(&current_time);
        printf("%s",c_time_string);

      if(consumer.acct_type=='W')
        {
        consumer.white_card.balwheat1-=w;
        consumer.white_card.balsugar1-=s;
        printf("\nbilling sucessful");
        strcpy(consumer.day,ctime(&current_time));
        getch();
        }
      else if(consumer.acct_type=='G')
        {
        consumer.green_card.balrice2-=r;
        consumer.green_card.balsugar2-=s;
        consumer.green_card.baldhal2-=d;
        consumer.green_card.balwheat2-=w;
        strcpy(consumer.day,ctime(&current_time));
        printf("\nbilling sucessful");
        getch();
        }
    }

    else{printf("\nbilling aborted");}
    fseek(fp,-size,SEEK_CUR);
    fwrite(&consumer,sizeof(consumer),1,fp);
    fflush(stdin);
    fclose(fp);
    fclose(fr);
}

void pricechange()
{
    long int size=sizeof(price);
    FILE *fr;
    fr=fopen("price.txt","wb+");
    while(fread(&price,sizeof(price),1,fr)==1);
    printf("\nenter the rice price\n");
    scanf("%f",&price.ri);
    printf("\nenter the wheat price\n");
    scanf("%f",&price.wh);
    printf("\nenter the sugar price\n");
    scanf("%f",&price.su);
    printf("\nenter the dhal price\n");
    scanf("%f",&price.dh);
    fseek(fr,-size,SEEK_END);
    fwrite(&price,sizeof(price),1,fr);
    fclose(fr);
}

