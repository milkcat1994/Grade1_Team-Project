#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include"MainHeader.h"

HANDLE Hout=GetStdHandle(STD_OUTPUT_HANDLE); 

void item_turn(int turn) // �ϼ� ���̱� ��� turn ���� 1�� �̻� ���� ���� 
{
	turn-=1; // 
	
}

int item_land(int*** turn)// turn ���� ���� �޶���
{ 
	item_turn(&turn);
	return ***turn;
}
int Item(int*** TURN)
{
	int*** resu;
	resu=item_land(TURN);
	Better_printf("������ ���� �Ϸ�",25,15,12);
	SetConsoleTextAttribute (Hout, 15 );
	Sleep(500);
	return **resu;
}
