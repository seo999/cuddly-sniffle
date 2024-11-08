////////////////////////////////////////////////////// 정의 ////////////////////////////////////////////////////
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
////////////////////////////////////////////////////// 유용한 기능 함수 /////////////////////////////////////////
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}
int wherey()
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
typedef enum {
	BLACK = 0, BLUE = 1, GREEN = 2, SKYBLUE = 3, RED = 4, PURPLE = 5, ORANGE = 6,
	WHITE = 7, GREY = 8, LIGHTBLUE = 9, LIGHTGREEN = 10, BLUEGREEN = 11, LIGHTRED = 12, LIGHTPURPLE = 13,
	YELLOW = 14, LIGHTWHITE = 15
} COLOR_TYPE;
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
void setcolor(COLOR_TYPE text, COLOR_TYPE back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
void textcolor(COLOR_TYPE text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayPattern1() {
	int dollone[25][25] = {
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

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			switch (dollone[i][j]) {
			case 0:
				setColor(0); // 검은색
				printf("■");
				break;
			case 1:
				setColor(1); // 파란색
				printf("■");
				break;
			case 4:
				setColor(4); // 빨간색
				printf("■");
				break;
			case 7:
				setColor(7); // 회색
				printf("■");
				break;
			case 12:
				setColor(12); // 밝은 빨간색
				printf("■");
				break;
			case 14:
				setColor(14); // 밝은 노란색
				printf("■");
				break;
			case 15:
				setColor(15); // 흰색
				printf("■");
				break;
			}
			setColor(15); // 기본 흰색으로 리셋
		}
		printf("\n"); // 한 행이 끝난 후 줄바꿈
	}
}
void displayPattern2() {
	int dolltwo[25][25] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},
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

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			switch (dolltwo[i][j]) {
			case 0:
				setColor(0); // 검은색
				printf("■");
				break;
			case 1:
				setColor(1); // 파란색
				printf("■");
				break;
			case 4:
				setColor(4); // 빨간색
				printf("■");
				break;
			case 7:
				setColor(7); // 회색
				printf("■");
				break;
			case 8:
				setColor(8); // 짙은 회색
				printf("■");
				break;
			case 9:
				setColor(9); // 밝은 파란색
				printf("■");
				break;
			case 11:
				setColor(11); // 밝은 청록색
				printf("■");
				break;
			case 12:
				setColor(12); // 밝은 빨간색
				printf("■");
				break;
			case 14:
				setColor(14); // 밝은 노란색
				printf("■");
				break;
			case 15:
				setColor(15); // 흰색
				printf("■");
				break;
			}
			setColor(15); // 기본 흰색으로 리셋
		}
		printf("\n"); // 한 행이 끝난 후 줄바꿈
	}
}
void displayPattern3() {
	int dollthree[25][25] = {
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

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			switch (dollthree[i][j]) {
			case 0:
				setColor(0); // 검은색
				printf("■");
				break;
			case 1:
				setColor(1); // 파란색
				printf("■");
				break;
			case 4:
				setColor(4); // 빨간색
				printf("■");
				break;
			case 5:
				setColor(5); // 보라색
				printf("■");
				break;
			case 7:
				setColor(7); // 회색
				printf("■");
				break;
			case 8:
				setColor(8); // 짙은 회색
				printf("■");
				break;
			case 9:
				setColor(9); // 밝은 파란색
				printf("■");
				break;
			case 11:
				setColor(11); // 밝은 청록색
				printf("■");
				break;
			case 12:
				setColor(12); // 밝은 빨간색
				printf("■");
				break;
			case 13:
				setColor(13); // 밝은 보라
				printf("■");
				break;
			case 15:
				setColor(15); // 흰색
				printf("■");
				break;
			}
			setColor(15); // 기본 흰색으로 리셋
		}
		printf("\n"); // 한 행이 끝난 후 줄바꿈
	}
}
void displayPattern4() {
	int dollfour[25][25] = {
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
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			switch (dollfour[i][j]) {
			case 0:
				setColor(0); // 검은색
				printf("■");
				break;
			case 1:
				setColor(1); // 파란색
				printf("■");
				break;
			case 7:
				setColor(7); // 회색
				printf("■");
				break;
			case 8:
				setColor(8); // 짙은 회색
				printf("■");
				break;
			case 9:
				setColor(9); // 밝은 파란색
				printf("■");
				break;
			case 12:
				setColor(12); // 밝은 빨간색
				printf("■");
				break;
			case 15:
				setColor(15); // 흰색
				printf("■");
				break;
			}
			setColor(15); // 기본 흰색으로 리셋
		}
		printf("\n"); // 한 행이 끝난 후 줄바꿈
	}
}
void OMG()
{

	char ask; //픽 최종확인 스페이스바를 입력받을 캐릭터형 변수
	char pick;
	COORD pos; //좌표를 저장할 구조체형식의 position 저장할 변수
	int firstEncounter = 0;
	while (1)
	{
		pos.X = 0; //x좌표 0으로
		pos.Y = 36; //y좌표 28로. 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서를 위 좌표 두개로 옮김
		for (int i = 0; i < 20; i++) //좌표서부터 아래로 20줄간
		{
			printf("                                                                                                                                   \n"); //기존 적힌 내용을 덮어씌워 지움
		}
		pos.X = 20;
		pos.Y = 36; //◀◀◀◀커서 위치 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //옮겨진 좌표로 커서이동

		//▼처음 픽화면 떳을때 혹은 잘못 입력받았을때 pick에 입력을 받는 기능
		if (firstEncounter == 0)
		{
			pick = getchar();
		}

		//▼1,2,3입력 이외엔 전부 뱉어내는 조건문
		if (!(pick == '1' || pick == '2' || pick == '3' || pick == '4'))
		{
			printf("\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　1~4만 입력하십시오!\n");
			Sleep(500); //읽을 시간을 잠시 줌
			firstEncounter = 0; //새로 픽을 입력 받아야 하므로 firstEncounter 플래그를 다시 0으로 바꾸어줌
			continue; //루프 다시 시작
		}
		else
		{

			switch (pick)
			{
			case '1':
			{//[케이스1 괄호 시작하는 중괄호] (스위치문은 내부에서 변수를 선언할수 없으므로 중괄호가 필요. 이하 본 내용 생략)
				{
					for (int i = 0; i < 25; i++)
					{
						displayPattern1();
						break;
						printf("\n"); //한줄 출력 후 띄우기
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//원래 콘솔 색깔로 복귀
				}

				{
					pos.X = 60;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서를 이동
					printf("푹찍이\n"); //이동한 곳에서 출력
					pos.Y = 40;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					pos.Y = 42;
					printf("□□□□□□□□□□□□\n");
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("번   호 : 1번\n");
					pos.Y = 44;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("금   액: 20,000원\n");
					pos.Y = 46;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("재고 수량: 5개 \n");
					pos.Y = 48;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("특징 : 인형인데 금방이라도 칼을 휘두를것같다.칼은 다행히 모형이다. ");
					pos.Y = 50;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("해당 캐릭터로 진행하시겠습니까?");
					pos.Y = 52;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("선택은 스페이스, 재선택은 1, 2, 3, 4 입력");
				} //커서 닫기

				//▼이 픽이 맞는지 확인하는 ask
				ask = _getch(); //pick과 ask를 분리해둔 이유는 고른적 없는상태서 스페이스바를 누르는걸 방지하기 위해서임
				if (ask == ' ') //스페이스바가 눌렸을때
				{
					for (int i = 0; i < 100; i++)
					{
						printf("\n"); //화면 전체를 밀어올리는 효과를 줄 수 있음
						Sleep(5); //너무 빨리 지나가면 안보이니 살짝 딜레이를 줌
					}
					system("cls");
				}
				else
				{
					pick = ask;
					firstEncounter++; //이미 픽을 한번 받았기 때문에 첫 화면이 아니란 사실을 알리기 위해 플래그를 세움 (사실상 BOOL true로 바꾼꼴)
					continue; //스페이스바를 입력받지 않았다면 다시 루프시작
				}
			}
			break; //케이스1 종료용 브레이크

			case '2':
			{
				{
					for (int i = 0; i < 25; i++)
					{
						displayPattern2();
						break;
						printf("\n"); //한줄 출력 후 띄우기
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//원래 콘솔 색깔로 복귀
				}
				{
					pos.X = 60; //x는 80번째 칸으로
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서를 이동
					printf("푹찍이\n"); //이동한 곳서 출력
					pos.Y = 40; //y는 30번째 줄로
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //이하 동일 로직
					pos.Y = 42;
					printf("□□□□□□□□□□□□\n");
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("번   호 : 2번\n");
					pos.Y = 44;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("금   액: 20,000원\n");
					pos.Y = 46;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("재고 수량: 5개 \n");
					pos.Y = 48;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("특징 : 인형인데 금방이라도 칼을 휘두를것같다.칼은 다행히 모형이다. ");
					pos.Y = 50;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("해당 캐릭터로 진행하시겠습니까?");
					pos.Y = 52;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("선택은 스페이스, 재선택은 1, 2, 3, 4 입력");
				} //커서 닫기

				//▼이 픽이 맞는지 확인하는 ask
				ask = _getch(); //pick과 ask를 분리해둔 이유는 한번도 고른적 없는상태서 스페이스바를 누르는걸 방지하기 위해서임
				if (ask == ' ') //스페이스바가 눌렸을때
				{
					for (int i = 0; i < 55; i++) //화면 크기가 50이니 조금 더 안전하게 55줄동안
					{
						printf("\n"); //화면 전체를 밀어올리는 효과를 줄 수 있음
						Sleep(5); //너무 빨리 지나가면 안보이니 살짝 딜레이를 줌
					}
				}
				else
				{
					pick = ask;
					firstEncounter++; //이미 픽을 한번 받았기 때문에 첫 화면이 아니란 사실을 알리기 위해 플래그를 세움 (사실상 BOOL true로 바꾼꼴)
					continue; //스페이스바를 입력받지 않았다면 다시 루프시작
				}
			}
			break; //케이스2 종료용 브레이크

			case '3':
			{
				{
					for (int i = 0; i < 25; i++)
					{
						displayPattern3();
						break;
						printf("\n"); //한줄 출력 후 띄우기
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//원래 콘솔 색깔로 복귀
				}
				{
					pos.X = 60; //x는 80번째 칸으로
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서를 이동
					printf("푹찍이\n"); //이동한 곳서 출력
					pos.Y = 40; //y는 30번째 줄로
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //이하 동일 로직
					pos.Y = 42;
					printf("□□□□□□□□□□□□\n");
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("번   호 : 3번\n");
					pos.Y = 44;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("금   액: 20,000원\n");
					pos.Y = 46;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("재고 수량: 5개 \n");
					pos.Y = 48;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("특징 : 인형인데 금방이라도 칼을 휘두를것같다.칼은 다행히 모형이다. ");
					pos.Y = 50;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("해당 캐릭터로 진행하시겠습니까?");
					pos.Y = 52;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("선택은 스페이스, 재선택은 1, 2, 3, 4 입력");
				} //커서 닫기

				//▼이 픽이 맞는지 확인하는 ask
				ask = _getch(); //pick과 ask를 분리해둔 이유는 한번도 고른적 없는상태서 스페이스바를 누르는걸 방지하기 위해서임
				if (ask == ' ') //스페이스바가 눌렸을때
				{
					for (int i = 0; i < 55; i++) //화면 크기가 50이니 조금 더 안전하게 55줄동안
					{
						printf("\n"); //화면 전체를 밀어올리는 효과를 줄 수 있음
						Sleep(5); //너무 빨리 지나가면 안보이니 살짝 딜레이를 줌
					}
				}
				else
				{
					pick = ask;
					firstEncounter++;
					continue;
				}
			}
			break; //케이스3 종료용 브레이크

			case '4':
			{
				{
					for (int i = 0; i < 25; i++)
					{
						displayPattern4();
						break;
						printf("\n"); //한줄 출력 후 띄우기
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//원래 콘솔 색깔로 복귀
				}
				{
					pos.X = 60;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서를 이동
					printf("푹찍이\n"); //이동한 곳서 출력
					pos.Y = 40; //y는 30번째 줄로
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //이하 동일 로직
					pos.Y = 42;
					printf("□□□□□□□□□□□□\n");
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("번   호 : 4번\n");
					pos.Y = 44;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("금   액: 20,000원\n");
					pos.Y = 46;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("재고 수량: 5개 \n");
					pos.Y = 48;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("특징 : 인형인데 금방이라도 칼을 휘두를것같다.칼은 다행히 모형이다. ");
					pos.Y = 50;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("해당 캐릭터로 진행하시겠습니까?");
					pos.Y = 52;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
					printf("선택은 스페이스, 재선택은 1, 2, 3, 4 입력");
				} //커서 닫기

				//▼이 픽이 맞는지 확인하는 ask
				ask = _getch(); //pick과 ask를 분리해둔 이유는 한번도 고른적 없는상태서 스페이스바를 누르는걸 방지하기 위해서임
				if (ask == ' ') //스페이스바가 눌렸을때
				{
					for (int i = 0; i < 55; i++) //화면 크기가 50이니 조금 더 안전하게 55줄동안
					{
						printf("\n"); //화면 전체를 밀어올리는 효과를 줄 수 있음
						Sleep(5); //너무 빨리 지나가면 안보이니 살짝 딜레이를 줌
					}
				}
				else
				{
					pick = ask;
					firstEncounter++; //이미 픽을 한번 받았기 때문에 첫 화면이 아니란 사실을 알리기 위해 플래그를 세움 (사실상 BOOL true로 바꾼꼴)
					continue; //스페이스바를 입력받지 않았다면 다시 루프시작
				}
			}
			break; //케이스4 종료용 브레이크

			}

		}
	}

}
void displayPatternall()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);


	int dollone[30][111] = {
		{0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,15,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,8,8,0,0,0,0,0,0,0,0,0,8,8,0,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,8,1,9,8,0,0,0,0,0,0,0,8,1,9,8,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,8,1,9,9,8,0,0,0,0,0,8,1,1,9,8,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,15,15,14,14,14,14,14,15,15,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,12,12,12,12,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,8,9,9,9,9,8,8,8,8,8,1,1,9,9,8,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,1,9,11,1,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,12,12,4,4,4,4,12,12,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,8,9,9,9,9,9,9,9,9,1,1,9,9,9,8,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0,0,15,0,0,0,0,0,0,0,1,9,11,11,1,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,12,4,4,4,4,4,4,4,4,12,0,0,0,0,0,0,0,0,15,0,0,0,0,8,9,9,9,9,9,9,9,15,9,9,9,9,9,9,9,8,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0,0,15,0,0,0,0,0,0,0,1,9,9,11,1,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,12,4,4,4,4,4,4,4,4,4,12,12,0,0,0,0,0,0,0,15,0,0,0,8,7,7,9,9,9,9,9,15,15,15,9,9,9,9,9,7,7,8,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,15,14,14,15,0,14,14,14,14,14,14,14,15,0,14,15,0,0,0,0,15,0,0,0,0,0,0,0,1,9,9,11,8,1,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,12,0,0,0,0,0,4,4,4,4,4,4,12,0,0,0,0,0,0,15,0,0,0,8,7,15,15,15,0,15,15,15,15,15,15,15,0,15,15,15,7,8,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,15,14,14,14,0,0,14,14,0,0,0,0,14,0,0,14,15,0,0,0,0,15,0,0,0,0,0,0,1,9,11,11,11,8,9,1,0,0,0,0,1,1,0,0,0,15,0,0,0,12,11,11,15,15,11,11,0,4,4,4,4,4,12,0,0,0,0,0,0,15,0,0,8,7,7,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,7,8,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,15,14,14,14,0,0,14,0,4,4,4,4,0,0,0,14,15,0,0,0,0,15,0,0,0,1,1,9,9,11,11,11,11,11,9,9,9,1,1,15,11,11,1,0,0,15,0,0,0,12,11,15,15,15,11,11,11,0,4,4,4,4,4,12,0,0,0,0,0,15,0,0,8,7,15,15,15,15,0,0,15,15,15,15,15,0,0,15,15,15,15,15,8,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,15,14,14,14,14,14,0,0,0,0,0,0,0,14,14,14,15,15,0,0,0,15,0,0,1,12,9,11,15,11,11,11,11,11,11,9,8,8,15,15,11,11,1,0,0,15,0,0,12,11,15,15,15,15,11,11,11,7,0,4,4,4,4,12,12,12,0,0,0,15,0,0,8,15,15,15,15,0,15,0,0,15,15,15,0,15,0,0,15,15,15,15,8,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,15,14,14,14,14,14,14,0,4,4,4,4,4,0,14,14,14,15,14,15,0,0,15,0,0,0,1,12,9,0,11,11,11,15,11,9,12,12,8,15,9,15,15,1,0,0,15,0,0,12,11,11,11,11,11,11,11,7,7,0,4,4,4,4,12,4,4,12,12,0,15,0,0,8,15,15,15,15,0,0,15,0,15,15,15,0,0,15,0,15,15,15,15,8,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,15,14,14,14,14,14,14,14,14,0,0,0,0,0,14,14,14,14,15,14,14,15,0,15,0,0,1,12,12,9,11,11,11,11,0,11,12,12,12,12,8,15,9,9,1,0,0,15,0,0,12,11,11,11,11,11,11,7,7,0,4,4,4,4,4,12,4,4,8,12,0,15,0,0,8,15,15,12,12,12,0,0,15,15,15,15,15,0,0,12,12,12,15,7,8,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,15,14,14,14,0,14,14,14,14,14,14,14,14,14,14,14,14,14,15,14,14,15,0,15,0,0,0,1,1,12,15,11,11,11,11,9,12,12,12,8,8,9,9,1,0,0,0,15,0,0,12,11,11,11,11,7,7,7,0,0,4,4,4,4,8,12,4,4,8,12,0,15,0,0,0,8,15,12,12,12,15,15,0,15,0,15,0,15,15,12,12,12,15,8,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,15,14,14,0,0,14,0,0,0,0,0,0,0,0,14,14,14,14,15,15,14,15,0,15,0,0,0,0,0,1,1,15,15,15,11,11,8,12,12,8,9,1,1,0,0,0,0,15,0,0,0,12,0,0,0,0,0,0,4,4,4,4,4,4,8,12,4,8,8,12,0,15,0,0,0,8,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,7,8,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,15,14,14,0,1,1,7,7,7,7,7,7,0,0,14,14,14,14,15,0,15,15,0,15,0,0,0,0,0,0,1,1,8,9,9,11,11,8,8,9,9,1,0,0,0,0,0,15,0,0,0,12,4,4,4,4,4,4,4,4,4,4,4,4,8,12,8,8,8,12,0,15,0,0,0,0,8,7,15,15,15,15,15,15,15,15,15,15,15,15,15,7,8,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,15,14,0,1,1,7,7,7,7,7,0,0,14,14,14,14,14,15,0,0,0,0,15,0,0,0,0,0,0,0,1,9,15,15,9,9,9,9,8,9,1,0,0,0,0,0,15,0,0,0,12,4,4,4,4,4,4,4,4,4,4,4,8,8,12,8,8,8,12,0,15,0,0,0,0,0,0,8,7,7,15,15,15,15,15,15,15,7,7,8,0,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,15,14,14,14,0,0,0,0,0,14,14,14,14,14,14,14,15,0,0,0,0,15,0,0,0,0,0,0,0,1,9,9,1,8,9,9,8,1,1,0,0,0,0,0,0,15,0,0,0,12,4,4,4,4,4,4,4,4,4,4,4,8,8,12,8,8,12,12,0,15,0,0,0,0,0,8,15,15,15,15,15,15,15,15,7,7,15,15,7,8,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0,15,0,0,0,0,0,0,0,0,1,1,0,1,9,9,1,0,0,0,0,0,0,0,0,15,0,0,0,12,4,4,4,4,4,4,4,4,4,4,8,8,8,12,12,12,0,0,0,15,0,0,0,0,8,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,8,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,15,14,14,14,14,14,14,14,14,14,14,14,14,14,14,15,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,15,0,0,0,12,4,4,4,8,8,8,8,8,4,4,8,8,8,12,0,0,0,0,0,15,0,0,0,0,8,15,8,15,15,15,15,15,15,15,15,15,15,15,8,7,8,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,15,15,15,15,14,14,14,14,14,14,14,14,14,14,15,15,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,12,8,8,12,12,12,12,12,8,8,8,8,8,12,0,0,0,0,0,15,0,0,0,0,0,8,8,15,15,15,15,15,15,15,15,15,15,15,8,8,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,15,12,12,12,15,14,14,14,14,14,14,14,15,15,12,15,15,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,12,8,8,12,0,0,0,12,8,8,8,8,12,0,0,0,0,0,0,15,0,0,0,0,0,0,8,15,15,15,7,7,7,7,7,15,15,15,8,0,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,15,12,12,12,12,15,14,14,14,14,14,15,12,12,12,12,15,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,12,8,8,12,0,0,0,0,12,8,8,8,12,0,0,0,0,0,0,15,0,0,0,0,0,0,0,8,15,7,7,7,7,7,7,7,15,8,0,0,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,15,12,12,12,15,15,15,15,15,15,15,12,12,12,12,15,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,12,12,0,0,0,0,0,0,12,12,12,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,8,15,8,8,8,8,8,8,8,15,8,0,0,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,15,15,15,15,0,0,0,0,0,15,15,15,15,15,15,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,8,7,8,0,0,0,0,0,8,7,8,0,0,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,8,8,8,0,0,0,0,0,8,8,8,0,0,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15},
		{0,15,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15},
	};

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 111; j++) {
			switch (dollone[i][j]) {
			case 0:
				setColor(0); // 검은색
				printf("■");
				break;
			case 1:
				setColor(1); // 파란색
				printf("■");
				break;
			case 2:
				setColor(2);
				printf("■");
				break;
			case 3:
				setColor(3);
				printf("■");
				break;
			case 4:
				setColor(4); // 빨간색
				printf("■");
				break;
			case 5:
				setColor(5); // 빨간색
				printf("■");
				break;
			case 6:
				setColor(6); // 회색
				printf("■");
				break;
			case 7:
				setColor(7); // 회색
				printf("■");
				break;
			case 8:
				setColor(8); // 회색
				printf("■");
				break;
			case 9:
				setColor(9); // 회색
				printf("■");
				break;
			case 10:
				setColor(10); // 회색
				printf("■");
				break;
			case 11:
				setColor(11); // 회색
				printf("■");
				break;
			case 12:
				setColor(12); // 밝은 빨간색
				printf("■");
				break;
			case 14:
				setColor(14); // 밝은 노란색
				printf("■");
				break;
			case 15:
				setColor(15); // 흰색
				printf("■");
				break;
			}
			setColor(15); // 기본 흰색으로 리셋
		}
		printf("\n"); // 한 행이 끝난 후 줄바꿈

	}
	printf("  ■              ┌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐ ┌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐ ┌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐ ┌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┐ \n");
	printf("  ■　　　　　  　│　 　　 　　 　　▶◀ 푹찍이 ▶◀ 　　　 　　 　│ │　 　　 　　　▶◀ 물찍이 ▶◀ 　　　　 　 　│ │　 　　 　　 　▶◀ 어몽이 ▶◀ 　　　　　 　│ │　 　　 　　 　 　▶◀ 치냥이 ▶◀ 　　　　 　  　│ \n");
	printf("  ■              └━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┘ └━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┘ └━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┘ └━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┘");
	OMG();
}



