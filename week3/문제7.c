#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
int cnt(char arr[], char s, int n) {
	if (n == 0) {
		return 0;
	}
	else {
		if (*arr == s) {
			return cnt(arr + 1, s, n - 1)+1;
		}
		else {
			return cnt(arr + 1, s, n - 1);
		}
	}
}
int main() //main() 함수의 시작
{
	char s, arr[101];
	int c = 0;
	scanf("%s", arr);
	getchar();
	scanf("%c", &s);
	c = strlen(arr);
	printf("%d", cnt(arr, s,c));
	return 0; //0을 반환
} //main()함수의 끝
