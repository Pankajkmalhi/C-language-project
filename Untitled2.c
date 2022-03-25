#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<MMsystem.h>
void wel(void);

void Log_In(void);

void returnfunc(void);

void mainmenu(void);

void administration(void);

void customer(void);

void addrecord(void);
void deleterecord(void);
void searchrecord(void);
void viewrecord(void);

void vegetarian(void);
void nonvegetarian(void);
void drinks(void);
void fastfood(void);

void details(void);

int getdata();

struct employee
{
	char name[30],department[20],place[20];
	int id,YOJ,quantity;
	float salary;
};
struct employee e;
FILE *fp,*ft,*dp,*dt;
int s,t,again,quantity;
char findrecord;
int main()
{
	mainmenu();
	return 0;
}
void mainmenu(void)
{	
	system("cls");
	system("color 70");
	wel();
	int i;	
	printf("\n|***************************************************************************|\n");
	printf("|                        WELCOME TO FOOD ORDER SYSTEM                       |\n");
	printf("|***************************************************************************|\n");
	printf("1. ADMINISTRATION\n\n");
	printf("2. CUSTOMER\n\n");
	printf("3. Exit\n\n");
	printf("Enter Your Choice");
	int choice;
	while(i==0)
	{
	PlaySound(TEXT("wel"),NULL,SND_SYNC);
		PlaySound(TEXT("select"),NULL,SND_SYNC);
	i++;
	}
	
	scanf("%d",&choice);
	if(choice==1){
		Log_In();
		administration();
	PlaySound(TEXT("admi"),NULL,SND_SYNC);
	}
	else if(choice==2){
		customer();
	}
	else if(choice==3){
		system("cls");
		printf("\n\n");
		printf("|**********************************|\n");
		printf("|            THANK YOU             |\n");
		printf("|**********************************|\n");
		exit(0);
	}
}
void wel(void){
	printf("\t[***WELCOME***]\n\n\n");
	printf("A Cafetaria MANAGEMENT PROJECT PRESENTED BY\n\n");
	printf("PANKAJ KUMAR\n");

}

void administration(void){
	system("cls");
	char str[10000];
	FILE *fp;
	fp=fopen("adm.txt","r");//open the file of administration data
	while(fgets(str,100,fp)!=NULL){
		printf("%s",str);}
	int n,wait;
	scanf("%d",&n);
		printf("\n\n");
	printf("\n\n");
	if(n==1){
		addrecord();
		system("cls");
	}
	else if(n==2){
		searchrecord();
	}
	else if(n==3){
		deleterecord();
	}
	else if(n==4){
		viewrecord();
	}
	else if(n==5){
		FILE *view;
		char viw;
		view = fopen("order.txt","rt");
		while((viw=fgetc(view))!=EOF){
			printf("%c",viw);
		}
		fclose(view);
	returnfunc();	
	}
	else if(n==6){
		system("cls");
		mainmenu();
	}
	else{
		printf("Wrong Input !! Please Re-enter The Correct Option");
		if(getch())
		administration();
	}
}
void addrecord(void){
	system("cls");
	char c;
	fp=fopen("record1.txt","a");
	if(getdata()==1){
		fseek(fp,0,SEEK_END);
		fwrite(&e,sizeof(e),1,fp);
		fclose(fp);
		printf("The Record Is Successfully Saved ! !\n\n");
		fflush(stdin);
		printf("Save any more?(Y / N): ");
		scanf("%c",&c);
		if(c=='n'||'N')
	    	administration();
		else
	    	system("cls");
	    	printf("\n\n");
	    	addrecord();}	
}
void deleterecord(void){
	system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
	{
	system("cls");
	printf("                Enter The Employee ID To Delete :");
	scanf(" %d",&d);
	fp=fopen("record1.txt","r");
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1){
	    if(e.id==d){
			
			printf("\n\n                              .....................The Employee Record Is Available....................\n\n");
			printf("               Employee Name Is %s\n\n",e.name);
			findrecord='t';
	    }
	}
	if(findrecord!='t'){
	    printf("                                    .........................No record is found modify the search..........................\n\n");
	    	PlaySound(TEXT("no rec found"),NULL,SND_SYNC);
		if(getch())
	    administration();
	}
	if(findrecord=='t' ){
	    printf("Do You Want To Delete THe Record ? (Y/N) ");
	    PlaySound(TEXT("do you delete"),NULL,SND_SYNC);
	    if(getch()=='y'){
			ft=fopen("test1.txt","r");  
			rewind(fp);
			while(fread(&e,sizeof(e),1,fp)==1){
		    	if(e.id!=d){
					fseek(ft,0,SEEK_CUR);
					fwrite(&e,sizeof(e),1,ft); 
		    	}}
			fclose(ft);
			fclose(fp);
			remove("record1.txt");
			rename("test1.txt","record1.txt");
			fp=fopen("record1.txt","r");    
			if(findrecord=='t'){
		    	printf("        THE RECORD IS SUCCESSFULLY DELETED.\n\n");
		    	PlaySound(TEXT("delete success"),NULL,SND_SYNC);
		    	printf("        Delete Another Record ? (Y/N) : ");
			PlaySound(TEXT("another search"),NULL,SND_SYNC);
			}}
		else
		administration();
		fflush(stdin);
		another=getch();
	}}
