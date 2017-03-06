#include "MiniGame5.h"


int nPlay=0;

char Otherhand_Default[][50]={
	"      /     ��      ��     ��      ��     ��",
	"     ��     ��      ��|   /��      ��     ��",
	"     ��     ��      ���� ����      ��     ��",
	"     ��     ��      ���� ����      ��     /",
	"      ��������      ��-   -��      ������",
	"            �����ᦡ��     �����ᦡ��"
};
char Otherhand_LeftUp[][50]={
	"      /     ��      ��     ��      ��     ��",
	"     ��     ��      ��|   //��      ��    ��",
	"     ��     ��      ���� ��/��  ��  ��    ��",
	"     ��     ��      ���� ��/����������    /",
	"      ��������      ��-   -��������������",
	"            �����ᦡ��          "
};
char Otherhand_RightUp[][50]={
	"      /     ��      ��     ��      ��     ��",
	"     ��    ��      ��/|   /��      ��     ��",
	"     ��    ��  ��  ��/�� ����      ��     ��",
	"     ��    ����������/�� ����      ��     /",
	"      ����������������-   -��      ������",
	"                           �����ᦡ��"
};
char Otherhand_DoubleUp[][50]={
	"      /     ��      ��     ��      ��     ��",
	"     ��    ��      ��/|   //��      ��    ��",
	"     ��    ��  ��  ��/�� ��/��  ��  ��    ��",
	"     ��    ����������/�� ��/����������    /",
	"      ����������������-   -��������������",
	"                                "
};
char Myhand_Default[][50]={
	"            �����ᦡ��     �����ᦡ��",
	"        ������      ��-   -��      ������",
	"      ��    ��      ���� ����      ��    ��",
	"     ��     ��      ���� ����      ��    ��",
	"     ��     ��      ��/   |��      ��    ��",
	"     ��     ��      ��     ��      ��    / "
};
	char Myhand_LeftUp[][50]={
	"                           �����ᦡ��",
	"        ��������������-   -��      ������",
	"      ��   ����������/�� ����      ��    ��",
	"     ��    ��  ��  ��/�� ����      ��    ��",
	"     ��    ��      ��//   |��      ��    ��",
	"     ��     ��      ��     ��      ��    /"
};
char Myhand_RightUp[][50]={
	"            �����ᦡ��               ",
	"        ������      ��-   -��������������",
	"      ��    ��      ���� ��/����������   ��",
	"     ��     ��      ���� ��/��  ��  ��   ��",
	"     ��     ��      ��/   |/��      ��   ��",
	"     ��     ��      ��     ��      ��    / "
};
char Myhand_DoubleUp[][50]={
	"                                          ",
	"        ��������������-   -��������������",
	"      ��   ����������/�� ��/����������   ��",
	"     ��    ��  ��  ��/�� ��/��  ��  ��   ��",
	"     ��    ��      ��//   |/��      ��   ��",
	"     ��     ��      ��     ��      ��    / "
};


int ZeroGame(BOOL User_Select, BOOL User_Select2)
{
	int whowin;
	clrsc(); nPlay+=1;
	CONSOLE_CURSOR_INFO CurInfo; //Ŀ�� ���ֱ�
    CurInfo.dwSize=1;
    CurInfo.bVisible=FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);

	DrawZeroIntro();	//��Ʈ��
	whowin=PlayWithHands(User_Select, User_Select2);	//���ݰ���
	system("cls");
	return whowin;
}

