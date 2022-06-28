#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		gcd(b, a % b);
	}
}

int main() //main() 함수의 시작
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));
	return 0; //0을 반환
} //main()함수의 끝
