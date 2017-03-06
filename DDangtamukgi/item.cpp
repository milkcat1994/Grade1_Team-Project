#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include"MainHeader.h"

HANDLE Hout=GetStdHandle(STD_OUTPUT_HANDLE); 

void item_turn(int turn) // 턴수 줄이기 계속 turn 수가 1개 이상 차이 나게 
{
	turn-=1; // 
	
}

int item_land(int*** turn)// turn 수에 따라 달라짐
{ 
	item_turn(&turn);
	return ***turn;
}
int Item(int*** TURN)
{
	int*** resu;
	resu=item_land(TURN);
	Better_printf("아이템 적용 완료",25,15,12);
	SetConsoleTextAttribute (Hout, 15 );
	Sleep(500);
	return **resu;
}
