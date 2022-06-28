#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct Node {
	int elem;
	struct Node* next;
}Node;
typedef struct Stack {
	struct Node* top;
}Stack;
Node* getNode() {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	return newNode;
}
void PUSH(Stack* s, char c) {
	Node* p = getNode();
	p->elem = c;
	p->next = s->top;
	s->top = p;
}
char POP(Stack* s) {
	char c = s->top->elem;
	Node* p = s->top;
	s->top = s->top->next;
	free(p);
	return c;
}
char PEEK(Stack* s) {
	return s->top->elem;
}
void DUP(Stack* s) {
	char c = POP(s);
	PUSH(s, c);
	PUSH(s, c);
}
void UpR(Stack* s, int n) {
	Node* p = s->top;
	Node* q = s->top;
	s->top = s->top->next;
	for (int i = 0; i < n-1; i++) {
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
}
void DownR(Stack* s, int n) {
	Node* p = s->top;
	for (int i = 0; i < n - 2; i++) {
		p = p->next;
	}
	Node* q = p->next;
	p->next = q->next;
	q->next = s->top;
	s->top = q;
}
void PRINT(Stack* s) {
	Node* p = s->top;
	while (p != NULL) {
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}
int main() //main() 함수의 시작
{
	Stack s;
	s.top = NULL;
	int N,M,p=0;
	scanf("%d", &N);
	scanf("%d", &M);
	getchar();
	for (int i = 0; i < M; i++) {
		char str[101],c;
		int n;
		scanf("%s",str);
		if (strcmp(str, "PUSH") == 0) {
			getchar();
			scanf("%c", &c);
			if (p== N) {
				printf("Stack FULL\n");
			}
			else {
				PUSH(&s, c);
				p++;
			}
		}
		else if (strcmp(str, "POP") == 0) {
			if (p == 0)printf("Stack Empty\n");
			else {
				POP(&s);
				p--;
			}
		}
		else if (strcmp(str, "PEEK") == 0) {
			if (p  ==0) {
				printf("Stack Empty\n");
			}
			else {
				printf("%c\n",PEEK(&s));
			}
		}
		else if (strcmp(str, "DUP") == 0) {
			if (p == N) {
				printf("Stack Full\n");
			}
			else {
				DUP(&s);
				p++;
			}
		}
		else if (strcmp(str, "UpR") == 0) {
			scanf("%d", &n);
			if (p >=n) {
				UpR(&s, n);
			}
		}
		else if (strcmp(str, "DownR") == 0) {
			scanf("%d", &n);
			if (p >= n) {
				DownR(&s, n);
			}
		}
		else if (strcmp(str, "PRINT") == 0) {
			PRINT(&s);
		}
		getchar();
	}
	return 0; //0을 반환
} //main()함수의 끝
