////////////////////////////////////////////////////// ���� ////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#define randomize() srand((unsigned)time(NULL))	
#define random(n) (rand() % (n))
#define cls system("cls")
#define delay(n) Sleep(n)
#define random_cost 1000

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
////////////////////////////////////////////////////// ������ ��� �Լ� /////////////////////////////////////////
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
int wherex() // ���� x ��ǥ ��ġ ����
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}
int wherey() // ���� y ��ǥ ��ġ ����
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}
typedef enum {
	NOCURSOR,
	SOLIDCURSOR,
	NORMALCURSOR
} CURSOR_TYPE;
typedef enum { // ���� �ڵ�
	BLACK = 0, BLUE = 1, GREEN = 2, SKYBLUE = 3, RED = 4, PURPLE = 5, ORANGE = 6,
	WHITE = 7, GREY = 8, LIGHTBLUE = 9, LIGHTGREEN = 10, BLUEGREEN = 11, LIGHTRED = 12, LIGHTPURPLE = 13,
	YELLOW = 14, LIGHTWHITE = 15
} COLOR_TYPE;
typedef enum {
	Main_Cursor_Start_X = 76,
	Main_Cursor_Start_Y = 25,

} Cursor_Start_Pos;
typedef enum {
	Main_Menu = 0,
	Menu_1 = 1,
	Menu_2 = 2,
	Menu_3 = 3,
} Menu_Code;
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
void setcolor(COLOR_TYPE text, COLOR_TYPE back) // ���� ����, ���ڵ��� ���� ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
void textcolor(COLOR_TYPE text) // ���� ���� ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

////////////////////////////////////////////////// ���� ���� // ����ü // �̹��� �迭 ////////////////////////////////

int start = 0; // �÷��� ����
int total_cash = 0; // �� �ݾ� ����
int speed = 800; // delay �ӵ� ���� delay(speed) = 0.8�� 
int text_speed = 10;
int img_speed = 200;
int text_color = LIGHTWHITE;
int cursor_color = ORANGE;
char cursor_shape[3] = "��";

typedef struct doll // ���� ��� ����ü
{
	char name[30]; // �̸�
	int number; // ���� ��ȣ 1, 2, 3 ...
	int price; // ����
	int stock; // �������� (���)
	char profile[100]; // ������ ���� ����

}DOLL;
DOLL doll[4] = { // ���� ����ü ���� ���� {�̸� / ������ȣ / ���� / ������� / �󼼼���}
		{"�����̸� 1", 1, 30000, 5, "��������"},
		{"�����̸� 2", 2, 20000, 5, "��������"},
		{"�����̸� 3", 3, 10000, 5, "��������"},
		{"�����̸� 4", 4, 5000, 5, "��������"},
};

typedef struct cursor_pos
{
	const int start_x;
	const int start_y;
	int cur_x;
	int cur_y;
	const int menu_level;
	int cur_select;
}CURSOR_POS;
CURSOR_POS Main_Menu_Cursor = { Main_Cursor_Start_X, Main_Cursor_Start_Y, Main_Cursor_Start_X,Main_Cursor_Start_Y,0,1 };

