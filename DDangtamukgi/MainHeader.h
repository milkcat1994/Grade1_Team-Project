#define TRUE 1
#define FALSE 0

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13

void SetCurPos(int,int);	// 커서 위치 옮기기
void Better_printf(char *str,int x,int y,int color);		//좌표,색 설정하는 출력함수
void clrsc();
void ShowResult(int WhoWin, BOOL User_Select, BOOL User_Select2);			//승,패 출력
int IntroSkip(int num);			//인트로 스킵 함수

void Better_printf_s(char *str,int x,int y,int length);

void Appear(char *str, int x, int y, int speed, int lastcolor);

void Fade(char *str, int x, int y, int speed, int firstcolor);