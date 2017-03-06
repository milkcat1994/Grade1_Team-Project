#include"MiniGame1.h"
#include"MiniGame2.h"
#include"MiniGame3.h"
#include"MiniGame4.h"
#include"MiniGame5.h"

int SelectGame()
{
int random;
srand(time(NULL));
random = rand()%5;
random=1;
return random;
}

int MGMain(BOOL User_Select, BOOL User_Select2)
{
	int WhoWin;
	int iSelGame=SelectGame();
	switch(iSelGame){
	case 0: WhoWin=SRPGame(User_Select, User_Select2); break;
	case 1: WhoWin=NumGame(User_Select, User_Select2); break;
	case 2: WhoWin=CardGame(User_Select, User_Select2); break;
	case 3: WhoWin=ChamGame(User_Select, User_Select2); break;
	case 4: WhoWin=ZeroGame(User_Select, User_Select2); break;
	}
	return WhoWin;
}
