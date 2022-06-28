#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>

void rhanoi(int N, char from, char aux, char to) {
	if (N == 1) {
		printf("%c %c\n", from, to);
	}
	else {
		rhanoi(N - 1, from, to, aux);
		printf("%c %c\n", from, to);
		rhanoi(N - 1, aux, from, to);
	}
}

int main() //main() 함수의 시작
{
	int N;
	char from='A', aux='B', to='C';
	scanf("%d", &N);
	rhanoi(N, from, aux, to);
	return 0; //0을 반환
} //main()함수의 끝
