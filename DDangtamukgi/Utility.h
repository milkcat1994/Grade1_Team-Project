#include<Windows.h>
#include<stdio.h>
#include<string.h>

/*===============  Ŀ�� ��ġ ���� �Լ�  ===============*/
void SetCurPos2(int x,int y);

/*===============  (char ��³���,int ��ǥ,int ����);  ===============*/
void Better_printf2(const char *str,int x,int y,int color);

void Better_printf_s(char *str,int x,int y,int length);

void Appear2(char *str, int x, int y, int speed, int lastcolor);

void Fade2(char *str, int x, int y, int speed, int firstcolor);