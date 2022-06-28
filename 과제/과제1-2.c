#pragma warning (disable : 4996) //scanf() 보안 오류를 비활성화
#include<stdio.h>  //헤더파일 포함
#include<string.h>//헤더파일 포함
#include<stdlib.h>//헤더파일 포함
#include<time.h>
#include <Windows.h>
int countOnesButSlow(int **A, int n){
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
int countOnes(int **A, int n) {
	int i = 0, j = 0, c = 0;

	while (i < n) {

		if (A[i][j] == 1 && j < n) {
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
	srand(time(NULL));
	LARGE_INTEGER ticksPerSec1, ticksPerSec2;
	LARGE_INTEGER start1, start2, end1,end2, diff1,diff2;
	int n,ran,onesA=0,onesB=0,onesC=0,a;
	int** A,**B,**C;
	onesA = 0;
	n = 3000;
	A = (int**)malloc(sizeof(int*) * n);
	if (A == NULL) {
		printf("No Enough Memory!!");
		return -1;
	}
	a = n;
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(sizeof(int) * n);
		if (A[i] == NULL) {
			printf("No Enough Memory!!");
			return -1;
		}
		ran = rand() % (a + 1);
		onesA += ran;
		a = (int)(ran * 0.9);
		for (int j = 0; j < ran; j++) {
			A[i][j] = 1;
		}
		if (ran < n || ran == 0) {
			for (int j = ran; j < n; j++) {
				A[i][j] = 0;
			}
		}

	}
	QueryPerformanceFrequency(&ticksPerSec1);
	QueryPerformanceCounter(&start1);
	printf("%d %d ", countOnesButSlow(A, n), onesA);
	QueryPerformanceCounter(&end1);

	diff1.QuadPart = end1.QuadPart - start1.QuadPart;
	printf("%.12f sec\n\n", (double)diff1.QuadPart / (double)ticksPerSec1.QuadPart);

	n = 1000;
	onesB = 0;
	B = (int**)malloc(sizeof(int*) * n);
	if (B == NULL) {
		printf("No Enough Memory!!");
		return -1;
	}
	a = n;
	for (int i = 0; i < n; i++) {
		B[i] = (int*)malloc(sizeof(int) * n);
		if (B[i] == NULL) {
			printf("No Enough Memory!!");
			return -1;
		}
		ran = rand() % (a + 1);
		onesB += ran;
		a = (int)(ran * 0.9);
		for (int j = 0; j < ran; j++) {
			B[i][j] = 1;
		}
		if (ran < n || ran == 0) {
			for (int j = ran; j < n; j++) {
				B[i][j] = 0;
			}
		}

	}
	QueryPerformanceFrequency(&ticksPerSec1);
	QueryPerformanceCounter(&start1);
	printf("%d %d ", countOnesButSlow(B, n), onesB);
	QueryPerformanceCounter(&end1);

	diff1.QuadPart = end1.QuadPart - start1.QuadPart;
	printf("%.12f sec\n\n", (double)diff1.QuadPart / (double)ticksPerSec1.QuadPart);

	n = 2000;
	onesC = 0;
	C = (int**)malloc(sizeof(int*) * n);
	if (C == NULL) {
		printf("No Enough Memory!!");
		return -1;
	}
	a = n;
	for (int i = 0; i < n; i++) {
		C[i] = (int*)malloc(sizeof(int) * n);
		if (C[i] == NULL) {
			printf("No Enough Memory!!");
			return -1;
		}
		ran = rand() % (a + 1);
		onesC += ran;
		a = (int)(ran * 0.9);
		for (int j = 0; j < ran; j++) {
			C[i][j] = 1;
		}
		if (ran < n || ran == 0) {
			for (int j = ran; j < n; j++) {
				C[i][j] = 0;
			}
		}

	}

	QueryPerformanceFrequency(&ticksPerSec1);
	QueryPerformanceCounter(&start1);
	printf("%d %d ", countOnesButSlow(C, n), onesC);
	QueryPerformanceCounter(&end1);

	diff1.QuadPart = end1.QuadPart - start1.QuadPart;
	printf("%.12f sec\n\n", (double)diff1.QuadPart / (double)ticksPerSec1.QuadPart);

	n = 3000;
	QueryPerformanceFrequency(&ticksPerSec2);
	QueryPerformanceCounter(&start2);
	printf("%d %d ", countOnes(A, n), onesA);
	QueryPerformanceCounter(&end2);

	diff2.QuadPart = end2.QuadPart - start2.QuadPart;
	printf("%.12f sec\n\n", (double)diff2.QuadPart / (double)ticksPerSec2.QuadPart);
	for (int i = 0; i < n; i++) {
		free(A[i]);

	}
	n = 1000;
	QueryPerformanceFrequency(&ticksPerSec2);
	QueryPerformanceCounter(&start2);
	printf("%d %d ", countOnes(B, n), onesB);
	QueryPerformanceCounter(&end2);

	diff2.QuadPart = end2.QuadPart - start2.QuadPart;
	printf("%.12f sec\n\n", (double)diff2.QuadPart / (double)ticksPerSec2.QuadPart);

	for (int i = 0; i < n; i++) {
		free(B[i]);
	}
	n = 2000;
	QueryPerformanceFrequency(&ticksPerSec2);
	QueryPerformanceCounter(&start2);
	printf("%d %d ", countOnes(C, n), onesC);
	QueryPerformanceCounter(&end2);

	diff2.QuadPart = end2.QuadPart - start2.QuadPart;
	printf("%.12f sec\n\n", (double)diff2.QuadPart / (double)ticksPerSec2.QuadPart);

	for (int i = 0; i < n; i++) {

		free(C[i]);

	}
	free(A);
	free(B);
	free(C);

	return 0; //0을 반환
} //main()함수의 끝
