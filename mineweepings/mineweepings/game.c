#include"game.h"

void init_board(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void print_board(char board[ROWS][COLS], int row, int col)
{
	{
		int i = 0;
		int j = 0;
		for (i = 0; i <= row; i++)
		{
			printf("%d ", i);//������ע�����к�
		}
		printf("\n");
		for (i = 0; i <row; i++)
		{
			printf("%d ", i+1);
			for (j = 0; j < col; j++)
			{
				printf("%c ", board[i + 1][j + 1]);
			}
			printf("\n");
		}
	}
}

void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = mine_count;
	while (count)
	{
	     x = rand() % row  + 1;
		 y = rand() % col  + 1;
		 //�������������
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	int count = (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1]) - 8 * '0';
	return count;
}
//��ȡ��(x,y)������Χ���׵ĸ���
void find_mine(char board[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int sum = 0;
	int x = 0;
	int y = 0;
	while (sum <= (row*col - mine_count))
	{
		printf("������Ҫɨ�׵�����:\n");
		scanf("%d%d", &x, &y);
		if (mine[x][y] == '1')
		{
			printf("���ź����㱻ը���ˣ�\n");
			break;
		}
		else
		{
			board[x][y] = get_mine_count(mine, x, y) + '0';
			print_board(board, row, col);
			sum++;
		}
	}
	if (sum > (row*col - mine_count))
	{
		printf("��ϲ�㣬ɨ�׳ɹ���\n");
		print_board(mine, row, col);
	}
}



