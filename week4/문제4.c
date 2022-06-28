#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>

int main() //main() 함수의 시작
{
	int N,M, **X,a=0,b=0;
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
	int p = M,f=0,l=N-1,k=M-1;
	for (int i = 1; i <= M * N; i++) {
		X[a][b] = i;
		if (i == p) {
			f++;
			if (f % 2 == 0) {
				p += k;
				k--;
			}
			else {
				p += l;
				l--;
			}
		}
		if (f % 4 == 0)b++;
		else if (f % 4 == 1)a++;
		else if (f % 4 == 2)b--;
		else a--;


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
