#include<stdio.h>
#include<string.h>

int k_letters(const char *string) {
	int count=0,i;
	for (i = 0; string[i] != '\0';) {
		if (string[i] >= 0 && string[i] <= 127) {
			i++;
		}
		else{
			i += 2;
			count++;
		}
	}
	return count;
}

int main() {
	char str[100];
	while (1){
		printf("Enter a sentence with Korean and English letter.\n");
		scanf("%[^\n]s", str);
		getchar();
		if (strcmp(str, "quit") == 0)
			break;
		printf("한글문자는 %d 나옵니다.\n", k_letters(str));

	}
	return 0;
}