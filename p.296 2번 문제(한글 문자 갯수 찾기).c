#include <stdio.h>
int main(void)
{
	char narray[32] = {0};
	int i = 0;
	int ncount = 0;
	
	scanf("%s",narray);
	
	while(narray[ncount] != '\0')
	ncount++;
	
	printf("�ѱ� ������ ������ %d �Դϴ�.", ncount/2);
	
 	return 0;
}
