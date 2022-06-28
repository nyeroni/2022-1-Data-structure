#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
int main() //main() 함수의 시작
{
	int N, X[100],M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int j = 0; j < (b-a)/2+1; j++) {
			int tmp = X[a+j];
			X[a+j] = X[b - j];
			X[b - j] = tmp;
		}
	}
	for (int i = 0; i < N; i++) {
		printf(" %d", X[i]);
	}
	return 0; //0을 반환
} //main()함수의 끝
