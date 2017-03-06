#include"MiniGame1.h"

char SRP[][5]={"����","����","��"};

enum SRP {S=100,R,P};		//S:����	R:����	P:��

int whoIsPlayer;

int SRPGame(BOOL User_Select, BOOL User_Select2)
{

	BOOL bUserChoice=FALSE;

	int player;
	int i;
	int eNow=S;
	int eTemp=R;
	int eComSel;
	char cInput;
	BOOL ComMove=FALSE;
	int WhoWin=0;
	clock_t t;
	if(User_Select==TRUE)
		player=1;
	else if(User_Select2==TRUE)
		player=2;
	whoIsPlayer = player;

	CONSOLE_CURSOR_INFO CurInfo; //Ŀ�� ���ֱ�
    CurInfo.dwSize=1;
    CurInfo.bVisible=FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
	clrsc();

	DrawMinigame();

	
	Better_printf("\t\t\t\t\t",23,10,NULL);
	UserSelect(&eNow,&eTemp);

	Better_printf("VS",39,10,15);

	do{	bUserChoice=FALSE;						//do{} while(!WhoWin)  -  ���ڰ� �������� �� Ż��(���º� �� ���ð��� �ݺ�)
	while(!bUserChoice){						//��ǻ�Ϳ� ������� ���ð���, ������ ���ÿϷ� �� Ż��
		ComSelect();
		if(User_Select==TRUE){
		if( _kbhit() )
		{
			eTemp=eNow;
			cInput = _getch();

			switch( cInput ){
			case LEFT:
					if(eNow!=S) 
					eNow-=1;
					break;
			case RIGHT:
					if(eNow!=P) 
					eNow+=1;
					break;
			case 'l':						//Enter Ű�� ����� ���� ���� �Ϸ�
				MessageBeep(MB_OK);
				bUserChoice=TRUE;				//���� ���� �Ϸ�
			}
			UserSelect(&eNow,&eTemp);
		}
		}
		else if(User_Select2==TRUE){
			if( _kbhit() )
		{
			eTemp=eNow;
			cInput = _getch();

			switch( cInput ){
			case 'a':
					if(eNow==S) break;
					eNow-=1;
					break;
			case 'd':
					if(eNow==P) break;
					eNow+=1;
					break;
			case 'b':						//Enter Ű�� ����� ���� ���� �Ϸ�
				MessageBeep(MB_OK);
				bUserChoice=TRUE;				//���� ���� �Ϸ�
			}
			UserSelect(&eNow,&eTemp);
		}
		}
	}
	
	ShowSelImage(eComSel=ComSelect(),2);
	if(eNow!=eComSel){
		if(User_Select==TRUE)
			( (eNow==eComSel+1) || (eNow==eComSel-2) ) ? ( WhoWin=1 ) : ( WhoWin=2 ); //���� ����
		else if(User_Select2==TRUE)
			( (eNow==eComSel+1) || (eNow==eComSel-2) ) ? ( WhoWin=2 ) : ( WhoWin=1 ); //���� ����
	}
	else {
		Better_printf("= �����ϴ� =",32,20,5);//����� ���� ��������
		Sleep(1000);
		for(i=7;i<=16;i++){
			if(User_Select==TRUE){
				SetCurPos(45,i);
				printf("\t\t\t\t\t");
			}
			else if(User_Select2==TRUE){
				SetCurPos(5,i);
				printf("\t\t\t\t\t");
			}
		SetCurPos(32,20);
		printf("\t\t");
		Better_printf("VS",39,10,15);
		}
	}

	} while(!WhoWin);		//���� ���� ���� �� Ż��
	
	Sleep(1000);
	ShowResult(WhoWin, User_Select, User_Select2);		//��� ���

	Sleep(2000);
	clrsc();
	return WhoWin;			//���ڰ��� ���������� ��ȯ  -  1:����� ��		2:AI ��
}

/*===============  ���� ���� �Լ���  ===============*/
int ComSelect(void)
{
	static BOOL bF=TRUE;
	static int i;
	if(bF){
	i=(rand()*17)%3;
	bF=FALSE;
	}

	MoveSelection(15+i%3*23,1,i%3,FALSE,2);
	i++;
	MoveSelection(15+i%3*23,1,i%3,TRUE,2);

	return i%3+100;
}
void UserSelect(int *eNow,int *eTemp)
{
	int i,j;

	j=*eTemp%100;
	MoveSelection(15+j*23,23,j,FALSE,1);

	i=*eNow%100;
	MoveSelection(15+i*23,23,i,TRUE,1);

	ShowSelImage(*eNow,1);
}

void MoveSelection(int x,int y,int i,BOOL _switch,int Player)
{
	int color=7+_switch*7;
	if(Player==2) color-=_switch*2;
	SetCurPos(x,y);
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),color);
	fflush(stdin);
	if(_switch)  printf(">>");
	else		 printf("  ");
	printf("%s   ",SRP[i]);
}

