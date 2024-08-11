#include<stdio.h>
#include<string.h>

// strcpy 구현 재귀함수
char *my_strcpy(char *dest, const char *src, int index) {
	if (src[index] == '\0') {
		dest[index] = '\0';
		return dest;
	}
	else {
		dest[index] = src[index];
		my_strcpy(dest, src, ++index);
	}
}


int main() {
	char dest[40],src[40];
	//입력
	printf("Enter destination string.\n");
	gets(dest);
	printf("Enter source string.\n");
	gets(src);
	//출력
	puts(my_strcpy(dest, src, 0));
	return 0;
}