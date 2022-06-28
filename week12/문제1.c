#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node* getNode() {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* tree() {

	Node* f7 = getNode();
	f7->data = 130;
	Node* f8 = getNode();
	f8->data = 80;
	Node* f6 = getNode();
	f6->data = 120;
	f6->left = f7;
	f6->right = f8;

	Node* f4 = getNode();
	f4->data = 70;
	Node* f5 = getNode();
	f5->data = 90;
	Node* f2 = getNode();
	f2->data = 30;
	f2->left = f4; 
	f2->right = f5;

	Node* f3 = getNode();
	f3->data = 50;
	f3->right = f6;

	Node* f1 = getNode();
	f1->data = 20;
	f1->left = f2; 
	f1->right = f3;

	return f1;
}
int main() //main() 함수의 시작
{
	int n;
	Node* root = tree();
	Node* tmp=NULL;
	scanf("%d", &n);
	if (n >= 1 && n <= 8) {
		if (n == 1) {
			tmp = root;
		}
		else if (n == 2) {
			tmp = root->left;
		}
		else if (n == 3) {
			tmp = root->right;
		}
		else if (n == 4) {
			tmp = root->left->left;
		}
		else if (n == 5) {
			tmp = root->left->right;
		}
		else if (n == 6) {
			tmp = root->right->right;
		}
		else if (n == 7) {
			tmp = root->right->right->left;
		}
		else if (n == 8) {
			tmp = root->right->right->right;
		}
		printf("%d",tmp->data);
		if (tmp->left != NULL) {
			printf(" %d", tmp->left->data);
		}
		if (tmp->right != NULL) {
			printf(" %d", tmp->right->data);
		}
		printf("\n");
	}
	else printf("-1\n");

	return 0; //0을 반환
} //main()함수의 끝
