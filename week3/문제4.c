#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
int max1(int *a, int N) {
	int max = *a;
	if (N == 1) {
		return max;
	}
	else {
		if (max <= *(a+1)) {
			max = *(a+1);
		}
		*(a + 1) = max;
		max1(a+1, N-1);
	}
}
int main() //main() 함수의 시작
{
	int N,*a;
	scanf("%d", &N);
	a = (int*)malloc(sizeof(int) * N);
	if (a == NULL) {
		printf("No enough memory");
		return -1;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d", max1(a, N));
	return 0; //0을 반환
} //main()함수의 끝
