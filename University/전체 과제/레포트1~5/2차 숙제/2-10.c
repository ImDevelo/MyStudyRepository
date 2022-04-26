/*  < C programing >                                  Day 2019. 03. 20
 Project Title:  Assignment 2. (2-10)
 Contents:
 아래 밑줄부분에 코드를 삽입해서 아스키코드 표를 직접 화면에 찍어 보라.
 단, 특수문자나 공백문자에 대해서는 이상한 문자가 나오거나 아무것도 보
 이지 않더라도 그대로 찍어야 한다.                                   */
 /* #include <stdio.h>

  int main() {
  int i;
  for (i = 0; i<=127; i++)
  ______________________________//여기에 프린트문으로 i값을 찍고 텝을 
                                  삽입할 것
  _______________________________//여기에 해당문자를 찍고 줄 바꿀 것
  }
   return 0;
 }
 */

#include <stdio.h>

int main() {
	int i;
	for (i = 0; i <= 127; i++) {
		printf("%d\t", i);
		printf("%c\n", i);
	}
	return 0;
}