int doll_image_01[25][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,15,15,14,14,14,14,14,15,15,15,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0,0,0},
	{0,0,0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0,0},
	{0,0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0,0},
	{0,0,0,0,0,15,14,14,15,0,14,14,14,14,14,14,14,15,0,14,15,0,0,0,0},
	{0,0,0,0,15,14,14,14,0,0,14,14,0,0,0,0,14,0,0,14,15,0,0,0,0},
	{0,0,0,0,15,14,14,14,0,0,14,0,4,4,4,4,0,0,0,14,15,0,0,0,0},
	{0,0,0,0,15,14,14,14,14,14,0,0,0,0,0,0,0,14,14,14,15,15,0,0,0},
	{0,0,0,15,14,14,14,14,14,14,0,4,4,4,4,4,0,14,14,14,15,14,15,0,0},
	{0,0,15,14,14,14,14,14,14,14,14,0,0,0,0,0,14,14,14,14,15,14,14,15,0},
	{0,0,15,14,14,14,0,14,14,14,14,14,14,14,14,14,14,14,14,14,15,14,14,15,0},
	{0,0,15,14,14,0,0,14,0,0,0,0,0,0,0,0,14,14,14,14,15,15,14,15,0},
	{0,0,15,14,14,0,1,1,7,7,7,7,7,7,0,0,14,14,14,14,15,0,15,15,0},
	{0,0,0,15,14,0,1,1,7,7,7,7,7,0,0,14,14,14,14,14,15,0,0,0,0},
	{0,0,0,0,15,14,14,14,0,0,0,0,0,14,14,14,14,14,14,14,15,0,0,0,0},
	{0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0},
	{0,0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0},
	{0,0,0,0,0,15,15,15,15,14,14,14,14,14,14,14,14,14,14,15,15,0,0,0,0},
	{0,0,0,0,0,15,12,12,12,15,14,14,14,14,14,14,14,15,15,12,15,15,0,0,0},
	{0,0,0,0,0,15,12,12,12,12,15,14,14,14,14,14,15,12,12,12,12,15,0,0,0},
	{0,0,0,0,0,0,15,12,12,12,15,15,15,15,15,15,15,12,12,12,12,15,0,0,0},
	{0,0,0,0,0,0,0,15,15,15,15,0,0,0,0,0,15,15,15,15,15,15,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
int doll_image_02[25][25] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,9,11,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,9,11,11,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,9,9,11,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,9,9,11,8,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,9,11,11,11,8,9,1,0,0,0,0,1,1,0,0,0,0},
		{0,0,0,0,0,0,1,9,9,11,11,11,11,9,9,1,0,0,1,15,15,1,0,0,0},
		{0,0,0,0,1,1,9,9,11,11,11,11,11,9,9,9,1,1,15,11,11,1,0,0,0},
		{0,0,0,1,12,9,11,15,11,11,11,11,11,11,9,8,8,15,15,11,11,1,0,0,0},
		{0,0,0,0,1,12,9,0,11,11,11,15,11,9,12,12,8,15,9,15,15,1,0,0,0},
		{0,0,0,1,12,12,9,11,11,11,11,0,11,12,12,12,12,8,15,9,9,1,0,0,0},
		{0,0,0,0,1,1,12,15,11,11,11,11,9,12,12,12,8,8,9,9,1,0,0,0,0},
		{0,0,0,0,0,0,1,1,15,15,15,11,11,8,12,12,8,9,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,8,9,9,11,11,8,8,9,9,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,9,15,15,9,9,9,9,8,9,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,9,9,1,8,9,9,8,1,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,0,1,9,9,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
int doll_image_03[25][25] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,12,12,12,12,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,12,12,4,4,4,4,12,12,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,12,4,4,4,4,4,4,4,4,12,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,12,4,4,4,4,4,4,4,4,4,12,12,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,12,0,0,0,0,0,4,4,4,4,4,4,12,0,0,0,0,0,0,0},
		{0,0,0,0,12,11,11,15,15,11,11,0,4,4,4,4,4,12,0,0,0,0,0,0,0},
		{0,0,0,0,12,11,15,15,15,11,11,11,0,4,4,4,4,4,12,0,0,0,0,0,0},
		{0,0,0,12,11,15,15,15,15,11,11,11,7,0,4,4,4,4,12,12,12,0,0,0,0},
		{0,0,0,12,11,11,11,11,11,11,11,7,7,0,4,4,4,4,12,4,4,12,12,0,0},
		{0,0,0,12,11,11,11,11,11,11,7,7,0,4,4,4,4,4,12,4,4,8,12,0,0},
		{0,0,0,12,11,11,11,11,7,7,7,0,0,4,4,4,4,8,12,4,4,8,12,0,0},
		{0,0,0,0,12,0,0,0,0,0,0,4,4,4,4,4,4,8,12,4,8,8,12,0,0},
		{0,0,0,0,12,4,4,4,4,4,4,4,4,4,4,4,4,8,12,8,8,8,12,0,0},
		{0,0,0,0,12,4,4,4,4,4,4,4,4,4,4,4,8,8,12,8,8,8,12,0,0},
		{0,0,0,0,12,4,4,4,4,4,4,4,4,4,4,4,8,8,12,8,8,12,12,0,0},
		{0,0,0,0,12,4,4,4,4,4,4,4,4,4,4,8,8,8,12,12,12,0,0,0,0},
		{0,0,0,0,12,4,4,4,8,8,8,8,8,4,4,8,8,8,12,0,0,0,0,0,0},
		{0,0,0,0,0,12,8,8,12,12,12,12,12,8,8,8,8,8,12,0,0,0,0,0,0},
		{0,0,0,0,0,12,8,8,12,0,0,0,12,8,8,8,8,12,0,0,0,0,0,0,0},
		{0,0,0,0,0,12,8,8,12,0,0,0,0,12,8,8,8,12,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,12,12,0,0,0,0,0,0,12,12,12,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
int doll_image_04[25][25] = {
		{0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0},
		{0,0,0,0,0,8,1,9,8,0,0,0,0,0,0,0,8,1,9,8,0,0,0,0,0},
		{0,0,0,0,0,8,1,9,9,8,0,0,0,0,0,8,1,1,9,8,0,0,0,0,0},
		{0,0,0,0,0,8,9,9,9,9,8,8,8,8,8,1,1,9,9,8,0,0,0,0,0},
		{0,0,0,0,0,8,9,9,9,9,9,9,9,9,1,1,9,9,9,8,0,0,0,0,0},
		{0,0,0,0,8,9,9,9,9,9,9,9,15,9,9,9,9,9,9,9,8,0,0,0,0},
		{0,0,0,8,7,7,9,9,9,9,9,15,15,15,9,9,9,9,9,7,7,8,0,0,0},
		{0,0,0,8,7,15,15,15,0,15,15,15,15,15,15,15,0,15,15,15,7,8,0,0,0},
		{0,0,8,7,7,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,7,8,0,0},
		{0,0,8,7,15,15,15,15,0,0,15,15,15,15,15,0,0,15,15,15,15,15,8,0,0},
		{0,0,8,15,15,15,15,0,15,0,0,15,15,15,0,15,0,0,15,15,15,15,8,0,0},
		{0,0,8,15,15,15,15,0,0,15,0,15,15,15,0,0,15,0,15,15,15,15,8,0,0},
		{0,0,8,15,15,12,12,12,0,0,15,15,15,15,15,0,0,12,12,12,15,7,8,0,0},
		{0,0,0,8,15,12,12,12,15,15,0,15,0,15,0,15,15,12,12,12,15,8,0,0,0},
		{0,0,0,8,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,7,8,0,0,0},
		{0,0,0,0,8,7,15,15,15,15,15,15,15,15,15,15,15,15,15,7,8,0,0,0,0},
		{0,0,0,0,0,0,8,7,7,15,15,15,15,15,15,15,7,7,8,0,0,0,0,0,0},
		{0,0,0,0,0,8,15,15,15,15,15,15,15,15,7,7,15,15,7,8,0,0,0,0,0},
		{0,0,0,0,8,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,8,0,0,0,0},
		{0,0,0,0,8,15,8,15,15,15,15,15,15,15,15,15,15,15,8,7,8,0,0,0,0},
		{0,0,0,0,0,8,8,15,15,15,15,15,15,15,15,15,15,15,8,8,0,0,0,0,0},
		{0,0,0,0,0,0,8,15,15,15,7,7,7,7,7,15,15,15,8,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,8,15,8,8,8,8,8,8,8,15,8,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,8,7,8,0,0,0,0,0,8,7,8,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0},
};

//////////////////////////////////////////////// ����� ���� �Լ� (�ð� ȿ�� ����) ////////////////////////////////////////////////

void Make_Image(int image[25][25], int x, int y) // �̹��� �迭 ��� �Լ� (����� �̹��� �迭 �̸�, ���� ��ǥ�� �ʿ�)
{
	for (int i = 0; i < 25; i = i + 1) // y
	{
		for (int j = 0; j < 25; j = j + 1) // x
		{
			gotoxy(x + (j * 2), y + i); // ������ ���� ��ǥ�� �̵�
			textcolor(image[i][j]); // �ش� �ȼ��� �����Ͽ� ����ȯ
			printf("��"); // ���
		}
	}
	textcolor(text_color); // ��� �� ������ �ʱ� �������� ����
}

void Text_Effect(char text[])
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		putchar(text[i]);
		delay(text_speed);
	}
}

