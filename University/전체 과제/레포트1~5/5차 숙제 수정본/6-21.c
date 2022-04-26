/* < C programing >                            Day 2019. 04. 11
 Project Title: Assignment 5. (6-21)
 Contents:
 2������ 10������ ��ȯ�ϴ� ���α׷��� �ۼ��϶�.               */
#include<stdio.h>
#include<math.h>
int bin_to_dec(long long);

int main() {
	long long Number;

	printf("Enter a binary number.\n");
	scanf("%lld", &Number);
	printf("The decimal value of binary %lld is %d", Number, bin_to_dec(Number));
	return 0;
}

//2������ 10������ �ٲٴ� �Լ�
int bin_to_dec(long long N) {
	int Zreo_or_one, i, sum = 0, Number_2E;

	for (i = 0; ; i++) {
		Zreo_or_one = N % 10;
		if (N == 1) {
			sum += pow((double)2.0, (double)i);
			break;
		}
		else if (N == 0) {
			break;
		}
		else {
			N /= 10;
			Number_2E = Zreo_or_one * pow((double)2.0, (double)i);
			sum += Number_2E;
		}
	}
	return (int)sum;
}
