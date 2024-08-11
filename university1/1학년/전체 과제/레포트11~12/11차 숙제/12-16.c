#include<stdio.h>
#include<string.h>

int k_palindrome(const char *string) {
	int i,j=0, first, last;
	char H_str[100];
	char ch1, ch2;

	for (i = 0; string[i] != '\0'; i++)
		if (!(string[i] >= 0 && string[i] <= 127)) {
			H_str[j++] = string[i++];
			H_str[j++] = string[i];
		}

	first = 0, last = j; j = 0;
	for (i = last-1; i >= first; ) {
		if ((H_str[i - 1] != H_str[j])|| (H_str[i] != H_str[j+1]))
			return 0;
		i -= 2; j += 2;

	}
	return 1;
	

}



int main() {

	while (1){
		char str[100];
		int lim;
		printf("한글 문장을 입력하시오.\n");
		gets(str);
		if (strcmp(str, "quit") == 0)
			break;

		lim = k_palindrome(str);
		if (lim)
			printf("네 회문입니다.\n");
		else
			printf("회문이 아닙니다.\n");

		return 0;
	}
}