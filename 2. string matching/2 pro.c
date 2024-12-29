#include<stdio.h>
#include<stdlib.h>
char STR[100], PAT[50], REP[50], ANS[100];
int Pattern_Match_Replace()
{
int i=0;
int c=0, m=0;
int k=0;
int flag=0;
int j=0;
while(STR[c]!='\0')
{
if(STR[m]==PAT[i])
{
i++;
m++;
if(PAT[i]=='\0')
{
flag=1;
k=0;
while(REP[k]!='\0')
{
ANS[j++]=REP[k++];
}
i=0;
c=m;
}
}
else
{
ANS[j++]=STR[c++];
m=c;
i=0;
}
}
ANS[j]='\0';
return flag;
}
int main()
{
printf("\nenter the main string:\n");
gets(STR);
printf("\nenter the pattern\n");
gets(PAT);
printf("\nenter the replacement\n");
gets(REP);
if(Pattern_Match_Replace())
printf("\nThe resultant string : %s\n", ANS);
else
printf("\nPattern not found");
return 0;
}