////////////////////////////////////////////////// 전역 변수 // 구조체 ///////////////////////////////////////////

int start = 0; // 플래그 변수
int total_cash = 0; // 총 금액 변수
int speed = 800;

typedef struct doll // 인형 목록 구조체
{
	char name[30]; // 이름
	int number; // 번호 1, 2, 3 ...
	int price; // 가격
	int stock; // 남은수량 (재고)
	char description[100]; // 인형에 대한 설명

}DOLL;
DOLL doll[4] = { // 인형 5종류 선언 {이름 / 고유번호 / 가격 / 재고수량 / 상세설명}
		{"인형이름 1", 1, 20000, 5, "설명"},
		{"인형이름 2", 2, 10000, 5, "설명"},
		{"인형이름 3", 3, 5000, 5, "설명"},
		{"인형이름 4", 4, 2000, 5, "설명"},
};

//////////////////////////////////////////////// 사용자 정의 함수 ////////////////////////////////////////////////
void Make_Frame()
{
	gotoxy(2, 1); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); // 116
	for (int y = 2; y < 61; y++)
	{
		gotoxy(2, y); printf("■"); // 왼쪽 벽 출력
		gotoxy(232, y); printf("■"); // 오른쪽 벽 출력
	}
	gotoxy(2, 61); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"); // 116
}

