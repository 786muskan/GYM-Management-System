void space(char name[100])
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
void change(char name[100])
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