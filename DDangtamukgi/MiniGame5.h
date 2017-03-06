#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"MainHeader.h"

#ifndef __OTHER_FUNCTION__
#define __OTHER_FUNCTION__

void Appear(char *str, int x, int y, int speed);
void Fade(char *str, int, int y, int speed);

#endif

int ZeroGame(BOOL User_Select, BOOL User_Select2);
void DrawZeroIntro();
int PlayWithHands(BOOL User_Select, BOOL User_Select2);
int Shouting(int selnum);

void Help();
