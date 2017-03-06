#include<Windows.h>
#include<stdio.h>
#include<string.h>

/*===============  커서 위치 변경 함수  ===============*/
void SetCurPos2(int x,int y);

/*===============  (char 출력내용,int 좌표,int 색깔);  ===============*/
void Better_printf2(const char *str,int x,int y,int color);

void Better_printf_s(char *str,int x,int y,int length);

void Appear2(char *str, int x, int y, int speed, int lastcolor);

void Fade2(char *str, int x, int y, int speed, int firstcolor);