#include "Intro.h"

void Intro()
{
	CONSOLE_CURSOR_INFO CurInfo; //커서 없애기
	clrsc();
    CurInfo.dwSize=1;
    CurInfo.bVisible=FALSE;
	
	BOOL start=FALSE;
	char START;
	while(!start)
	{
		SetCurPos(0,0);
		Better_printf("땅따먹기 게임",33,7,12);
		Better_printf("1.  -게임 시작-",31,8,15);
		Better_printf("2.   -도움말-",31,9,15);
		Better_printf("원하는 항목의 숫자를 입력하세요\n",25,10,15);
		while(!start)
		{
			if(_kbhit()){
				START=_getch();
				if(START=='1')
				start=TRUE;
				else if(START=='2'){
				information(); start=TRUE;
				}
			}
		}
	}
		clrsc();
}

void information()
{
	fflush(stdin);
	clrsc();

	Better_printf("                       땅따먹기                   ",12,7,12);
	Better_printf("      제한된 TURN 수 안에 더 많은 땅을 차지하세요. ",12,8,15);
	Better_printf("     MiniGame에서 승리해야 땅을 차지 할 수 있습니다.",12,9,15);
	Better_printf("                  <<게임 방법 안내>>",12,11,12);
	Better_printf("  1p는 방향키로 움직이고 , 'L'키를 눌러 땅을 선택합니다.",12,12,15);
	Better_printf(" 2p는 'w,a,s,d'로 움직이고 , 'B'키를 눌러 땅을 선택합니다.",12,13,15);
	Better_printf("  지금 현재의 위치에서 인접한 땅으로만 이동이 가능합니다  ",12,14,15);
	Better_printf("   단, MiniGame에서 패배할 경우 땅을 차지 하지 못합니다.   ",12,15,15);
	Better_printf("아이템 사용은 1p : 'P', 2p : 'V'키를 눌러 땅을 선택합니다.",12,16,15);
	Better_printf("             게임에서의 조작법도 같습니다.",12,17,15);
	Better_printf("            더 많은 땅을 차지한 사람이 승자!!",12,18,12);
	Better_printf("                 다 읽으셨다면 엔터!",12,19,15);
		getchar();
		clrsc();
	Better_printf("                   -아이템 설명서-",12,6,15);
	Better_printf("                   한번 더! 아이템",12,7,12);
	Better_printf("            사용을 할경우 자신의 턴수를 줄여",12,8,15);
	Better_printf("        한번 더 이동하여 미니게임을 할 수 있습니다.",12,9,15);
	Better_printf("                  다 읽으셨다면 엔터!",12,11,15);
		getchar();
}

