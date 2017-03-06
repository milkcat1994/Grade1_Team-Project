#include"MiniGame1.h"

char SRP[][5]={"가위","바위","보"};

enum SRP {S=100,R,P};		//S:가위	R:바위	P:보

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

	CONSOLE_CURSOR_INFO CurInfo; //커서 없애기
    CurInfo.dwSize=1;
    CurInfo.bVisible=FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
	clrsc();

	DrawMinigame();

	
	Better_printf("\t\t\t\t\t",23,10,NULL);
	UserSelect(&eNow,&eTemp);

	Better_printf("VS",39,10,15);

	do{	bUserChoice=FALSE;						//do{} while(!WhoWin)  -  승자가 결정났을 시 탈출(무승부 시 선택과정 반복)
	while(!bUserChoice){						//컴퓨터와 사용자의 선택과정, 유저가 선택완료 시 탈출
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
			case 'l':						//Enter 키로 사용자 선택 결정 완료
				MessageBeep(MB_OK);
				bUserChoice=TRUE;				//유저 선택 완료
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
			case 'b':						//Enter 키로 사용자 선택 결정 완료
				MessageBeep(MB_OK);
				bUserChoice=TRUE;				//유저 선택 완료
			}
			UserSelect(&eNow,&eTemp);
		}
		}
	}
	
	ShowSelImage(eComSel=ComSelect(),2);
	if(eNow!=eComSel){
		if(User_Select==TRUE)
			( (eNow==eComSel+1) || (eNow==eComSel-2) ) ? ( WhoWin=1 ) : ( WhoWin=2 ); //승자 결정
		else if(User_Select2==TRUE)
			( (eNow==eComSel+1) || (eNow==eComSel-2) ) ? ( WhoWin=2 ) : ( WhoWin=1 ); //승자 결정
	}
	else {
		Better_printf("= 비겼습니다 =",32,20,5);//비길경우 승자 결정안함
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

	} while(!WhoWin);		//승자 결정 났을 시 탈출
	
	Sleep(1000);
	ShowResult(WhoWin, User_Select, User_Select2);		//결과 출력

	Sleep(2000);
	clrsc();
	return WhoWin;			//승자값을 정수형으로 반환  -  1:사용자 승		2:AI 승
}

/*===============  선택 관련 함수들  ===============*/
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

/*===============  인트로  ===============*/
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
			case 1 : Better_printf("가위!",20,10,13);
			case 2 : Better_printf("바위!",24,12,10);
			case 3 : Better_printf("보!",28,14,11);
			case 4 : Better_printf("게임입니다.",33,11,15);
			case 5 : Better_printf("화살표 키와 엔터키를 이용하여",36,13,15);
			case 6 : Better_printf("선택하시면 됩니다!",41,15,15);
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


/*===============  가위,바위,보 손모양 출력 함수들  ===============*/
//가위
void PrintS(int x,int y,int pos)
{
	int i;
	char S[][10][40]={{"────┐             \n",
					"────┴──────────┐\n",
					"                             ■\n",
					"───────────────┤\n",
					"                             ■\n",
					"──────┬────────┘\n",
					"            │                  \n",
					"──────┤                  \n",
					"            │                  \n",
					"──────┘                  \n"
					},
					{
		
					"                      ┌────\n",
					"┌──────────┴────\n",
					" ■                             \n",
					"├───────────────\n",
					" ■                             \n",
					"└────────┬──────\n",
					"                  │            \n",
					"                  ├──────\n",
					"                  │            \n",
					"                  └──────\n"
					}
	};
	
	for(i=0;i<10;i++){
	SetCurPos(x,y+i);
	printf("%s",S[pos-1][i]);
	}
}
//바위
void PrintR(int x,int y,int pos)
{
	int i;
	
	char R[][10][40]={{"──────────┐\n",
					"                    │─┐       \n",
					"              └──┘  │       \n",
					"                  ───┤       \n",
					"                        │       \n",
					"                  ───┤       \n",
					"                        │       \n",
					"                  ───┤       \n",
					"                        │       \n",
					"          ───────┘       \n"
					},
					{"    ┌──────────\n",
					"┌─│                    \n",
					"│  └─┘                \n",
					"├───                  \n",
					"│                        \n",
					"├───                  \n",
					"│                        \n",
					"├───                  \n",
					"│                        \n",
					"└──────────    \n"
					
					}
	};

	for(i=0;i<10;i++){
	SetCurPos(x,y+i);
	printf("%s",R[pos-1][i]);
	}
}
//보
void PrintP(int x,int y,int pos)
{
	int i;

	char P[][10][40]={{ "────┐                      \n",
						"────┴──────────┐\n",
						"                             ■\n",
						"                ───────┤\n",
						"                             ■\n",
						"                ───────┤\n",
						"                             ■\n",
						"                ───────┤\n",
						"                             ■\n",
						"───────────────┘\n",
						},
					   {"                      ┌────\n",
						"┌──────────┴────\n",
						" ■                             \n",
						"├───────────────\n",
						" ■                             \n",
						"├───────────────\n",
						" ■                             \n",
						"├───────────────\n",
						" ■                             \n",
						"└───────────────\n",
						}
	};

	for(i=0;i<10;i++){
	SetCurPos(x,y+i);
	printf("%s",P[pos-1][i]);
	}
}

/*===============  유저의 선택에 따라 손 모양 출력하는 함수  ===============*/
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