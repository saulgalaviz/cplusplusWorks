#include <iostream>
#include <time.h>  
#include <string>

using namespace std;

void pause(int milliseconds) 
{
	int limit = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
	while (clock() < limit) 
	{
		// Do nothing...just wait
	}
}

int main()
{
	char ESC = 27; 

	int column = 0;

	for (int colorNumber = 0; colorNumber < 8; colorNumber++)
	{
		while (column < 80)
		{
			std::string columnString = std::to_string(column);
			std::string colorString = std::to_string(colorNumber);

			cout << ESC << "[37;40m" << ESC << "[13;0f" << "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo" << ESC << "[3"+colorString+";40m" << ESC << "[13;"+columnString+"f" << "O" << flush;
			pause(40);
			cout << ESC << "[2J";
			column++;
		}

		while (column > 0)
		{
			std::string columnString = std::to_string(column);
			std::string colorString = std::to_string(colorNumber);

			cout << ESC << "[37; 40m";
			cout << ESC << "[37;40m" << ESC << "[13;0f" << "ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo" << ESC << "[3" + colorString + ";40m" << ESC << "[13;" + columnString + "f" << "O" << flush;
			pause(40);
			cout << ESC << "[2J";
			column--;
		}
	}
	return 0;
}