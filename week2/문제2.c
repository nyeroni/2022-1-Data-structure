#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
int mostOnes(int arr[100][100], int N) {
	int j = 0,cnt=0;
	for (int i = 0; i < N; ) {
		if (arr[i][j] == 1) {
			j++;
			cnt = i;
		}
		else {
			i++;
		}
	}
	return cnt;
}
int main() //main() 함수의 시작
{
	int N, arr[100][100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++){
			scanf("%d", &arr[i][j]);
		}	
	}
	printf("%d", mostOnes(arr, N));
	return 0; //0을 반환
} //main()함수의 끝
