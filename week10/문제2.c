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
	if (c >= '0' && c <= '9') {
		return 1;
	}
	else {
		return 0;
	}
}
void PUSH(stack* s, char c) {
	node* p = getNode();
	p->elem = c;
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
int result(char* arr) {
	stack s;
	s.top = NULL;
	for (int i = 0; i < strlen(arr); i++) {
		char c = arr[i];
		if (isOperand(c)) {
			PUSH(&s, c);
		}
		else {
			char a = c;
			int x, y,res;
			y = POP(&s) - '0';
			x = POP(&s) - '0';
			if (a == '+') {
				res = x + y;
			}
			else if (a == '-') {
				res = x - y;
			}
			else if (a == '*') {
				res = x * y;
			}
			else if (a == '/') {
				res = x / y;
			}
			PUSH(&s, res + '0');
		}
	}
	return POP(&s) - '0';
}

int main() //main() 함수의 시작
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		char arr[101];
		gets(arr);
		
		printf("%d\n", result(arr));
	}
	return 0; //0을 반환
} //main()함수의 끝
