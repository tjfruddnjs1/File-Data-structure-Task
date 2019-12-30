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

// 스택 초기화 함수
void init(StackType *s) {
	s->top = -1;
}

// 포화 상태 검출 함수
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 공백 상태 검출 함수
int is_empty(StackType *s) {
	return (s->top == -1);
}

// 삽입 함수
void push(StackType *s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

// 삭제 함수
element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

// 피크 함수
element peek(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[s->top];
}


//후위 표기 수식 계산 함수
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

//연산자의 우선순위 반환
int prec(char op) {
	switch (op) {
	case'(':case')': return 0;
	case'+':case'-': return 1;
	case'*':case'/': return 2;
	}
	return -1;
}

//중위 표기 수식 → 후위 표기 수식
void infix_to_postfix(char exp[]) {
	int i = 0;
	int j = 0;
	char ch, top_op;
	StackType s;
	init(&s); 	// 스택 초기화                    

	for (i = 0; i < strlen(exp); i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':	//연산자
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				data[j++] = pop(&s);
			}
			push(&s, ch);
			break;
		case '(':		//왼쪽 괄호
			push(&s, ch);
			break;
		case ')':		//오른쪽 괄호 
			top_op = pop(&s);
			// 왼쪽 괄호를 만날 때까지 출력
			while (top_op != '(') {
				data[j++] = top_op;
				top_op = pop(&s);
			}
			break;
		default:           // 피연산자
			data[j++] = ch;
			break;
		}
	}
	while (!is_empty(&s))
		data[j++] = pop(&s);
}

int main(void) {

	int result;
	printf("중위표기식: ");
	scanf("%s", word);
	infix_to_postfix(word);
	printf("\n후위표기식: %s\n", data);
	result = eval(data);
	printf("\n결과값: %d\n", result);
	system("pause");
	return 0;
}