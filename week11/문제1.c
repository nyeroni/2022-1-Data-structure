#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
int f = 0, r = 0, N;
int isEmpty() {
	return r % N==f;
}
int isFull() {
	return (r + 1) % N == f;
}
void initQueue() {
	f = 0;
	r = N - 1;
}
void enqueue(int Q[], int e) {
	if (isFull()) {
		printf("FULL\n");
	}
	else{
		r = (r + 1) % N;
		Q[r] = e;
	}
}
int dequeue(int Q[]) {
	int e;
	if(isEmpty()) {
		printf("Empty\n");
	}
	else {
		Q[f + 1] = 0;
		e = Q[f];
		f = (f + 1) % N;
		return e;
	}
}
int size() {
	return (N - f + r + 1) % N;
}
int front(int Q[]) {
	if (isEmpty()) {
		printf("Empty\n");
	}
	else {
		return Q[f];
	}
}
void print(int Q[]) {
	for (int i = 0; i < N; i++) {
		printf(" %d", Q[i]);
	}
	printf("\n");
}
int main() //main() 함수의 시작
{
	int* q;
	int n,e;
	char c;
	scanf("%d", &N);
	q = (int*)calloc(N,sizeof(int));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c", &c);
		if (c == 'I') {
			scanf("%d", &e);
			if (isFull()) {
				printf("overflow");
				print(q);
				break;
			}
			enqueue(q, e);
		}
		else if (c == 'D') {
			if (isEmpty()) {
				printf("underflow");
				break;
			}
			dequeue(q);
		}
		else if (c == 'P') {
			print(q);
		}
	}
	return 0; //0을 반환
} //main()함수의 끝
