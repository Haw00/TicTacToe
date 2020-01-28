#include <iostream>
#include <cstdlib>
using namespace std;

int compare();
void display();
void reset();
char a[9] = { '1','2','3','4','5','6','7','8','9' };

int main()
{
	cout << "This is a TicTacToe game!\n";
	int input = 1;
	while (input != 0)
	{
		system("cls");
		reset();
		display();
		for (int i = 0; i < 9; i++)
		{
			cin >> input;
			if (a[input-1] == 'X' || a[input - 1] == 'O')
			{
				cout << "already taken" << endl;
				cin >> input;
			}
			system("cls");
			if (i%2 == 0)
				a[input - 1] = 'X';
			else
				a[input - 1] = 'O';
			display();

			int temp = compare();
			if (temp == 1 || temp == 2)
			goto label;
		}
		label:cout << "press 0 to quit or any number 1-9 to continue";
		cin >> input;
	}
	return 0;
}

int compare()
{
	if (a[0] == 'X' && a[1] == 'X' && a[2] == 'X' ||
		a[3] == 'X' && a[4] == 'X' && a[5] == 'X' ||
		a[6] == 'X' && a[7] == 'X' && a[8] == 'X' ||
		a[0] == 'X' && a[3] == 'X' && a[6] == 'X' ||
		a[1] == 'X' && a[4] == 'X' && a[7] == 'X' ||
		a[2] == 'X' && a[5] == 'X' && a[8] == 'X' ||
		a[0] == 'X' && a[4] == 'X' && a[8] == 'X' ||
		a[2] == 'X' && a[4] == 'X' && a[6] == 'X')
	{
		cout << "X wins!" << endl;
		return 1;
	}else
	if (a[0] == 'O' && a[1] == 'O' && a[2] == 'O' ||
		a[3] == 'O' && a[4] == 'O' && a[5] == 'O' ||
		a[6] == 'O' && a[7] == 'O' && a[8] == 'O' ||
		a[0] == 'O' && a[3] == 'O' && a[6] == 'O' ||
		a[1] == 'O' && a[4] == 'O' && a[7] == 'O' ||
		a[2] == 'O' && a[5] == 'O' && a[8] == 'O' ||
		a[0] == 'O' && a[4] == 'O' && a[8] == 'O' ||
		a[2] == 'O' && a[4] == 'O' && a[6] == 'O')
	{
		cout << "O wins!" << endl;
		return 2;
	}
	return 0;
}

void display()
{
	for (int i = 0; i < 9; i++)
	{
		cout << a[i];
		if (i != 2 && i != 5 && i != 8)
			cout << "|";

		if (i == 2 || i == 5 || i == 8)
		{
			cout << endl;
			if(i != 8)
			cout << "-----" << endl;
		}
	}
}

void reset()
{
	for (int i = 0; i < 9; i++)
	{
		a[0] = '1';
		a[1] = '2';
		a[2] = '3';
		a[3] = '4';
		a[4] = '5';
		a[5] = '6';
		a[6] = '7';
		a[7] = '8';
		a[8] = '9';
	}
}