administration();
}

void searchrecord(void){
	system("cls");
    int d;
    printf("		|*****************************\n|");
	printf("		|  Search Employees Record    \n|");
	printf("		|*****************************\n|");
    printf("		    Enter the employee ID\n    ");

    fp=fopen("record1.txt","r"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
{
	    	system("cls");
	    	printf("                                   **************Search Record By Id****************\n\n");
	    	printf("                Enter The Employee ID : ");
	    	scanf(" %d",&d);
			printf("\n\nSearching........");
	    	while(fread(&e,sizeof(e),1,fp)==1){ 
				if(e.id==d){
		    		printf("\n\n");
					printf("...........................The Record is available............................\n\n");
				    printf("       ID : %d\n\n",e.id);
				    printf("       Name : %s\n\n",e.name);
				    printf("       Year Of Joining :%d\n\n",e.YOJ);
				    printf("       Department :%s\n\n",e.department);
				    printf("       Place :%s\n\n",e.place);
				    findrecord='t';
			}}
	    if(findrecord!='t')  //checks whether conditiion enters inside loop or not
	{
	    	printf("\aNo Record Found\a");
	    		PlaySound(TEXT("no rec found"),NULL,SND_SYNC);
	    }
	    printf("Try Another Search ? (y/n)");
	    PlaySound(TEXT("another search"),NULL,SND_SYNC);
	    if(getch()=='y')
	    searchrecord();
	    else
	    administration();
}
fclose(fp);
}
void viewrecord(void) {
    system("cls");
    printf("                 **************************** Employee Details**********************\n\n");
    printf("                 DEPARTMENT    ID     EMPLOYEE NAME    Y.O.J      address\n\n");
    fp=fopen("record1.txt","r");
    	PlaySound(TEXT("emp all"),NULL,SND_SYNC);
    while(fread(&e,sizeof(e),1,fp)==1)
    {
		printf("                 %s",e.department);
		printf("        %d",e.id);
		printf("        %s",e.name);

		printf("        %d",e.YOJ);
		printf("        %s",e.place);
		printf("\n\n");
	}
      fclose(fp);
      returnfunc();
}

void returnfunc(void){
    {
		printf(" Press ENTER to return to main menu");
    }
    e:
    if(getch()==13) //allow only use of enter
    administration();
    else
    goto e;
}
int checkid(int c)  //check whether the record is exist in list or not
{
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
	if(e.id==c)	
	return 0;  //returns 0 if employee exits
	return 1; //return 1 if it not
}
int getdata(){
	PlaySound(TEXT("emp rec"),NULL,SND_SYNC);
	printf("Employee ID :");
	scanf("%d",&t);
	if(checkid(t)==0){
		printf("\n\n\a                        The Employee Record Already Exists !!!\a");
		getch();
		mainmenu();
		return 0;
	}
	e.id=t;
	printf("        Employee Name : ");
	scanf("%s",e.name);
	printf("        Year OF Joining :");
	scanf("%d",&e.YOJ);
	printf("        address :");
	scanf("%s",e.place);
	printf("        Department :");
	scanf("%s\n",e.department);
	return 1;
}


void customer(void){
	system("cls");
	char str[10000];
	FILE *fp;
	fp=fopen("main menu.txt","r");
	while(fgets(str,100,fp)!=NULL){
		printf("%s",str);}
	int k;
	scanf("%d",&k);
	if(k==1){
		system("cls");
		vegetarian();
	}
	else if(k==2){
		system("cls");
		nonvegetarian();
	}
	else if(k==3){
		system("cls");
		drinks();
	}
	else if(k==4){
		system("cls");
		fastfood();
	}
	else if(k==5){
		system("cls");
		mainmenu();
	}
	else{
		printf("Wrong Input !Please Re-enter The Correct Option......\n\n");
		customer();
	}}

void vegetarian(void){
	int choice,again,quantity;
	double total1=0,price=0;
	//opening the menu file
	char str[10000],v;
	FILE *fp;
fp=fopen("Veg.txt","r");
	if(fp==NULL){
		printf("NOt found");}
	while(fgets(str,100,fp)!=NULL){
	printf("%s",str);}
	fclose(fp);
	PlaySound(TEXT("veg menu"),NULL,SND_SYNC);
    printf("\n\nEnter What You Want :");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1){
			PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total1=total1 + 140*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");		
		scanf("%d",&again);
		printf("\n");
		if(again==1){
			printf("\n\n");
			vegetarian();
		}
		else if(again==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total1);
			int totl = total1;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total1;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			details();
		}}
	else if(choice==2){
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		printf("Quantity :");
		scanf("%d",&quantity);
		total1=total1 + 60*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1){
			printf("\n\n");
			vegetarian();
		}
		else if(again==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total1);
			int totl = total1;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total1;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			details();
		}}
	else if(choice==3){
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total1=total1 + 45*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1){
			printf("\n\n");
			vegetarian();
		}
		else if(again==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total1);
			int totl = total1;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total1;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();}
	}
	else if(choice==4){
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		printf("Quantity :");
		scanf("%d",&quantity);
		total1=total1 + 150*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1){
			printf("\n\n");
			vegetarian();
		}
		else if(again==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total1);
			int totl = total1;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
		else if(again==3){
			int total=total1;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==5){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf("%d",&quantity);
		total1=total1 + 120*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1){
			printf("\n\n");
			vegetarian();
		}
		else if(again==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total1);
			int totl = total1;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total1;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==6){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf("%d",&quantity);
		total1=total1 + 140*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1){
			printf("\n\n");
			vegetarian();
		}
		else if(again==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total1);
			int totl = total1;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
		details();
		}
		else if(again==3){
			int total=total1;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			details();
		
		}}
	else if(choice==7){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf("%d",&quantity);
		total1=total1 + 100*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1){
			printf("\n\n");
			vegetarian();
		}
		else if(again==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total1);
			int totl = total1;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total1;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==8){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf("%d",&quantity);
		total1=total1 + 120*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1){
			printf("\n\n");
			vegetarian();
		}
		else if(again==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total1);
			int totl = total1;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
		
			details();
		}
		else if(again==3){
			int total=total1;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==9){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf("%d",&quantity);
		total1=total1 + 170*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1){
			printf("\n\n");
			vegetarian();
		}
		else if(again==2){
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total1);
			int totl = total1;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total1;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			details();
		}}
	else if(choice==10){
		system("cls");
		customer();
	}
	else{
		printf("Wrong Input! Re-enter The Correct Option\n\n");
		if(getch())
		vegetarian();
	
	}}
	
