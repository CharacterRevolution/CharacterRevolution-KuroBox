#include <iostream>
#include <stdlib.h>

using namespace std;

int CHAR_PIXEL = 16;
int CHAR_NUM_WIDTH = 40;
int CHAR_NUM_HEIGHT = 20;

int main(int argc, char* argv[])
{
	int PIXEL_WIDTH = CHAR_NUM_WIDTH * CHAR_PIXEL; //绘制像素模拟到现在的屏幕才会用到
	int PIXEL_HEIGHT = CHAR_NUM_HEIGHT * CHAR_PIXEL; //绘制像素模拟到现在的屏幕才会用到
	int i = 0;
	int j = 0;
	//while (1)
	//{
	//	;
	//}
	system("cls");
	for (i = 0; i < CHAR_NUM_HEIGHT; ++i)
	{
		for (j = 0; j < CHAR_NUM_WIDTH; ++j)
		{
			if (i == 0 || i == CHAR_NUM_HEIGHT -1)
			{
				cout << "■";
			}
			else if (j == 0 || j == CHAR_NUM_WIDTH -1)
			{
				cout << "■";
			}
			else
			{
				cout << "□";
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}