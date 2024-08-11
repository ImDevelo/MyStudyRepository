/* < C programing >                           Day 2019. 05. 02
 Project Title: Assignment 7. (8-15)
 Contents: 예제 8-22의 프로그램 연산 경과시간을 출력하라    */
#include<stdio.h>
#include<time.h>

//피고나치수열 함수
long long fid(long long n) {
	if (n < 3)
		return 1;
	else
		return ((long long)(fid(n - 1) + fid(n - 2)));
}

int main() {
	long long num, result;
	clock_t start, end;//시작점과 종료점 설정
	printf("Enter a number N.\n");
	scanf("%lld", &num);

	start = clock();//시작
	result = fid(num);
	end = clock();//종료
	printf("%lld th fibonacci number is %lld.\n", num, result);
	printf("Time elapsed for fibonacci is %.3f second\n", (float)(end - start) / CLOCKS_PER_SEC);// (시작-종료)시간 출력
	return 0;
}