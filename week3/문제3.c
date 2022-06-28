#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
void divi(int N) {
	if (N < 10) {
		printf("%d\n", N);
		
	}
	else {
		printf("%d\n", N%10);
		divi(N / 10);
	}
}
int main() //main() 함수의 시작
{
	int N;
	scanf("%d", &N);
	divi(N);
	return 0; //0을 반환
} //main()함수의 끝
