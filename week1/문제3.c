#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
void swap(int* pa, int* pb) {
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
int main() //main() 함수의 시작
{
	int N,c[50],a,b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &c[i]);
	}
	scanf("%d %d", &a, &b);
	swap(c + a, c + b);
	for (int i = 0; i < N; i++) {
		printf(" %d", c[i]);
	}

	return 0; //0을 반환
} //main()함수의 끝
