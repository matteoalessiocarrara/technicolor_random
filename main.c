#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
unsigned short verifica(unsigned char *s,unsigned char c)
{
	unsigned short n;
	while(*s)
		if(*(s++)==c)
			n++;
	return n;
}
bool controlla(unsigned char *s,unsigned char *c,unsigned short start,unsigned short end,unsigned short q)
{
	bool t=1;
	for(unsigned short i=start;i!=end;i++)
     	if(verifica(s,*(c+i))>q)
		{
			t=0;
			break;
		}
	return t;
}
void genera(unsigned char *s,unsigned char *c)
{
	for(unsigned short i=0;i!=10;i++)
     	*(s+i)=*(c+rand()%+16);
}
void main()
{
	unsigned char s[11]="XXXXXXXXXX\0",c[17]="0123456789ABCDEF\0";
	srand(time(NULL));
	while(1)
	{
     	genera(s,c);
		if(controlla(s,c,0,10,2)&&controlla(s,c,10,16,3))
      		printf("%s\n",s);	
	}
}