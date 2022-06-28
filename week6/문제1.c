#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct Node {
	int coef,exp;
	struct Node *next;

}Node;
Node* getNode() {
	Node* n = (Node*)malloc(sizeof(Node));
	n->next = NULL;
	return n;
}
Node* appendTerm(Node *k, int c, int e) {
	Node* t = getNode();
	t->coef = c;
	t->exp = e;
	t->next = NULL;
	k->next = t;
	return t;
}
Node* addPoly(Node* x, Node* y) {
	Node* result = getNode();
	result->next = NULL;
	Node *i = x->next;
	Node* j = y->next;
	Node* k = result;
	while ((i != NULL) && (j != NULL)) {
		if (i->exp > j->exp) {
			k=appendTerm(k, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			k = appendTerm(k, j->coef, j->exp);
			j = j->next;
;		}
		else {
			int sum = i->coef + j->coef;
			if (sum != 0) {
				k=appendTerm(k, sum, i->exp);
			}
			i = i -> next;
			j = j->next;
		}

	}
	while (i != NULL) {
		k=appendTerm(k, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL) {
		k=appendTerm(k, j->coef, j->exp);
		j = j->next;
	}
	k = result;
	return k;

}
int main() //main() 함수의 시작
{
	int a, b,c, e;
	Node* head1 = getNode(), * head2 = getNode();
	Node* x=head1, * y=head2;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d %d", &c, &e);
		x = appendTerm(x, c, e);
	}
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		scanf("%d %d", &c, &e);
		y = appendTerm(y, c, e);

	}
	x = head1;
	y = head2;
	Node* result = addPoly(x, y);
	while (result->next != NULL) {
		result = result->next;
		printf(" %d %d", result->coef, result->exp);
	}
	
	return 0; //0을 반환
} //main()함수의 끝
