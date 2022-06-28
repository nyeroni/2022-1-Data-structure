#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct student {
	char name[10];
	int g;
};
int main() //main() 함수의 시작
{
	int N;
	int* a=NULL,*b=NULL,*c=NULL;
	scanf("%d", &N);
	a = (int*)malloc(sizeof(int) * N);
	if (a == NULL) {
		printf("No Enough Memory!");
		return -1;
	}
	b = (int*)malloc(sizeof(int) * N);
	if (b == NULL) {
		printf("No Enough Memory!");
		return -1;
	}	
	c = (int*)malloc(sizeof(int) * N);
	if (c == NULL) {
		printf("No Enough Memory!");
		return -1;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < N; i++) {
		c[i] = a[i] + b[N - i - 1];
	}
	for (int i = 0; i < N; i++) {
		printf(" %d", c[i]);
	}
	return 0; //0을 반환
} //main()함수의 끝
