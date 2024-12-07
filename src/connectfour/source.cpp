#include <iostream>
using namespace std;

class Game
{
public:
    string players[2];
    Game()
    {

        cout << "Let's Play Connect Four! Coded by Nico." << endl;

        cout << "Enter Player 1's Name: ";
        cin >> players[0];
        cout << "Enter Player 2's Name: ";
        cin >> players[1];
        cout << endl;

        cout << "Initializing Game..." << endl;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                board[i][j] = TOKEN;
            };
        };

        cout << "Created Board." << endl;

        printBoard();

        cout << "Starting Game." << endl;

        while (canPlay)
        {
            /* code */
            doTurn();
        }

        // New Game
        cout << "Play Again? (y/n): ";
        char choice;
        cin >> choice;
        cout << endl;
        if (choice == 'y' || choice == 'Y')
        {
            Game newgame;
        }
    }

    const bool checkWin() // Made Constant
    {
        // cout << "Debug: Entering checkWin" << endl;
        /*
        Winning Cases:
        - Horizontal 4
        - Vertical 4
        - Diagonal 4
        */

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                // Horizontal Check (Checked, Works.)

                /*
                if (j < 4)
                {
                    if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]) && (board[i][j] == board[i][j + 3]) && (board[i][j] != TOKEN))
                    {
                        return true;
                    }
                }

                // Vertical Check (Checked, Works.)
                if (i < 3)
                {
                    if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]) && (board[i][j] == board[i + 3][j]) && (board[i][j] != TOKEN))
                    {
                        return true;
                    }
                }

                // Diagonal Check 1
                if (i < 3 && j > 4)
                {
                    if (
                        board[i][j] != TOKEN &&
                        board[i][j] == board[i + 1][j + 1] &&
                        board[i][j] == board[i + 2][j + 2] &&
                        board[i][j] == board[i + 3][j + 3])
                    {
                        return true;
                    }
                }

                // Diagonal Check 2
                if (i < 3 && j < 4)
                {
                    if (
                        board[i][j] != TOKEN &&
                        board[i][j] == board[i + 1][j - 1] &&
                        board[i][j] == board[i + 2][j - 2] &&
                        board[i][j] == board[i + 3][j - 3])
                    {
                        return true;
                    }
                }

                // Diagonal Check 3
                if (i >= 3 && j > 4)
                {
                    if (
                        board[i][j] != TOKEN &&
                        board[i][j] == board[i - 1][j + 1] &&
                        board[i][j] == board[i - 2][j + 2] &&
                        board[i][j] == board[i - 3][j + 3])
                    {
                        return true;
                    }
                }

                // Diagonal Check 4
                if (i < 3 && j >= 3)
                {
                    if (
                        board[i][j] != TOKEN &&
                        board[i][j] == board[i + 1][j - 1] &&
                        board[i][j] == board[i + 2][j - 2] &&
                        board[i][j] == board[i + 3][j - 3])
                    {
                        return true;
                    }
                }
                */
               if ( fourInARow(i,j,1,1) || fourInARow(i,j,1,-1) || fourInARow(i,j,-1,1) || fourInARow(i,j,-1,-1) || fourInARow(i,j,1,0) || fourInARow(i,j,0,1) ){
                    return true;
               }
            };
        };

        // cout << "Debug: Exiting doTurn" << endl;
        return false;
    }

    void doTurn()
    {
        // cout << "Debug: Entering doTurn" << endl;
        currentPlayer = (currentPlayer%2)+1; // modulo
        int x, y = -1;
        cout << "Player " << currentPlayer << " (" << players[currentPlayer - 1] << "), Where would you like to put your chip (X)?" << endl;
        cout << "X: ";
        cin >> x;
        cout << endl;

        // find available Y in the board.
        for (int i = 5; i > -1; i--)
        {
            if (board[i][x - 1] == TOKEN)
            {
                y = i + 1;
                break;
            }
        };

        // check if x,y is valid

        // Neatened Code
        if (cin.fail() || x < 1 || x > COLS)
        {
            cout << "Invalid input, Moving On." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');

            return;
        }

        board[y - 1][x - 1] = currentPlayer == 1 ? "X" : "O";

        printBoard();
        if (checkWin())
        {
            canPlay = false;

            cout << "Player " << currentPlayer << " (" << players[currentPlayer - 1] << "), Has Won!" << endl;
            return;
        }

        if (y == -1)
        {
            

            int left = 0;
            // Check if All Columns are filled
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    if (board[i][j] == TOKEN)
                    {
                        left++;
                    }
                };
            };
            // cout << "Debug: " << left << endl;
            canPlay = left > 0;
            if (canPlay){
                cout << "Column full! Choose another column." << endl;
            }else{
                cout << "Board full! Nobody Wins." << endl;
            }

            return;
        }
        // cout << "Debug: Exiting doTurn" << endl;
    }

    // Getter
    const void printBoard() // Made Constant
    {
        for (int i = 0; i < ROWS; i++)
        {
            cout << i + 1 << " ";
            for (int j = 0; j < COLS; j++)
            {
                cout << board[i][j] << " ";
            };
            cout << "\n";
        };
        cout << "  ";
        for (int i = 0; i < COLS; i++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }

private:
    const static int ROWS = 6;
    const static int COLS = 7; // both constant variables now
    string board[ROWS][COLS];
    int currentPlayer;
    const string TOKEN = "-"; // Made Constant
    bool canPlay = true;

    // helper functions
    bool fourInARow(int x, int y, int dx, int dy){
        string curAt = board[x][y]; // currently at, AKA the current token.
        if( curAt == TOKEN ){
            //cerr << "Default Token" << endl;
            return false;
        }
        
        //cerr << "x: " << x+1 << " y: " << y+1 << " dx: " << dx << " dy: " << dy << endl;

        // assure that x + (4 * dx) and y + (4 * dy) are in bounds

        if ( !( (-1 < (x + (4 * dx)) && (x + (4 * dx)) < ROWS) && (-1 < (y + (4 * dy)) && (y + (4 * dy)) < COLS)  ) ){
            //cerr << "(" <<(x + (4 * dx))+1 << "," << (y + (4 * dy))+1 << ") Out of Bounds" << endl;
            return false;
        }

        //cerr << "(" <<(x + (4 * dx))+1 << "," << (y + (4 * dy))+1 << ") In Bounds" << endl;
        
        for ( int i = 0; i < 4; i++){
            
            if(board[x + i * dx][y + i * dy] != curAt){
                //cerr << "Doesnt Equal" << board[x + 1 * dx][y + 1 * dy] << endl;
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Game game;
    // game.printBoard();
    cout << sizeof(game);
    return 0;
}