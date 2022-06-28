#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h> 
#include<Windows.h>
typedef struct Node { //노드 구조체 선언
	int e; 
	struct Node* next;
	struct Node* prev;
}Node;
typedef struct deque { //큐 구조체 선언
	Node* front;
	Node* rear;
}deque;
Node* getNode() { //노드생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void initdeQueue(deque* q) { //큐 초기화
	q->front = NULL;
	q->rear = NULL;
}

int isEmpty(deque* q) { //큐가 비었다면
	if (q->front == NULL) {
		return 1; //11리턴
	}
	else {
		return 0; //아니면 0리턴
	}
}
int top(deque* q) { //맨 위에거 불러오기
	int e = q->front->e;
	return e;
}
void push(deque* q, int e) { //큐에 입력받은 원소 추가
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
void pushMillion(deque* q) { //큐에 원소 백만개 임의로 추가
	for (int i = 0; i < 1000000; i++) { //반복문 실행
		int x = rand() % 90 + 10; //1000~9999 사이의 난수 발생
		push(q, x); //스택에 추가
	}
}
int pop(deque* q) { //큐으로부터 원소 1개 제거
	int c = q->rear->e;
	if (q->rear->prev == NULL) {
		q->front = NULL;
	}
	else {
		q->rear = q->rear->prev;
	}
	q->rear->next = NULL;
	return c;
}

int main() //main() 함수의 시작
{
	srand(time(NULL)); //난수를 발생시켜야 하기 때문에 추가

	//시간을 측정하기 위한 변수 선언
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	deque q1, q2; //큐 2개 선언
	initdeQueue(&q1); //큐 초기화
	initdeQueue(&q2); //큐 초기화
	int cnt = 0;//큐에 있는 원수 개수
	char c;
	while (1) { //무한루트 실행
		scanf("%c", &c);//문자 입력
		getchar(); //공백받기
		if (c == 'S') { //S를 입력받았다면
			int em;
			//시간 측정 시작
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			em = isEmpty(&q1);//큐가 비었는지 확인하는 함수 불러오기
			QueryPerformanceCounter(&end);
			//시간측정끝
			if (em) { //큐가 비었다면
				printf("Empty "); //Empty 출력
			}
			else {//비어있지 않았다면
				printf("Nonempty "); //Noempty출력
			}
			printf("(%d), ", cnt);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000); //걸린 시간 출력

		}
		else if (c == 't') {//t를 입력받았다면
			//시간 측정 시작
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			int t = top(&q1); //함수 불러오기
			QueryPerformanceCounter(&end);
			//시간측정 끝
			printf("%d ", t);
			printf("(%d), ", cnt);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000); //걸린 시간 출력

		}
		else if (c == 'p') {//p를 입력받았다면
			double timetotal = 0;
			while (1) { //무한루프 시작
				char a, c;
				int b = 0;
				scanf("%c", &a);//여러 개를 입력받을 수 있도록 문자로 입력
				c = getchar();//공백받기
				if (c == '\n')b = 1;//엔터키를 눌렀다면 b를 1로해줌
				cnt++;//cnt값 1증가
				//시간 측정 시작
				QueryPerformanceFrequency(&ticksPerSec);
				QueryPerformanceCounter(&start);
				push(&q1, a - '0');//큐1에 입력받은 원소 추가하는 함수 호출
				QueryPerformanceCounter(&end);
				//시간측정끝
				diff.QuadPart = end.QuadPart - start.QuadPart;
				timetotal += (((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
				if (b == 1) { //엔터를 받았다면
					b = 0; //b=0으로 전환
					break;//반복문 탈출
				}

			}
			printf("OK "); 
			printf("(%d), ", cnt);

			printf("cputime = %.12f\n", (timetotal)); //걸린 시간 출력

		}
		else if (c == 'P') {//P를 입력받았다면
			//시간 측정 시작
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			pushMillion(&q1);
			QueryPerformanceCounter(&end);
			//시간측정끝
			cnt += 1000000; //cnt값 100만개 추가
			printf("OK (%d), ", cnt);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000); //걸린 시간 출력


		}
		else if (c == 'o') {//o를 입력받았다면
			int em, el;
			//시간 측정 시작
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			em = isEmpty(&q1);//큐가 비었는지 검사하는 함수 호출
			QueryPerformanceCounter(&end);
			//시간측정끝
			if (isEmpty(&q1)) {//큐가비어있다면
				printf("Empty Stack Exception!! ");//출력
				printf("(%d), ", cnt);
				diff.QuadPart = end.QuadPart - start.QuadPart;
				printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000); //걸린 시간 출력
			}
			else {//큐가 비어있지 않다면
				for (int i = 0; i < cnt - 1; i++) {//반복문 실행으로 1개 빼고 다 다른 큐로 옮김
					push(&q2, pop(&q1));
				}
				//시간측정 시작
				QueryPerformanceFrequency(&ticksPerSec);
				QueryPerformanceCounter(&start);
				el = pop(&q1);//pop호출로 남은 하나 제거
				QueryPerformanceCounter(&end);
				//시간증정끝
				printf("%d ", el);//제거한 원소 출력
				for (int i = 0; i < cnt - 1; i++) {//반복문 호출로 다시 큐1으로 원소 옮기기
					push(&q1, pop(&q2));
				}

				cnt--;//cnt1감소
				printf("(%d), ", cnt);
				diff.QuadPart = end.QuadPart - start.QuadPart;
				printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000); //걸린 시간 출력


			}
		}
		else if (c == 'q') {//q를 입력받았다면

			break;//종료
		}

	}
	return 0; //0을 반환
} //main()함수의 끝
