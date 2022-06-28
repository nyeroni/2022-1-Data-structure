#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>

int main() //main() 함수의 시작
{
	int N, X[100],M,Y[100],tmp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	scanf("%d", &M);
	
	for (int i = 0; i < M; i++) {
		scanf("%d", &Y[i]);
	}
	tmp = X[Y[0]];
	for (int i = 0; i < M-2; i++) {
		X[Y[M-i-1]] = X[Y[M-i-2]];
	}
	X[Y[1]] = tmp;
	for (int i = 0; i < N; i++) {
		printf(" %d", X[i]);
	}
	return 0; //0을 반환
} //main()함수의 끝
