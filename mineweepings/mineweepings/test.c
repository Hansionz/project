#include"game.h"

void meun()
{
	printf("******   ɨ����Ϸ   ******\n");
	printf("**************************\n");
	printf("******   1.PLAY     ******\n");
	printf("******   2.EXIT     ******\n");
	printf("**************************\n");

}
void game()
{
	char board[ROWS][COLS] = { ' 0 ' };
	char mine[ROWS][COLS] = { ' 0 ' };

	init_board(board, ROWS, COLS, '*');
	init_board(mine, ROWS, COLS, '0');
	set_mine(mine, ROW, COL);
	/*printf("����\n");*/
	/*print_board(mine, ROW, COL);*/
	/*printf("չʾ��\n");*/
	print_board(board, ROW, COL);
	find_mine(board, mine, ROW, COL);
	

}

int main()
{
	int input = 0;
	srand((uint)time(NULL));
	do{
		meun();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case START:
			game();
			break;
		case EXIT:
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
}