#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <stdio.h>
//#include <stdlib.h>
//#include <thread>


using namespace std;

const int UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, SPACE = 32, ENTER = 13, TAB = 9, ESCAPE = 27;
const int  size1 = 12;

void printArray(char* ptr, int s);

void directioDecision(char arr[size1][size1], int x, int y)
{
	while (1 > 0)
	{
		if (rand() % 2 == 0)
		{

			arr[y][x] = ' ';
			arr[y][x + 1] = 'W';
			x += 1;
			if (x > size1 - 3)
			{
				x = size1 - 3;

			}
		}
		else
		{
			arr[y][x] = ' ';
			arr[y][x - 1] = 'W';
			x -= 1;
			if (x < 2)
			{
				x = 2;

			}
		}
	}
}
// это жопа
int main()
{
	const int size1 = 12;
	int xHolder, yHolder;
	int enemyXholder, enemyYholder;
	char field[size1][size1];
	srand(time(NULL));
	int directionDecision;
	bool fire = false;

	//char * enemyptr;



	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			if (i == 1 && j == 1)
			{
				field[i][j] = 'Y';
				xHolder = i, yHolder = j;
			}
			else if (i == 0 || i == size1 - 1 || j == 0 || j == size1 - 1)
			{
				field[i][j] = '*';
			}
			else if (i == size1 - 2 && j == 1)
			{
				field[i][j] = 'W';
				enemyXholder = j;
				enemyYholder = i;
				//enemyptr = &field[i][j];
			}
			else
				field[i][j] = ' ';
		}
	}

	/*thread t1(directioDecision, *enemyptr);
	t1.join();*/
	char *pointer = field[0];
	printArray(pointer, size1);


	while (1 > 0)
	{
		if (rand() % 2 == 0)
		{
			field[enemyYholder][enemyXholder] = ' ';
			field[enemyYholder][enemyXholder + 1] = 'W';
			enemyXholder += 1;
			if (enemyXholder > size1 - 3)
			{
				enemyXholder = size1 - 3;

			}
		}
		else
		{
			if (enemyXholder < 2)
			{
				enemyXholder = 2;
			}
			field[enemyYholder][enemyXholder] = ' ';
			field[enemyYholder][enemyXholder - 1] = 'W';
			enemyXholder -= 1;
		}
		for (int i = 1; i < size1 - 1; i++)
		{
			for (int j = 1; j < size1 - 1; j++)
			{
				field[i][j] = ' ';
				field[yHolder][xHolder] = 'Y';
				field[enemyYholder][enemyXholder] = 'W';
			}
		}
		system("cls");
		printArray(pointer, size1);
		if (fire == true)
		{
			static int i = 3;
			field[i][xHolder] = '|';
			field[i - 1][xHolder] = ' ';
			system("cls");
			printArray(pointer, size1);
			if (i == size1 - 2)
			{
				i = 3;
				fire = false;
			}
			if (xHolder == enemyXholder && i == enemyYholder - 1)
			{
				cout << "GAME OVER\n";
				_getch();
				system("pause");
				continue;
			}
			i++;

		}
		if (_kbhit())
		{
			switch (_getch())
			{
			case RIGHT:
			{
				field[yHolder][xHolder] = ' ';
				field[yHolder][xHolder + 1] = 'Y';
				xHolder += 1;

				if (xHolder > size1 - 3)
				{
					xHolder = size1 - 3;
				}

				break;
			}
			case LEFT:
			{
				if (xHolder < 2)
				{
					xHolder = 2;
				}
				field[yHolder][xHolder] = ' ';
				field[yHolder][xHolder - 1] = 'Y';
				xHolder -= 1;
				break;
			}

			case SPACE:
			{
				fire = true;
				break;
			}
			case ESCAPE:
			{
				return 0;
				break;
			}
			default:
			{
				continue;
			}

			}

		}
		Sleep(50);
	}

	return 0;
}
void printArray(char* ptr, int s)
{
	for (int i = 0; i < s*s;)
	{
		cout << *ptr++ << " ";

		if (++i % s == 0)
		{
			cout << endl;
		}
	}
}

