#include <stdio.h>
int main(void)
{
	int narray[5] = {0}; 
	int nMin,nMax=0;
	int i = 0;
	
	for(i=0;i<5;++i)
		scanf("%d", &narray[i]);
		
	nMin = narray[4];
	nMax = narray[4];
	
	for(i=0;i<4;++i)
 		if(nMin>narray[i])
 			nMin=narray[i];
 			
 	for(i=0;i<4;++i)
 		if(nMax<narray[i])
 			nMax=narray[i];
 	
 	printf("Min:%d, Max:%d",nMin,nMax);
 	return 0;
}
