//Seth Schaller
#include <iostream>
using namespace std;

enum game_status { inProgress, Xwon, Owon, tie };

//Struct that defines the positioning of the players move
struct position
{
	int row, col;
};

//Struct that defines the board and its attributes
struct TicTacToeBoard
{
	char board[3][3];
	position chosen;
	int validMoves;
	game_status status;
	char move;
};

//Preconditional - board must be initialized before it can be printed
//Postconditional - board is printed
//Helper function that prints the board when called
void printBoard(TicTacToeBoard board)
{
	cout << endl;
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
			cout << " " << board.board[r][c];
		cout << endl;
	}
	cout << endl;
}

//Preconditional - instance of TicTacToeBoard must be created
//Postconditional - Board is set to blank, status is set to inProgress, validMoves is set to 0 and the first player is set to X
//Helper function that initializes the board
void initializeIt(TicTacToeBoard &board)
{
	for (int r = 0; r < 3; ++r)
		for (int c = 0; c < 3; ++c)
			board.board[r][c] = '-';
	board.move = 'X';
	board.validMoves = 0;
	board.status = inProgress;
}

//Preconditional - there must be no winner or the game status is still inProgress
//Postconditional - the players turn is switched or the move is swithed
//Helper function that changes whos turn it is at the end of each turn
void switchTurn(TicTacToeBoard &board)
{
		if (board.move == 'X')
			board.move = 'O';
		else if (board.move == 'O')
			board.move = 'X';
}

//Preconditional - Valid move must be entered
//Postconditional - If either x won, o won, its a tie or the game continues
//Helper function that checks to see if there is a winner or a tie
void checkWinner(TicTacToeBoard &board)
{
	while (board.move == 'X') {
		if (board.board[0][0] == 'X' && board.board[0][1] == 'X' && board.board[0][2] == 'X')//Top accross
		{
			board.status = Xwon;
			break;
		}
		else if (board.board[1][0] == 'X' && board.board[1][1] == 'X' && board.board[1][2] == 'X')//Middle accross
		{
			board.status = Xwon;
			break;
		}
		else if (board.board[2][0] == 'X' && board.board[2][1] == 'X' && board.board[2][2] == 'X')//Bottom accross
		{
			board.status = Xwon;
			break;
		}
		else if (board.board[0][0] == 'X' && board.board[1][0] == 'X' && board.board[2][0] == 'X')//Left down
		{
			board.status = Xwon;
			break;
		}
		else if (board.board[0][1] == 'X' && board.board[1][1] == 'X' && board.board[2][1] == 'X')//Middle down
		{
			board.status = Xwon;
			break;
		}
		else if (board.board[0][2] == 'X' && board.board[1][2] == 'X' && board.board[2][2] == 'X')//Right down
		{
			board.status = Xwon;
			break;
		}
		else if (board.board[0][0] == 'X' && board.board[1][1] == 'X' && board.board[2][2] == 'X')//Top left corner to bottom right corner
		{
			board.status = Xwon;
			break;
		}
		else if (board.board[0][2] == 'X' && board.board[1][1] == 'X' && board.board[2][0] == 'X')//Top right corner to bottom left corner
		{
			board.status = Xwon;
			break;
		}
		else if (board.validMoves == 9 && board.status == inProgress)//Checks for tie
		{
			board.status = tie;
			break;
		}
		else
			break;
	}
	while (board.move == 'O') {
		if (board.board[0][0] == 'O' && board.board[0][1] == 'O' && board.board[0][2] == 'O')//Top accross
		{
			board.status = Owon;
			break;
		}
		else if (board.board[1][0] == 'O' && board.board[1][1] == 'O' && board.board[1][2] == 'O')//Middle accross
		{
			board.status = Owon;
			break;
		}
		else if (board.board[2][0] == 'O' && board.board[2][1] == 'O' && board.board[2][2] == 'O')//Bottom accross
		{
			board.status = Owon;
			break;
		}
		else if (board.board[0][0] == 'O' && board.board[1][0] == 'O' && board.board[2][0] == 'O')//Left down
		{
			board.status = Owon;
			break;
		}
		else if (board.board[0][1] == 'O' && board.board[1][1] == 'O' && board.board[2][1] == 'O')//Middle down
		{
			board.status = Owon;
			break;
		}
		else if (board.board[0][2] == 'O' && board.board[1][2] == 'O' && board.board[2][2] == 'O')//Right down
		{
			board.status = Owon;
			break;
		}
		else if (board.board[0][0] == 'O' && board.board[1][1] == 'O' && board.board[2][2] == 'O')//Top left corner to bottom right corner
		{
			board.status = Owon;
			break;
		}
		else if (board.board[0][2] == 'O' && board.board[1][1] == 'O' && board.board[2][0] == 'O')//Top right corner to bottom left corner
		{
			board.status = Owon;
			break;
		}
		else if (board.validMoves == 9 && board.status == inProgress)//Checks for tie
		{
			board.status = tie;
			break;
		}
		else
			break;
	}
}

//Preconditional - Instance of the TicTacToeBoard must be created and initialized
//Postconditional - The game is able to be played
//Function that allows the user to play Tic Tac Toe
void play(TicTacToeBoard &board)
{
	printBoard(board); //prints blank board
	while (board.validMoves < 9 && board.status == inProgress) //Stops when whole board is filled up or someone won
	{
		cout << "Player " << board.move << " - enter a row # and column # seperated by a space";
		cin >> board.chosen.row >> board.chosen.col;
		if (board.board[board.chosen.row][board.chosen.col] == '-' && board.chosen.row <3 && board.chosen.col < 3)
		{
			board.board[board.chosen.row][board.chosen.col] = board.move;
			board.validMoves++;
			checkWinner(board);
			printBoard(board);

			if (board.status == Xwon)
				cout << "Congrats, X, you won!" << endl;
			else if (board.status == Owon)
				cout << "Congrats, O, you won!" << endl;
			else if (board.status == tie)
				cout << "It's a tie" << endl;
			else
				switchTurn(board);
		}
		else if (board.board[board.chosen.row][board.chosen.col] != '-') //Move has already been placed
			cout << "Invalid move, try again" << endl;
		else if (board.chosen.row >= 3 || board.chosen.col >= 3) //Checks for a valid position chosen
			cout << "Invalid move, try again" << endl;
	} 
}

int main()
{
	cout << "TIC TAC TOE" << endl;
	TicTacToeBoard myBoard;
	initializeIt(myBoard);
	play(myBoard);

	char c;
	cin >> c;

	return EXIT_SUCCESS;
}