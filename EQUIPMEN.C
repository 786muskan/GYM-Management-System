#include<stdio.h>
#include<conio.h>
#include "head3.c"
#include "uspace2.c"
#include "sleep.c"
typedef struct equipment
{
	char name[100];
	int qty;
	int id;
}equip;
int eq_id()
{
	FILE *ptr;
	char ch;
	int c=0;
	ptr=fopen("eq.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file \n");
		exit();
	}
	while(!((ch=getc(ptr))==EOF))
	{
		if(ch=='\n')
			c++;
	}
	fclose(ptr);
	return c;
}
void add_equipment()
{
	FILE *ptr;
	equip e;
	char na[100];
	int q;
	char te[100],name[100];
	int temp=0;
	ptr=fopen("eq.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	v:
	printf("Enter the name of equipment : ");
	fflush(stdin);
	gets(na);
	while(1)
	{
		fscanf(ptr,"%d%s%d",&e.id,&name,&e.qty);
		convert3(name);
		if((strcmp(name,na))==0)
		{
			temp=1;
			break;
		}
		if(fgetc(ptr)==EOF)
		{
			break;
		}
	}
	fclose(ptr);
	if(temp==0)
	{
		if((strlen(na))<=15)
		{
			change3(na);
			strcpy(e.name,na);
		}
		else
		{
			printf("\n\"INVALID NAME PLEASE ENTER 15 CHARACTER ONLY\"\n");
			goto v;
		}
		quan:
		printf("Enter the quantity of equipment : ");
		scanf("%d",&q);
		if(q<=0 || q>15)
		{
			printf("\n\"Invalid quantity\"\n \n");
			goto quan;
		}
		e.qty=q;
		ptr=fopen("eq.txt","a");
		if(ptr==NULL)
		{
			printf("Unable to open file ");
			exit();
		}
		e.id=eq_id()+100;
		if(e.qty<10)
		{
			if(strlen(e.name)<=7)
			{
				fprintf(ptr,"%d\t\t\t%s\t\t\t\t%d%d\n",e.id,e.name,0,e.qty);
			}
			else
			{
				fprintf(ptr,"%d\t\t\t%s\t\t\t%d%d\n",e.id,e.name,0,e.qty);
			}
		}
		else
		{
			if(strlen(e.name)<=7)
			{
				fprintf(ptr,"%d\t\t\t%s\t\t\t\t%d\n",e.id,e.name,e.qty);
			}
			else
			{
				fprintf(ptr,"%d\t\t\t%s\t\t\t%d\n",e.id,e.name,e.qty);
			}
		}
		fclose(ptr);
		clrscr();
		head3();
		printf("\nEquipment added");
		sleepping();
	}
	else
	{
		printf("\nThis equipment is exsting already \n");
	}
}
int ee_add()
{
	FILE *ptr,*pr;
	equip e;
	int id,qy,temp=0,qu,c,id2,i;
	char name[100],ch[200];
	printf("Enter the id of the equipment whose quantity you want change : ");
	scanf("%d",&id);
	ptr=fopen("eq.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	pr=fopen("temp_e.txt","w");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	c=100+eq_id();
	while(1)
	{
		if(getc(ptr)==EOF)
		{
			break;
		}
		fscanf(ptr,"%d",&id2);
		if(id==id2 || id==100)
		{
			qq:
			printf("Enter the new quantity of equipment : ");
			scanf("%d",&qy);
			if(qy<=0 || qy>15)
			{
				printf("\ninvalid quantity !! Please enter between 1 - 15\n\n");
				goto qq;
			}
			qu=qy;
			rewind(ptr);
			for(i=100;i<=c;i++)
			{
				if(i!=id)
				{
					fscanf(ptr,"%d%s%d",&e.id,&name,&e.qty);
					strcpy(e.name,name);
					if(e.qty<10)
					{
						if(strlen(e.name)<=7)
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t\t%d%d\n",e.id,e.name,0,e.qty);
						}
						else
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t%d%d\n",e.id,e.name,0,e.qty);
						}
					}
					else
					{
						if(strlen(e.name)<=7)
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t\t%d\n",e.id,e.name,e.qty);
						}
						else
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t%d\n",e.id,e.name,e.qty);
						}
					}	
				}
				else 
				{
					fscanf(ptr,"%d%s%d",&e.id,&name,&e.qty);
					strcpy(e.name,name);
					if(qu<10)
					{		
						if(strlen(e.name)<=7)
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t\t%d%d\n",e.id,e.name,0,qu);
						}
						else
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t%d%d\n",e.id,e.name,0,qu);
						}
					}
					else
					{
						if(strlen(e.name)<=7)
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t\t%d\n",e.id,e.name,qu);
						}
						else
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t%d\n",e.id,e.name,qu);
						}
					}	
				}
			}
			temp=1;
			break;
		}
	}
	if(temp==0)
	{
		printf("\nInvalid equipment ID \n");
		fclose(pr);
		fclose(ptr);
		return 0;
	}
	fclose(pr);
	fclose(ptr);
	pr=fopen("temp_e.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file~~ ");
		exit();
	}
	ptr=fopen("eq.txt","w");
	if(ptr==NULL)
	{
		printf("Unable to open file00 ");
		exit();
	}
	rewind(pr);
	for(i=100;i<c;i++)
	{
		fgets(ch,200,pr);
		fputs(ch,ptr);
	}
	fclose(ptr);
	fclose(pr);
	clrscr();
	head3();
	printf("\nEquipment edited");
	sleepping();
	return 0;
}
void view()
{
	FILE *ptr;
	char ch;
	equip e;
	ptr=fopen("eq.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("ID\t\t\tNAME\t\t\t\tQuantity\n");
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
void ie_search()
{
	FILE *ptr;
	equip e;
	char name[100];
	int id,temp=0;
	ptr=fopen("eq.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("Enter the id of the equipment you want to search : ");
	scanf("%d",&id);
	clrscr();
	head3();
	while(1)
	{
		fscanf(ptr,"%d%s%d",&e.id,&name,&e.qty);
		uspace(name);
		strcpy(e.name,name);
		if(id==e.id)
		{
			printf("ID\t\t\tNAME\t\t\t\t  Quantity\n");
			printf("============================================================================\n");
			printf("%d\t\t\t%s\t\t\t\t%d\n",e.id,e.name,e.qty);
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
//search2
void name_search()
{
	FILE *ptr;
	equip e;
	char te[100],name[100];
	int temp=0;
	ptr=fopen("eq.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	printf("Enter the Name of the Equipment you want to search : ");
	fflush(stdin);
	gets(te);
	clrscr();
	head3();
	while(1)
	{
		fscanf(ptr,"%d%s%d",&e.id,&name,&e.qty);
		convert3(name);
		strcpy(e.name,name);
		if(fgetc(ptr)==EOF)
		{
			break;
		}
		if((strcmp(te,e.name))==0)
		{
			printf("ID\t\t\tNAME\t\t\t\tQuantity\n");
			printf("============================================================================\n");
			printf("%d\t\t\t%s\t\t\t\t%d\n",e.id,e.name,e.qty);
			temp=1;
			break;
		}
	}
	if(temp==0)
	{
		printf("\n\"RECORD NOT FOUND \"\n");
	}
	fclose(ptr);
}

int remove_eq()
{
	FILE *ptr,*pr;
	equip e;
	int id,temp=0,c,id2,i;
	char name[100],ch[200];
	printf("Enter the id of the equipment which you want to delete : ");
	scanf("%d",&id);
	ptr=fopen("eq.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	pr=fopen("temp_e.txt","w");
	if(pr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	c=100+eq_id();
	while(1)
	{
		if(getc(ptr)==EOF)
		{
			break;
		}
		fscanf(ptr,"%d",&id2);
		if(id==id2 || id==100)
		{
			rewind(ptr);
			for(i=100;i<=c;i++)
			{
				fscanf(ptr,"%d%s%d",&e.id,&e.name,&e.qty);
				if(i!=id)
				{
					if(i>id)
						e.id-=1;	
					if(e.qty<10)
					{		
						if(strlen(e.name)<=7)
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t\t%d%d\n",e.id,e.name,0,e.qty);
						}
						else
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t%d%d\n",e.id,e.name,0,e.qty);
						}
					}
					else
					{
						if(strlen(e.name)<=7)
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t\t%d\n",e.id,e.name,e.qty);
						}
						else
						{
							fprintf(pr,"%d\t\t\t%s\t\t\t%d\n",e.id,e.name,e.qty);
						}
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
		printf("\nInvalid equipment ID \n");
		fclose(pr);
		fclose(ptr);
		return 0;
	}
	fclose(pr);
	fclose(ptr);
	pr=fopen("temp_e.txt","r");
	if(pr==NULL)
	{
		printf("Unable to open file~~ ");
		exit();
	}
	ptr=fopen("eq.txt","w");
	if(ptr==NULL)
	{
		printf("Unable to open file00 ");
		exit();
	}
	rewind(pr);
	for(i=100;i<c-1;i++)
	{
		fgets(ch,200,pr);
		fputs(ch,ptr);
	}
	fclose(ptr);
	fclose(pr);
	clrscr();
	head3();
	printf("\nEquipment removed");
	sleepping();
	return 0;
}