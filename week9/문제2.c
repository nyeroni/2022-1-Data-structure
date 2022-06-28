#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct node {
	int elem;
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
void PUSH(stack* s, char c) {
	node* p = getNode();
	p->elem = c;
	p->next = s->top;
	s->top = p;

}
char POP(stack* s) {
	char e = s->top->elem;
	node* p = s->top;
	s->top = s->top->next;
	free(p);
	return e;
}

int wrong(char a, char b) {
	if ((a == '(' && b == ')')||( a == '[' && b == ']')|| (a == '{' && b == '}')) {
		return 1;
	}
	else {
		return 0;
	}
}
int balance(char* arr) {
	stack s;
	s.top = NULL;

	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{') {
			PUSH(&s, arr[i]);
		}
		else if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}') {
			if (s.top == NULL) {
				return 0;
			}
			char e = POP(&s);
			if (wrong(e, arr[i]) == 0) {
				return 0;
			}
		}
		
	}
	if (s.top != NULL) {
		return 0;

	}
	else {
		return 1;
	}
}
int main() //main() 함수의 시작
{
	int n = 0;
	char arr[1001];
	gets(arr);
	
	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{'|| arr[i] == ')' || arr[i] == ']' || arr[i] == '}') {
			n++;
		}
	}
	if (balance(arr)==1) {
		printf("OK_%d", n);
	}
	else {
		printf("Wrong_%d", n);
	}

	return 0; //0을 반환
} //main()함수의 끝
