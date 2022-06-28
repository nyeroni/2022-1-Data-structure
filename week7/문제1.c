#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct Node {
	int elem;
	struct Node* next;
}Node;
Node* getNode() {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	return newNode;
}
void add(Node *x, int a) {
	Node* p = x;
	while (p->next!=NULL) {
		p = p ->next;
	}
	Node* q = getNode();
	q->elem = a;
	p->next = q;
}
int member(Node* x, int e) {
	Node* p = x;
	int a;
	if (x == NULL)return 0;
	while (1) {
		a = p->elem;
		if (a == e) {
			return 1;
		}
\
		else {
			if (p->next == NULL)break;
			p = p->next;
		}
		
	}
	return 0;
}
int subset(Node* x, Node* y) {
	Node* p = x;
	Node* q = y;
	int min = 99999999;
	if (x == NULL)return 0;
	while (1) {
		if (member(q, p->elem)==0) {
			if (min > p->elem) {
				min = p->elem;
			}
			if (p->next == NULL)break;
			else p = p->next;
		}
		else {
			if (p->next == NULL)return 0;
			else {
				p = p->next;
			}
		}
	}
	return min;
}
int main() //main() 함수의 시작
{
	Node* x = getNode();
	Node* y = getNode();
	int N, M,a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		add(x, a);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		add(y, a);
	}
	if (N == 0)printf("0");
	else {
		printf("%d", subset(x, y));
	}
	return 0; //0을 반환
} //main()함수의 끝