void Make_Frame() // �׵θ� ���
{
	gotoxy(2, 1); printf("���������������������������������������������������������������������������������������������������������������������\n"); // 116
	for (int y = 2; y < 61; y++)
	{
		gotoxy(2, y); printf("��"); // ���� �� ���
		gotoxy(232, y); printf("��"); // ������ �� ���
	}
	gotoxy(2, 61); printf("���������������������������������������������������������������������������������������������������������������������\n"); // 116
}

void Intro_Screen() // ��Ʈ�� ȭ�� ����
{
	gotoxy(112, 8); printf("< ���� �̱� >"); // ����

	gotoxy(220, 59); printf("Ver 1.0.0"); // ����
}
void Press_Key_Text()
{
	gotoxy(100, 55); printf("<  P R E S S  A N Y  K E Y  T O  S T A R T  >");
}
void Press_Key_Delete()
{
	gotoxy(100, 55); printf("��������������������������������������������������"); // ���� 25��
}
void Intro_Effect() // ��Ʈ�� ȭ��
{
	for (;;)
	{
		Make_Frame(); // �׵θ� ���
		Intro_Screen();// ������ ���� Ÿ��Ʋ ��Ʈ�� ȭ�� ���
		Press_Key_Text();
		delay(speed / 4); // 0.2�� ���
		Press_Key_Delete();
		if (_kbhit()) // Ű �Է� ������ Ż��
		{
			break;
		}
		delay(speed / 4);
		if (_kbhit())
		{
			break;
		}
	}
}
/*void Cursor_Check(CURSOR_POS cursor_temp)
{
	if (cursor_temp.cur_select <= 0)
	{
		Main_Menu_Cursor.cur_select = 1;
		Main_Menu_Cursor.cur_x = Main_Menu_Cursor.start_y;
		Main_Menu_Cursor.cur_y = Main_Menu_Cursor.start_y;
	}
	if (cursor_temp.cur_select >= 7)
	{
		Main_Menu_Cursor.cur_select = 6;
		Main_Menu_Cursor.cur_x = Main_Menu_Cursor.start_y;
		Main_Menu_Cursor.cur_y = Main_Menu_Cursor.start_y+(4*5);
	}
}
*/
void Cursor_Make(CURSOR_POS cursor_temp)
{
	textcolor(cursor_color);
	switch (cursor_temp.menu_level)
	{
	case 0: // ���θ޴��ΰ��
	{
		gotoxy(cursor_temp.cur_x, cursor_temp.cur_y); // ���� �޴� ��� ������ ��ǥ�� �̵�
		puts(cursor_shape); // Ŀ�� ���
	}
	}
	textcolor(text_color);
}
void Cursor_Delete(CURSOR_POS cursor_temp) // Ŀ�� ���� �Լ�
{
	gotoxy(cursor_temp.cur_x, cursor_temp.cur_y);
	printf("��"); // �������� ����
}
void Cursor_Move_Up(CURSOR_POS cursor_temp)
{
	if (cursor_temp.menu_level == 0) // ���� �޴��ϰ��
	{
		if(cursor_temp.cur_select >= 2)
		Main_Menu_Cursor.cur_y = Main_Menu_Cursor.cur_y - 4; // Ŀ�� ��ǥ�� ����
		Main_Menu_Cursor.cur_select = Main_Menu_Cursor.cur_select - 1; // �޴� �� ����
	}
}
void Cursor_Move_Down(CURSOR_POS cursor_temp) // �Ʒ�Ű �Է� �Լ�
{
	
	if (cursor_temp.menu_level == 0 ) // ���� �޴��ϰ��
	{
		if (cursor_temp.cur_select <= 5)
		{
			Main_Menu_Cursor.cur_y = Main_Menu_Cursor.cur_y + 4; // Ŀ�� ��ǥ�� ����
			Main_Menu_Cursor.cur_select = Main_Menu_Cursor.cur_select + 1; // �޴� �� ����
		}
	}

}
//////////////////////////////////////////////// ����� ���� �Լ� (��� ����) ////////////////////////////////////////////////////

