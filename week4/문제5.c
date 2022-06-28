#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>

int main() //main() 함수의 시작
{
	int N,M, **X,cnt=1,f=0;
	scanf("%d %d", &N,&M);
	X = (int**)malloc(sizeof(int*) * N);
	if (X == NULL) {
		printf("No enough memory");
		return -1;
	}
	for (int i = 0; i < N; i++) {
		X[i] = (int*)malloc(sizeof(int) * M);
		if (X[i] == NULL) {
			printf("No enough memory");
			return -1;
		}
	}
	while (cnt!=N*M+1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i + j == f) {
					X[i][j] = cnt;
					cnt++;
				}
			}
		}
		f++;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf(" %d", X[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < N; i++) {
		free(X[i]);
	}
	free(X);
	return 0; //0을 반환
} //main()함수의 끝