void nonvegetarian(void){
	int choice,again,quantity;
	double price=0,total2=0;
	char n,str[1000];
	FILE *nmenu,*fp;
	//open file of menu
	fp=fopen("non veg.txt","r");
	while(fgets(str,100,fp)!=NULL){
	printf("%s",str);}
	PlaySound(TEXT("non veg menu"),NULL,SND_SYNC);
	printf("\n\nEnter What You Want :\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity : ");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total2=total2 + 1000*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total2);
			int totl = total2;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total2;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total2=total2 + 1200*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total2);
			int totl = total2;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total2;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total2=total2 + 140*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total2);
			int totl = total2;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total2;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total2=total2 + 200*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total2);
			int totl = total2;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total2;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==5)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total2=total2 + 1600*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total2);
			int totl = total2;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total2;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==6)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total2=total2 + 1200*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total2);
			int totl = total2;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total2;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==7)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total2=total2 + 150*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total2);
			int totl = total2;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total2;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==8)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total2=total2 + 1800*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==8)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total2);
			int totl = total2;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total2;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==9)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total2=total2 + 1100*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total2);
			int totl = total2;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total2;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==10)
	{
		system("cls");
		customer();
	}
	
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		nonvegetarian();
	}
}


void drinks(void)
{
	int choice,again,quantity;
	double price=0,total3=0;	
	char d,str[1000];
	FILE *fp;
	fp=fopen("drinks.txt","r");

	while(fgets(str,100,fp)!=NULL){
		printf("%s",str);}
		PlaySound(TEXT("drinks"),NULL,SND_SYNC);
	printf("\n\nEnter What You Want :\n\n");
	scanf("%d",&choice);
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
	if(choice==1){
		printf("Quantity : ");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total3=total3 + 40*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1){
			printf("\n\n");
			drinks();
		}
		else if(again==2){
			printf("Your Total Amount Is :%.2lf\n\n",total3);
			int totl = total3;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total3,discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==2){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total3=total3 + 30*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1){
			printf("\n\n");
			drinks();
		}
		else if(again==2){
			printf("Your Total Amount Is :%.2lf\n\n",total3);
			int totl = total3;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total3;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==3){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total3=total3 + 100*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1){
			printf("\n\n");
			drinks();
		}
		else if(again==2){
			printf("Your Total Amount Is :%.2lf\n\n",total3);
			int totl = total3;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total3;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==4){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total3=total3 + 80*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1){
			printf("\n\n");
			drinks();
		}
		else if(again==2){
			printf("Your Total Amount Is :%.2lf\n\n",total3);
			int totl = total3;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total3;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);	
			details();
		}}
	else if(choice==5)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total3=total3 + 90*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1){
			printf("\n\n");
			drinks();
		}
		else if(again==2){
			printf("Your Total Amount Is :%.2lf\n\n",total3);
			int totl = total3;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total3;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			details();
			}}
	else if(choice==6){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total3=total3 + 120*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1){
			printf("\n\n");
			drinks();
		}
		else if(again==2){
			printf("Your Total Amount Is :%.2lf\n\n",total3);
			int totl = total3;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total3;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==7){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total3=total3 + 150*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1){
			printf("\n\n");
			drinks();
		}
		else if(again==2){
			printf("Your Total Amount Is :%.2lf\n\n",total3);
			int totl = total3;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total3;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==8){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total3=total3 + 100*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1){
			printf("\n\n");
			drinks();
		}
		else if(again==2){
			printf("Your Total Amount Is :%.2lf\n\n",total3);
			int totl = total3;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total3;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==9){
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total3=total3 + 100*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1){
			printf("\n\n");
			drinks();
		}
		else if(again==2){
			printf("Your Total Amount Is :%.2lf\n\n",total3);
			int totl = total3;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3){
			int total=total3;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}}
	else if(choice==10){
		system("cls");
		customer();
	}
	else{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
	    drinks();
	}}