int Main_Screen(int x, int y) // ���� �޴� ȭ��
{
	int menu_select = 0;
	int Distance = 4; // ����
	Make_Image(doll_image_01, 5, 20);
	Make_Image(doll_image_02, 182, 20);
	gotoxy(112, 8);				printf("<  �� �� �� ��  >");
	gotoxy(x, y);				printf("< 1 >   �� �� ��   �� ��");
	gotoxy(x, y + Distance * 1); printf("< 2 >   �� �� ��   �� �� �� ��");
	gotoxy(x, y + Distance * 2); printf("< 3 > ");
	gotoxy(x, y + Distance * 3); printf("< 4 >   ȯ �� �� ��");
	gotoxy(x, y + Distance * 4); printf("< 5 >   �� �� ��   /   �� ��");
	gotoxy(x, y + Distance * 5); printf("< 6 >   �� ��");
	gotoxy(100, 56);			printf("�޴��� �����ϼ��� : ");
	


}

void Machine_Screen() // ���� ��� ȭ��
{
	gotoxy(80, 10); printf("<<<�����̱� ���Ǳ� ȭ�� ���;��ϴ°�>>>");
}

int Cash_System_Print(int x, int y) // �ݾ� ���� �ý��� 1 (��� / �Է� ���)
{
	int Distance = 1;
	int cash_select = 0;
	gotoxy(x, y); printf("");
	gotoxy(x, y + Distance); printf("< 1 > 50000��");
	gotoxy(x, y + Distance * 2); printf("< 2 > 10000��");
	gotoxy(x, y + Distance * 3); printf("< 3 > 5000��");
	gotoxy(x, y + Distance * 4); printf("< 4 > 1000��");
	gotoxy(x, y + Distance * 5); printf("");
	gotoxy(x, y + Distance * 6); printf("< 7 > ���� �ݾ� ��ȯ");
	gotoxy(x, y + Distance * 7); printf("< 8 > ���� �ܰ� �̵�");
	gotoxy(x, y + Distance * 8); printf("< 9 > ���� �ܰ� �̵�");
	gotoxy(x, y + Distance * 9); printf("");
	gotoxy(x, y + Distance * 10); printf("< ���� ���� �� �ݾ� : %d �� >", total_cash);
	gotoxy(x, y + Distance * 11); printf("");
	gotoxy(x, y + Distance * 12); printf("� ���� ���� �Ͻðڽ��ϱ�? ");
	scanf("%d", &cash_select);
	return cash_select;
}
void Cash_System_Calculate(int cash_select, int x, int y) // �ݾ� ���� �ý��� 2 (���� ���)
{
	char str[50];
	gotoxy(x, y);
	switch (cash_select) // ���� ���� [3]
	{
	case 1: // 5�������� �����Ѱ��
	{
		strcpy(str, "< 5�������� �����Ͽ����ϴ� >");
		Text_Effect(str);
		total_cash = total_cash + 50000;
		delay(speed);
		break;
	}
	case 2: // 1������ 
	{
		strcpy(str, "< 1�������� �����Ͽ����ϴ� >");
		Text_Effect(str);
		total_cash = total_cash + 10000;
		delay(speed);
		break;
	}
	case 3: // 5õ����
	{
		strcpy(str, "< 5õ������ �����Ͽ����ϴ� >");
		Text_Effect(str);
		total_cash = total_cash + 5000;
		delay(speed);
		break;
	}
	case 4: // 1õ����
	{
		strcpy(str, "< 1õ������ �����Ͽ����ϴ� >");
		Text_Effect(str);
		total_cash = total_cash + 1000;
		delay(speed);
		break;
	}
	case 7: // ȯ��
	{
		strcpy(str, "< ���� ȯ�� ó�� �Ǿ����ϴ�. >");
		Text_Effect(str);
		gotoxy(x, y + 1);
		strcpy(str, "ȯ�� �ݾ� : ");
		Text_Effect(str);
		printf("%d", total_cash);
		strcpy(str, "��");
		Text_Effect(str);
		total_cash = 0;
		delay(speed);
		break;
	}
	case 8: // �ڷΰ���
	{
		strcpy(str, "<<< ���� �޴��� �̵��մϴ� >>>");
		Text_Effect(str);
		delay(speed);
		start = -1;
		break;
	}
	case 9: // ���� �Ϸ�
	{
		strcpy(str, "<<< ���� �ܰ�� �̵��մϴ� >>>");
		Text_Effect(str);
		start = 1; // �÷��� ���� ��ȯ >> Ż�� �� �����̱�� ����
		delay(speed);
		break;
	}
	default:
	{
		strcpy(str, "�߸��� �Է��Դϴ�.");
		Text_Effect(str);
		delay(speed);
		break;
	}
	}
}

