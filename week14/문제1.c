#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함

typedef struct Node { //노드 구조체 선언
	int data; 
	struct Node* left;
	struct Node* right;
}Node;
Node* getNode() { //노드생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* find(Node* p, int x) {
	if (p != NULL) {
		if (p->data == x) {
			return p;
		}
		Node* q = NULL;
		q = find(p->left, x);
		if (q != NULL) {
			return q;
		}
		q = find(p->right, x);
		if (q != NULL) {
			return q;
		}
	}
	return NULL;
}
void maketree(Node* root) {
	Node* p = root;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x,y,z;
		scanf("%d %d %d", &x, &y, &z);
		if (i == 0) {
			p->data = x;
			if (y != 0) {
				p->left = getNode();
				p->left->data = y;
			}
			if (z != 0) {
				p->right = getNode();
				p->right->data = z;
			}
		}
		else {
			Node* q = find(p, x);
			if (y != 0) {
				q->left = getNode();
				q->left->data = y;
			}
			if (z != 0) {
				q->right = getNode();
				q->right->data = z;
			}
		}
	}
}
void search(Node* root) {
	Node* p = root;
	int N;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		char str[101];
		p = root;

		scanf("%s", str);
		getchar();

		int length = strlen(str);
		for (int j = 0; j <= length; j++) {
			printf(" %d", p->data);
			if (str[j] == 'L') {
				p = p->left;
			}
			else if (str[j] == 'R') {
				p = p->right;
			}
		}
		printf("\n");
	}
}
int main() //main() 함수의 시작
{
	Node* root = getNode();
	maketree(root);
	search(root);

	return 0; //0을 반환
} //main()함수의 끝
