#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct Node {
	char elem;
	struct Node *next;
	struct Node *prev;
}Node;
Node* header;
Node* trailer;
Node* getNode() {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void invalid() {
	printf("invalid position\n");
}
void initialize() {
	header = getNode();
	trailer = getNode();
	header->next = trailer;
	trailer->prev = header;
}
void add(int r, char e) {
	Node* a = getNode();
	a->elem = e;
	Node* b = header;
	while (r--) {
		b = b->next;
	}
	a->prev = b->prev;
	a->next = b;
	b->prev->next = a;
	b->prev = a;
}
void delete(int r) {
	Node* b = header;
	while (r--) {
		b = b->next;
	}
	Node* tmp = b;
	b->prev->next = b->next;
	b->next->prev = b->prev;
	free(tmp);
}
char get(int r) {
	Node* b = header;
	while (r--) {
		b = b->next;
	}
	return b->elem;
}
void print() {
	Node* b=header->next;
	while (b!=trailer) {
		printf("%c", b->elem);
		b = b->next;
	}
}
int main() //main() 함수의 시작
{
	initialize();
	int N,r,s=0;
	char c,e;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%c", &c);
		if (c == 'A') {
			scanf("%d %c", &r, &e);
			if (r > s + 1) {
				invalid();
			}
			else {
				add(r, e);
				s++;
			}
		}
		else if (c == 'D') {
			scanf("%d", &r);
			if (r>s) {
				invalid();
			}
			else {
				delete(r);
				s--;
			}
		}
		else if (c == 'G') {
			scanf("%d", &r);
			if (r > s) {
				invalid();
			}
			else {
				printf("%c\n",get(r));
			}
		}
		else if (c == 'P') {
			print();
			printf("\n");
		}
	}
	return 0; //0을 반환
} //main()함수의 끝
