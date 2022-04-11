#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define canvas_n 15
#define canvas_m 15
int canvas[canvas_n][canvas_m] = { 0, };

void recur_fill(int x, int y);   // �� ���� ä��� (�밢�� ������)
void recur_fill_2(int x,int y);  // �� ä��� (�밢�� ����)
void print_canvas(int x,int y);   // 0 = blank, 1 = O (wall) , 2 = X (painting), (x,y) = S
void canvas_eraser();  // canvas 0���� �ʱ�ȭ
void canvas_border(int x, int y,int option);  // �������� �� �����, option=0 : �õ��ڸ� ����, option=1 : �õ��ڸ� ������ ä���
void recursive_line(int x1, int y1, int x2, int y2); // (x1,y1)���� (x2,y2)���� ���� �׸���

int main()
{

	int seed_x = 14;
	int seed_y = 14;
	srand(time(NULL));

	canvas_border(seed_y, seed_x, 0);
	printf("< Before >\n");
	print_canvas(seed_y,seed_x);
	recur_fill(seed_y, seed_x);
	printf("< After >\n");
	print_canvas(seed_y,seed_x);
	printf("Border = O\nFilled = X\nStart = S\nEmpty = blank\n\n");



}
void recur_fill(int x, int y)
{
	if ((canvas[x][y] > 0) || x<0 || x>canvas_n-1 || y<0 || y>canvas_m-1)
		return;

	canvas[x][y] = 2;

	recur_fill(x + 1, y);
	recur_fill(x, y - 1);
	recur_fill(x, y + 1);
	recur_fill(x - 1, y);

	


}
void recur_fill_2(int x, int y)
{
	if (canvas[x][y] !=1 || x<0 || x>canvas_n - 1 || y<0 || y>canvas_m - 1)
		return;

	canvas[x][y] =2;

	recur_fill_2(x + 1, y);
	recur_fill_2(x - 1, y);
	recur_fill_2(x, y - 1);
	recur_fill_2(x, y + 1);
	recur_fill_2(x + 1, y + 1);
	recur_fill_2(x + 1, y - 1);
	recur_fill_2(x - 1, y - 1);
	recur_fill_2(x - 1, y + 1);


}
void print_canvas(int x, int y)
{

	for (int i = 0; i < canvas_n; i++)
	{
		for (int j = 0; j < canvas_m; j++)
		{
			if ((i == x) && (j == y))
			{
				printf("S ");
				continue;
			}

			if (canvas[i][j] == 1)
				printf("O ");
			else if (canvas[i][j] == 2)
				printf("X ");
			else if (canvas[i][j] == 0)
				printf("  ");
			
		}
		printf("\n");
	}
	
	printf("\n");
}
void canvas_eraser()
{
	for (int i = 0; i < canvas_n; i++)
	{
		for (int j = 0; j < canvas_m; j++)
		{
			canvas[i][j] = 0;
		}
	}
}
void canvas_border(int x, int y,int option)
{
	for (int i = 0; i < canvas_n; i++)
	{
		for (int j = 0; j < canvas_m; j++)
		{
			canvas[i][j] = rand()%2;
		}
	}
	if (option == 0)
		canvas[x][y] = 0;
	else
		canvas[x][y] = option;
}
void recursive_line(int x1, int y1, int x2, int y2)
{
	if (((x1 + 1) == x2) && ((y1 + 1) == y2))
		return;

	int middlepoint_x = (x1 + x2) / 2;
	int middlepoint_y = (y1 + y2) / 2;
	canvas[middlepoint_y][middlepoint_x] = 2;
	canvas[y1][x1] = 2;
	canvas[y2][x2] = 2;

	recursive_line(x1, y1, middlepoint_x, middlepoint_y);
	recursive_line(middlepoint_x, middlepoint_y, x2, y2);

}