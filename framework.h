/*
***FRAMEWORK FOR TIC-TAC-TOE GAME***
====================================================
class TTTgame
|
|---|class TTTgrid (Nested class)
    |
    |---| class Position (Nested class)
        |
        Public Member Functions:
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
    |-TTTgrid(TTTgrid) >> Copy constructor
    |
    |-int getCount() - Count total markings
    |
    |-bool isPosEmpty(position) >> Check vacancy of a position
    |-char getMarkAt(position) >> get Mark at position, If empty, returns null
    |-void getGrid(char**) >> get a copy of the grid in a 2D char array
    |
    |-void reset() >> reinitialise all positions to null
    |
|
Public Member Functions:
|
|-bool isAlive() >> Returns false if there is a winner
|-char getTurn() >> Get current turn of the game
|
|-bool mark(position,char) >> Put a char mark in position
|-bool autoMark(position) >> Automatically mark a positon
|
|-void new_game()
|
|-void getWinner()
|
|Private Member Functions:
|
|-void setWinner()
|-char checkWin(position) >> Checks and returns the winner, or 'D' for Draw


=====================================================
~Designed by Anubhab
(For pull requests, changes and suggestions,
contact Anubhab >> chakraborty.anubhab@gmail.com)
*/
class TTTgame
{
  char winner;

public:
  class TTTgrid
  {
    friend class TTTgame;
    char grid[3][3];
    int count;

  public:

    class Position
    {
      int x;
      int y;
      /*
        -- x -->
        0  1  2 |
      0__|__|__ y
      1__|__|__ |
      2  |  |   V
      */
    public:
      int getx() { return x; }
      int gety() { return y; }

      void setxy(int a, int b)
      {
        if (a < 3 && b < 3)
        {
          x = a;
          y = b;
        }
        else
        {
          x = -1;
          y = -1;
        }
      }
    };

    //Def Con --> Create an empty TTTgrid
    TTTgrid()
    {
      reset();
    }

    //copy constructor for TTTgrid
    TTTgrid(const TTTgrid& inGrid)
    {
      TTTgame::TTTgrid::Position pos;
      for (int i = 0; i < 3; i++)
        for (int j = 0; j<3; j++)
          {
            pos.setxy(i,j);
            grid[i][j] = inGrid.getMarkAt(pos);
            count = inGrid.getCount();
          }
    }



  //return total markings
  int getCount() const { return count; }

  //returns the status of a given position
  bool isPosEmpty( Position pos )
  {
    if ( grid[ pos.getx() ][ pos.gety() ] == '\0' )
      return true;
    else
      return false;
  }

  //get mark at a specified position
  char getMarkAt( Position pos ) const
  {
    return grid[ pos.getx() ][ pos.gety() ];
  }

  //returns a two dimensional character array of the grid
  void getGrid(char** tmpGrid)
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j<3; j++)
        tmpGrid[i][j] = grid[i][j];
  }

  void reset()
  {
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        grid[i][j] = '\0';
    count = 0;
  }

} gameGrid;

  TTTgame()
  {
    new_game();
  }

  //call to check status of the game
  bool isAlive()
  {
    if (winner == '\0')
      return true; //if there is no winner, the game is still alive
    else
      return false;
  }

  //get the current turn of the game
  char getTurn()
  {
    //game always starts with 'X'
    if( gameGrid.getCount()%2 == 0 )
      return 'X';
    else
      return 'O';
  }

  //Marks a position on the grid
  bool mark(TTTgrid::Position pos, char ch)
  {
    if ((isAlive() == true) &&  //proceed only if game is on!
        (pos.getx() != -1) &&  //check if the x coord is valid
          (pos.gety() != -1)) //check if the y coord is valid
    {
      if (ch == 'X' || ch == 'x' || ch == 'O' || ch == 'o')
      {
        if (gameGrid.isPosEmpty(pos) ==  true) //replacing marks not allowed
        {
          gameGrid.grid[ pos.getx() ][ pos.gety() ] = ch;
          gameGrid.count++;
          char w = checkWin(pos); //after every mark check if
          if(w != '\0')           //there is any winner
            setWinner(w);         //if there is, set winner
          return true; //Marking Successful!
        }
        else
          return false; // Position Blocked
      }
      else
        return false; //Invalid character
    }
  }


  //Automatically mark a given postion
  bool autoMark( TTTgrid::Position pos )
  {
    char turn = getTurn();
    if(mark(pos, turn)== true)
      return true;
    else
      return false;
  }

  void new_game()
  {
    winner = '\0';
    gameGrid.reset();
  }

  void getGrid( TTTgrid tempGrid )
  {
    tempGrid = gameGrid;
  }

  char getWinner() { return winner; }

private:

  //sets the winner if the grid is full
  //if no winner, then winner is set to 'D' (=Draw)
  void setWinner(char a)
  {
    winner = a;
  }

  //Start checking from a given Position
  //where pos is the last marked position
  char checkWin( TTTgrid::Position pos )
  {
    int x2, y2, x3, y3; //the other positions alongside the selected positions
    int x = pos.getx();
    int y = pos.gety();

    {//setting perpherial positions for check
      if (x == 0) {x2 = 1; x3= 2;}
      else if (x == 1) {x2 = 0; x3= 2;}
      else {x2 = 0; x3= 1;}
      if (y == 0) {y2 = 1; y3= 2;}
      else if (y == 1) {y2 = 0; y3= 2;}
      else {y2 = 0; y3= 1;}
    }

    if ((gameGrid.grid[x][y] == gameGrid.grid[x2][y]) && //check horizontal matching
        (gameGrid.grid[x][y] == gameGrid.grid[x3][y]))
       return gameGrid.grid[x][y];

    else if ((gameGrid.grid[x][y] == gameGrid.grid[x][y2]) && //check vertical matching
        (gameGrid.grid[x][y] == gameGrid.grid[x][y3]))
       return gameGrid.grid[x][y];

    if (x == y)
    {
      if ((gameGrid.grid[1][1] == gameGrid.grid[0][0]) && //check 1st diagonal matching
          (gameGrid.grid[1][1] == gameGrid.grid[2][2]))
        return gameGrid.grid[x][y];
    }
    else if(x + y == 2)
    {
      if ((gameGrid.grid[1][1] == gameGrid.grid[0][2]) && //2nd diagonal matching
            (gameGrid.grid[1][1] == gameGrid.grid[2][0]))
        return gameGrid.grid[x][y];
    }

    if (gameGrid.getCount() == 9) //note: increase the count before calling checkwin
      return 'D';
    else
      return '\0';
  }
};