int Machine_System_Print(int x, int y) // ���� ���Ǳ� �ý��� 1 (��� / �Է�)
{
	int Distance = 1;
	int doll_select = 0;

	gotoxy(x, y); printf(""); // (80, 40)
	gotoxy(x, y + Distance); printf("< 1�� ���� > ���� : %d �� // �������� : %d ��", doll[0].price, doll[0].stock);
	gotoxy(x, y + Distance * 2); printf("< 2�� ���� > ���� : %d �� // �������� : %d ��", doll[1].price, doll[1].stock);
	gotoxy(x, y + Distance * 3); printf("< 3�� ���� > ���� : %d �� // �������� : %d ��", doll[2].price, doll[2].stock);
	gotoxy(x, y + Distance * 4); printf("< 4�� ���� > ���� : %d �� // �������� : %d ��", doll[3].price, doll[3].stock);
	gotoxy(x, y + Distance * 5); printf("< 8�� : ���� �޴��� �̵� >");
	gotoxy(x, y + Distance * 6); printf("< ���� ���� �ݾ� : %d �� >", total_cash);
	gotoxy(x, y + Distance * 7); printf("");
	gotoxy(x, y + Distance * 8); printf("������ ������ ��ȣ�� �������ּ��� : "); // (80, 48) ������ (80, 49)
	scanf("%d", &doll_select);
	return doll_select;
}
void Machine_System_Activate(int n, int x, int y) // ���� ���Ǳ� �ý��� 2 (����)
{
	char str[50];
	gotoxy(x, y);
	switch (n) // n = doll_select
	{
	case 1:
	case 2:
	case 3:
	case 4: // ���� ���ý� // ����ȭ �� 1~4�� ��츦 ��� ���� ���� �ʿ䰡 ����, ������ �ڵ�� ����
	{
		if (total_cash < doll[n - 1].price) // �ݾ��� �����Ѱ��
		{
			strcpy(str, "�ݾ��� �����մϴ�.");
			Text_Effect(str);
			delay(speed);
			break;
		}
		else if (total_cash >= doll[n - 1].price) // �ݾ��� ����� ����ε�,
		{
			if (doll[n - 1].stock >= 1) // ����� �ִ°�� > ���� ����
			{
				strcpy(str, "���ſ� �����Ͽ����ϴ�.");
				Text_Effect(str);
				total_cash = total_cash - doll[n - 1].price;
				doll[n - 1].stock = doll[n - 1].stock - 1;
				delay(speed);
				break;
			}
			else if (doll[n - 1].stock <= 0) // ����� ���°��
			{
				strcpy(str, "���� ������ �����ϴ�.");
				Text_Effect(str);
				delay(speed);
				break;
			}
		}
	}
	case 8: // �ڷΰ���
	{
		start = 0; // �÷��� ���� �ʱ�ȭ
		strcpy(str, "<<< ���� �޴��� �̵��մϴ� >>>");
		Text_Effect(str);
		delay(speed);
		break;
	}
	default:
	{
		strcpy(str, "�߸� �Է��Ͽ����ϴ�");
		Text_Effect(str);
		delay(speed);
		break;
	}
	}
}

