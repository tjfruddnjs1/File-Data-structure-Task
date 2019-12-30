#include <stdio.h>
#define COUNT 66
int array_data[COUNT];

int main()
{
	int i, j, k, key;
	int run;
	int record;
	int count = 0;
	int array_run[6][11] = { 0, };
	printf("66 Input data \n");
	for (i = 0; i < COUNT; i++) {
		scanf_s("%d", &array_data[i]);
		// 데이터 입력
	}
	printf("=================================================\n");
	for (run = 0, record = 0; run < 6; run++) {
		printf("run %d : ", run + 1);

		while (array_data[count] != NULL && record != 11) {
			array_run[run][record] = array_data[count];
			count = count + 1;
			record = record + 1;
		}
		// 해당 run의 record값 하나씩 넣어주는 과정 
		for (j = 1; j < 11; j++) {
			key = array_run[run][j];
			for (k = j - 1; k >= 0 && array_run[run][k] > key; k--) {
				array_run[run][k + 1] = array_run[run][k];
			}
			array_run[run][k + 1] = key;
		}
		// 삽입 정렬을 이용한 레코드 오름차순 정렬	

		for (record = 0; record < 11; record++) {
			printf("%4d", array_run[run][record]);
		}
		// run에 해당하는 record값 각 run별 출력
		printf("\n");
		record = 0;



	}
	scanf_s("%d", &array_data);
}
