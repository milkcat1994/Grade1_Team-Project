#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

/*===============  커서 위치 변경 함수  ===============*/
void SetCurPos(int x,int y)
{
	COORD Pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

/*===============  (char 출력내용,int 좌표,int 색깔);  ===============*/
void Better_printf(char *str,int x,int y,int color)
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	SetCurPos(x,y);
	printf("%s",str);
}
/*========================= 화면 클리어 함수 =========================*/
void clrsc (void) 
{   
    for (int i = 0; i<24; i++) { // 콘솔 화면이 24줄까지임을 이용
        SetCurPos(0,i);
        printf("%80c",' '); // 콘솔 가로의 칸이 80칸임을 이용. 참고로 안 띄면 실행 에러
    }
    
}

void Appear(char *str, int x, int y, int speed, int lastcolor)
{
	int count=0,i,color=0;

	if(speed==0)
		speed=200;

	for(i=0;i<4;i++){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	SetCurPos(x,y);
	printf("%s",str);
	switch(++count){
	case 1: color=8; break;
	case 2: color=7; break;
	case 3: color=lastcolor;
	}
	Sleep(speed);
	}
}

void Fade(char *str, int x, int y, int speed, int firstcolor)
{
	int count=0,i,color=firstcolor;

	if(speed==0)
		speed=200;

	for(i=0;i<4;i++){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	SetCurPos(x,y);
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

/*==========인트로 스킵 함수 =============*/
int IntroSkip(int num)
{
	if( _kbhit())
		num=0;
	return num;
}
void ShowResult(int WhoWin, BOOL User_Select, BOOL User_Select2)
{
	Better_printf("                                   ",22,9,15);
	Better_printf("  ===============================  ",22,10,15);
	if((WhoWin==1)&&(User_Select==TRUE)||(WhoWin==2)&&(User_Select2==TRUE))
	Better_printf("  ===  당신이 승리하였습니다  ===  ",22,11,15);
	else
	Better_printf("  ===  당신은 패배하였습니다  ===  ",22,11,12);
	Better_printf("  ===============================  ",22,12,15);
	Better_printf("                                   ",22,13,15);
	if((WhoWin==1)&&(User_Select==TRUE)||(WhoWin==2)&&(User_Select2==TRUE)){
		Better_printf("＼○／",31,15,15);
		Better_printf("│",33,16,15);
		Better_printf("ル",33,17,15);
	} else { 
		Better_printf("○┬ㄴ",32,15,15);
		Better_printf("II",32,16,15);
	}
}
