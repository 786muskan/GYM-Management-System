void convert3(char name[100])
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
void change3(char name[100])
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