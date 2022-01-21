#include <iostream>

using namespace std;

int CHAR_PIXEL = 16;
int CHAR_NUM_X = 40/2;
int CHAR_NUM_Y = 20/2;

int main(int argc, char* argv[])
{
	int PIXEL_X = CHAR_NUM_X * CHAR_PIXEL; //绘制像素模拟到现在的屏幕才会用到
	int PIXEL_Y = CHAR_NUM_Y * CHAR_PIXEL; //绘制像素模拟到现在的屏幕才会用到
	int i = 0;
	int j = 0;
	for (i = 0; i < CHAR_NUM_X; ++i)
	{
		for (j = 0; j < CHAR_NUM_Y; ++j)
		{
			if (i == 0 || i == CHAR_NUM_X-1)
			{
				cout << "■";
			}
			else if (j == 0 || j == CHAR_NUM_Y-1)
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
	return 0;
}