/*<<<<<<<<<<<<<  ���� ����  >>>>>>>>>>>>>>*/
int PlayWithHands(BOOL User_Select, BOOL User_Select2)
{
	const int pHand_Left=17,pHand_Top=19;			//���� ��� ����ġ
	int i;	//���� ��Ʋ
	int nWhat=0;	//ȭ�� ������ ����
	int bHelp=FALSE;	//���� (�ʿ� ����, Ȥ�� ���� ���ξ���)
	int myselnum=0;	//���� ���ø� �հ��� ����
	int gap=0;			// (���� ��ģ ����) - (��밡 ���ø� �հ��� ����)

	Better_printf("���� ���� : H Ű",0,0,8);                            //  ����
	for(i=0;i<6;i++)													//    ��
			Better_printf(Myhand_Default[i],pHand_Left,pHand_Top+i,15); //	  ����>  �ʱ� ȭ��
	for(i=0;i<6;i++)													//    ��
			Better_printf(Otherhand_Default[i],pHand_Left,0+i,15);		//  ����

	while(1){ //Ű���� �Է� �޾Ƽ� �۵��ϴ� ����
		if( (GetKeyState(72) & 0x8000) && !(bHelp) ){ // HŰ ������ ���� ���( Help() ) �� ȭ�� �ٽ� �׸���( for(;;) )
			//bHelp=TRUE;
			Help();
			for(i=0;i<6;i++)
			Better_printf(Myhand_Default[i],pHand_Left,pHand_Top+i,15);
			for(i=0;i<6;i++)
			Better_printf(Otherhand_Default[i],pHand_Left,0+i,15);
		}
		/***************   A, D Ű �Է� �ޱ�   **************/
		if( (GetKeyState(65) & 0x8000) && !(GetKeyState(68) & 0x8000) && !(nWhat==1) ){		
			for(i=0;i<6;i++)
				Better_printf(Myhand_LeftUp[i],pHand_Left,pHand_Top+i,15);
			nWhat=1;	myselnum=1;
		}
		if( (GetKeyState(68) & 0x8000) && !(GetKeyState(65) & 0x8000) && !(nWhat==2) ){
			for(i=0;i<6;i++)
				Better_printf(Myhand_RightUp[i],pHand_Left,pHand_Top+i,15);
			nWhat=2;	myselnum=1;
		}
		if( (GetKeyState(65) & 0x8000) && (GetKeyState(68) & 0x8000) && !(nWhat==3) ){
			for(i=0;i<6;i++)
				Better_printf(Myhand_DoubleUp[i],pHand_Left,pHand_Top+i,15);
			nWhat=3;	myselnum=2;
		}
		if( !(GetKeyState(65) & 0x8000) && !(GetKeyState(68) & 0x8000) && !(nWhat==0) ){
			for(i=0;i<6;i++)
				Better_printf(Myhand_Default[i],pHand_Left,pHand_Top+i,15);
			nWhat=0;	myselnum=0;
		}
		/****************************************************/
		 
		/***************   ���� �Է� �ޱ�   **************/ 
		if( GetKeyState(49) & 0x8000 || GetKeyState(0x61) & 0x8000 ){ gap=Shouting(1); break; }			//Shouting() �� ��ġ�� �ô� ����ϰ�
		else if( GetKeyState(50) & 0x8000 || GetKeyState(0x62) & 0x8000 ){ gap=Shouting(2); break; }	//����� �հ����� �������� ����Ͽ�
		else if( GetKeyState(51) & 0x8000 || GetKeyState(0x63) & 0x8000 ){ gap=Shouting(3); break; }	//�ڽ��� ��ģ ���ڿ� ����� �ø� �հ��� ������
		else if( GetKeyState(52) & 0x8000 || GetKeyState(0x64) & 0x8000 ){ gap=Shouting(4); break; }	//���̸� ��ȯ.  �� ��ȯ���� gap�� �����Ѵ�
		else if( GetKeyState(48) & 0x8000 || GetKeyState(0x60) & 0x8000 ){ gap=Shouting(0); break; }
	}
	//printf("��: %d,  ����: %d",myselnum,gap);

	if(myselnum==gap){	//�� ��ȯ ���� ���� �ø� �հ��� ������ ��ġ �� ���
		printf("�̱�");	//�¸�
		Sleep(2000);
		if(User_Select==TRUE)
			return 1;
		else if(User_Select2==TRUE)
			return 2;
	}
	else
	{
		printf("��");	//�׷��� ������� �й�
		Sleep(2000);
		return 0;
	}
	
}

