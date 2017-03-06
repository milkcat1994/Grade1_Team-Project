#include "MiniGame3.h"
#include "resource.h"
#include "MainHeader.h"

#define STR_LEFT 20
#define STR_TOP 6
#define STR_RIGHT 49
#define STR_BOTTOM 14

LRESULT CALLBACK CardProc1(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK CardProc2(HWND,UINT,WPARAM,LPARAM);
HINSTANCE hInstance;
HWND hWndMain;
LPCTSTR lpszClass1=TEXT("card1");
LPCTSTR lpszClass2=TEXT("card2");
HWND hWnd1,hWnd2;
BOOL b1win;
int WinPlayer;
int wx,wy;
RECT crt;
BOOL PlayerP, Player2P;

int CardGame(BOOL User_Select, BOOL User_Select2)
{
	system("cls");
	DrawOnConsole();
	Sleep(500);
	WindowMain();
	system("cls");
	WinPlayer=WhoWin(User_Select, User_Select2, PlayerP, Player2P);
	return WinPlayer;
}
void WindowMain()
{
	MSG Message;
	WNDCLASS WndClass;
	int nCmdShow=SW_SHOW;
	
	hInstance=GetModuleHandle(NULL);
	hWndMain=GetConsoleWindow();

	GetWindowRect(hWndMain,&crt);
	wx=(crt.right+crt.left)/2;
	wy=(crt.bottom+crt.top)/2;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.hCursor=LoadCursor(NULL,IDC_HAND);
	WndClass.hIcon=NULL;
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=CardProc1;
	WndClass.lpszClassName=lpszClass1;
	WndClass.lpszMenuName=NULL;
	WndClass.style=NULL;
	RegisterClass(&WndClass);

	//WndClass.lpfnWndProc=CardProc2;
	WndClass.lpszClassName=lpszClass2;
	RegisterClass(&WndClass);


	hWnd1=CreateWindow(lpszClass1,lpszClass1,WS_POPUP|WS_THICKFRAME,
		wx-250,wy-170,205,310,
		hWndMain,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd1,nCmdShow);
	hWnd2=CreateWindow(lpszClass2,lpszClass2,WS_POPUP|WS_THICKFRAME,
		wx-250,wy-170,205,310,
		hWndMain,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd2,nCmdShow);
	b1win=clock()%2;
	while (GetMessage(&Message,NULL,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	
}

LRESULT CALLBACK CardProc1(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	static int i;

	HDC hdc,MemDC;
	PAINTSTRUCT ps;
	HBITMAP Bitmap,OldBitmap;
	RECT rt;
	LPWINDOWPOS wp;
	static BOOL CurOn,OnGoing=FALSE;
	static POINT pt;
	static int iSel=108;
	static int nMovingCount=0,tCount=0;

	switch(iMessage){
	case WM_CREATE:
		CurOn=OnGoing=FALSE;
		nMovingCount=tCount=0;
		iSel=108;
		SetTimer(hWnd,1,30,NULL);
		SetTimer(hWnd,2,1000,NULL);
		OnGoing=TRUE;
		return 0;
	case WM_TIMER:
		switch(wParam){
		case 1:
		wx+=10;
		SetWindowPos(hWnd2,hWnd1,wx-290,wy-170,0,0,SWP_NOSIZE);
		if(nMovingCount<4)
		SetWindowPos(hWnd1,hWndMain,wx-290,wy-170,0,0,SWP_NOSIZE);
		nMovingCount++;
		if(nMovingCount>32){
			KillTimer(hWnd,1);
			
			OnGoing=FALSE;
		break;
		case 2:
			SetCurPos(31,12);
			if(tCount==0) printf(".\t");
			else if(tCount==2) printf("..\t");
			else if(tCount==4) printf("...\t");
			else if(tCount==6) printf("....");
			tCount++;
			if(tCount==7) tCount=0;
		}
		}
		return 0;
	case WM_LBUTTONDOWN:
		if(!OnGoing){
			OnGoing=TRUE;
		GetCursorPos(&pt);
		if(WindowFromPoint(pt)==hWnd1){
			//SetWindowLongPtr(hWnd2,GWL_STYLE,(LONG_PTR)WS_DISABLED);
			ShowWindow(hWnd1,SW_HIDE);
			AnimateWindow(hWnd1,200,AW_SLIDE|AW_HOR_POSITIVE);
			InvalidateRect(hWnd1,NULL,TRUE);
			SetForegroundWindow(hWnd1);
			if(b1win){
				iSel--;
				MessageBox(hWnd,TEXT("승리카드를 고르셨습니다!"),TEXT("승리!"),MB_OK);
				PlayerP=TRUE;	Player2P=TRUE;
			}
			else {
				iSel-=2;
				MessageBox(hWnd,TEXT("패배카드를 고르셨습니다!"),TEXT("패배!!"),MB_OK);
				PlayerP=FALSE;	Player2P=FALSE;	
			}
			InvalidateRect(hWnd1,NULL,TRUE);
		}
		else// if(WindowFromPoint(pt)==hWnd2)
			{
			ShowWindow(hWnd2,SW_HIDE);
			AnimateWindow(hWnd2,200,AW_SLIDE|AW_HOR_POSITIVE);
			InvalidateRect(hWnd2,NULL,TRUE);
			SetForegroundWindow(hWnd2);
			if(b1win) {
				iSel-=2;
				MessageBox(hWnd,TEXT("패배카드를 고르셨습니다!"),TEXT("패배!!"),MB_OK);
				PlayerP=FALSE;	Player2P=FALSE;
			}
			else {
				iSel-=1;
				MessageBox(hWnd,TEXT("승리카드를 고르셨습니다!"),TEXT("승리!"),MB_OK);
				PlayerP=TRUE;	Player2P=TRUE;
			}
			InvalidateRect(hWnd2,NULL,TRUE);
		}
		
		DestroyWindow(hWnd1);
		DestroyWindow(hWnd2);
		}
		OnGoing=FALSE;
		return 0;
	case WM_MOUSEMOVE:
		if(!OnGoing){
		if(LOWORD(lParam)>20&&LOWORD(lParam)<170)
			CurOn=TRUE;
		else
			CurOn=FALSE;
		InvalidateRect(hWnd,NULL,TRUE);
		}
		return 0;
		
	case WM_WINDOWPOSCHANGING:
        GetWindowRect(hWndMain,&rt); 
        wp=(LPWINDOWPOS)lParam; 
        wp->cx=205; //윈도우의 폭,높이 고정
		wp->cy=310;
		return 0;
	case WM_PAINT:
		hdc=BeginPaint(hWnd,&ps);
		MemDC=CreateCompatibleDC(hdc);
		Bitmap=LoadBitmap(hInstance,MAKEINTRESOURCE(IDB_CARD+(IDB_CARD-iSel)));
		OldBitmap=(HBITMAP)SelectObject(MemDC,Bitmap);
		if(!CurOn||IDB_CARD+(IDB_CARD-iSel)!=IDB_CARD)
			BitBlt(hdc,0,0,200,300,MemDC,0,0,SRCCOPY);
		else if(IDB_CARD+(IDB_CARD-iSel)==IDB_CARD)
			BitBlt(hdc,0,0,200,300,MemDC,0,0,NOTSRCCOPY);
		SelectObject(MemDC,OldBitmap);
		DeleteObject(Bitmap);
		DeleteDC(MemDC);
		EndPaint(hWnd,&ps);
		return 0;
	case WM_DESTROY:
		//DeleteObject(OldBitmap);
		KillTimer(hWnd,2);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

void DrawOnConsole()
{
	int a,i=-1,j=0,k=0,mem=-1,nCount=0,NowCur=STR_LEFT,nKey=1,result;
	char str[5][100]={"대망의 카드 고르기 미니게임 ! ", "두장의 카드가 주어집니다 "
		,"한 장의 카드를 선택하면 되요 ","둘 중 한장은 승리카드 ","또 다른 한장은 패배카드 "};
	char NowWriting[256];

	for(a=0;a<30;a++){
		if(a==29){
			Better_printf("★",STR_LEFT+a,STR_TOP-1,14);
			Better_printf("★",STR_RIGHT-a,STR_BOTTOM+1,14);
		} else {
		Better_printf("=",STR_LEFT+a,STR_TOP-1,14);
		Better_printf("=",STR_RIGHT-a,STR_BOTTOM+1,14);
		}
		if(!(a%3)){
			Better_printf("∥",STR_LEFT-1,STR_TOP+a/3,14);
			Better_printf("∥",STR_RIGHT+1,STR_BOTTOM-a/3,14);
		}
		
		Sleep(30);
	}

	for(j=0;j<sizeof(str)/sizeof(str[0]);j++){
	while(str[j][mem+1]!=NULL){
		while(1)
		{
			i++; mem++;
			NowWriting[i]=str[j][mem];
			
			if(str[j][mem]==' ')
				break;
			nCount++;
		}
		for(i=0;i<nCount;i++)
		{
			if(j==3&&nCount>7)
				Better_printf("",NowCur+i,STR_TOP+j*2,11);
			else if(j==4&&nCount>7)
				Better_printf("",NowCur+i,STR_TOP+j*2,12);
			else if(j==0&&nCount>7)
				Better_printf("",NowCur+i,STR_TOP+j*2,10);
			else Better_printf("",NowCur+i,STR_TOP+j*2,15);
			SetCurPos(NowCur+i,STR_TOP+j*2);
			
			printf("%c",NowWriting[i]);
			result=IntroSkip(nKey);
			Sleep((15+rand()%130)*result);
		}
		NowCur+=i+1;
		i=-1; nCount=0;
	}
	//NowCur=20+(clock()%4)-(clock()%2);
	NowCur=STR_LEFT;//+(j+1)*2;
	mem=-1;
	}
	Sleep(500);

	int t,z;
	t=clock();
	for(z=0;z<40;z++){
		if(clock()-t>50)
			break;
		Better_printf("엔터를 눌러요",44,24,10);
		getchar();
	}
	system("cls");
	Better_printf("게임 진행중",20,12,15);
}

int WhoWin(BOOL User_Select, BOOL User_Select2, BOOL PlayerP, BOOL Player2P)
{
	if((User_Select==TRUE)&&(PlayerP==TRUE))
		return 1;
	else if((User_Select2==TRUE)&&(Player2P==TRUE))
		return 2;
	else return 0;
}