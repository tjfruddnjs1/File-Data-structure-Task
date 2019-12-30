#include <stdio.h>

int main(void)
{
	int ninput,i = 0;
	
	scanf("%d", &ninput);
	
	if(ninput>=2 &&  ninput<=9)
	{
	
		while(i<9)
		{
			i++;
			printf("%d * %d = %d", ninput, i, ninput*i);
			putchar('\n');
		}
	}
	else
	printf("ERROR");
	
	return 0;
}
