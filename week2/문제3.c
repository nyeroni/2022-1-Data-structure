#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
int *prefixAverages1(int X[], int n) {
	double sum;
	int* A = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += X[j];
		}
		A[i] = (int)(sum / (i + 1)+0.5);
	}
	return A;
}
int* prefixAverages2(int X[], int n) {
	double sum;
	int* A = (int*)malloc(sizeof(int) * n);
	sum = X[0];
	A[0] = sum;
	for (int i = 1; i < n; i++) {
		sum += X[i];
		A[i] = (int)(sum / (i + 1)+0.5);
	}
	return A;
}
int main() //main() 함수의 시작
{
	int n;
	scanf("%d", &n);
	int* X=(int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &X[i]);
	}
	int *A = (int*)malloc(sizeof(int) * n);
	A=prefixAverages1(X, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	int* B = (int*)malloc(sizeof(int) * n);
	B = prefixAverages2(X, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", B[i]);
	}

	return 0; //0을 반환
} //main()함수의 끝