void fastfood(void)
{
	int choice, again,quantity;
	double price=0,total4=0;
	char str[10000];
	FILE *fp;
fp=fopen("fast.txt","r");
if(fp==NULL)
{
	printf("File address error\n");
	exit(0);
}
	while(fgets(str,100,fp)!=NULL){
		printf("%s",str);}
			PlaySound(TEXT("fast"),NULL,SND_SYNC);
	printf("\n\nEnter What You Want :");
	printf("\n\n");
	scanf("%d",&choice);
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
	if(choice==1){
		printf("Quantity : ");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total4=total4 + 220*(quantity);
	
		printf("\nPress 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			fastfood();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total4);
			int totl = total4;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total4;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total4=total4 + 200*(quantity);
		printf("\nPress 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			fastfood();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total4);
			int totl = total4;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total4;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total4=total4 + 100*(quantity);
		
		printf("\nPress 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			fastfood();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total4);
			int totl = total4;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total4;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total4=total4 + 300*(quantity);
		printf("\nPress 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			fastfood();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total4);
			int totl = total4;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total4;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==5)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total4=total4 + 600*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			fastfood();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total4);
			int totl = total4;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
		else if(again==3)
		{
			int total=total4;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==6)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total4=total4 + 70*(quantity);
		printf("\n");
	printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			fastfood();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total4);
			int totl = total4;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
			else if(again==3)
		{
			int total=total4;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==7)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total4=total4 + 100*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			fastfood();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total4);
			int totl = total4;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
			else if(again==3)
		{
			int total=total4;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==8)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total4=total4 + 60*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			fastfood();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total4);
			int totl = total4;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
			else if(again==3)
		{
			int total=total4;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\nDiscount = %d\nGrand Total : %d\n",discount,total);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==9)
	{
		printf("Quantity :");
		PlaySound(TEXT("quantity"),NULL,SND_SYNC);
		scanf(" %d",&quantity);
		total4=total4 + 150*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\npress 3 to get a free random discount coupon from 1 percent to 10 percent, Try your luck!\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
		fastfood();
	}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total4);
			int totl = total4;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
			else if(again==3)
		{
			int total=total4;
			int discount;
			FILE*ttl;
			ttl = fopen("order.txt","a");
			srand(time(NULL));
			discount=total/100*(rand()%11);
			total=total-discount;
			fprintf(ttl,"\n\nGrand Total : %dDiscount = %d\n",total,discount);
			printf("\nCONGRATULATIONS!!! your discount is %d\nYour total is %d\n",discount,total);
			fclose(ttl);
			
			details();
		}
	}
	else if(choice==10)
	{
		system("cls");
		customer();
	}
	
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
	    fastfood();
	}
}


