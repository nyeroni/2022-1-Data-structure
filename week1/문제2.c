#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
void ABC(int *a, int k) {
	int max = a[k], tmp,j=k;
	for (int i = k; i < 10; i++) {
		if (max < a[i]) {
			max = a[i];
			j=i;
		}
	}
	tmp = a[j];
	a[j] = a[k];
	a[k] = tmp;
}
int main() //main() 함수의 시작
{
	int a[10], s;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &s);
		a[i] = s;
	}
	for (int k = 0; k <10; k++) {
		ABC(a, k);
	}
	for (int i = 0; i < 10; i++) {
		printf(" %d", a[i]);
	}

	return 0; //0을 반환
} //main()함수의 끝
