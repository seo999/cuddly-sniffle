int main_menu_cursor_x = 56; // ���� �޴� Ŀ�� ��ǥ�� �ʱ�ȭ
int main_menu_cursor_y = 20;
int menu_01_cursor_x;
int menu_01_cursor_y;
COLOR_TYPE user_color = LIGHTWHITE;
void Cursor(int x, int y, COLOR_TYPE t, COLOR_TYPE b)
{
	gotoxy(x, y);
	setcolor(t, b);
	printf("��");
	setcolor(user_color, BLACK);
}



Cursor(main_menu_cursor_x, main_menu_cursor_y, ORANGE, BLACK); // �ش� ��ǥ�� Ŀ�� ���


main_menu_cursor_input = _getch();
if (main_menu_cursor_input == 72) // �� Ű
{
	main_menu_cursor_y = main_menu_cursor_y - 4;
	menu_choice = menu_choice - 1;
}
else if (main_menu_cursor_input == 80) // �Ʒ� Ű
{
	main_menu_cursor_y = main_menu_cursor_y + 4;
	menu_choice = menu_choice + 1;
}
else if (main_menu_cursor_input == 13)// ���� �Է�
{

}
else // �ٸ� �Է�
{

}

if (main_menu_cursor_y < 20)
{
	main_menu_cursor_y = 20;
	menu_choice = menu_choice + 1;
}
if (main_menu_cursor_y > 40)
{
	main_menu_cursor_y = 40;
	menu_choice = menu_choice - 1;
}