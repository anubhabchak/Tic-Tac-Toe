#include<iostream>
#include "framework.h"

using namespace std;

int main()
{
	int x, y;
	TTTgame mygame;
	TTTgame::TTTgrid::Position pos;
	cout << "***TIC-TAC-TOE Framework Test***" << endl << endl;
	while(mygame.isAlive() == true)
	{
		cout << mygame.getTurn() << "'s turn" << endl;
		cout << "x coord: ";
		cin >> x;
		cout << "y coord: ";
		cin >> y;
		cout << endl;
		pos.setxy(x,y);
		if(mygame.autoMark(pos) == false)
		{
			cout << "\nmove not granted, try again"<< endl;
		}
	}
	if (mygame.getWinner() != 'D')
	{
		cout << "The winnner is: " << mygame.getWinner();
	}
	else
		cout << "The game is draw!";
}
