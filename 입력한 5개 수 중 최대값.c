#include <stdio.h>

int main (void)
{
	int ninput, nMax = 0;
	scanf("%d", &ninput);
	
	if(ninput<0) ninput = 0;
	else if (ninput>100) ninput = 100;
	
	nMax = ninput;
	
	scanf("%d", &ninput);
	
	if(ninput<0) ninput = 0;
	else if (ninput>100) ninput = 100;
	
	if(nMax<ninput)
	nMax = ninput;
	
	scanf("%d", &ninput);
	
	if(ninput<0) ninput = 0;
	else if (ninput>100) ninput = 100;
	
	if(nMax<ninput)
	nMax = ninput;
	
	scanf("%d", &ninput);
	
	if(ninput<0) ninput = 0;
	else if (ninput>100) ninput = 100;
	
	if(nMax<ninput)
	nMax = ninput;
	
	scanf("%d", &ninput);
	
	if(ninput<0) ninput = 0;
	else if (ninput>100) ninput = 100;
	
	if(nMax<ninput)
	nMax = ninput;
	
	printf("%d", nMax);
	return 0;
}