void details(void)
{
	int i;
	char name[20],landmark[30],address[40];
	long long int phone;
	printf("Press 1 for the home delivery\n");
	printf("Press 2 for eating at the hotel\n");
	printf("Enter your choice\n");
	scanf("%d",&i);
		PlaySound(TEXT("details"),NULL,SND_SYNC);
	if(i==1)
	{
	printf("Please Give Your Contact Details \n");
	printf(" Name : ");
	scanf("%s",name);
	printf("Phone : ");
	scanf("%lld",&phone);
	printf("Address : ");
	scanf("%s",address);
	printf("\n\n");
	FILE *cust;
	cust = fopen("order.txt","a");
	printf("------------------------------------------------------------\n");
	fprintf(cust,"Order Placed By : %s\nPhone number : %lld\n",name,phone);
	printf("------------------------------------------------------------\n");
	fclose(cust);
	printf("\n\nPress Any To The Main Menu.");
	if(getch())
	customer();
}
	else if(i==2){
	printf("Please Give Your Details \n");
	printf(" Name : ");
	scanf("%s",name);
	printf("Table number : ");
	scanf("%lld",&phone);
	printf("\n\n");
	FILE *cust;
	cust = fopen("order.txt","a");
	printf("--------------------------------------------------------\n");
	fprintf(cust,"Order Placed By:%s\nTable number:%lld\n",name,phone);
	printf("--------------------------------------------------------\n");
	fclose(cust);
	printf("---------------------------------------------\n");
	printf("Name :  %s\nTable no:     %lld \n",name,phone);
	printf("---------------------------------------------\n");
	printf("\n\n\n");
	printf("                    Please wait your order is about to  prepared\n");
		PlaySound(TEXT("order prepare"),NULL,SND_SYNC);
		
	printf("                              .....HAPPY ORDERING.....\n");
		PlaySound(TEXT("ordering thank"),NULL,SND_SYNC);
	printf("Press Any To The Main Menu.");
	if(getch())
	customer();
}
}
void Log_In()
{
	system("cls");
	int i;
	char pass[100]={0},user[100]={0},USER[] = "FAST",PASSWORD[] = "1234",temp1,temp2;
		PlaySound(TEXT("username"),NULL,SND_SYNC);
	printf("Enter Username:\n");
	for( i=0; i<10; i++)
	{
		temp1 = getch();
		if(temp1 == 13) // ascii enter key
		{
			break;
		}
		else
		{
			user[i] = temp1;
			
		}
		printf("%c",user[i]);
	}
	printf("\nEnter Password: \n");
	for( i=0; i<10; i++)
	{
		temp2 = getch();
		if(temp2 == 13)
		{
			break;
		}
		else
		{
			pass[i] = temp2;
		}
		printf("*");
	}
	if( strcmp(pass,PASSWORD ) == 0 && strcmp(user,USER) == 0)
	{
		printf("\nSUCCESFULLY LOGIN\n");
		system("cls");
	}
	else
	{	
		printf("\nWRONG PASSWORD,TRY AGAIN \n");
		Log_In();
	}
}
