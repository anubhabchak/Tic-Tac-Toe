#include<iostream>
#include "framework.h"

using namespace std;

int main()
{
	int x, y;
	TTTgame mygame;
	TTTgame::TTTgrid::Position pos;
	TTTgame::TTTgrid::Position disppos;
	TTTgame::TTTgrid mygrid;
	cout << "***TIC-TAC-TOE Framework Test***" << endl << endl;
	while(mygame.isAlive() == true)
	{
		cout << mygame.getTurn() << "'s turn" << endl;
		cout << "x coord: ";
		cin >> x;
		cout << "y coord: ";
		cin >> y;
		//cout << endl;
		pos.setxy(x,y);
		if(mygame.autoMark(pos) == false)
		{
			cout << "\nmove not granted, try again"<< endl;
			cout << "***************************" << endl;
		}
		else
		{
			char c;
			cout << endl;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
					{
						disppos.setxy(j,i);
						c = mygame.gameGrid.getMarkAt(disppos);
						if (c == '\0')
							cout << " - ";
						else
							cout << " " << mygame.gameGrid.getMarkAt(disppos) << " ";
					}
					cout << endl;
			}
			cout << endl;
		}
	}
	if (mygame.getWinner() != 'D')
	{
		cout << "The winnner is: " << mygame.getWinner();
	}
	else
		cout << "The game is draw!";
}
