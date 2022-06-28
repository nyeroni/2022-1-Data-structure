#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
int sum(int N) {
	if (N == 1) {
		return N;
	}
	else {
		return N + sum(N - 1);
	}
}
int main() //main() 함수의 시작
{
	int N;
	scanf("%d", &N);
	printf("%d", sum(N));
	
	return 0; //0을 반환
} //main()함수의 끝
