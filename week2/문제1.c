#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
int modulo(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		modulo(a-b, b);
	}

}
int main() //main() 함수의 시작
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));
	return 0; //0을 반환
} //main()함수의 끝
