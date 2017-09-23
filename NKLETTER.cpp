#include <stdio.h>
#include <string.h>
#define max 250
char sb[max],se[max];
int tim (int i)
{
	int j=0;
	while (sb[i]==se[j])
	{
		i++;
		j++;
		if(sb[i]=='\0')
			return j;
	}
	return 0;
}
int NKLETTER ()
{
	int i,n,maxc=-1;
	n=strlen (sb);
	for (i=0;i<n;i++)
	{
		maxc=tim(i);
		if (maxc!=0)
			return maxc;
	}
        return 0;
}
int main ()
{
	int n,m;
	scanf ("%s\n%s",sb,se);
	n=strlen (sb);
	m=strlen (se);
	printf ("%d",n+m-NKLETTER ());
	return 0;
}
