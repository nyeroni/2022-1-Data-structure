#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
int main() //main() 함수의 시작
{
	char a[101];
	gets(a);
	printf("%s\n", a);
	for (int i = 1; i < strlen(a); i++) {
		char tmp = a[0];
		for (int j = 1; j < strlen(a); j++) {
			a[j - 1] = a[j];
		}
		a[strlen(a)-1] = tmp;
		printf("%s\n", a);

	}
	return 0; //0을 반환
} //main()함수의 끝