void Randomize_Doll_Stock(int n) // ���� ���� ����ȭ
{
	for (int i = 0; i < 4; i++)
	{
		doll[i].stock = random(n - 1) + 1; // ������� ���� ����
	}
}

void Random_Game_Screen_Print(int x, int y) // ���� �̱� ȭ�� ���
{
	int Distance = 1;
	gotoxy(x, y);				printf("<< ���� �̱� >>");
	gotoxy(x, y + Distance * 1); printf("----------------------------");
	gotoxy(x, y + Distance * 2); printf("1�� ���� ��÷ Ȯ�� : 1%%");
	gotoxy(x, y + Distance * 3); printf("2�� ���� ��÷ Ȯ�� : 4%%");
	gotoxy(x, y + Distance * 4); printf("3�� ���� ��÷ Ȯ�� : 15%%");
	gotoxy(x, y + Distance * 5); printf("4�� ���� ��÷ Ȯ�� : 30%%");
	gotoxy(x, y + Distance * 6); printf("�� Ȯ�� : 50%%");
	gotoxy(x, y + Distance * 7); printf("----------------------------");
}
int Random_Game_Message(int x, int y)
{
	int Distance = 1;
	int input = 0;
	gotoxy(x, y);				printf("< 1 > ���� �̱� ���� ");
	gotoxy(x, y + Distance * 1); printf("< 8 > �ڷΰ���");
	gotoxy(x, y + Distance * 2); printf("----------------------------");
	gotoxy(x, y + Distance * 3); printf("���� ���Ե� �ݾ� : %d ��", total_cash);
	gotoxy(x, y + Distance * 4); printf("----------------------------");
	gotoxy(x, y + Distance * 5); printf("�����ϼ��� : ");
	scanf("%d", &input);
	return input;
}

