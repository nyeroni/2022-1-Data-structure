#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct node { //구조체 선언

	struct node* nextgroup; 
	struct node* nextelement;

	int coupon_num;//쿠폰 번호
	char user_name;//사용자 이름
}Node;
typedef struct list { //구조체 선언
	struct node* header;
}List;
typedef struct Groups { //구조체 선언
	char user_name;
	Node* header;
}Groups;
typedef struct Elements { //구조체 선언
	int coupon_num;
	Node* header;
}Elements;
// NG =5, NE=4로 가정
//가입자 명은 {A, B, C, D, E}
//쿠폰 명은  {1, 2, 3, 4}
Groups groups[5]; //구조체 배열 선언
Elements elements[4]; //구조체 배열 선언

Node* getNode() { //노드 생성 및 초기화
	Node* p = (Node*)malloc(sizeof(Node));  //동적할당
	p->nextgroup = NULL; //초기화
	p->nextelement = NULL;//초기화

	return p; //반환
}
void initShare() { //초기화

	for (int i = 0; i < 4; i++) { //반복문 실행
		List* list = (List*)malloc(sizeof(List)); //구초체 배열 동적 할당
		Node* H = getNode(); //노드생성
		list->header = H;
		list->header->nextgroup = NULL;
		list->header->nextelement = list->header;

		elements[i].header = list->header;
		elements[i].coupon_num = i + 1;
	}
	for (int i = 0; i < 5; i++) { //반복문 실행
		List* list = (List*)malloc(sizeof(List)); //구초체 배열 동적 할당
		Node* H = getNode(); //노드생성
		list->header = H;
		list->header->nextelement = NULL;
		list->header->nextgroup = list->header;

		groups[i].header = list->header;
		groups[i].user_name = i + 'A';
	}
	return;
}
void addShare(int e, char g) { //추가
	Node* p = getNode();
	p->user_name = g;
	p->coupon_num = e;

	p->nextelement = elements[e - 1].header->nextelement;
	elements[e - 1].header->nextelement = p;
	p->nextgroup = groups[g - 'A'].header->nextgroup;
	groups[g - 'A'].header->nextgroup = p;
	printf("OK\n");
}
void removeShare(int e, char g) { //제거

	Node* prev_node = elements[e - 1].header;
	while (1) {
		if ((prev_node->nextelement)->user_name == g) {
			prev_node->nextelement = (prev_node->nextelement)->nextelement;
			break;
		}
		prev_node = prev_node->nextelement;
	}
	prev_node = groups[g - 'A'].header;
	while (1) {
		if ((prev_node->nextgroup)->coupon_num == e) {
			Node* tmp = prev_node->nextgroup;
			prev_node->nextgroup = (prev_node->nextgroup)->nextgroup;
			free(tmp);
			printf("OK\n");
			break;
		}
		prev_node = prev_node->nextgroup;
	}
}
void traverseShareElements(char g) { // 사용자의 쿠폰 번호출력
	Node* node = groups[g - 'A'].header->nextgroup;
	if (node == groups[g - 'A'].header) {//리스트가 비었으면
		printf("0"); //0출력
	}
	else {
		while (node != groups[g - 'A'].header) {
			printf("%d ", node->coupon_num); //사용자가 갖고있는 쿠폰 번호 출력
			node = node->nextgroup;

		}
	}
	printf("\n");
}
void traverseShareGroups(int e) { //쿠폰을 보유한 사용자의 이름 출력
	Node* node = elements[e - 1].header->nextelement;
	if (node == elements[e - 1].header) { //리스트가 비었으면
		printf("0"); //0출력
	}
	else {
		while (node != elements[e - 1].header) {
			printf("%c ", node->user_name); //쿠폰을 갖고있는 사용자 이름 출력
			node = node->nextelement;

		}
	}
	printf("\n");
}
int main() //main() 함수의 시작
{
	int e; //정수 변수 선언
	char cmd, g; //문자 변수 선언
	initShare(); //고객 정보와 쿠폰 번호 
	while (1) { //무한루프 실행
		scanf("%c", &cmd); 
		getchar();
		switch (cmd) {
		case 'a': //추가
			scanf("%d %c", &e, &g);
			addShare(e, g);
			break;
		case 'r': //제거
			scanf("%d %c", &e, &g);
			removeShare(e, g);
			break;
		case'e': //사용자의 쿠폰 번호 출력
			scanf("%c", &g);
			traverseShareElements(g);
			break;
		case'g': //쿠폰을 가진 사용자의 이름 출력
			scanf("%d", &e);
			traverseShareGroups(e);
			break;
		case'q': //종료하라
			return 0; //종료
		}
		getchar();
	}
	return 0; //0을 반환
} //main()함수의 끝