/*===============  ��Ʈ��  ===============*/
void DrawMinigame()
{
	int i,nKey=1,result=1;
	
	for(i=0;i<79;i++){
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),11);
		SetCurPos(i,3);
		printf("=");
		SetCurPos(i,21);
		printf("=");
		result=IntroSkip(nKey);
		Sleep(20*result);
	}

	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	SetCurPos(1,1);
	printf("Computer ->");
	SetCurPos(1,23);
	printf("You	->");
	Sleep(500*result);
	for(i=0;i<3;i++){
		SetCurPos(17+23*i,1);
		printf("%s\t",SRP[i]);
		SetCurPos(17+23*i,23);
		printf("%s\t",SRP[i]);
		result=IntroSkip(nKey);
		Sleep(500*result);
	}
	for(i=1; i<7; i++)
	{
		switch(i){
			case 1 : Better_printf("����!",20,10,13);
			case 2 : Better_printf("����!",24,12,10);
			case 3 : Better_printf("��!",28,14,11);
			case 4 : Better_printf("�����Դϴ�.",33,11,15);
			case 5 : Better_printf("ȭ��ǥ Ű�� ����Ű�� �̿��Ͽ�",36,13,15);
			case 6 : Better_printf("�����Ͻø� �˴ϴ�!",41,15,15);
		}
		result=IntroSkip(nKey);
		Sleep(500*result);
	}
	Sleep(1000);
	
	for(i=10;i<=15;i++){
		SetCurPos(20,i);
		printf("\t\t\t\t\t\t\t\n");;
	}

}


/*===============  ����,����,�� �ո�� ��� �Լ���  ===============*/
//����
void PrintS(int x,int y,int pos)
{
	int i;
	char S[][10][40]={{"����������             \n",
					"��������������������������������\n",
					"                             ��\n",
					"��������������������������������\n",
					"                             ��\n",
					"��������������������������������\n",
					"            ��                  \n",
					"��������������                  \n",
					"            ��                  \n",
					"��������������                  \n"
					},
					{
		
					"                      ����������\n",
					"��������������������������������\n",
					" ��                             \n",
					"��������������������������������\n",
					" ��                             \n",
					"��������������������������������\n",
					"                  ��            \n",
					"                  ��������������\n",
					"                  ��            \n",
					"                  ��������������\n"
					}
	};
	
	for(i=0;i<10;i++){
	SetCurPos(x,y+i);
	printf("%s",S[pos-1][i]);
	}
}
//����
void PrintR(int x,int y,int pos)
{
	int i;
	
	char R[][10][40]={{"����������������������\n",
					"                    ������       \n",
					"              ��������  ��       \n",
					"                  ��������       \n",
					"                        ��       \n",
					"                  ��������       \n",
					"                        ��       \n",
					"                  ��������       \n",
					"                        ��       \n",
					"          ����������������       \n"
					},
					{"    ����������������������\n",
					"������                    \n",
					"��  ������                \n",
					"��������                  \n",
					"��                        \n",
					"��������                  \n",
					"��                        \n",
					"��������                  \n",
					"��                        \n",
					"����������������������    \n"
					
					}
	};

	for(i=0;i<10;i++){
	SetCurPos(x,y+i);
	printf("%s",R[pos-1][i]);
	}
}
//��
void PrintP(int x,int y,int pos)
{
	int i;

	char P[][10][40]={{ "����������                      \n",
						"��������������������������������\n",
						"                             ��\n",
						"                ����������������\n",
						"                             ��\n",
						"                ����������������\n",
						"                             ��\n",
						"                ����������������\n",
						"                             ��\n",
						"��������������������������������\n",
						},
					   {"                      ����������\n",
						"��������������������������������\n",
						" ��                             \n",
						"��������������������������������\n",
						" ��                             \n",
						"��������������������������������\n",
						" ��                             \n",
						"��������������������������������\n",
						" ��                             \n",
						"��������������������������������\n",
						}
	};

	for(i=0;i<10;i++){
	SetCurPos(x,y+i);
	printf("%s",P[pos-1][i]);
	}
}

/*===============  ������ ���ÿ� ���� �� ��� ����ϴ� �Լ�  ===============*/
void ShowSelImage(int sel,int Player)
{
	const int y = 7;
	const int x1 = 5, x2 = 45;
	int x;
	int shape;
	if(Player==1)
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),14);
	if(Player==2)
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),12);

	if ( whoIsPlayer == 1 )
	{
		x = (Player == 1) ? x1 : x2;
		shape = (Player == 1) ? 1 : 2;
		switch(sel){
			case S: PrintS( x , y , shape );
				break;
			case R: PrintR( x , y , shape );
				break;
			case P: PrintP( x , y , shape );
		}
	}
	else if ( whoIsPlayer == 2 )
	{
		x = (Player == 1) ? x2 : x1;
		shape = (Player == 1) ? 2 : 1;

		switch(sel){
			case S: PrintS( x , y , shape );
				break;
			case R: PrintR( x , y , shape );
				break;
			case P: PrintP( x , y , shape );
		}
	}

}