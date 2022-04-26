/* < C programing >                               Day 2019. 06. 06
 Project Title: Assignment 12. (13-9)
 Contents: 전자시계를 만들어라                                   */
#include<stdio.h>
#include<time.h>
#include<Windows.h>

int main() {
	struct tm* struct_ptr;
	while (1){
		system("CLS");
		time_t now = time(NULL);
		struct_ptr = localtime(&now);
		printf("%02d:%02d:%02d", struct_ptr->tm_hour, struct_ptr->tm_min, struct_ptr->tm_sec);
		Sleep(1000);
	}
	return 0;
}