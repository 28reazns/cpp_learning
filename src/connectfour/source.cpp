#include <iostream>
using namespace std;

class Game
{
public:
    string players[2];
    Game()
    {
        cout << "\n"
             << "\n"
             << "\n"
             << "\n"
             << "\n"
             << endl;
        cout << "Let's Play Connect Four! Coded by Nico." << endl;

        
        size[0] = sizeof(board) / sizeof(board[0]);
        size[1] = sizeof(board[0]) / sizeof(board[0][0]);
        cout << "Enter Player 1's Name: ";
        cin >> players[0];
        cout << "Enter Player 2's Name: ";
        cin >> players[1];
        cout << endl;

        cout << "Initializing Game..." << endl;

        for (int i = 0; i < size[0]; i++)
        {
            for (int j = 0; j < size[1]; j++)
            {
                board[i][j] = defaultString;
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
    }

    bool checkWin()
    {

        /*
        Winning Cases:
        - Horizontal 4
        - Vertical 4
        - Diagonal 4
        */
        // Horizontal Check (Checked, Works.)
        for (int i = 0; i < size[0]; i++)
        {
            for (int j = 0; j < size[1]-4; j++)
            {
               if( ( board[i][j] == board[i][j+1] ) && ( board[i][j] == board[i][j+2] ) && ( board[i][j] == board[i][j+3] ) && (board[i][j]!=defaultString) ){
                    return true;
                }
            };
        };

        // Vertical Check (Checked, Works.)
        for (int i = 0; i < size[0]; i++)
        {
            for (int j = 0; j < size[1]-4; j++)
            {
                if( ( board[i][j] == board[i+1][j] ) && ( board[i][j] == board[i+2][j] ) && ( board[i][j] == board[i+3][j] ) && (board[i][j]!=defaultString) ){
                    return true;
                }
            };
        };

        // Diagonal Check 1 
        for (int i = 0; i < size[0]-4; i++)
        {
            for (int j = 0; j < size[1]-4; j++)
            {
                if( 
                    board[i][j]!=defaultString 
                    &&
                    board[i][j] == board[i+1][j+1]
                    &&
                    board[i][j] == board[i+2][j+2]
                    &&
                    board[i][j] == board[i+3][j+3]
                ){
                    return true;
                }
            };
        };

        // Diagonal Check 2
        for (int i = size[0]; i > 4 ; --i)
        {
            for (int j = size[1]; j > 4 ; --j)
            {
                if( 
                    board[i][j]!=defaultString 
                    &&
                    board[i][j] == board[i-1][j-1]
                    &&
                    board[i][j] == board[i-2][j-2]
                    &&
                    board[i][j] == board[i-3][j-3]
                ){
                    return true;
                }
            };
        };

        // Diagonal Check 3
        for (int i = 0; i < size[0]-4; i++)
        {
            for (int j = size[1]; j > 4 ; --j)
            {
                if( 
                    board[i][j]!=defaultString 
                    &&
                    board[i][j] == board[i+1][j-1]
                    &&
                    board[i][j] == board[i+2][j-2]
                    &&
                    board[i][j] == board[i+3][j-3]
                ){
                    return true;
                }
            };
        };

        // Diagonal Check 4
        for (int i = size[0]; i > 4 ; --i)
        {
            for (int j = 0; j < size[1]-4; j++)
            {
                if( 
                    board[i][j]!=defaultString 
                    &&
                    board[i][j] == board[i-1][j+1]
                    &&
                    board[i][j] == board[i-2][j+2]
                    &&
                    board[i][j] == board[i-3][j+3]
                ){
                    return true;
                }
            };
        };

        

        return false;
    }

    void doTurn()
    {
        currentPlayer = currentPlayer == 1 ? 2 : 1;
        int x, y = -1;
        cout << "Player " << currentPlayer << " (" << players[currentPlayer - 1] << "), Where would you like to put your chip (X)?" << endl;
        cout << "X: ";
        cin >> x;
        cout << endl;

        // find available Y in the board.
        for (int i = size[0] - 1; i > -1; i--)
        {
            if (board[i][x - 1] == defaultString)
            {
                y = i + 1;
                break;
            }
        };

        // check if x,y is valid
        if ((0 >= x || x > size[1]) || (0 >= y || y > size[0]) || (board[y - 1][x - 1] != defaultString))
        {
            cout << "Invalid Coordinate Passed. Try Again.";
        }
        else
        {
            board[y - 1][x - 1] = currentPlayer == 1 ? "X" : "O";

            printBoard();
            if(checkWin()){
                canPlay = false;

                cout << "Player " << currentPlayer << " (" << players[currentPlayer - 1] << "), Has Won!" << endl;
            }
        }
    }

    // Getter
    void printBoard()
    {
        for (int i = 0; i < size[0]; i++)
        {
            cout << i + 1 << "   ";
            for (int j = 0; j < size[1]; j++)
            {
                cout << board[i][j] << " ";
            };
            cout << "\n";
        };
        cout << "\n";
        cout << "    ";
        for (int i = 0; i < size[1]; i++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }

private:
    string board[6][7];
    int currentPlayer;
    int size[2];
    string defaultString = "-";
    bool canPlay = true;
};

int main()
{
    Game *game = new Game();
    // game.printBoard();
    cout << sizeof(game);
    delete game;

    return 0;
}