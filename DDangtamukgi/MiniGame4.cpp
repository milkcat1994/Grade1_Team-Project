#include "MiniGame4.h"  


int ChamGame(BOOL User_Select, BOOL User_Select2)
{
	clrsc();
	int whowin;
	chamintro(1,1);
	whowin=cham_main(User_Select, User_Select2);
	//system("pause");
	eraseface();//���α׷����������� �Ⱦ������Ƿ� ���־ߵ�
	system("cls");
	return whowin;
}

void chamintro(int x,int y)
{
	
	
	int i,j;
	int a,result,nkey=1;
	char time=NULL;
	char Press_Enter=NULL;
	char cham[15][30]={
	"    ������          ��\n",
	"                    ��\n",
	"  ����������        ��\n",
	"          ��        ��\n",
	"        ��          ������\n",
	"       ����         ��\n",
	"     ��    ��       ��\n",
	"   ��        ��     ��\n",
	"\n",
	"      ��������������\n",
	"      ��          ��\n",
	"      ��          ��\n",
	"      ��          ��\n",
	"      ��������������\n"
	};

	
	


	for(j=0;j<3;j++)
	{
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),10+j*2);
		for(i=0;i<15;i++)
		{
			SetCurPos(x+j*25,y+i+4);
			printf("%s",cham[i]);
		}
		result=IntroSkip(nkey);
		Sleep(500*result);
	}
	system("cls");
	for(a=1 ; a<=5 ; a++)
	{
		switch(a){
		case 1 : Better_printf("    ������ �����Դϴ�.    ",30,9,15); break;
		case 2 : Better_printf(" �¿�ȭ��ǥŰ�� �̿��Ͽ�. ",30,10,15); break;
		case 3 : Better_printf("  ���� ������ ���ð�.   ",30,11,15); break;
		case 4 : Better_printf("���� ����� ���� ������.",30,12,15); break;
		case 5 : Better_printf("��ġ�ϸ� �¸��ϰ� �˴ϴ�..",30,13,15); break;
			result=IntroSkip(nkey);
			Sleep(300*result);
		}
	}
	Sleep(1000);
	int t;
		t=clock();
	for(i=0;i<40;i++){
		if(clock()-t>50)
			break;
		Better_printf("����Ű�� ������ �����մϴ�",29,14,15);
		getchar();
	}
	clrsc();
	}


int cham_main(BOOL User_Select, BOOL User_Select2)
{
	int face=1;
	int hand=1;
	int handlife=2;
	
	table();//������
		im(face);//�� ���� ���
	
		srand((unsigned int)time(NULL));
		face=rand()%3;
		hand=Selecthand(hand);//�ռ���
		

		if(face!=1)
		eraseface();//�����
	
		
		
		im(face);
	
		SetCurPos(1,22);
		printf("face = %d, hand = %d",face,hand);
	
		if(hand==face)
		{
			Better_printf("�¸��ϼ̽��ϴ�\t\t\t\t\t\t",1,23,11);
			Sleep(1000);
			if(User_Select==TRUE)
				return 1;
			else if(User_Select2==TRUE)
				return 2;
		}
		else
		{
			Better_printf("�й��ϼ̽��ϴ�\t\t\t\t\t\t",1,23,12);
			Sleep(1000);
			handlife--;
			return 0;
		}
	
}

int Selecthand(int handpoint)
{

	char enter=1;
	char select;
	int x=1;//�ո����������Ѻ���

		switch(handpoint)
		{
		case 0 : printlefthand(); break;
		case 1 : printmiddlehand(); break;
		case 2 : printrighthand(); break;
		}
		
	while(enter)
	{

		if(_kbhit())//���ʿ����ʴ����� ����Ű�º�������
		{
			
			select=_getch();
			switch(select)
			{
			case LEFT : if(handpoint>0)
						{
							erase(x);
							handpoint--;
							x--;
						}
						break;
			case RIGHT : if(handpoint<2)
						 {
							 erase(x);
							 handpoint++;
							 x++;
						 }
						 break;
			case ENTER : enter = 0;
				break;
			}
	switch(handpoint)
	{
	case 0 : printlefthand(); break;
	case 1 : printmiddlehand(); break;
	case 2 : printrighthand(); break;
	}

		}
	}
	
	return handpoint;
}

void im(int face)
{
	
	hConWnd = GetConsoleWindow();


				BCX_Bitmap(face,hConWnd,123,160+face*130,50,0,0);//(0,0,x,y,0,0);
	
		// select a bitmap file you have or use one of the files in the Windows folder
		// filename, handle, ID, ulcX, ulcY, width, height   0,0 auto-adjusts
			
}


