#include "Intro.h"

void Intro()
{
	CONSOLE_CURSOR_INFO CurInfo; //Ŀ�� ���ֱ�
	clrsc();
    CurInfo.dwSize=1;
    CurInfo.bVisible=FALSE;
	
	BOOL start=FALSE;
	char START;
	while(!start)
	{
		SetCurPos(0,0);
		Better_printf("�����Ա� ����",33,7,12);
		Better_printf("1.  -���� ����-",31,8,15);
		Better_printf("2.   -����-",31,9,15);
		Better_printf("���ϴ� �׸��� ���ڸ� �Է��ϼ���\n",25,10,15);
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

	Better_printf("                       �����Ա�                   ",12,7,12);
	Better_printf("      ���ѵ� TURN �� �ȿ� �� ���� ���� �����ϼ���. ",12,8,15);
	Better_printf("     MiniGame���� �¸��ؾ� ���� ���� �� �� �ֽ��ϴ�.",12,9,15);
	Better_printf("                  <<���� ��� �ȳ�>>",12,11,12);
	Better_printf("  1p�� ����Ű�� �����̰� , 'L'Ű�� ���� ���� �����մϴ�.",12,12,15);
	Better_printf(" 2p�� 'w,a,s,d'�� �����̰� , 'B'Ű�� ���� ���� �����մϴ�.",12,13,15);
	Better_printf("  ���� ������ ��ġ���� ������ �����θ� �̵��� �����մϴ�  ",12,14,15);
	Better_printf("   ��, MiniGame���� �й��� ��� ���� ���� ���� ���մϴ�.   ",12,15,15);
	Better_printf("������ ����� 1p : 'P', 2p : 'V'Ű�� ���� ���� �����մϴ�.",12,16,15);
	Better_printf("             ���ӿ����� ���۹��� �����ϴ�.",12,17,15);
	Better_printf("            �� ���� ���� ������ ����� ����!!",12,18,12);
	Better_printf("                 �� �����̴ٸ� ����!",12,19,15);
		getchar();
		clrsc();
	Better_printf("                   -������ ����-",12,6,15);
	Better_printf("                   �ѹ� ��! ������",12,7,12);
	Better_printf("            ����� �Ұ�� �ڽ��� �ϼ��� �ٿ�",12,8,15);
	Better_printf("        �ѹ� �� �̵��Ͽ� �̴ϰ����� �� �� �ֽ��ϴ�.",12,9,15);
	Better_printf("                  �� �����̴ٸ� ����!",12,11,15);
		getchar();
}

