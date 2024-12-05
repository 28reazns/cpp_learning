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

        cout << "Enter Player 1's Name: ";
        cin >> players[0];
        cout << "Enter Player 2's Name: ";
        cin >> players[1];
        cout << endl;

        cout << "Initializing Game..." << endl;

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
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
        //cout << "Debug: Entering checkWin" << endl;
        /*
        Winning Cases:
        - Horizontal 4
        - Vertical 4
        - Diagonal 4
        */
        
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                // Horizontal Check (Checked, Works.)
                
                if (j < 4){
                    if ((board[i][j] == board[i][j + 1]) && (board[i][j] == board[i][j + 2]) && (board[i][j] == board[i][j + 3]) && (board[i][j] != defaultString))
                    {
                        return true;
                    }
                }

                 // Vertical Check (Checked, Works.)
                if(i < 3){
                    if ((board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 2][j]) && (board[i][j] == board[i + 3][j]) && (board[i][j] != defaultString))
                    {
                        return true;
                    }
                }

                // Diagonal Check 1 
                if( i<3 && j>4 ){
                    if (
                        board[i][j] != defaultString &&
                        board[i][j] == board[i + 1][j + 1] &&
                        board[i][j] == board[i + 2][j + 2] &&
                        board[i][j] == board[i + 3][j + 3])
                    {
                        return true;
                    }
                }
                
                // Diagonal Check 2 
                if( i<3 && j<4 ){
                    if (
                        board[i][j] != defaultString &&
                        board[i][j] == board[i + 1][j - 1] &&
                        board[i][j] == board[i + 2][j - 2] &&
                        board[i][j] == board[i + 3][j - 3])
                    {
                        return true;
                    }
                }

                // Diagonal Check 3
                if( i>=3 && j>4 ){
                    if (
                        board[i][j] != defaultString &&
                        board[i][j] == board[i - 1][j + 1] &&
                        board[i][j] == board[i - 2][j + 2] &&
                        board[i][j] == board[i - 3][j + 3])
                    {
                        return true;
                    }
                }

                // Diagonal Check 4 
                if( i<3 && j>=3 ){
                    if (
                        board[i][j] != defaultString &&
                        board[i][j] == board[i + 1][j - 1] &&
                        board[i][j] == board[i + 2][j - 2] &&
                        board[i][j] == board[i + 3][j - 3])
                    {
                        return true;
                    }
                }

            };
        };

        //cout << "Debug: Exiting doTurn" << endl;
        return false;
    }

    void doTurn() 
    {
        //cout << "Debug: Entering doTurn" << endl;
        currentPlayer = currentPlayer == 1 ? 2 : 1;
        int x, y = -1;
        cout << "Player " << currentPlayer << " (" << players[currentPlayer - 1] << "), Where would you like to put your chip (X)?" << endl;
        cout << "X: ";
        cin >> x;
        cout << endl;

        // find available Y in the board.
        for (int i = 5; i > -1; i--)
        {
            if (board[i][x - 1] == defaultString)
            {
                y = i + 1;
                break;
            }
        };

        // check if x,y is valid

        // Neatened Code
        if (cin.fail() || x < 1 || x > 7)
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

        if (y == -1) {
            cout << "Column full! Choose another column." << endl;

            int left = 0;
            // Check if All Columns are filled
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    if (board[i][j] == defaultString)
                    {
                        left++;
                    }
                };
            };
            //cout << "Debug: " << left << endl;
            canPlay = left > 0;

            return;
        }
        //cout << "Debug: Exiting doTurn" << endl;
        
    }

    // Getter
    const void printBoard() // Made Constant
    {
        for (int i = 0; i < 6; i++)
        {
            cout << i + 1 << " ";
            for (int j = 0; j < 7; j++)
            {
                cout << board[i][j] << " ";
            };
            cout << "\n";
        };
        cout << "  ";
        for (int i = 0; i < 7; i++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }

private:
    string board[6][7];
    int currentPlayer;
    const string defaultString = "-"; // Made Constant
    bool canPlay = true;
};

int main()
{
    Game game;
    // game.printBoard();
    cout << sizeof(game);
    return 0;
}