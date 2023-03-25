// �̷� Ʋ ����� ����
// �� �Ʒ� �¿츦 �����ؼ� �������� ��� ����Ȱ� �־����
// �� ��� ������ �����غ�����
// ���� ��� ����Ȱ� ������ ��� �׸��� ������ �������� (--- ������) �̾��� ���� �������� ����2���̻� �Ȱ��̰�ġ�� �̹����� ���� �ϳ��� ������ �ٲ۴�..
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

#define WIDTH 7
#define HEIGHT 7

void print_maze(char* maze[][WIDTH + 1])
{
	for (int i = 0; i < HEIGHT + 1; i++)
	{
		for (int j = 0; j < WIDTH + 1; j++)
		{
			printf("%s", &maze[j][i]);
		}
		printf("\n");
	}
}
int enter = rand() % (WIDTH - 1) + 1;
int exit = rand() % (WIDTH - 1) + 1;
int previous_path = enter;

void initialze_maze(char* maze[][WIDTH + 1])
{
	int y = 1;
	for (int i = 0; i < HEIGHT + 1; i++)
	{
		for (int j = 0; j < WIDTH + 1; j++)
		{
			memcpy(&maze[j][i], "  ", sizeof(char*));
		}
	}
	for (int i = 0; i <= WIDTH; i++)
	{
		memcpy(&maze[i][0], "��", sizeof(char*));
		memcpy(&maze[i][HEIGHT], "��", sizeof(char*));
	}
	for (int i = 0; i <= HEIGHT; i++)
	{
		memcpy(&maze[0][i], "��", sizeof(char*));
		memcpy(&maze[WIDTH][i], "��", sizeof(char*));
	}
	//�� ���ε�..
	memcpy(&maze[enter][0], "��", sizeof(char*));
	memcpy(&maze[exit][HEIGHT], "��", sizeof(char*));
	//���� ������ �ٵ��Ұ�, check_maze_row �� 1�̸� ���� ������
	//i�� ���� ��Ÿ����.
	while (y < HEIGHT)
	{
		int last_path = exit;
		int check_maze_row_number = 1;
		while (check_maze_row_number)
		{
			if (y != HEIGHT)
			{
				int x = 1;
				while (x < WIDTH)
				{
					x++;
					int z = rand() % 2 + 1;
					if (z / 2 == 0)
					{
						memcpy(&maze[x][y], "��", sizeof(char*));
					}
					else
					{
						memcpy(&maze[x][y], "��", sizeof(char*));
					}
				}
				check_maze_row_number = check_maze_row(y, maze);
			}
			else
			{

			}
		}
	}
}

//�������� ��� ����� ���� ������ 1�� ��ȯ �ƴϸ� 0�� ��ȯ
// ���� ��� ����Ȱ� ������ ��� �׸��� ������ �������� (--- ������) �̾��� ���� �������� ����2���̻� �Ȱ��̰�ġ�� �̹����� ���� �ϳ��� ������ �ٲ۴�..


int check_maze_row(int row, char* maze[][WIDTH + 1])
{
	int stack[WIDTH + 1] = { 0, };

	for (int i = 1; i < WIDTH + 1; i++)
	{
		if (strcmp(maze[i][row], "��"))
		{
			stack[i] = 1;
		}
	}
	return 1;
}

int main()
{
	srand(time(NULL));
	char* maze[WIDTH + 1][HEIGHT + 1] = { 0 , };
	initialze_maze(maze);
	print_maze(maze);
//	memset(maze, 0, sizeof(char*));
//��ó�� maze�� �ʱ�ȭ�ϸ� �Ǿտ� ��ĭ�� 0���� �ʱ�ȭ��
}