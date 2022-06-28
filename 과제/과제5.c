#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 
#include<math.h>
#include<time.h>

typedef struct Node { //노드 구조체 선언
	char elem[100];

	struct Node* left; 
	struct Node* right;
}Node;
Node* getNode() { //노드생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
//외부노드 생성 
//외부노드에 도달하면 그 노드 내용 사용자에게 제시하고 프로그램 종료
Node* makeExternalNode() {
	Node* v = getNode();//노드생성
	printf("Enter decision:");
	//질문입력
	gets(v->elem);


	v->left = NULL;
	v->right = NULL;
	return v; //노드반환
}
//내부노드 생성
Node* makeInternalNode() {
	Node* v = getNode();//노드생성
	printf("Enter question:");
	//질문 입력
	gets(v->elem);
	printf("Question if yes to \'%s\'",v->elem);
	printf("?");
	char answer[4]; //yes or no 대답입력
	scanf("%s", answer);
	getchar();//엔터키받기

	if (strcmp(answer, "yes") == 0) { //yes입력했다면
		v->left = makeInternalNode(); //내부노드 생성
	}
	else{//no입력했다면
		v->left = makeExternalNode();//외부노드 생성 , 외부노드 도다랗면 그 노드 내용 사용자에게 제시하고 프로그램 종료
	}
	printf("Question if no to \'%s\'", v->elem);
	printf("?");

	char answer2[4];
	scanf("%s", answer2);  //yes or no 대답입력
	getchar();//엔터키받기

	if (strcmp(answer2, "yes") == 0) {//yes입력했다면
		v->right = makeInternalNode(); //내부노드 생성
	}
	else {//no입력했다면
		v->right = makeExternalNode();//외부노드 생성 , 외부노드 도다랗면 그 노드 내용 사용자에게 제시하고 프로그램 종료
	}
	return v;//노드반환
}
Node* buildDecisionTree() { //결정트리 생성
	printf("***Let's build a dichotomous QA system\n");
	return makeInternalNode(); //내부노드 생성하는 함수 호출
}
void processNode(Node* v) { //사용자가 답을 하며 결정트리를 내부노드들을 거쳐 내려감
	printf("%s", v->elem);//질문 출력
	if (v->right != NULL &&v->left!=NULL) { //노드가 끝나기 전까지
		char answer[4];
		scanf("%s", answer); //대답입력

		if (strcmp(answer, "yes") == 0) {//yes를 대답했다면
			processNode(v->left); //왼쪽노드로 이동하며 재귀함수 호출-> 반복
		}
		else {//no를 입력햇다면
			processNode(v->right);//오른쪽노드로 이동하며 재귀함수 호출-> 반복
		}
	}
	printf("\n");

}
void runDecisionTree(Node *v) {//processNode호출함수
	printf("***Please answer questions\n");
	processNode(v);
}

int main() //main() 함수의 시작
{
	Node* v = buildDecisionTree(); //결정트리 생성
	printf("Tree complete. Now Running!!\n"); //사용자가 입력을 시작하라고 알림

	for (int i = 0; i < 3; i++) {//3회 반복
		runDecisionTree(v); //runDecisionTree(v) 호출하여 사용자가 결정트리에서 대답을 하며 내부노드를 통해 내려옴
	}
	
	
	return 0; //0을 반환

} //main()함수의 끝
