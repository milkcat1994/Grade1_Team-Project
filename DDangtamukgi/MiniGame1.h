#include<stdio.h>
#include<conio.h>
#include<windows.h> //COORD
#include<time.h>
#include"mainheader.h"

 //Ŀ�� �̵�, ���� ��

int SRPGame(BOOL User_Select, BOOL User_Select2);		//���� ����

int ComSelect();	//AI�� ���ð���
void UserSelect(int *eNow,int *eTemp);	//������� ���ð���

void DrawMinigame();	//��Ʈ��
void MoveSelection(int x,int y,int i,BOOL _switch,int Player);	//���ú����
void ShowSelImage(int i,int Player);	//�÷��̾� �հ��� ��� ���


void PrintS(int x,int y,int pos);	//����(�ո��)		
void PrintR(int x,int y,int pos);	//����(�ո��)
void PrintP(int x,int y,int pos);	//��(�ո��)
