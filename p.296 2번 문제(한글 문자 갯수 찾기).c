#include <stdio.h>
int main(void)
{
	char narray[32] = {0};
	int i = 0;
	int ncount = 0;
	
	scanf("%s",narray);
	
	while(narray[ncount] != '\0')
	ncount++;
	
	printf("한글 문자의 개수는 %d 입니다.", ncount/2);
	
 	return 0;
}
