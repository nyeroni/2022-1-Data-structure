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

Node* union1(Node* A, Node* B) {
	Node* p = A;
	Node* q = B;
	if ((p == NULL) && (q == NULL)) {
		return 0;
	}
	Node* C = getNode();
	if (p == NULL) {
		C->elem = q->elem;
		C->next = union1(p, q->next);
	}
	else if (q == NULL) {
		C->elem = p->elem;
		C->next = union1(p->next,q);
	}
	else {
		if (p->elem < q->elem) {
			C->elem = p->elem;
			C->next = union1(p->next, q);
		}
		else if (p->elem > q->elem) {
			C->elem = q->elem; 
			C->next= union1(p, q->next);
		}
		else {
			C->elem = p->elem;
			C->next = union1(p->next, q->next);
		}
	}
	return C;

}
Node* intersect(Node* A, Node* B) {
	Node* p = A;
	Node* q = B;
	if ((p == NULL) || (q == NULL)) {
		return 0;
	}
	if (p->elem < q->elem) {
		return intersect(p->next, q);
	}
	else if(p->elem>q->elem) {
		return intersect(p, q->next);
	}
	else {
		Node* C = getNode();
		C->elem = p->elem;
		C->next = intersect(p->next, q->next);
		return C;
	}
}
void print(Node* x) {
	Node* p = x;
	if (p == NULL)printf("0\n");
	else {
		while (p->next!=NULL) {
			p = p->next;
			printf(" %d", p->elem);

		}
		printf("\n");
	}
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
	if (N == 0 && M == 0) {
		printf(" 0\n");
	}
	else print(union1(x, y));
	if (N == 0 || M == 0) {
		printf(" 0\n");
	}
	else {
		print(intersect(x, y));
	}
	return 0; //0을 반환
} //main()함수의 끝
