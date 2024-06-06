#include<stdio.h>
#include "heading.c"
#include "space.c"
#include "sleept.c"
typedef struct trainer
{
	char t_name[100];
	int t_age;
	char t_type[50];
	char t_phone[15];
	char t_batch[50];
	int exp;
	int id;
}trainer;

int g_id()
{
	FILE *pr;
	char ch;
	int c=0;
	pr=fopen("trainer.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file \n");
		exit();
	}
	ch=getc(pr);
	while(!(ch==EOF))
	{
		ch=getc(pr);
		if(ch=='\n')
			c++;
	}
	fclose(pr);
	return c;
}
void add_trainer()
{
	FILE *pr;
	trainer t;
	char ph[15],nam[100];
	int i,n,op,op2,ex,ag;
	pr=fopen("trainer.txt","a");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	t.id=100+g_id();
	v:
	printf("Enter your name : ");
	fflush(stdin);
	gets(nam);
	if((strlen(nam))<=15)
	{
		change(nam);
		strcpy(t.t_name,nam);
	}
	else
	{
		printf("\n\"INVALID NAME PLEASE ENTER 15 CHARACTER ONLY\"\n");
		goto v;
	}
	a:
	printf("Enter your age : ");
	scanf("%d",&ag);
	if(ag<20 || ag>65)
	{
		printf("\n\"Invalid age \"\n\n");
		goto a;
	}
	t.t_age=ag;
	clrscr();
	head();
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
				printf("\n\"Invalid number ! please enter 10 digit number\"\n\n");
				goto no;
			}
		}
	}
	else
	{
		printf("\n\"Invalid number ! please enter 10 digit number\" \n\n");
		goto no;
	}
	if(i==n)
		strcpy(t.t_phone,ph);
	clrscr();
	head();
	x:
	printf("Enter your experience : ");
	scanf("%d",&ex);
	if(ex<0 || ex>45)
	{
		printf("\n\"INVALID VALUE\"\n\n");
		goto x;
	}
	t.exp=ex;
	type:
	printf("Choose the type of trainer you are:\n");
	printf("Press 1 for Normal\nPress 2 for Star\nPress 3 for Elite\n");
	printf("Your option is : ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			if(t.exp<5)
			{
				strcpy(t.t_type,"Normal");
			}
			else
			{
				printf("\n\"Your experience and type doesn`t match\"\n\n");
				goto type;
			}
			break;
		case 2:
			if(t.exp>=5)
			{
				strcpy(t.t_type,"Star");
			}
			else
			{
				printf("\n\"Your experience and type doesn`t match\"\n\n");
				goto type;
			}
			break;
		case 3:
			if(t.exp>=10)
			{
				strcpy(t.t_type,"Elite");
			}
			else
			{
				printf("\n\"Your experience and type doesn`t match\"\n\n");
				goto type;
			}
			break;
		default :
			printf("\n\"Invalid option\"\n\n");
			goto type;
	}
	clrscr();
	head();
	time:
	printf("Choose your batch timings : \n");
	printf("Press 1 for Morning\tPress 2 for Evening\nYour option is : ");
	scanf("%d",&op2);
	switch(op2)
	{
		case 1:
			strcpy(t.t_batch,"Morning");
			break;
		case 2:
			strcpy(t.t_batch,"Evening");
			break;
		default :
			printf("\n\"Please enter vaild option\" \n\n");
			goto time;
	}
	if(strlen(t.t_name)<=7)
	{
		fprintf(pr,"%d\t%s\t\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
	}
	else
	{
		fprintf(pr,"%d\t%s\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
	}
	fclose(pr);
	clrscr();
	head();
	printf("\n\nTrainer edited");
	sleepingt();

}
void view_trainer()
{
	FILE *pr;
	char ch;
	trainer t;
	pr=fopen("trainer.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("ID\tNAME\t\tAGE\tPHONE\t\tExperience(Y)\tTYPE\tBATCH\n");
	printf("============================================================================\n");
	while(!((ch=getc(pr))==EOF))
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
	fclose(pr);
}
void id_search()
{
	FILE *pr;
	char ch;
	trainer t;
	int id,temp=0;
	char name[100];
	pr=fopen("trainer.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("Enter the id of the record you want : ");
	scanf("%d",&id);
	while(1)
	{
		fscanf(pr,"%d%s%d%s%d%s%s",&t.id,&name,&t.t_age,&t.t_phone,&t.exp,&t.t_type,&t.t_batch);
		uspace(name);
		strcpy(t.t_name,name);
		if(id==t.id)
		{

			if(strlen(t.t_name)<=7)
			{
				printf("ID\tNAME\t\tAGE\tPHONE\t\tExperience(Y)\tTYPE\tBATCH\n");
				printf("============================================================================\n");
				printf("%d\t%s\t\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
			}
			else
			{
				printf("ID\tNAME\t\tAGE\tPHONE\t\tExperience(Y)\tTYPE\tBATCH\n");
				printf("============================================================================\n");
				printf("%d\t%s\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
			}
			temp=1;
			break;
		}
		if(fgetc(pr)==EOF)
		{
			break;
		}

	}
	if(temp==0)
	{
		printf("\n\"RECORD NOT FOUND \"\n");
	}
	fclose(pr);
}
void na_search()
{
	FILE *pr;
	trainer t;
	char te[100],name[100];
	int temp=0;
	pr=fopen("trainer.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("Enter the Name of the record you want : ");
	fflush(stdin);
	gets(te);
	printf("ID\tNAME\t\tAGE\tPHONE\t\tExperience(Y)\tTYPE\tBATCH\n");
	printf("============================================================================\n");
	while(1)
	{
		fscanf(pr,"%d%s%d%s%d%s%s",&t.id,&name,&t.t_age,&t.t_phone,&t.exp,&t.t_type,&t.t_batch);
		uspace(name);
		strcpy(t.t_name,name);
		if(fgetc(pr)==EOF)
		{
			break;
		}
		if((strcmp(te,t.t_name))==0)
		{
		       if(strlen(t.t_name)<=7)
			{


				printf("%d\t%s\t\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
				printf("============================================================================\n");
			}
			else
			{


				printf("%d\t%s\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
				printf("============================================================================\n");
			}
			temp=1;
		}


	}
	if(temp==0)
	{
		printf("\n\"RECORD NOT FOUND \"\n");
	}
	fclose(pr);
}
void t_search()
{
	FILE *pr;
	trainer t;
	char te[100],name[100];
	int temp=0,op;
	pr=fopen("trainer.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	ty:
	printf("Choose the type of trainer you want to search :\n");
	printf("Press 1 for Normal\nPress 2 for Star\nPress 3 for Elite\n");
	printf("Your option is : ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			strcpy(te,"Normal");
			break;
		case 2:
			strcpy(te,"Star");
			break;
		case 3:
			strcpy(te,"Elite");
			break;
		default :
			printf("\n\"Please enter vaild option\"\n\n");
			getch();
			clrscr();
			head();
			goto ty;
	}
	clrscr();
	head();
	printf("ID\tNAME\t\tAGE\tPHONE\t\tExperience(Y)\tTYPE\tBATCH\n");
	printf("============================================================================\n");
	while(1)
	{

		fscanf(pr,"%d%s%d%s%d%s%s",&t.id,&name,&t.t_age,&t.t_phone,&t.exp,&t.t_type,&t.t_batch);
		uspace(name);
		strcpy(t.t_name,name);
		if(fgetc(pr)==EOF)
		{
			break;
		}

		if((strcmp(te,t.t_type))==0)
		{
			if(strlen(t.t_name)<=7)
			{
				printf("%d\t%s\t\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
				printf("============================================================================\n");

			}
			else
			{
				printf("%d\t%s\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
				printf("============================================================================\n");

			}
			temp=1;
		}


	}
	if(temp==0)
	{
		printf("\n\"RECORD NOT FOUND \"\n");
	}
	fclose(pr);
}
int edit_trainer1()
{
	FILE *ptr,*pr;
	char ch;
	trainer t;
	int j,id,id2,cp,temp=0,c,i,id3,choice;
	char ph[15],nam[100],phone[11],cha[100];
	int n,op,op2,ex,ag;
	char name[100];
	ptr=fopen("trainer.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	pr=fopen("temp.txt","w");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	c=100+g_id();	
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
					fscanf(ptr,"%d%s%d%s%d%s%s",&t.id,&name,&t.t_age,&t.t_phone,&t.exp,&t.t_type,&t.t_batch);
				//uspace(name);
					strcpy(t.t_name,name);
					if(strlen(t.t_name)<=7)
					{
						fprintf(pr,"%d\t%s\t\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
					}
					else
					{
						fprintf(pr,"%d\t%s\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
					}
				}
				else
				{
					fscanf(ptr,"%d%s%d%s%d%s%s",&t.id,&name,&t.t_age,&t.t_phone,&t.exp,&t.t_type,&t.t_batch);
					space(name);	
					strcpy(t.t_name,name);
					clrscr();
					head();
					printf("The details of the record are : \n");
					printf("ID \t\t: \t%d\nNAME \t\t: \t%s\nPHONE NO.\t: \t%s\nAGE \t\t: \t%d\nExperience \t: \t%d\nTrainer TYPE \t: \t%s\nBATCH \t\t: \t%s\n",t.id,t.t_name,t.t_phone,t.t_age,t.exp,t.t_type,t.t_batch);
					edit_opt:
					printf("\nEnter what do you want to edit : \n");
					printf("1.Name\t\t\t2.Age\n3.Phone No.\t\t4.Experience\n5.Type\t\t\t6.Batch\n7.Exit\n");
					printf("\nYour option is : ");
					scanf("%d",&choice);
					clrscr();
					head();
					switch(choice)
					{
						case 1:
							v:
							printf("Enter your name : ");
							fflush(stdin);
							gets(nam);
							if((strlen(nam))<=15)
							{
								change(nam);
								strcpy(t.t_name,nam);
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
							if(ag<20 || ag>65)
							{
								printf("\n\"Invalid age \"\n\n");
								goto a;
							}
							t.t_age=ag;
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
										printf("\n\"Invalid number ! please enter 10 digit number\"\n\n");
										goto no;
									}
								}
							}
							else
							{
								printf("\n\"Invalid number ! please enter 10 digit number\" \n\n");
								goto no;
							}
							if(i==n)
								strcpy(t.t_phone,ph);
							break;
						case 4: 
							x:
							printf("Enter your experience : ");
							scanf("%d",&ex);
							if(ex<0 || ex>45)
							{
								printf("\n\"INVALID VALUE\"\n\n");
								goto x;
							}
							t.exp=ex;
							break;
						case 5:
							type:
							printf("Choose the type of trainer you are:\n");
							printf("Press 1 for Normal\nPress 2 for Star\nPress 3 for Elite\n");
							printf("Your option is : ");
							scanf("%d",&op);
							switch(op)
							{
								case 1:
									if(t.exp<5)
									{
										strcpy(t.t_type,"Normal");
									}
									else
									{
										printf("\n\"Your experience and type doesn`t match\"\n\n");
										goto type;
									}
									break;
								case 2:
									if(t.exp>=5)
									{
										strcpy(t.t_type,"Star");
									}
									else
									{
										printf("\n\"Your experience and type doesn`t match\"\n\n");
										goto type;
									}
									break;
								case 3:
									if(t.exp>=10)
									{
										strcpy(t.t_type,"Elite");
									}
									else
									{
										printf("\n\"Your experience and type doesn`t match\"\n\n");
										goto type;
									}
									break;
								default :
									printf("\n\"Invalid option\"\n\n");
									goto type;
							} 
							break;
						case 6:
							time:
							printf("Choose your batch timings : \n");
							printf("Press 1 for Morning\tPress 2 for Evening\nYour option is : ");
							scanf("%d",&op2);
							switch(op2)
							{
								case 1:
									strcpy(t.t_batch,"Morning");
									break;
								case 2:
									strcpy(t.t_batch,"Evening");
									break;
								default :
									printf("\n\"Please enter vaild option\" \n\n");
									goto time;
							}
							break;
						case 7:
							exit();
						default:
							printf("\nInvalid option \n");
							goto edit_opt;
					}
					if(strlen(t.t_name)<=7)
					{
						fprintf(pr,"%d\t%s\t\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
					}
					else
					{
						fprintf(pr,"%d\t%s\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
					}
				}
			}
			temp=1;
			break;
		}
	}
	if(temp==0)
	{
		printf("Record not found");
		fclose(pr);
		fclose(ptr);
		return 0;
	}
	fclose(pr);
	fclose(ptr);
	pr=fopen("temp.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	ptr=fopen("trainer.txt","w");
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
	head();
	printf("\n\nTrainer edited");
	sleepingt();
	return 0;
}

int remove_trainer()
{
	FILE *ptr,*pr;
	char ch;
	trainer t;
	int j,id,id2,cp,temp=0,c,i,id3,choice;
	char ph[15],nam[100],phone[11],cha[100];
	int n,op,op2,ex,ag;
	char name[100];
	ptr=fopen("trainer.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	pr=fopen("temp.txt","w");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	c=100+g_id();	
	printf("Enter the id of the record you want to remove: ");
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
				fscanf(ptr,"%d%s%d%s%d%s%s",&t.id,&name,&t.t_age,&t.t_phone,&t.exp,&t.t_type,&t.t_batch);
				if(i!=id)
				{
					if(i>id)
						t.id-=1;
					strcpy(t.t_name,name);
					if(strlen(t.t_name)<=7)
					{
						fprintf(pr,"%d\t%s\t\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
					}
					else
					{
						fprintf(pr,"%d\t%s\t%d\t%s\t%d\t\t%s\t%s\n",t.id,t.t_name,t.t_age,t.t_phone,t.exp,t.t_type,t.t_batch);
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
		printf("Record not found");
		fclose(pr);
		fclose(ptr);
		return 0;
	}
	fclose(pr);
	fclose(ptr);
	pr=fopen("temp.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	ptr=fopen("trainer.txt","w");
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
	head();
	printf("\n\nTrainer removed");
	sleepingt();
	return 0;
}
