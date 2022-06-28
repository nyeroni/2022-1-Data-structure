#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct student {
	char name[8];
	int ko,en,ma;
	double avg;
};
int main() //main() 함수의 시작
{
	int N,total=0;
	scanf("%d", &N);
	struct student* st;
	st = (struct student*)malloc(sizeof(struct student) * N);
	if (st == NULL) {
		printf("No Enough Memory!");
		return -1;
	}
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d %d", st[i].name, &st[i].ko, &st[i].en, &st[i].ma);
		total = st[i].ko + st[i].en + st[i].ma;
		st[i].avg = (double)total / 3.0;
	}
	for (int i = 0; i < N; i++) {
		printf("%s %.1f ", st[i].name, st[i].avg);
		if (st[i].ma >= 90 || st[i].en >= 90 || st[i].ko >= 90) {
			printf("GREAT ");
		}
		if (st[i].ma < 70 || st[i].en <70 || st[i].ko <70) {
			printf("BAD ");
		}
		printf("\n");
	}

	return 0; //0을 반환
} //main()함수의 끝
