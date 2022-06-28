#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct node {
	char elem;
	int flag;
	struct node* next;
}node;

typedef struct stack {
	node* top;
}stack;

node* getNode() {
	node* n = (node*)malloc(sizeof(node));
	n->next = NULL;
	return n;
}
int isOperand(char c) {
	if (c >= 'A' && c <= 'Z') {
		return 1;
	}
	else {
		return 0;
	}
}
void PUSH(stack* s, char c, int a) {
	node* p = getNode();
	p->elem = c;
	p->flag = a;
	p->next = s->top;
	s->top = p;

}
char POP(stack* s) {
	char c = s->top->elem;
	node* p = s->top;
	s->top = s->top->next;
	free(p);
	return c;
}

char PEEK(stack* s) {
	return s->top->elem;
}
int rank(char c, int a) {
	if (a == 1 && (c == '!' || c == '+' || c == '-')) {
		return 6;
	}
	else if (c == '*' || c == '/') {
		return 5;
	}
	else if (c == '+' || c == '-') {
		return 4;
	}
	else if (c == '>' || c == '<') {
		return 3;
	}
	else if (c == '&') {
		return 2;
	}
	else if (c == '|') {
		return 1;
	}
	else {
		return 0;
	}
}
char* convert(char* arr) {
	stack s;
	s.top = NULL;
	int flag = 0, j = 0;
	char* x = (char*)malloc(sizeof(char) * (strlen(arr) + 1));
	for (int i = 0; i < strlen(arr); i++) {
		flag=0;
		if (!isOperand(arr[i - 1]) && arr[i - 1] != ')') {
			flag = 1;
		}
		if (isOperand(arr[i])) {
			x[j] = arr[i];
			j++;
		}
		else if (arr[i] == '(') {
			PUSH(&s, arr[i], flag);
		}
		else if (arr[i] == ')') {
			while (PEEK(&s) != '(') {
				x[j] = POP(&s);
				j++;
			}
			POP(&s);
		}
		else {
			while (s.top != NULL && rank(arr[i], flag) <= rank(PEEK(&s), s.top->flag)) {
				x[j] = POP(&s);
				j++;
			}
			PUSH(&s, arr[i], flag);
			if (arr[i] == '&' || arr[i] == '|') {
				PUSH(&s, arr[i], flag);
				i++;
			}
		}
	}
	while (s.top != NULL) {
		x[j] = POP(&s);
		j++;
	}
	return x;
}
int main() //main() 함수의 시작
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		char arr[101];
		gets(arr);
		char* x;
		x = convert(arr);
		for (int j = 0; j < strlen(x); j++) {
			printf("%c", x[j]);
		}
		printf("\n");
	}

	return 0; //0을 반환
} //main()함수의 끝
