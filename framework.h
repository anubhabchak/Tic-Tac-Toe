/*
***FRAMEWORK FOR TIC-TAC-TOE GAME***
====================================================
class TTTgame
|
|---|class TTTgrid
    |
    |---| class Position (Nested class)
        |
        |Public Member Functions:
        |
        |-Position() >> Def Con - Call to create a Position object
        |
        |-getx()
        |-gety()
        |
        |-setxy()
        |
    |
    Public Member Functions:
    |
    |-TTTgrid() >> Def Con - Call to create a TTTgrid object
    |
    |-bool isFull() >> Check if the grid is full
    |
    |-int getCount()  | \
    |-int getXcount() |  } Count getters
    |-int getOcount() | /
    |
    |-bool isPosEmpty(position) >> Check vacancy of a position
    |-char getMarkAt(position) >> get Mark at position, If empty, returns null
    |
    |-void reset() >> reinitialise all positions to null
    |
|Public Member Functions:
|
|-char getTurn() >> Get current turn of the game
|
|-bool mark(position,char) >> Put a char mark in position
|-bool autoMark(position) >> Automatically mark a positon
|
|Private Member Functions:
|
|-void setWinner()
|-char checkWin() >> Checks and returns the winner, or 'D' for Draw


=====================================================
~Thought and Implemented by CS#9
(For pull requests, changes and suggestions,
contact Anubhab >> chakraborty.anubhab@gmail.com)
*/
class TTTgame
{
  char win;

public:
  class TTTgrid
  {
    friend class TTTgame;
    char grid[3][3];
    int count, xcount, ocount;
    //stores total marks, 'X' marks and 'Y' marks resp.

  public:

    class Position
    {
      int x;
      int y;
      /*
      -- x -->
      1  2  3  |
      1__|__|__ y
      2__|__|__ |
      3  |  |   V
      */
    public:
      int getx() { return x; }
      int gety() { return y; }

      void setxy(int a, int b)
      {
        if (a < 4 && b < 4)
        {
          x = ( a - 1 );
          y = ( b - 1 );
        }
        else
        {
          x = 0;
          y = 0;
        }
      }
    };

    //Def Con --> Create an empty TTTgrid
    TTTgrid()
    {
      reset();
    }

    //FIX ISSUE REGARDING PARAMETER LIST
    //N-para Con --> Create a non-empty TTTgrid using
    //another TTTgrid object
    /*
    TTTgrid( TTTgrid gr )
    {
    grid[i][j] = gr.getGrid;
    count = gr.getCount();
    xcount = gr.getXcount();
    ocount = gr.getOcount();
  }
  */



  //returns the number of X, Y and total Markings
  int getXcount() { return xcount; }
  int getOcount() { return ocount; }
  int getCount() { return count; }

  //returns if the grid is full or not
  bool isFull()
  {
    if (count == 9)
    return true;
    else
    return false;
  }

  //FIX ISSUE WITH RETURN TYPE
  /*
  //returns the grid
  char **getGrid() { return grid; }
  */

  //returns the status of a given position
  bool isPosEmpty( Position pos )
  {
    if ( grid[ pos.getx() ][ pos.gety() ] == '\0' )
    return true;
    else
    return false;
  }

  //get mark at a specified position
  char getMarkAt( Position pos )
  {
    return grid[ pos.getx() ][ pos.gety() ];
  }

  void reset()
  {
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
    grid[i][j] = '\0';
    count = 0;
    xcount = 0;
    ocount = 0;
  }

} gameGrid;

  //get the current turn of the game
  char getTurn()
  {
    if( gameGrid.getCount()%2 == 0 )
      return 'X';
    else
      return 'O';
  }

  //Marks a position on the grid
  bool mark(TTTgrid::Position pos, char ch)
  {
    if ( (ch == 'X' || ch == 'x' || ch == 'O' || ch == 'o')
          && ( gameGrid.isFull() != true ) )
    {
      if (gameGrid.isPosEmpty(pos) ==  true)
      {
        gameGrid.grid[ pos.getx() ][ pos.gety() ] = ch;
        if (ch == 'X' || ch == 'x')
        {
          gameGrid.xcount++;
        }
        else
        {
          gameGrid.ocount++;
        }
        gameGrid.count++;
        if (gameGrid.isFull() == true)
          setWinner();
        return true; //Marking Successful!
      }
      else
      return false; // Position Blocked
    }
    else
    return false; //Invalid character
  }

  //Automatically mark a given postion
  bool autoMark( TTTgrid::Position pos )
  {
    //Game always starts with 'X'
    char turn = getTurn();
    if(mark(pos, turn)== true)
    return true;
    else
    return false;
  }

  char getWinner() { return win; }

private:

  //sets the winner if the grid is full
  //if no winner, then winner is set to 'D' (=Draw)
  void setWinner()
  {
    win = checkWin();
  }

  char checkWin()
  {
    //code to check winner
    return '\0';
  }
};
