#define TRUE 1
#define FALSE 0

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13

void SetCurPos(int,int);	// Ŀ�� ��ġ �ű��
void Better_printf(char *str,int x,int y,int color);		//��ǥ,�� �����ϴ� ����Լ�
void clrsc();
void ShowResult(int WhoWin, BOOL User_Select, BOOL User_Select2);			//��,�� ���
int IntroSkip(int num);			//��Ʈ�� ��ŵ �Լ�

void Better_printf_s(char *str,int x,int y,int length);

void Appear(char *str, int x, int y, int speed, int lastcolor);

void Fade(char *str, int x, int y, int speed, int firstcolor);