#include <stdio.h>
#include <stdlib.h>
#define COUNT 66

int main()
{
	int i, j, k, temp;
	int data[COUNT];
	int run[COUNT], memory[6], frozen[6]; 
	// 버퍼의 크기 : 6

	printf("66 Input data \n");
	for (i = 0; i < COUNT; i++) {
		scanf_s("%d", &data[i]);
	}

	for (i = 0; i < 6; i++) {
		frozen[i] = 1;
	}

	printf("==================================\n");
	
	 
	for (i = 0; i < 6; i++) {
		memory[i] = data[i];
	}
	// 비어있는 버퍼에 자료를 채움

	for (i = 0; i < COUNT; i++) {
		if (!frozen[0] && !frozen[1] && !frozen[2] && !frozen[3] && !frozen[4] && !frozen[5]) {  
			for (j = 0; j < 6; j++) frozen[j] = 1;
		}
		// 모든 메모리가 동결되면 해당 run 의 작업이 종료됨

		temp = INT_MAX;
		for (j = 0; j < 6; j++) {  
			if (!frozen[j]) continue; // 동결된 값은 대체 선정대상 제외 
			if (temp > memory[j]) {
				temp = memory[j];
				k = j;
			}
		}
		// 메모리값중 가장 작은 수를 구하는 과정

		run[i] = memory[k];
		if (i + 6 >= COUNT) {
			frozen[k] = 0;
			continue;
		}
		// 남는 자료가 없도록 버퍼의 크기(6) 보다 작은 나머지는 모두 동결 처리

		if (memory[k] > data[i + 6]) { // 원래있던 수보다 작으면 동결 처리
			memory[k] = data[i + 6];
			frozen[k] = 0;
		}
		else {
			memory[k] = data[i + 6]; // 아닐 시 메모리에 다음 수를 불러와 버퍼에 넣어줌
		}
	}

	j = 1;
	for (i = 0; i < COUNT; i++) {
		if (i == 0)printf("\n run %d\t: ", j++);
		if (i != 0 && run[i] < run[i - 1]) {
			printf("\n run %d\t: ", j++);
		}
		printf("%d ", run[i]);
	}

	scanf_s("%d", &data[i]);
}
