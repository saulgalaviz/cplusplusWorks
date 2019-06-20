#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

char ESC = 27;
int milliseconds;
int foreGround = 37;
int backGround = 40;

ofstream logfile;

void setfg(int newfgColor)
{
	std::string fg = std::to_string(newfgColor);
	std::string bg = std::to_string(backGround);
	foreGround = newfgColor;

	cout << ESC << "[" + fg + ";" + bg + "m";
}

void setbg(int newbgColor)
{
	std::string fg = std::to_string(foreGround);
	std::string bg = std::to_string(newbgColor);
	backGround = newbgColor;

	cout << ESC << "[" + fg + ";" + bg + "m";
}

void pause()
{
	int limit = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
	while (clock() < limit)
	{
	}
}

int main(char* args[])	
{
	string command_file = args[1];
	string nextCommand;
	int n, row, col, h, w, Dr, Dc, cnt;
	char character;
	string strain;

	bool slow = false;
	int lineNumber = 0;
	logfile.open("project2.log");

	char screen[26][81] = { ':' };
	char screenMirror[26][81] = { ':' };

	for (;;)
	{
		cin >> nextCommand;
		lineNumber++;

		if (nextCommand == "clear")
		{		
			cout << ESC << "[2J" << ESC << "[0;0f";
			memset(screen, ':', sizeof(screen));
			memset(screenMirror, ':', sizeof(screenMirror));
		}

		else if (nextCommand == "setms")
		{
			cin >> n;

			milliseconds = n;
		}

		else if (nextCommand == "setfg")
		{
			cin >> n;

			if (n >= 30 && n <= 39)
				setfg(n);
			else
				logfile << "Error: Line " << lineNumber << " - invalid color range, skipping." << endl;
		}

		else if (nextCommand == "setbg")
		{
			cin >> n;

			if (n >= 40 && n <= 49)
				setbg(n);
			else
				logfile << "Error: Line " << lineNumber << " - invalid color range, skipping." << endl;
		}

		else if (nextCommand == "pause")
			pause();

		else if (nextCommand == "slow")
			slow = true;

		else if (nextCommand == "fast")
			slow = false;

		else if (nextCommand == "plot")
		{
			cin >> row >> col >> character;

			if (row <= 25 && col <= 80)
			{
				screen[row][col] = character;

				std::string Row = std::to_string(row);
				std::string Col = std::to_string(col);
				string Character(1, character);

				cout << ESC << "[0;0f";
				cout << ESC << "[" + Row + ";" + Col + "f" << Character << flush;
				cout << ESC << "[0;0f";
			}
		}

		else if (nextCommand == "hplot")
		{
			cin >> row >> col >> character >> cnt;

			for (int counter = 0; counter < cnt; counter++)
			{
				if (row <= 25 && (col + counter) <= 80)
				{
					screen[row][col + counter] = character;

					string Character(1, character);

					std::string Row = std::to_string(row);
					std::string Col = std::to_string(col + counter);

					cout << ESC << "[0;0f";
					cout << ESC << "[" + Row + ";" + Col + "f" << Character << flush;
					cout << ESC << "[0;0f";
				}
			}
		}

		else if (nextCommand == "vplot")
		{
			cin >> row >> col >> character >> cnt;

			for (int counter = 0; counter < cnt; counter++)
			{
				if ((row + counter) <= 25 && col <= 80)
				{
					screen[row + counter][col] = character;

					string Character(1, character);

					std::string Row = std::to_string(row + counter);
					std::string Col = std::to_string(col);

					cout << ESC << "[0;0f";
					cout << ESC << "[" + Row + ";" + Col + "f" << Character << flush;
					cout << ESC << "[0;0f";
				}
			}
		}

		else if (nextCommand == "text")
		{
			cin >> row >> col >> strain;

			if ((row <= 25) && (col + strain.length() <= 80))
			{
				for (int counter = 0; counter < strain.length(); counter++)
					screen[row][col + counter] = strain[counter];
				
				std::string Row = std::to_string(row);
				std::string Col = std::to_string(col);

				cout << ESC << "[0;0f";
				cout << ESC << "[" + Row + ";" + Col + "f" << strain << flush;
				cout << ESC << "[0;0f";
			}

			else if (row <= 25)
			{
				string newStrain = strain.substr(0, 80 - col);

				for (int counter = 0; counter < strain.length(); counter++)
					screen[row][col + counter] = newStrain[counter];

				std::string Row = std::to_string(row);
				std::string Col = std::to_string(col);

				cout << ESC << "[0;0f";
				cout << ESC << "[" + Row + ";" + Col + "f" << newStrain << flush;
				cout << ESC << "[0;0f";
			}
		}

		else if (nextCommand == "move")
		{
			cin >> row >> col >> h >> w >> Dr >> Dc;

			if (h != 0 && w != 0 && (Dr + row + h - 1) < 26 && (Dc + col + w - 1) < 81)
			{
				int yValues = row + h - 1;
				int xValues = col + w - 1;

				memcpy(screenMirror, screen, sizeof(screenMirror));

				bool hasMoved[26][81] = { false };

				for (int y = row; y <= yValues; y++)
				{
					for (int x = col; x <= xValues; x++)
					{
						screen[Dr + y][Dc + x] = screenMirror[y][x];

						hasMoved[Dr + y][Dc + x] = true;
					}
				}

				for (int y = row; y <= yValues; y++)
				{
					for (int x = col; x <= xValues; x++)
					{
						if (!hasMoved[y][x])
							screen[y][x] = ':';
					}
				}

				cout << ESC << "[0;0f";

				for (int row = 1; row < 26; row++)
				{
					for (int col = 1; col < 81; col++)
					{
						if (screen[row][col] != ':')
							cout << screen[row][col];
						
						else
							cout << ' ';
					}
				}
				cout << ESC << "[0;0f";
			}
		}

		else if (nextCommand == "copy")
		{
			cin >> row >> col >> h >> w >> Dr >> Dc;

			if (h != 0 && w != 0 && (Dr + row + h - 1) < 26 && (Dc + col + w - 1) < 81)
			{
				int yValues = row + h - 1;
				int xValues = col + w - 1;

				memcpy(screenMirror, screen, sizeof(screenMirror));

				for (int y = row; y <= yValues; y++)
				{
					for (int x = col; x <= xValues; x++)
					{
						screen[Dr + y][Dc + x] = screenMirror[y][x];
					}
				}

				cout << ESC << "[0;0f";

				for (int row = 1; row < 26; row++)
				{
					for (int col = 1; col < 81; col++)
					{
						if (screen[row][col] != ':')
							cout << screen[row][col];
						else
							cout << ' ';
					}
				}
				cout << ESC << "[0;0f";
			}
		}

		else if (nextCommand == "//")
		{
			string ignoreLine;
			getline(cin, ignoreLine);
		}

		else if (nextCommand == "quit")
			break;

		else 
		{
			logfile << "Error: Line " << lineNumber << " - bad command '" << nextCommand << "', skipping." << endl;
			string ignoreLine;
			getline(cin, ignoreLine);
		}

		if (slow && (nextCommand != "//"))
			pause();
	}
	logfile.close();

	cout << ESC << "[37;40m";
	cout << ESC << "[0;0f";

	return 0;
}