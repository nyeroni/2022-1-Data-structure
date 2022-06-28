#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct Node {
	int e;
	struct Node* next;
	struct Node* prev;
}Node;
typedef struct deque {
	Node* front;
	Node* rear;
}deque;
Node* getNode() {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}
int f = 0, r = 0, N;
int isEmpty(deque*q) {
	if (q->front == NULL)return 1;
	else return 0;
}

void initdeQueue(deque*q) {
	q->front = NULL;
	q->rear = NULL;
}
void add_front(deque* q, int e) {
	Node* p = getNode();
	p->e = e;
	if (isEmpty(q)) {
		q->front = p;
		q->rear = p;
		
	}
	else {
		p->next = q->front;
		q->front->prev = p;
		q->front = p;
	}
}
void add_rear(deque* q, int e) {
	Node* p = getNode();
	p->e = e;
	if (isEmpty(q)) {
		q->front = p;
		q->rear = p;
	}
	else {
		q->rear->next = p;
		p->prev = q->rear;
		q->rear = p;
	}
}
int delete_front(deque* q) {
	int e = q->front->e;
	if (q->front->next == NULL) {
		q->rear = NULL;
	}
	else {
		q->front = q->front->next;
	}
	q->front->prev = NULL;
	return e;
}
int delete_rear(deque* q) {
	int e = q->rear->e;
	if (q->rear->prev == NULL) {
		q->front = NULL;

	}
	else {
		q->rear = q->rear->prev;
	}
	q->rear->next = NULL;
	return e;
}
void print(deque* q) {
	Node* p = q->front;
	while (p != NULL) {
		printf(" %d", p->e);
		p = p->next;
	}
	printf("\n");
}
int main() //main() 함수의 시작
{
	deque q;
	initdeQueue(&q);
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		char arr[3];
		int e;
		scanf("%s", arr);
		if (strcmp(arr, "AF") == 0) {
			scanf("%d", &e);
			add_front(&q, e);
		}
		else if (strcmp(arr, "AR") == 0) {
			scanf("%d", &e);
			add_rear(&q, e);
		}
		else if (strcmp(arr, "DF") == 0) {
			if (isEmpty(&q)) {
				printf("underflow\n");
				break;
			}
			else {
				delete_front(&q);
			}
		}
		else if (strcmp(arr, "DR") == 0) {
			if (isEmpty(&q)) {
				printf("underflow\n");
				break;
			}
			else {
				delete_rear(&q);
			}
		}
		else if (strcmp(arr, "P") == 0) {
			print(&q);
		}
		getchar();
	}
	return 0; //0을 반환
} //main()함수의 끝
