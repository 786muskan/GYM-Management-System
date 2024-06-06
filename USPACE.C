void uspace(char name[100])
{
	int i;
	for(i=0;name[i]!=NULL;i++)
	{
		if(name[i]=='_')
		{
			name[i]=' ';
		}
	}
}
void change2(char name[100])
{
	int i;
	for(i=0;name[i]!=NULL;i++)
	{
		if(name[i]==' ')
		{
			name[i]='_';
		}
	}
}