void Intro_Screen()
{
	gotoxy(112, 8); printf("< 인형 뽑기 >");

	gotoxy(220, 59); printf("Ver 1.0.0");
}
void Press_Key_Text()
{
	gotoxy(100, 55); printf("<  P R E S S  A N Y  K E Y  T O  S T A R T  >");
}
void Press_Key_Delete()
{
	gotoxy(100, 55); printf("　　　　　　　　　　　　　　　　　　　　　　　　　"); // 공백 25개
}

void Intro_Effect()
{
	for (;;)
	{
		Make_Frame(); // 테두리 출력
		Intro_Screen();// 간단한 메인 타이틀 인트로 화면 출력
		Press_Key_Text();
		delay(speed / 4);
		Press_Key_Delete();
		if (_kbhit())
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

int Main_Screen(int x, int y)
{
	int menu_select = 0;
	int Distance = 4; // 간격
	gotoxy(112, 8);				printf("< 메인 메뉴 >");
	gotoxy(x, y);				printf("< 1 > 자판기 실행");
	gotoxy(x, y + Distance * 1); printf("< 2 > 복불복 랜덤 뽑기");
	gotoxy(x, y + Distance * 2); printf("< 3 > 도움말 / 제작자");
	gotoxy(x, y + Distance * 3); printf("< 4 > 종료");
	gotoxy(x, y + Distance * 4); printf("< 5 > ");
	gotoxy(x, y + Distance * 5); printf("< 6 > ");
	gotoxy(100, 56);			printf("메뉴를 선택하세요 : ");
	gotoxy(120, 56);
	scanf("%d", &menu_select);
	return menu_select;
}

void Machine_Screen() // ◀◀◀◀캐릭터 선택창
{
	gotoxy(0, 3);
	displayPatternall();

}

int Cash_System_Print(int x, int y)
{
	int Distance = 1;
	int cash_select = 0;
	gotoxy(x, y); printf("");
	gotoxy(x, y + Distance); printf("< 1 > 50000원");
	gotoxy(x, y + Distance * 2); printf("< 2 > 10000원");
	gotoxy(x, y + Distance * 3); printf("< 3 > 5000원");
	gotoxy(x, y + Distance * 4); printf("< 4 > 1000원");
	gotoxy(x, y + Distance * 5); printf("");
	gotoxy(x, y + Distance * 6); printf("< 7 > 투입 금액 반환");
	gotoxy(x, y + Distance * 7); printf("< 8 > 이전 단계 이동");
	gotoxy(x, y + Distance * 8); printf("< 9 > 다음 단계 이동");
	gotoxy(x, y + Distance * 9); printf("");
	gotoxy(x, y + Distance * 10); printf("< 현재 투입 총 금액 : %d 원 >", total_cash);
	gotoxy(x, y + Distance * 11); printf("");
	gotoxy(x, y + Distance * 12); printf("어떤 지폐를 투입 하시겠습니까? ");
	scanf("%d", &cash_select);
	return cash_select;
}
void Cash_System_Calculate(int cash_select, int x, int y)
{
	gotoxy(x, y);
	switch (cash_select) // 지폐 선택 [3]
	{
	case 1: // 5만원권을 선택한경우
	{
		printf("< 5만원권을 투입하였습니다 >");
		total_cash = total_cash + 50000;
		delay(speed);
		break;
	}
	case 2: // 1만원권 
	{
		printf("< 1만원권을 투입하였습니다 >");
		total_cash = total_cash + 10000;
		delay(speed);
		break;
	}
	case 3: // 5천원권
	{
		printf("< 5천원권을 투입하였습니다 >");
		total_cash = total_cash + 5000;
		delay(speed);
		break;
	}
	case 4: // 1천원권
	{
		printf("< 1천원권을 투입하였습니다 >");
		total_cash = total_cash + 1000;
		delay(speed);
		break;
	}
	case 7: // 환불
	{
		printf("<<< %d 원이 환불되었습니다 >>>", total_cash);
		total_cash = 0;
		delay(speed);
		break;
	}
	case 8: // 뒤로가기
	{
		printf("<<< 이전 메뉴로 이동합니다 >>>");
		delay(speed);
		start = -1;
		break;
	}
	case 9: // 투입 완료
	{
		printf("<<< 다음 단계로 이동합니다 >>>");
		start = 1; // 플래그 변수 전환 >> 탈출 후 인형뽑기로 진입
		delay(speed);
		break;
	}
	default:
	{
		printf("잘못된 입력입니다.");
		delay(speed);
		break;
	}
	}
}

int Machine_System_Print(int x, int y)
{
	int Distance = 1;
	int doll_select = 0;

	gotoxy(x, y); printf(""); // (80, 40)
	gotoxy(x, y + Distance); printf("< 1번 인형 > 가격 : %d 원 // 남은수량 : %d 개", doll[0].price, doll[0].stock);
	gotoxy(x, y + Distance * 2); printf("< 2번 인형 > 가격 : %d 원 // 남은수량 : %d 개", doll[1].price, doll[1].stock);
	gotoxy(x, y + Distance * 3); printf("< 3번 인형 > 가격 : %d 원 // 남은수량 : %d 개", doll[2].price, doll[2].stock);
	gotoxy(x, y + Distance * 4); printf("< 4번 인형 > 가격 : %d 원 // 남은수량 : %d 개", doll[3].price, doll[3].stock);
	gotoxy(x, y + Distance * 5); printf("< 8번 : 이전 메뉴로 이동 >");
	gotoxy(x, y + Distance * 6); printf("< 현재 투입 금액 : %d 원 >", total_cash);
	gotoxy(x, y + Distance * 7); printf("");
	gotoxy(x, y + Distance * 8); printf("뽑으실 인형의 번호를 선택해주세요 : "); // (80, 48) 다음줄 (80, 49)
	scanf("%d", &doll_select);
	return doll_select;
}
void Machine_System_Activate(int n, int x, int y)
{
	gotoxy(x, y);
	switch (n) // n = doll_select
	{
	case 1:
	case 2:
	case 3:
	case 4: // 간소화 후 1~4의 경우를 모두 따로 적을 필요가 없음, 동일한 코드니 통일
	{
		if (total_cash < doll[n - 1].price) // 금액이 부족한경우
		{
			printf("금액이 부족합니다.");
			delay(speed);
			break;
		}
		else if (total_cash >= doll[n - 1].price) // 금액이 충분한 경우인데,
		{
			if (doll[n - 1].stock >= 1) // 재고가 있는경우 > 구매 성공
			{
				printf("구매에 성공하였습니다.");
				total_cash = total_cash - doll[n - 1].price;
				doll[n - 1].stock = doll[n - 1].stock - 1;
				delay(speed);
				break;
			}
			else if (doll[n - 1].stock <= 0) // 재고가 없는경우
			{
				printf("남은 수량이 없습니다.");
				delay(speed);
				break;
			}
		}
	}
	case 8: // 뒤로가기
	{
		start = 0; // 플래그 변수 초기화
		printf("<<< 이전 메뉴로 이동합니다 >>>");
		delay(speed);
		break;
	}
	default:
	{
		printf("잘못 입력하였습니다");
		delay(speed);
		break;
	}
	}
}

void Randomize_Doll_Stock(int n)
{
	randomize(); // 랜덤함수사용
	for (int i = 0; i < 4; i++)
	{
		doll[i].stock = random(n - 1) + 1; // 재고수량 랜덤 배정
	}
}

void Random_Game_Screen_Print()
{
	int Start_X = 80;
	int Start_Y = 35;
	int Distance = 1;
	gotoxy(Start_X, Start_Y);				printf("<< 랜덤 뽑기 >>"); // (80, 35)
	gotoxy(Start_X, Start_Y + Distance * 1); printf("----------------------------");
	gotoxy(Start_X, Start_Y + Distance * 2); printf("1등 인형 당첨 확률 : 1%%");
	gotoxy(Start_X, Start_Y + Distance * 3); printf("2등 인형 당첨 확률 : 4%%");
	gotoxy(Start_X, Start_Y + Distance * 4); printf("3등 인형 당첨 확률 : 15%%");
	gotoxy(Start_X, Start_Y + Distance * 5); printf("4등 인형 당첨 확률 : 30%%");
	gotoxy(Start_X, Start_Y + Distance * 6); printf("꽝 확률 : 50%%");
	gotoxy(Start_X, Start_Y + Distance * 7); printf("----------------------------"); // (80, 57) 다음 (80, 43)
}

int Random_Game_Message(int x, int y)
{
	int Distance = 1;
	int input = 0;
	gotoxy(x, y);				printf("< 1 > 랜덤 뽑기 진행 ");
	gotoxy(x, y + Distance * 1); printf("< 8 > 뒤로가기");
	gotoxy(x, y + Distance * 2); printf("----------------------------");
	gotoxy(x, y + Distance * 3); printf("현재 투입된 금액 : %d 원", total_cash);
	gotoxy(x, y + Distance * 4); printf("----------------------------");
	gotoxy(x, y + Distance * 5); printf("선택하세요 : ");
	scanf("%d", &input);
	return input;
}

void Random_Game_Start(int game_menu_select, int x, int y)
{
	randomize();
	int dice = random(100);
	gotoxy(x, y);
	switch (game_menu_select)
	{
	case 1: // 진행을 선택했는데,
	{
		if (total_cash < random_cost) // 돈이 부족한경우
		{
			printf("투입 금액이 부족합니다.");
			delay(speed);
			break;
		}
		else if (total_cash >= random_cost) // 돈이 충분한경우
		{
			printf("뽑기를 진행합니다.");
			delay(speed);
			total_cash = total_cash - random_cost;
			gotoxy(x, y + 1);
			if (dice < 1) // 0 = 1%
			{
				printf("1등 당첨 !!! dice값 : %d", dice);
				delay(speed);
			}
			else if (dice >= 1 && dice < 5) // 1~4 = 4%
			{
				printf("2등 당첨 !!! dice값 : %d", dice);
				delay(speed);
			}
			else if (dice >= 5 && dice < 20) // 5~20 15%
			{
				printf("3등 당첨 !!! dice값 : %d", dice);
				delay(speed);
			}
			else if (dice >= 20 && dice < 50) // 30%
			{
				printf("3등 당첨 !!! dice값 : %d", dice);
				delay(speed);
			}
			else if (dice >= 50 && dice < 100) // 50%
			{
				printf("꽝입니다... dice값 : %d", dice);
				delay(speed);
			}
			else
			{
				printf("알 수 없는 오류");
				delay(speed);
			}
		}
		break;
	}
	case 8: // 뒤로 이동
	{
		start = 0;
		printf("이전 메뉴로 이동합니다.");
		delay(speed);
		break;
	}
	default:
	{
		printf("잘못된 입력입니다.");
		delay(speed);
		break;
	}
	}
}


//////////////////////////////////////////////////// 메인 ////////////////////////////////////////////////////////

void main()
{
	//int main_menu_cursor_input = 0; 커서 시스템 적용시 사용할 변수
	//int menu_choice = 1; // 현재 선택한 값
	int menu_select = 0; // 메인 메뉴 선택 변수
	int cash_select = 1; // 투입 금액 변수

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); // 창크기 전체화면
	setcolor(LIGHTWHITE, BLACK); // 기본 글자 색상
	setcursortype(NOCURSOR); // 커서 타입
	Randomize_Doll_Stock(5); // 재고 랜덤 1~5개 배정
	Intro_Effect();

	for (;;) // 프로그램 시작 // 메인 무한 반복
	{
		start = 0; // 플래그 변수 초기화 //
		cls; // 화면 지우기
		Make_Frame();
		menu_select = Main_Screen(60, 20); // 메뉴 선택화면 출력 함수

		switch (menu_select) // 메인 메뉴 선택 [1]
		{
		case 1: // 1번메뉴 인형뽑기 진입 [2]
		{
			start = 0; // 플래그 변수 초기화 //
			for (; start == 0;) // 인형뽑기의 금액투입 반복 구문 [2] (플래그 변수 start가 0 일 경우 무한 실행)
			{
				cls;
				Make_Frame();
				Machine_Screen(); // 인형 목록
				cash_select = Cash_System_Print(80, 35); // 출력 및 입력 받기 함수 좌표에 출력
				Cash_System_Calculate(cash_select, 80, 50); // 계산 및 좌표에 출력

				for (; start == 1;) // 인형뽑기 무한 반복 구문 (플래그 변수가 1 일경우)
				{
					int doll_select = 0;
					cls;
					Make_Frame();
					Machine_Screen();
					doll_select = Machine_System_Print(80, 40); // 해당좌표에 출력
					//Machine_System_Activate(doll_select, 80, 49);
				}
				if (start == -1)
				{
					break;
				}
			}// for(;;)
			break;
		} // case 1 인형 뽑기 메뉴 진입

		case 2: // 2번 메뉴 랜덤 뽑기 메뉴 진입
		{

			start = 0; // 플래그 변수 초기화 //
			for (; start == 0;) // 금액 투입 진행
			{
				cls;
				Make_Frame();
				Random_Game_Screen_Print(); // 확률 표 출력
				cash_select = Cash_System_Print(80, 43); // 출력 및 입력 받기 함수 좌표에 출력
				Cash_System_Calculate(cash_select, 80, 58); // 계산 및 좌표에 출력

				for (; start == 1;) // 랜덤 게임 진행
				{
					int random_menu_select = 0;
					cls;
					Make_Frame();
					Random_Game_Screen_Print();
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



		case 3: // 3번 메뉴 도움말/제작자
		{
			cls;
			printf("< 도움말 >");
			_getch();
			break;
		}
		case 4: // 4번 메뉴 종료
		{
			cls;
			printf("프로그램을 종료합니다.\n");
			exit(0);
		}
		default: // 잘못입력된경우 (메인메뉴)
		{
			break;
		}

		} // 메인 메뉴 switch

	} // for(;;) = 메인 메뉴 반복

} // void main () 오류 수정해줘