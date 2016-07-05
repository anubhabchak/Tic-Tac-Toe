#include<iostream>
#include "framework.h"

using namespace std;

int main()
{
	TTTgame mygame;
	TTTgame::TTTgrid::Position pos;
	cout << mygame.gameGrid.getCount() << " ";
	cout << mygame.getTurn() << endl;
	pos.setxy(1, 2);
	cout << pos.getx() << " " << pos.gety() << endl;
	mygame.autoMark(pos);
	cout << mygame.gameGrid.getCount() << " ";
	cout << mygame.getTurn() << endl;
	pos.setxy(3, 2);
	cout << pos.getx() << " " << pos.gety() << endl;
	mygame.autoMark(pos);
	cout << mygame.gameGrid.getXcount() << " ";
	cout << mygame.gameGrid.getOcount() << endl;
	pos.setxy(2, 2);
	cout << pos.getx() << " " << pos.gety() << endl;
	mygame.autoMark(pos);
	cout << mygame.gameGrid.getXcount() << " ";
	cout << mygame.gameGrid.getOcount() << endl;
	pos.setxy(2, 3);
	cout << pos.getx() << " " << pos.gety() << endl;
	mygame.autoMark(pos);
	cout << mygame.gameGrid.getXcount() << " ";
	cout << mygame.gameGrid.getOcount() << endl;
	mygame.gameGrid.xcount = 0;
}

//Make a triplenested class TTTgame
