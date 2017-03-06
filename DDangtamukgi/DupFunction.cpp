#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

/*===============  Ŀ�� ��ġ ���� �Լ�  ===============*/
void SetCurPos(int x,int y)
{
	COORD Pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

/*===============  (char ��³���,int ��ǥ,int ����);  ===============*/
void Better_printf(char *str,int x,int y,int color)
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	SetCurPos(x,y);
	printf("%s",str);
}
/*========================= ȭ�� Ŭ���� �Լ� =========================*/
void clrsc (void) 
{   
    for (int i = 0; i<24; i++) { // �ܼ� ȭ���� 24�ٱ������� �̿�
        SetCurPos(0,i);
        printf("%80c",' '); // �ܼ� ������ ĭ�� 80ĭ���� �̿�. ����� �� ��� ���� ����
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

/*==========��Ʈ�� ��ŵ �Լ� =============*/
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
	Better_printf("  ===  ����� �¸��Ͽ����ϴ�  ===  ",22,11,15);
	else
	Better_printf("  ===  ����� �й��Ͽ����ϴ�  ===  ",22,11,12);
	Better_printf("  ===============================  ",22,12,15);
	Better_printf("                                   ",22,13,15);
	if((WhoWin==1)&&(User_Select==TRUE)||(WhoWin==2)&&(User_Select2==TRUE)){
		Better_printf("���ۣ�",31,15,15);
		Better_printf("��",33,16,15);
		Better_printf("��",33,17,15);
	} else { 
		Better_printf("�ۦ���",32,15,15);
		Better_printf("II",32,16,15);
	}
}
