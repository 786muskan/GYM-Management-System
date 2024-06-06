#include<stdio.h>
#include<conio.h>
#include "head2.c"
#include "uspace.c"
#include "sleepi.c"
typedef struct member
{
	char name[100];
	int age;
	char mem_type[50];
	char phone[15];
	char batch[50];
	float weight;
	char pur[20];
	int id;
}memb;

//id
int gen_id()
{
	FILE *ptr;
	char ch;
	int c=0;
	ptr=fopen("member.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file \n");
		exit();
	}
	ch=getc(ptr);
	while(!(ch==EOF))
	{
		ch=getc(ptr);
		if(ch=='\n')
			c++;
	}
	fclose(ptr);
	return c;
}
//add
void add_member()
{
	FILE *ptr;
	memb m;
	char ph[15],na[100];
	int i,n,op,op2,ag,op3;
	float wg;

	ptr=fopen("member.txt","a");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	m.id=100+gen_id();
	v:
	printf("Enter your name : ");
	fflush(stdin);
	gets(na);
	if((strlen(na))<=15)
	{
		change2(na);
		strcpy(m.name,na);
	}
	else
	{
		printf("\n\"INVALID NAME PLEASE ENTER 15 CHARACTER ONLY\"\n");
		goto v;
	}
	a:
	printf("Enter your age : ");
	scanf("%d",&ag);
	if(!(ag>12 && ag<70))
	{
		printf("\n\"Invalid age\"\n \n");
		goto a;
	}
	m.age=ag;
	w:
	printf("Enter your weight : ");
	scanf("%f",&wg);
	if(!(wg>=30 && wg<=150))
	{
		printf("\n\"Invalid weight \"\n\n");
		goto w;
	}
	m.weight=wg;
	clrscr();
	head2();
	no:
	printf("Enter your phone no. : ");
	fflush(stdin);
	gets(ph);
	n=strlen(ph);
	if(n==10)
	{
		for(i=0;i<n;i++)
		{
			if(!(ph[i]>='0' && ph[i]<='9'))
			{
				printf("\n\"Invalid number ! please enter 10 digit number \"\n\n");
				goto no;
			}
		}
	}
	else
	{
		printf("\n\"Invalid number ! please enter 10 digit number \"\n\n");
		goto no;
	}
	if(i==n)
		strcpy(m.phone,ph);
	clrscr();
	head2();
	type:
	printf("Choose the type of membership :\n");
	printf("\tPress 1 for Normal\n\tPress 2 for Silver\n\tPress 3 for Gold\n\tPress 4 for Diamond\n");
	printf("Your option is : ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			strcpy(m.mem_type,"Normal");
			break;
		case 2:
			strcpy(m.mem_type,"Silver");
			break;
		case 3:
			strcpy(m.mem_type,"Gold");
			break;
		case 4:
			strcpy(m.mem_type,"Diamond");
			break;
		default :
			printf("\n\"Invalid option\"\n\n");
			goto type;
	}
	clrscr();
	head2();
	time:
	printf("Choose your batch timings : \n");
	printf("\tPress 1 for Morning\n\tPress 2 for Evening\nYour option is : ");
	scanf("%d",&op2);
	switch(op2)
	{
		case 1:
			strcpy(m.batch,"Morning");
			break;
		case 2:
			strcpy(m.batch,"Evening");
			break;
		default :
			printf("\n\"Please enter vaild option\"\n\n");
			goto time;
	}
	clrscr();
	head2();
	purpose:
	printf("Choose your gym purpose : \n");
	printf("\tPress 1 for weight gain\n\tPress 2 for weight loss \nYour option is : ");
	scanf("%d",&op3);
	switch(op3)
	{
		case 1:
			strcpy(m.pur,"gain");
			break;
		case 2:
			strcpy(m.pur,"loss");
			break;
		default :
			printf("\n\"Please enter vaild option\"\n\n");
			goto purpose;
	}
	if(strlen(m.name)<=7)
	{
		fprintf(ptr,"%d\t%s\t\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
	}
	else
	{
		fprintf(ptr,"%d\t%s\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
	}
	fclose(ptr);
	clrscr();
	head2();
	printf("\n\nMember added");
	sleeping();
}
int edit_membe()
{
	FILE *ptr,*pr;
	char ch;
	memb m;
	int j,id,id2,cp,temp=0,c,i,id3,choice;
	char ph[15],nam[100],na[100],cha[200];
	int n,op,op2,ex,ag,op3;
	char name[100];
	float wg;
	ptr=fopen("member.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	pr=fopen("temp_m.txt","w");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	c=gen_id()+100;
	printf("Enter the id of the record you want to edit : ");
	scanf("%d",&id);
	rewind(ptr);
	while(1)
	{
		if(getc(ptr)==EOF)
		{
			break;
		}
		fscanf(ptr,"%d",&id2);
		if(id == id2 || id==100)
		{
			rewind(ptr);
			for(i=100;i<c;i++)
			{

				//start copy
				if(i!=id)
				{
					fscanf(ptr,"%d%s%d%s%f%s%s%s",&m.id,&name,&m.age,&m.phone,&m.weight,&m.mem_type,&m.batch,&m.pur);
						//uspace(name);
					strcpy(m.name,name);
					if(strlen(m.name)<=7)
					{
						fprintf(pr,"%d\t%s\t\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
					}
					else
					{
						fprintf(pr,"%d\t%s\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
					}
				}
				else
				{
					fscanf(ptr,"%d%s%d%s%f%s%s%s",&m.id,&name,&m.age,&m.phone,&m.weight,&m.mem_type,&m.batch,&m.pur);
					uspace(name);
					strcpy(m.name,name);
					clrscr();
					head2();
					printf("The details of the record are : \n");
					printf("ID \t\t: \t%d\nNAME \t\t: \t%s\nPHONE NO.\t: \t%s\nAGE \t\t: \t%d\nWEIGHT \t\t: \t%.2f\nMEMBERSHIP TYPE : \t%s\nBATCH \t\t: \t%s\nGYM PURPOSE \t: \t%s\n",m.id,name,m.phone,m.age,m.weight,m.mem_type,m.batch,m.pur);
					edit_op:
					printf("\nEnter what do you want to edit : \n");
					printf("1.Name\t\t\t2.Age\n3.Phone No.\t\t4.Weight\n5.Membership\t\t6.Batch\n7.Purpose\t\t8.Exit\n");
					printf("\nYour option is : ");
					scanf("%d",&choice);
					clrscr();
					head2();
					switch(choice)
					{
						case 1 :
							v:
							printf("Enter your name : ");
							fflush(stdin);
							gets(na);
							if((strlen(na))<=15)
							{
								change2(na);
								strcpy(m.name,na);
							}
							else
							{
								printf("\n\"INVALID NAME PLEASE ENTER 15 CHARACTER ONLY\"\n");
								goto v;
							}
							break;
						case 2:
							a:
							printf("Enter your age : ");
							scanf("%d",&ag);
							if(ag<12 || ag>70)
							{
								printf("\n\"Invalid age\"\n \n");
								goto a;
							}
							m.age=ag;
							break;
						case 3:
							no:
							printf("Enter your phone no. : ");
							fflush(stdin);
							gets(ph);
							n=strlen(ph);
							if(n==10)
							{
								for(i=0;i<n;i++)
								{
									if(!(ph[i]>='0' && ph[i]<='9'))
									{
										printf("\n\"Invalid number ! please enter 10 digit number \"\n\n");
										goto no;
									}
								}
							}
							else
							{
								printf("\n\"Invalid number ! please enter 10 digit number \"\n\n");
								goto no;
							}
							if(i==n)
								strcpy(m.phone,ph);
							break;
						case 4:
							w:
							printf("Enter your weight : ");
							scanf("%f",&wg);
							if(wg<30 && wg>=150)
							{
								printf("\n\"Invalid weight \"\n\n");
								goto w;
							}
							m.weight=wg;
							break;
						case 5:
							type:
							printf("Choose the type of membership :\n");
							printf("\tPress 1 for Normal\n\tPress 2 for Silver\n\tPress 3 for Gold\n\tPress 4 for Diamond\n");
							printf("Your option is : ");
							scanf("%d",&op);
							switch(op)
							{
								case 1:
									strcpy(m.mem_type,"Normal");
									break;
								case 2:
									strcpy(m.mem_type,"Silver");
									break;
								case 3:
									strcpy(m.mem_type,"Gold");
									break;
								case 4:
									strcpy(m.mem_type,"Diamond");
									break;
								default :
									printf("\n\"Invalid option\"\n\n");
									goto type;
							}
							break;
						case 6:
							time:
							printf("Choose your batch timings : \n");
							printf("\tPress 1 for Morning\n\tPress 2 for Evening\nYour option is : ");
							scanf("%d",&op2);
							switch(op2)
							{
								case 1:
									strcpy(m.batch,"Morning");
									break;
								case 2:
									strcpy(m.batch,"Evening");
									break;
								default :
									printf("\n\"Please enter vaild option\"\n\n");
									goto time;
							}
							break;
						case 7:
							purpose:
							printf("Choose your gym purpose : \n");
							printf("\tPress 1 for weight gain\n\tPress 2 for weight loss \nYour option is : ");
							scanf("%d",&op3);
							switch(op3)
							{
								case 1:
									strcpy(m.pur,"gain");
									break;
								case 2:
									strcpy(m.pur,"loss");
									break;
								default :
									printf("\n\"Please enter vaild option\"\n\n");
									goto purpose;
							}
							break;
						case 8:
							exit();
						default:
							printf("\n\"Please enter vaild option\"\n\n");
							goto edit_op;
					}
					if(strlen(m.name)<=7)
					{
						fprintf(pr,"%d\t%s\t\t%d\t%s\t%.2f\t%s\t%s\t%s\n",id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
					}
					else
					{
						fprintf(pr,"%d\t%s\t%d\t%s\t%.2f\t%s\t%s\t%s\n",id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
					}
				}
			}
			temp=1;
			break;
		}
	}
	if(temp==0)
	{
		printf("\nRecord not found");
		fclose(pr);
		fclose(ptr);
		return 0;
	}
	fclose(pr);
	fclose(ptr);
	pr=fopen("temp_m.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	ptr=fopen("member.txt","w");
	if(ptr==NULL)
	{
		printf("Unable to open file00 ");
		exit();
	}
	rewind(pr);
	for(i=100;i<c;i++)
	{
		fgets(cha,200,pr);
		fputs(cha,ptr);
	}
	fclose(ptr);
	fclose(pr);
	clrscr();
	head2();
	printf("\n\nMember edited");
	sleeping();
	return 0;
}

void view_member()
{
	FILE *ptr;
	char ch;
	memb m;
	ptr=fopen("member.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("ID\tNAME\t\tAGE\tPHONE\t\tWEIGHT\tTYPE\tBATCH\tPURPOSE\n");
	printf("============================================================================\n");
	while(!((ch=getc(ptr))==EOF))
		{
			if(ch=='_')
			{
				ch=' ';
				printf("%c",ch);
			}
			else
			{
				printf("%c",ch);
			}
		}
	fclose(ptr);
}
//1.search
void i_search()
{
	FILE *ptr;
	memb m;
	char name[100];
	int id,temp=0;
	ptr=fopen("member.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("Enter the id of the record you want : ");
	scanf("%d",&id);
	while(1)
	{
		fscanf(ptr,"%d%s%d%s%f%s%s%s",&m.id,&name,&m.age,&m.phone,&m.weight,&m.mem_type,&m.batch,&m.pur);
		uspace(name);
		strcpy(m.name,name);
		if(id==m.id)
		{
			if(strlen(m.name)<=7)
			{
				printf("ID\tNAME\t\tAGE\tPHONE\t\tWEIGHT\tTYPE\tBATCH\tPURPOSE\n");
				printf("============================================================================\n");
				printf("%d\t%s\t\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
			}
			else
			{
				printf("ID\tNAME\t\tAGE\tPHONE\t\tWEIGHT\tTYPE\tBATCH\tPURPOSE\n");
				printf("============================================================================\n");
				printf("%d\t%s\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
			}
			temp=1;
			break;
		}
		if(fgetc(ptr)==EOF)
		{
			break;
		}

	}
	if(temp==0)
	{
		printf("\n\"RECORD NOT FOUND \"\n");
	}
	fclose(ptr);
}
//2.search
void n_search()
{
	FILE *ptr;
	memb m;
	char te[100],name[100];
	int temp=0;
	ptr=fopen("member.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("Enter the Name of the record you want : ");
	fflush(stdin);
	gets(te);
	printf("ID\tNAME\t\tAGE\tPHONE\t\tWEIGHT\tTYPE\tBATCH\tPURPOSE\n");
	printf("============================================================================\n");
	while(1)
	{
		fscanf(ptr,"%d\t%s\t\t%d\t%s\t%f\t%s\t%s\t%s",&m.id,&name,&m.age,&m.phone,&m.weight,&m.mem_type,&m.batch,&m.pur);
		uspace(name);
		strcpy(m.name,name);
		if(fgetc(ptr)==EOF)
		{
			break;
		}
		if((strcmp(te,m.name))==0)
		{
			if(strlen(m.name)<=7)
			{


				printf("%d\t%s\t\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
				printf("============================================================================\n");
			}
			else
			{
				printf("%d\t%s\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
				printf("============================================================================\n");
			}
			temp=1;
		}


	}
	if(temp==0)
	{
		printf("\n\"RECORD NOT FOUND \"\n");
	}
	fclose(ptr);
}
//3.search
void p_search()
{
	FILE *ptr;
	memb m;
	char te[100],name[100];
	int temp=0,op;
	ptr=fopen("member.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	pur:
	printf("Enter the Purpose of the member you want to search : \n");
	printf("\tPress 1 for weight gain\n\tPress 2 for weight loss \nYour option is :  ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			strcpy(te,"gain");
			break;
		case 2:
			strcpy(te,"loss");
			break;
		default :
			printf("\n\"Please enter vaild option\"\n\n");
			getch();
			clrscr();
			head2();
			goto pur;
	}
	clrscr();
	head2();
	printf("ID\tNAME\t\tAGE\tPHONE\t\tWEIGHT\tTYPE\tBATCH\tPURPOSE\n");
	printf("============================================================================\n");
	while(1)
	{

		fscanf(ptr,"%d\t%s\t\t%d\t%s\t%f\t%s\t%s\t%s",&m.id,&name,&m.age,&m.phone,&m.weight,&m.mem_type,&m.batch,&m.pur);
		if(fgetc(ptr)==EOF)
		{
			break;
		}
		uspace(name);
		strcpy(m.name,name);
		if((strcmp(te,m.pur))==0)
		{
			if(strlen(m.name)<=7)
			{

				printf("%d\t%s\t\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
				printf("============================================================================\n");
			}
			else
			{

				printf("%d\t%s\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
				printf("============================================================================\n");
			}
			temp=1;
		}


	}
	if(temp==0)
	{
		printf("\n\"RECORD NOT FOUND \"\n");
	}
	fclose(ptr);
}
int remove_mem()
{
	FILE *ptr,*pr;
	char ch;
	memb m;
	int j,id,id2,cp,temp=0,c,i,id3,choice;
	char ph[15],nam[100],na[100],cha[200];
	int n,op,op2,ex,ag,op3;
	char name[100];
	float wg;
	ptr=fopen("member.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	pr=fopen("temp_m.txt","w");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	c=gen_id()+100;
	printf("Enter the id of the record you want to remove : ");
	scanf("%d",&id);
	rewind(ptr);
	while(1)
	{
		if(getc(ptr)==EOF)
		{
			break;
		}
		fscanf(ptr,"%d",&id2);
		if(id == id2 || id==100)
		{
			rewind(ptr);
			for(i=100;i<c;i++)
			{
				fscanf(ptr,"%d%s%d%s%f%s%s%s",&m.id,&name,&m.age,&m.phone,&m.weight,&m.mem_type,&m.batch,&m.pur);
				if(i!=id)
				{
					if(i>id)
						m.id-=1;
					strcpy(m.name,name);
					if(strlen(m.name)<=7)
					{
						fprintf(pr,"%d\t%s\t\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
					}
					else
					{
						fprintf(pr,"%d\t%s\t%d\t%s\t%.2f\t%s\t%s\t%s\n",m.id,m.name,m.age,m.phone,m.weight,m.mem_type,m.batch,m.pur);
					}
				}
				else
				{
					fprintf(pr,"");
				}
			}
			temp=1;
			break;
		}
	}
	if(temp==0)
	{
		printf("\nRecord not found");
		fclose(pr);
		fclose(ptr);
		return 0;
	}
	fclose(pr);
	fclose(ptr);
	pr=fopen("temp_m.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	ptr=fopen("member.txt","w");
	if(ptr==NULL)
	{
		printf("Unable to open file00 ");
		exit();
	}
	rewind(pr);
	for(i=100;i<c-1;i++)
	{
		fgets(cha,200,pr);
		fputs(cha,ptr);
	}
	fclose(ptr);
	fclose(pr);
	clrscr();
	head2();
	printf("\n\nMember removed");
	sleeping();
	return 0;
}
void feereceipt()
{
	FILE *ptr;
	char name[100];
	int id1,temp=0;
	long amt,famt;
	double gst,total,less;
	memb m;
	ptr=fopen("member.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("Enter the id you want to see reccipt of : ");
	scanf("%d",&id1);
	while(1)
	{

		fscanf(ptr,"%d%s%d%s%f%s%s%s",&m.id,&name,&m.age,&m.phone,&m.weight,&m.mem_type,&m.batch,&m.pur);
		uspace(name);
		strcpy(m.name,name);
		if(m.id==id1)
		{
			in:
			printf("Enter the deposited amount : ");
			scanf("%ld",&amt);
			if(strcmp(m.mem_type,"Normal")==0)
			{
				if(amt<0 || amt>2000)
				{
					printf("\nPlease enter a valid amount (between 0 - 2000) \n\n");
					getch();
					goto in;
				}
				famt=2000;
			}
			else if(strcmp(m.mem_type,"Silver")==0)
			{
				if(amt<0 || amt>5000)
				{
					printf("\nPlease enter a valid amount (between 0 - 5000) \n\n");
					getch();
					goto in;
				}
				famt=5000;
			}
			else if(strcmp(m.mem_type,"Gold")==0)
			{
				if(amt<0 || amt>10000)
				{
					printf("\nPlease enter a valid amount (between 0 - 10000) \n\n");
					getch();
					goto in;
				}
				famt=10000;
			}
			else if(strcmp(m.mem_type,"Diamond")==0)
			{
				if(amt<0 || amt>25000)
				{
					printf("\nPlease enter a valid amount (between 0 - 25000) \n\n");
					getch();
					goto in;
				}
				famt=25000;
			}
			clrscr();
			head2();
			printf("\n\t\tID : %d",m.id);
			printf("\t\tNAME : %s\n\n",m.name);
			printf("\t\t\tMEMBERSHIP TYPE : %s\n",m.mem_type);
			printf("_____________________________________________________________________________\n");
			printf("\t\t\t\tPAYMENT RECEIPT\n\n");
			printf("_____________________________________________________________________________\n");
			printf("GYM FEES AMOUNT  	:  %ld\n",famt);
			gst=(2.5*famt)/100;
			printf("CGST(2.5) 	 	:  %.2lf\n",gst);
			printf("SGST(2.5) 	 	:  %.2lf\n",gst);
			printf("-----------------------------------------------------------------------\n");
			total=famt+gst+gst;
			printf("TOTAL AMOUNT 	 	:  %.2lf\n",total);
			printf("-----------------------------------------------------------------------\n");
			printf("DEPOSITED AMOUNT 	:  %ld\n",amt);
			less=total-amt;
			printf("-----------------------------------------------------------------------\n");
			printf("FINAL PAYABLE AMOUNT 	:  %.2lf\n",less);
			temp=1;
			break;

		}
		if(getc(ptr)==EOF)
		{
			break;
		}
	}
	if(temp==0)
	{
		printf("\n\"Invalid record id\".\nPlease enter valid id.. \n");
	}
	fclose(ptr);
}