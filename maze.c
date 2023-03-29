https://junyoeng.tistory.com/18


1. 틀만들기
2. 행 끝까지->열끝까지
  2-0 랜덤으로 행 끝까지 벽과 길을 생성
  2-1 upper, left, cross 변수를 만들어서 길잇기
     아래중 하나도 만족 안할때까지 반복
     2-1-1 1 == 길  0 == 벽
     2-1-2 u l c u_right 현재길  수정
     2-1-3 0 1 0    X      0 -> 현재길 1로 변경
     2-1-3 1 0 0    1 	   0 -> 현재길 1로 변경
     2-1-4 0 0 1    1      0 -> l을 1로 변경
     2-1-5 0 0 1    0      0 -> 현재길 1로 변경
     2-1-6 1 1 0   	   0 ->   c와 현재길중 하나 1로 변경
     2-1-7 1 1 1           1 ->   4개중 하나 0으로 변경
     2-1-8 0 0 1  	   1 ->   l또는u 하나 1로 변경
 
  2-2 마지막 길과 연결된 길이 반드시 있어야함
  2-3 연결된 길과 그 행에 연결된 길중 랜덤으로 하나의 길을 선택하여 다음 길로 선택
  2-4 마지막은 직전 마지막길과 연결되도록 출구를 만듬

0. 맨마지막에 해야함
1. 블록단위로 스택에 x,y 좌표를 저장
2. 연결이 안된 길 처리
  2-1 연결이 안된 길의 x,y좌표와 가장 가까운 길 블록의 가장 가까운 x, y 좌표중 하나와 직선으로 이어준다. ( 랜덤으로 이어준다 - 재귀)


// 미로 틀 만들기 성공
// 위 아래 좌우를 조사해서 이전행의 길과 연결된게 있어야함
// 길 어떻게 만들어갈지 생각해봐야함
// 이전 길과 연결된게 있으면 통과 그리고 그행의 연속으로 (--- 행으로) 이어진 길들과 이전행의 길들과2개이상 똑같이겹치면 이번행의 둘중 하나를 벽으로 바꾼다..
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
		memcpy(&maze[i][0], "■", sizeof(char*));
		memcpy(&maze[i][HEIGHT], "■", sizeof(char*));
	}
	for (int i = 0; i <= HEIGHT; i++)
	{
		memcpy(&maze[0][i], "■", sizeof(char*));
		memcpy(&maze[WIDTH][i], "■", sizeof(char*));
	}
	//열 행인듯..
	memcpy(&maze[enter][0], "□", sizeof(char*));
	memcpy(&maze[exit][HEIGHT], "□", sizeof(char*));
	//행을 끝까지 다돌았고, check_maze_row 가 1이면 다음 행으로
	//i는 행을 나타낸다.
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
						memcpy(&maze[x][y], "□", sizeof(char*));
					}
					else
					{
						memcpy(&maze[x][y], "■", sizeof(char*));
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

//이전행의 길과 연결된 길이 있으면 1을 반환 아니면 0을 반환
// 이전 길과 연결된게 있으면 통과 그리고 그행의 연속으로 (--- 행으로) 이어진 길들과 이전행의 길들과2개이상 똑같이겹치면 이번행의 둘중 하나를 벽으로 바꾼다..


int check_maze_row(int row, char* maze[][WIDTH + 1])
{
	int stack[WIDTH + 1] = { 0, };

	for (int i = 1; i < WIDTH + 1; i++)
	{
		if (strcmp(maze[i][row], "□"))
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
//위처럼 maze를 초기화하면 맨앞에 한칸만 0으로 초기화됨
}
