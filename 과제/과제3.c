#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h> 
#include<Windows.h>
typedef struct node { //노드 구조체 선언
	int elem;
	struct node* next;
}node;

typedef struct stack { //스택 구조체 선언
	node* top;
}stack;

node* getNode() { //노드 생성
	node* n = (node*)malloc(sizeof(node));
	n->next = NULL;
	return n;
}

void push(stack* s, int e) { // 스택에 입력받은 원소 추가
	node* p = getNode();
	p->elem = e;
	p->next = s->top;
	s->top = p;
}
void pushMillion(stack* s) { //스택에 원소 백만개 임의로 추가
	srand(time(NULL)); //난수를 발생시켜야 하기 때문에 추가
	for (int i = 0; i < 1000000; i++) { //반복문 실행
		int x=rand()%9000+1000; //1000~9999 사이의 난수 발생
		push(s, x); //스택에 추가
	}
}
int pop(stack* s) { //스택으로부터 원소 1개 제거
	int c = s->top->elem;
	node* p = s->top;
	s->top = s->top->next;
	free(p);
	return c;
}
void popMillion(stack* s) { //스택으로부터 원소 백만개 제거
	for (int i = 0; i < 1000000; i++) { //반복문 실행
		pop(s); //스택으로부터 원소 제거
	}
}
int findMin(stack* s) { //스택 원소 중에 최소값 반환
	node* p = s->top;
	int min = p->elem;
	while (p != NULL) { 
		if (p->elem < min) {
			min = p->elem;
		}
		p = p->next;
	}
	return min;
}
int quit(stack*s) { //수행 종료

	while (s->top != NULL) { //스택 값 비우기
		pop(s);
	}
	return 0;
}

int main() //main() 함수의 시작
{
	//시간을 측정하기 위한 변수 선언
	LARGE_INTEGER ticksPerSec; 
	LARGE_INTEGER start, end, diff;

	stack s;
	s.top = NULL;
	char c;
	int a, cnt = 0;
	while (1) { //무한루트 실행
		scanf("%c", &c); 
		if (c == 'p') { //p를 입력받는다면
			scanf("%d", &a);
			getchar();
			//시간 측정 시작
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			push(&s, a); //함수 실행
			QueryPerformanceCounter(&end);
			//시간측정 끝
			cnt++; //스택에 1개 추가했으므로 cnt 1증가
			printf("push %d (%d), ", a, cnt); //추가한 원소와 스택의 크기 출력
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart)*1000); //걸린 시간 출력
		}
		else if (c == 'P') {//P입력받으면
			//시간 측정 시작

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			pushMillion(&s);//함수 실행
			QueryPerformanceCounter(&end);
			//시간측정 끝

			cnt += 1000000;//스택에 백만개 추가했으므로 cnt 백만개 증가
			printf("pushMillion (%d), ", cnt);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);//걸린 시간 출력

		}
		else if (c == 'o') { //o입력받으면
			//시간 측정 시작

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			int p = pop(&s);//함수 실행
			QueryPerformanceCounter(&end);
			//시간측정 끝

			cnt--; //스택으로부터 원소 하나 제거했으므로 cnt값 1감소
			printf("pop %d (%d), ", p, cnt);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);//걸린 시간 출력


		}
		else if (c == 'O') { //O입력받으면
			//시간 측정 시작

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			popMillion(&s); //함수 실행
			QueryPerformanceCounter(&end);
			//시간측정 끝

			cnt -= 1000000; //스택으로부터 원소 백만개 제거하였으므로 cnt값 백만개 감소
			printf("popMillion (%d), ", cnt);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);//걸린 시간 출력

		}
		else if (c == 'f') {//f입력받으면
			//시간 측정 시작

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);
			int min = findMin(&s);//함수 실행
			QueryPerformanceCounter(&end);
			//시간측정 끝

			printf("min %d (%d), ", min,cnt); //스택 내의 최소값과 현재 스택의 크기 출력
			diff.QuadPart = end.QuadPart - start.QuadPart;
			printf("cputime = %.12f\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);//걸린 시간 출력

		}
		else if (c == 'q') { //q를 입력받으면 
			quit(&s);//스택 비우기
			break;//종료
		}
	}

	return 0; //0을 반환
} //main()함수의 끝
