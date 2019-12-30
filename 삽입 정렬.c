#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 30
char word[MAX_STACK_SIZE];
char data[MAX_STACK_SIZE];
typedef char element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

// ���� �ʱ�ȭ �Լ�
void init(StackType *s) {
	s->top = -1;
}

// ��ȭ ���� ���� �Լ�
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s) {
	return (s->top == -1);
}

// ���� �Լ�
void push(StackType *s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

// ���� �Լ�
element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

// ��ũ �Լ�
element peek(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[s->top];
}


//���� ǥ�� ���� ��� �Լ�
int eval(char exp[]) {
	int op1, op2, value = 0;
	char ch;
	StackType s;
	init(&s);
	for (int i = 0; i < strlen(exp); i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

//�������� �켱���� ��ȯ
int prec(char op) {
	switch (op) {
	case'(':case')': return 0;
	case'+':case'-': return 1;
	case'*':case'/': return 2;
	}
	return -1;
}

//���� ǥ�� ���� �� ���� ǥ�� ����
void infix_to_postfix(char exp[]) {
	int i = 0;
	int j = 0;
	char ch, top_op;
	StackType s;
	init(&s); 	// ���� �ʱ�ȭ                    

	for (i = 0; i < strlen(exp); i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':	//������
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				data[j++] = pop(&s);
			}
			push(&s, ch);
			break;
		case '(':		//���� ��ȣ
			push(&s, ch);
			break;
		case ')':		//������ ��ȣ 
			top_op = pop(&s);
			// ���� ��ȣ�� ���� ������ ���
			while (top_op != '(') {
				data[j++] = top_op;
				top_op = pop(&s);
			}
			break;
		default:           // �ǿ�����
			data[j++] = ch;
			break;
		}
	}
	while (!is_empty(&s))
		data[j++] = pop(&s);
}

int main(void) {

	int result;
	printf("����ǥ���: ");
	scanf("%s", word);
	infix_to_postfix(word);
	printf("\n����ǥ���: %s\n", data);
	result = eval(data);
	printf("\n�����: %d\n", result);
	system("pause");
	return 0;
}