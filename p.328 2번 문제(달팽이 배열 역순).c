#include <stdio.h>
int main(void)
{
	int array[5][5] = {0};
	int x=5, y=0, nlength=9;
	int i=0, j=0, ncount=0, ndirection=1;
	
	for(nlength=9;nlength>0;nlength-=2)
		{
			for(i=0;i<nlength;i++)
			{
				if(i<nlength/2 +1) x-=ndirection;
				else			   y+=ndirection;
				array[y][x] = ++ncount;
			}
			ndirection = -ndirection;
		}
	
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)	
		printf("%d\t", array[i][j]);
	putchar('\n');
	}
	
return 0;	
}
