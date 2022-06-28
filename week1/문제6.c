#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct student {
	char name[10];
	int g;
};
int main() //main() 함수의 시작
{
	int total = 0;
	double avg = 0;
	struct student st[5];
	for (int i = 0; i < 5; i++) {
		scanf("%s %d", st[i].name, &st[i].g);
		total += st[i].g;
	}
	avg = (double)total / 5.0;
	for (int i = 0; i < 5; i++) {
		if ((double)st[i].g < avg) {
			printf("%s\n", st[i].name);
		}
	}
	return 0; //0을 반환
} //main()함수의 끝
