#include<Windows.h>
#include<stdio.h>
#include<string.h>

/*===============  커서 위치 변경 함수  ===============*/
void SetCurPos2(int x,int y)
{
	COORD Pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

/*===============  (char 출력내용,int 좌표,int 색깔);  ===============*/
void Better_printf2(const char *str,int x,int y,int color)
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	if(x>=0 && y>=0)
		SetCurPos2(x,y);
	printf("%s",str);
}

void Better_printf_s(char *str,int x,int y,int length)
{
	char temp[100];
	int i;
	for(i=0;i<length;i++)
	{
		temp[i]=str[i];
	}
	temp[i]='\0';
	SetCurPos2(x,y);
	printf("%s",temp);
}

void Appear2(char *str, int x, int y, int speed, int lastcolor)
{
	int count=0,i,color=0;

	if(speed==0)
		speed=200;

	for(i=0;i<4;i++){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	SetCurPos2(x,y);
	printf("%s",str);
	switch(++count){
	case 1: color=8; break;
	case 2: color=7; break;
	case 3: color=lastcolor;
	}
	Sleep(speed);
	}
}

void Fade2(char *str, int x, int y, int speed, int firstcolor)
{
	int count=0,i,color=firstcolor;

	if(speed==0)
		speed=200;

	for(i=0;i<4;i++){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	SetCurPos2(x,y);
	printf("%s",str);
	count++;
	switch(count){
	case 1: color=7; break;
	case 2: color=8; break;
	case 3: color=0;
	}
	Sleep(speed);
	}
}