void Random_Game_Start(int game_menu_select, int x, int y)
{
	int dice = random(100);
	gotoxy(x, y);
	switch (game_menu_select)
	{
	case 1: // ������ �����ߴµ�,
	{
		if (total_cash < random_cost) // ���� �����Ѱ��
		{
			printf("���� �ݾ��� �����մϴ�.");
			delay(speed);
			break;
		}
		else if (total_cash >= random_cost) // ���� ����Ѱ��
		{
			printf("�̱⸦ �����մϴ�.");
			delay(speed);
			total_cash = total_cash - random_cost;
			gotoxy(x, y + 1);
			if (dice < 1) // 0 = 1%
			{
				printf("1�� ��÷ !!! dice�� : %d", dice);
				delay(speed);
			}
			else if (dice >= 1 && dice < 5) // 1~4 = 4%
			{
				printf("2�� ��÷ !!! dice�� : %d", dice);
				delay(speed);
			}
			else if (dice >= 5 && dice < 20) // 5~20 15%
			{
				printf("3�� ��÷ !!! dice�� : %d", dice);
				delay(speed);
			}
			else if (dice >= 20 && dice < 50) // 30%
			{
				printf("3�� ��÷ !!! dice�� : %d", dice);
				delay(speed);
			}
			else if (dice >= 50 && dice < 100) // 50%
			{
				printf("���Դϴ�... dice�� : %d", dice);
				delay(speed);
			}
			else
			{
				printf("�� �� ���� ����");
				delay(speed);
			}
		}
		break;
	}
	case 8: // �ڷ� �̵�
	{
		start = 0;
		printf("���� �޴��� �̵��մϴ�.");
		delay(speed);
		break;
	}
	default:
	{
		printf("�߸��� �Է��Դϴ�.");
		delay(speed);
		break;
	}
	}
}

