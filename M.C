//NORMAL MEMBERSHIP
void normal()
{
	FILE *ptr;
	char ch;
	ptr=fopen("normal.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	while(!((ch=getc(ptr))==EOF))
		{
			printf("%c",ch);
		}
	fclose(ptr);
}
//SILVER MEMBERSHIP
void silver()
{
	FILE *ptr;
	char ch;
	ptr=fopen("silver.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	while(!((ch=getc(ptr))==EOF))
		{
			printf("%c",ch);
		}
	fclose(ptr);
}
//GOLD MEMBERSHIP
void gold()
{
	FILE *ptr;
	char ch;
	ptr=fopen("gold.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	while(!((ch=getc(ptr))==EOF))
		{
			printf("%c",ch);
		}
	fclose(ptr);
}
//DIAMOND MEMBERSHIP
void diamond()
{
	FILE *ptr;
	char ch;
	ptr=fopen("diamond.txt","r");
	if(ptr==NULL)
	{
		printf("Unable to open file ");
		exit();
	}
	while(!((ch=getc(ptr))==EOF))
		{
			printf("%c",ch);
		}
	fclose(ptr);
}