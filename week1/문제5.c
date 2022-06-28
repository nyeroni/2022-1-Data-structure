#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
typedef struct time {
	int h, m, s;
};
int main() //main() 함수의 시작
{
	struct time t[3];
	for (int i = 0; i < 2; i++) {
		scanf("%d %d %d", &t[i].h, &t[i].m, &t[i].s);
	}
	if (t[1].s < t[0].s) {
		t[2].s = t[1].s + 60 - t[0].s;
		if (t[1].m > 0) {
			t[1].m--;
		}
		else {
			t[1].m = 59;
		}
	}
	else {
		t[2].s = t[1].s - t[0].s;
	}
	if (t[1].m < t[0].m) {
		t[2].m = t[1].m + 60 - t[0].m;
		t[1].h--;
		
	}
	else {
		t[2].m = t[1].m - t[0].m;
	}
	t[2].h = t[1].h - t[0].h;
	printf("%d %d %d", t[2].h, t[2].m, t[2].s);


	return 0; //0을 반환
} //main()함수의 끝