void Setting_Screen(int x, int y) // ȯ�� ���� �޴�
{
	int input = 0;
	gotoxy(x, y);
	printf("< 1 > �۵� �ӵ� ����");
	printf("< 2 > �ؽ�Ʈ ��� �ӵ� ����");
	printf("< 3 > �ִϸ��̼� �ӵ� ����");
	printf("< 4 > �۾� ���� ����");
	printf("< 5 > �׵θ� ��� ����");
	printf("< 6 > ������ ���");
	printf("< 8 > ���� �޴��� �̵�");
	printf("�����Ͻ� �޴� ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &input);
}
void Information_Screen(int x, int y) // ����, ������ �޴�
{
	gotoxy(x, y);
	printf("< ���� >");
	printf("");
	gotoxy(x, y + 20);
	printf("< �������� >");
	printf("�鼺�� : ");
	printf("������ : ");
	printf("��ȣȯ : ");
	printf("������ : ");
	gotoxy(x, y + 30);
	printf("< ��Ÿ >");
	printf("���� �Ⱓ : 2024�� 10�� 31�� - 2024�� 11�� ��");
	printf("�Ҽ� : �뱸 ��ϻ�����������б� ( AI ������ Ǯ���� ������ ������ - 3 �� )");
	printf("");
}
void Exit_Screen(int x, int y)
{
	gotoxy(x, y);
	printf("���α׷��� �����մϴ�.\n");
}

//////////////////////////////////////////////////// ���� ////////////////////////////////////////////////////////

void main()
{
	//int main_menu_cursor_input = 0; Ŀ�� �ý��� ����� ����� ����
	//int menu_choice = 1; // ���� ������ ��
	int menu_select = 0;	// ���� �޴� ���� ����
	int cash_select = 1;	// ���� �ݾ� ����
	char str[50];
	int input = 0;
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);		// âũ�� ��üȭ��
	setcolor(LIGHTWHITE, BLACK);	// �⺻ ���� ����
	setcursortype(NORMALCURSOR);		// Ŀ�� Ÿ��
	randomize();					// �����Լ����
	Randomize_Doll_Stock(5);		// ��� ���� 1~5�� ����
	Intro_Effect();					// ��Ʈ�� ���
	cls;


	for (;;)	// ���α׷� ����	// ���� ���� �ݺ�
	{
		start = 0;		// �÷��� ����
		Make_Frame();
		Main_Screen(80, 25); // �޴� ����ȭ�� ��� �Լ�
		Cursor_Make(Main_Menu_Cursor);
		
			if (_kbhit())
			{
				input = _getch();
				switch (input)
				{
				case 72: // ��Ű
				{
					Cursor_Delete(Main_Menu_Cursor);
					Cursor_Move_Up(Main_Menu_Cursor);
					break;
				}
				case 80: // �Ʒ�Ű
				{
					Cursor_Delete(Main_Menu_Cursor);
					Cursor_Move_Down(Main_Menu_Cursor);
					break;
				}

				}
			}
		switch (menu_select) // ���� �޴� ���� [1]
		{
		case 1: // 1���޴� �����̱� ���� [2]
		{
			start = 0; // �÷��� ���� �ʱ�ȭ //
			for (; start == 0;) // �����̱��� �ݾ����� �ݺ� ���� [2] (�÷��� ���� start�� 0 �� ��� ���� ����)
			{
				cls;
				Make_Frame();
				Machine_Screen(); // ���� ���
				cash_select = Cash_System_Print(80, 35); // ��� �� �Է� �ޱ� �Լ� ��ǥ�� ���
				Cash_System_Calculate(cash_select, 80, 50); // ��� �� ��ǥ�� ���

				for (; start == 1;) // �����̱� ���� �ݺ� ���� (�÷��� ������ 1 �ϰ��)
				{
					int doll_select = 0;
					cls;
					Make_Frame();
					Machine_Screen();
					doll_select = Machine_System_Print(80, 40); // �ش���ǥ�� ���
					Machine_System_Activate(doll_select, 80, 49);
				}
				if (start == -1)
				{
					break;
				}
			}// for(;;)
			break;
		} // case 1 ���� �̱� �޴� ����

		case 2: // 2�� �޴� ���� �̱� �޴� ����
		{

			start = 0; // �÷��� ���� �ʱ�ȭ //
			for (; start == 0;) // �ݾ� ���� ����
			{
				cls;
				Make_Frame();
				Random_Game_Screen_Print(80, 35); // Ȯ�� ǥ ���
				cash_select = Cash_System_Print(80, 43); // ��� �� �Է� �ޱ� �Լ� ��ǥ�� ���
				Cash_System_Calculate(cash_select, 80, 58); // ��� �� ��ǥ�� ���

				for (; start == 1;) // ���� ���� ����
				{
					int random_menu_select = 0;
					cls;
					Make_Frame();
					Random_Game_Screen_Print(80, 46);
					random_menu_select = Random_Game_Message(80, 43);
					Random_Game_Start(random_menu_select, 80, 50);

				}
				if (start == -1)
				{
					break;
				}
			} // for (start == 0);
			break;
		} // case 2 :



		case 3: // 3�� �޴� �̱���
		{
			break;
		}
		case 4: // ȯ�漳��
		{
			Setting_Screen(80, 20);
			_getch();
			break;
		}
		case 5: // ���� // ����
		{
			cls;
			Information_Screen(80, 20);
			_getch();
			break;
		}
		case 6: // ����
		{
			cls;
			Exit_Screen(80, 20);
			exit(0);
		}
		default: // �߸��ԷµȰ�� (���θ޴�)
		{
			break;
		}

		} // ���� �޴� switch

	} // for(;;) = ���� �޴� �ݺ�

} // void main ()