void Help()
{
	const int pHelp_Mid=38, pHelp_Top=5;
	int i;
	char cESC;

	char help[][100]={"*Ȥ�� '���� ����'�� �𸣼���?","���ڸ� ��ġ��,","���� �հ����� ���ø� �� �ֽ��ϴ�.","\n",
		"�����а� ��밡 ���ø� ������ �� ����","��ģ ���ڿ� ��ġ �� ���,",
	    "���ڸ� ��ģ ����� �¸��մϴ�.","\n","���⿡���� ���ڰ� ��ġ ���� ���� ���,","�й��մϴ�.","���� ���� ��� : A Ű, ������ ���� ��� : DŰ, ��ġ�� : ����(0��4) Ű"};
	

	Appear(help[0],pHelp_Mid-strlen(help[0])/2,pHelp_Top,NULL);
	Better_printf(help[0],pHelp_Mid-strlen(help[0])/2,pHelp_Top,10);

	for(i=1;i<10;i++){
		Appear(help[i],pHelp_Mid-strlen(help[i])/2,pHelp_Top+2+i,150);
	}
	Better_printf(help[10],pHelp_Mid-strlen(help[10])/2,pHelp_Top+13,11);
	Better_printf("ESC Ű�� ���� ���� �����",pHelp_Mid-strlen(help[10])/2,pHelp_Top+15,8);
	
	while(1){
	if( _kbhit() ){
		if( cESC=_getch() == 27 )
			break;
	}
	}

	Fade(help[0],pHelp_Mid-strlen(help[0])/2,pHelp_Top,30);

	for(i=1;i<10;i++){
		Fade(help[i],pHelp_Mid-strlen(help[i])/2,pHelp_Top+2+i,30);
	}
	Fade(help[10],pHelp_Mid-strlen(help[10])/2,pHelp_Top+13,30);
	Fade("ESC Ű�� ���� ���� �����",pHelp_Mid-strlen(help[10])/2,pHelp_Top+15,30);
}

int Shouting(int selnum)
{
	int OtherSel=0;			//��밡 �� �հ��� ���
	int OtherCount=0;		//��밡 �ø� ���� �հ��� ��
	int i;

	char *ShoutWhat="";
	switch(selnum){
	case 0: ShoutWhat="����!"; break;
	case 1: ShoutWhat="�ϳ�!"; break;
	case 2: ShoutWhat="��!  "; break;
	case 3: ShoutWhat="��!  "; break;
	case 4: ShoutWhat="��!  "; break;
	}
	Better_printf("  |    ",2,21,15);
	Better_printf("  |  /",2,22,15);
	Better_printf("   /  -- --",2,23,15);
	Better_printf(ShoutWhat,9,21,15);

	srand(time(NULL));
	OtherSel=rand()%3;
	switch(OtherSel){
	case 0: for(i=0;i<6;i++)
			Better_printf(Otherhand_Default[i],17,0+i,15); break;
	case 1: if(OtherSel=rand()%2){
				for(i=0;i<6;i++)
				Better_printf(Otherhand_LeftUp[i],17,0+i,15); 
			} else {
				for(i=0;i<6;i++)
				Better_printf(Otherhand_RightUp[i],17,0+i,15);
			} OtherCount=1; break;
	case 2: for(i=0;i<6;i++)
			Better_printf(Otherhand_DoubleUp[i],17,0+i,15);
		OtherCount=2;
	}



	return selnum-OtherCount;
}