// draw the bitmap
HWND BCX_Bitmap(int face,HWND hWnd,int id,int X,int Y,int W,int H,int Res,int Style,int Exstyle)
{
  
  HWND A;
  HBITMAP hBitmap;
  
  // set default style
  if (!Style) Style = WS_CLIPSIBLINGS|WS_CHILD|WS_VISIBLE|SS_BITMAP|WS_TABSTOP;
  
  // form for the image
  A = CreateWindowEx(Exstyle,TEXT("static"),NULL,Style,X,Y,0,0,hWnd,(HMENU)id,GetModuleHandle(0),NULL);
                      

  if (W || H) SetWindowPos(A,HWND_TOP,X,Y,W,H,SWP_DRAWFRAME);
  // Text contains filename
  if(face==0)
  {
  hBitmap=(HBITMAP)LoadImage(0,TEXT("C:\\Users\\pp\\Desktop\\��������\\���ʹ���.bmp"),IMAGE_BITMAP,100,100,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
  }
  else if(face==1)
  {

	  hBitmap=(HBITMAP)LoadImage(0,TEXT("C:\\Users\\pp\\Desktop\\��������\\����.bmp"),IMAGE_BITMAP,100,100,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
  }
  else if(face==2)
  {
	  hBitmap=(HBITMAP)LoadImage(0,TEXT("C:\\Users\\pp\\Desktop\\��������\\�����ʹ���.bmp"),IMAGE_BITMAP,100,100,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
  }
  else 
  {
	  hBitmap=NULL;
	printf("����");
  }
  


  // auto-adjust width and height
  if (W || H) hBitmap = (HBITMAP)CopyImage(hBitmap,IMAGE_BITMAP,W,H,LR_COPYRETURNORG);
  SendMessage(A,(UINT)STM_SETIMAGE,(WPARAM)IMAGE_BITMAP,(LPARAM)hBitmap);
  if (W || H) SetWindowPos(A,HWND_TOP,X,Y,W,H,SWP_DRAWFRAME);
	
	

  return A;
}


void eraseface()
{
Better_printf("�ƾ�",1,50,15);//�̹�����������ؼ�
	Better_printf(" ",0,0,15);//�ٽ�ȭ�� �������
}

void printlefthand()
{
	int i;
	char hand[][20]={
		" ___       ",
		"(��_��     ",
		" ��   ��    ",
		"   ��   ��   ",
		"     ��   ��  ",
		"       ��   �� ",
		"      ������ ��",
		"      ��  �� ��",
		"      ��  �� ��",
		"      ��  �� ��"//������� x35,y12
	};


	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	for(i=0;i<10;i++)
	{
		SetCurPos(15,12+i);
		printf("%s",hand[i]);
	}
}	
void printmiddlehand()//��� ���ýÿ�
{
	int i;
	char hand[][13]={
		"  ��������",
		"  ��  ����",
		"  ��  ����",
		"  ��  ����",
		"  ��  ����",
		"  ��  ����",
		"������  ��",
		"��  ��  ��",
		"��  ��  ��",
		"��  ��  ��"//������� x35,y12
	};


	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	for(i=0;i<10;i++)
	{
		SetCurPos(35,12+i);
		printf("%s",hand[i]);
	}




};
void printrighthand()
{
	int i;
	char hand[][20]={
		"        ____",
		"       ����_)",
		"      ��  ��",
		"     ��  ��",
		"    ��  ��",
		"   ��  ��",
		"������ ��",
		"��  �� ��",
		"��  �� ��",
		"��  �� ��"//������� x35,y12
	};


	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	for(i=0;i<10;i++)
	{
		SetCurPos(55,12+i);
		printf("%s",hand[i]);
	}




};

void erase(int x)//�����ո�������
{
	int i;
	char erase[][20]={
		"               ",
		"               ",
		"               ",
		"               ",
		"               ",
		"               ",
		"               ",
		"               ",
		"               ",
		"               "
	};


	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	for(i=0;i<10;i++)
	{
		SetCurPos(15+20*x,12+i);
		printf("%s",erase[i]);
	}
}

void table()
{
	int x,y;
	Better_printf("��������������������������������������������������",17,1,15);
	
	for(y=2;y<10;y++)
	{
		for(x=0;x<4;x++)
		{
		Better_printf("��",17+16*x,y,15);
		}
	}
	Better_printf("��������������������������������������������������",17,10,15);
	Better_printf("�¿� ����Ű�� �̿��Ͽ� ������ ���� ������",1,23,15);
}
