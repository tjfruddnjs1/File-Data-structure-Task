#include <stdio.h>
#include <stdlib.h>
#define COUNT 66

int main()
{
	int i, j, k, temp;
	int data[COUNT];
	int run[COUNT], memory[6], frozen[6]; 
	// ������ ũ�� : 6

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
	// ����ִ� ���ۿ� �ڷḦ ä��

	for (i = 0; i < COUNT; i++) {
		if (!frozen[0] && !frozen[1] && !frozen[2] && !frozen[3] && !frozen[4] && !frozen[5]) {  
			for (j = 0; j < 6; j++) frozen[j] = 1;
		}
		// ��� �޸𸮰� ����Ǹ� �ش� run �� �۾��� �����

		temp = INT_MAX;
		for (j = 0; j < 6; j++) {  
			if (!frozen[j]) continue; // ����� ���� ��ü ������� ���� 
			if (temp > memory[j]) {
				temp = memory[j];
				k = j;
			}
		}
		// �޸𸮰��� ���� ���� ���� ���ϴ� ����

		run[i] = memory[k];
		if (i + 6 >= COUNT) {
			frozen[k] = 0;
			continue;
		}
		// ���� �ڷᰡ ������ ������ ũ��(6) ���� ���� �������� ��� ���� ó��

		if (memory[k] > data[i + 6]) { // �����ִ� ������ ������ ���� ó��
			memory[k] = data[i + 6];
			frozen[k] = 0;
		}
		else {
			memory[k] = data[i + 6]; // �ƴ� �� �޸𸮿� ���� ���� �ҷ��� ���ۿ� �־���
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