void DrawZeroIntro()
{
	int bkbhit=1;
	int changing=0;
	int color;
	int count=0;
	int i;
	int appeartime=0;
	char str_ZERO[][200]={
		"��������������������  ������������������ ������������������ ������������������",
		"�Ʀ�������������  ��  ��  �������������� ��  ����������  �� �� ������������ ��",
		"              /  //   ��  ��             ��  ��      ��  �� �� ��        �� ��",
		"            /  //     ��  ��             ��  �Ŧ�������  �� �� ��        �� ��",
		"          /  //       ��  �Ŧ����������� ��  �������������� �� ��        �� ��",
		"        /  //         ��  �������������� ��  �Ŧ����������� �� ��        �� ��",
		"      /  //           ��  ��             ��  ����������  �� �� ��        �� ��",
		"    /  //             ��  ��             ��  ��      ��  �� �� ��        �� ��",
		"  /    �������������� ��  �Ŧ����������� ��  ��      ��  �� �� �Ŧ��������� ��",
		" �Ʀ����������������� �Ʀ��������������� �Ʀ���      �Ʀ��� �Ʀ���������������"
	};
	Better_printf("\n",10,10,12);
	/********************���� �˷ϴ޷�~***************/
	while(changing<28){
	for(i=0;i<10;i++){
		if( _kbhit() )
			bkbhit=0;
		color=15-changing-i;
		if(color<-1)
			color+=12;

		Better_printf("",0,0,color);
		SetCurPos(1,7+i);
		printf("%s",str_ZERO[i]);
	}
	changing++;

	Sleep(100*bkbhit);
	}

	Sleep(500*bkbhit);
	/***********************/
	count=color=0;
	while(count<18){
		for(i=0;i<10;i++){
			Better_printf(str_ZERO[i],1,7+i,color);
		}
		switch(++count){
		case 1: color=8; break;
		case 2: color=7; break;
		case 3: color=15; break;
		case 15: color=7; break;
		case 16: color=8; break;
		case 17: color=0; 
		}
		Sleep(150*bkbhit);
	}
	if((bkbhit==0)&&(nPlay!=1))
		appeartime=1;

	system("cls");
	Appear("���� ���� ��� : Ű���� A ��ư",20,9,appeartime);
	Appear("������ ���� ��� : Ű���� D ��ư",20,11,appeartime);
	Appear("���� ��ġ�� : Ű���� ���� ��ư",20,13,appeartime);
	Sleep(1000*bkbhit);
	Fade("���� ���� ��� : Ű���� A ��ư",20,9,appeartime);
	Fade("������ ���� ��� : Ű���� D ��ư",20,11,appeartime);
	Fade("���� ��ġ�� : Ű���� ���� ��ư",20,13,appeartime);

	system("cls");
}
/*
int AskWhatNum()
{
	int i;
	char cInput;
	char num0[][40]={" ������������������"," ��              ��"," ��   ��������   ��"," ��   ��    ��   ��",
					" ��   ��    ��   ��"," ��   ��    ��   ��"," ��   ��    ��   ��",
					" ��   ��������   ��"," ��              ��"," ������������������",
					};
	char num1[][40]={"          ������    ","          /   ��   ","       ����   ��    ",
					"       �� ��  ��    ","          ��  ��    ","          ��  ��    ",
					"          ��  ��    ","          ��  ��    ","        ����  ����  ","        ����������  "
	};
	char num2[][40]={"  ������������������",
					 "  ��              ��",
					 "  ��������������  ��",
					 "              ��  ��",
					 "  ��������������  ��",
					 "  ��  ��������������",
					 "  ��  ��            ",
					 "  ��  ��������������",
					 "  ��              ��",
					 "  ������������������"
	};
	char num3[][40]={"  ������������������","  ��              ��","  ��������������  ��",
					"              ��  ��","  ��������������  ��","  ��������������  ��",
					"              ��  ��","  ��������������  ��","  ��              ��","  ������������������",
	};
	char num4[][40]={
		" ������  ������    ",
		" ��  ��  ��  ��    ",
		" ��  ��  ��  ��    ",
		" ��  ��  ��  ��    ",
		" ��  ��  ��  ��    ",
		" ��  ������  ������",
		" ����������  ������",
		"         ��  ��    ",
		"         ��  ��    ",
		"         ������    "
					};
	char oh[][8]={
		"������",
		"��  ��",
		"��  ��",
		"��  ��",
		"��  ��",
		"��  ��",
		"������",
		"������",
		"������"
	};

	const int str_top=5;
	const int str_left=38;
	int sel=-1,bsel=0;

	Better_printf("Ű����� ���� �Է� �� ���� �� �����ּ���",0,0,8);
	Better_printf("�ۦ�",str_left-26,10,7);
	Better_printf("�Ǧ�ġ�� ���� ���� : ",str_left-26,11,7);
	Better_printf("( 0 �� 4 �߿� )",str_left-23,13,7);
	//SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
	while( !bsel ){
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ),15);
		if( _kbhit() )
		{
			switch(cInput=_getch()){
			case '0': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); } for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num0[i]);} Better_printf("����!",str_left+25,str_top,11); sel=0; break;
			case '1': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); }for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num1[i]);} Better_printf("�ϳ�!",str_left+25,str_top,11); sel=1; break;
			case '2': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); }for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num2[i]);} Better_printf("��!  ",str_left+25,str_top,11); sel=2; break;
			case '3': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); }for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num3[i]);} Better_printf("��!  ",str_left+25,str_top,11); sel=3; break;
			case '4': for(i=0;i<9;i++){ SetCurPos(str_left+20,str_top+1+i);printf("%s",oh[i]); }for( i=0;i<10;i++){ SetCurPos(str_left,str_top+i); printf("%s",num4[i]);} Better_printf("��!  ",str_left+25,str_top,11); sel=4; break;
			case 13 : if(sel!=-1) bsel=TRUE;
			}
			
		}
		SetCurPos(0,0);
	}
	return sel;
}
*/
void Appear(char *str, int x, int y, int speed)
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
	case 3: color=15;
	}
	Sleep(speed);
	}
}

void Fade(char *str, int x, int y, int speed)
{
	int count=0,i,color=15;

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
