#include"game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', sizeof(board[0][0] )* row*col);
}//memset����������һ���ڴ�ռ�ȫ������Ϊĳ���ַ�

void print_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		if (i != row-1)
		{
			printf("---|---|---\n");
		}
	}
}

void  paiyer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���������ӵ����꣺\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		//��֤��������ĺϷ���,�������������Ǵ�1��ʼ��
		if (((x >= 1) && ( x <= row)) && ((y >= 1) && ( y <= col)))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';//�������
				break;
			}
			else
			{
				printf("�������ѱ�ռ�ã��뻻һ�����꣺\n");
			}
		}
		else
		{
			printf("�������겻�Ϸ������������룺\n");
		}
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;//����rand���������������
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	}
	
}

static int is_full(char board[ROW][COL], int row, int col)
//����is_fullֻ��is_win�б����ã����Լ���static�ı�����������
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}//�ж������Ƿ�������

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][2] != ' '))
		{
			return  board[i][1];
		}	
	}
	for (j = 0; j < col; j++)
	{
		if ((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]) && (board[2][j] != ' '))
		{
			return  board[1][j];
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[2][2] != ' '))
	{
		return board[1][1];
	}
	else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && (board[1][1] != ' '))
	{
		return board[1][1];
	}
    else if (is_full(board,ROW,COL) == 1)
	{
		return 'Q';//��ʾ����������
	}
	else
		return ' ';
}

