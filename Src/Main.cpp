#include <iostream>

using namespace std;

int CHAR_PIXEL = 16;
int CHAR_NUM_X = 40;
int CHAR_NUM_Y = 20;

int main(int argc, char* argv[])
{
	int PIXEL_X = CHAR_NUM_X * CHAR_PIXEL;
	int PIXEL_Y = CHAR_NUM_Y * CHAR_PIXEL;
	int i = 0;
	int j = 0;
	for (i = 0; i < PIXEL_X; ++i)
	{
		for (j = 0; j < PIXEL_Y; ++j)
		{
			cout << "■" /*<< endl*/;
		}
		cout << endl;
	}
	return 0;
}