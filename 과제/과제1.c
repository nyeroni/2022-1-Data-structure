#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
//#include <Windows.h>
int countOnesButSlow(int A[][100], int n){
	int c = 0;

	for (int i = 0; i < n; i++) {
		int j = 0;
		while(j < n && A[i][j] == 1) {
			c += 1;
			j += 1;
		}
	}
	return c;
}
int countOnes(int A[][100], int n) {
	int i = 0, j = 0,c=0;
	while (i<n) {
		if (A[i][j] == 1 && j<n) {
			c++;
			j++;
		}
		else {
			j = 0;
			i++;
		}
	}
	return c;
}
int main() //main() 함수의 시작
{
	//LARGE_INTEGER ticksPerSec1, ticksPerSec2;
	//LARGE_INTEGER start1, start2, end1,end2, diff1,diff2;
	int n, A[100][100];
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
/*	QueryPerformanceFrequency(&ticksPerSec1);
	QueryPerformanceCounter(&start1);
	printf("%d\n", countOnesButSlow(A, n));
	QueryPerformanceCounter(&end1);

	diff1.QuadPart = end1.QuadPart - start1.QuadPart;
	printf("%.12f sec\n\n",(double)diff1.QuadPart / (double)ticksPerSec1.QuadPart);

	QueryPerformanceFrequency(&ticksPerSec2);
	QueryPerformanceCounter(&start2);
	printf("%d\n", countOnes(A, n));
	QueryPerformanceCounter(&end2);

	diff2.QuadPart = end2.QuadPart - start2.QuadPart;
	printf("%.12f sec\n\n", (double)diff2.QuadPart / (double)ticksPerSec2.QuadPart);
*/
	printf("%d\n", countOnesButSlow(A, n));

	printf("%d\n", countOnes(A, n));


	return 0; //0을 반환
} //main()함수의 끝
