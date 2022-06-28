#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
int sum(int n) {
	int total=0;
	for (int i = 1; i <= n; i++) {
		total += i;
	}
	return total;
}
int main() //main() 함수의 시작
{
	int X,total=0;
	scanf("%d", &X);
	for (int i = 1; i <= X; i++) {
		total += sum(i);
	}
	printf("%d", total);

	return 0; //0을 반환
} //main()함수의 끝
