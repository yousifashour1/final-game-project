
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;


struct node           // we implemented this game using linked list and arrays *FROM SCRATCH*
{
	char data;
	node* next;
};

//function to insert a node in a linked list at a given position

void insert_at_position(node** head, char data, int pos)
{
	node* newnode = new node();
	node* prev;
	node* after;
	if (newnode == NULL)
	{
		std::cout << "Heap is full !!!" << endl;
		return;
	}
	newnode->data = data;
	if (*head == NULL)
	{
		newnode->next = NULL;
		*head = newnode;
	}
	else if (pos == 0)
	{
		newnode->next = *head;
		*head = newnode;
	}
	else
	{
		prev = *head;
		int i = 0;
		for (i; i < pos - 1; i++)
			prev = prev->next;
		after = prev->next;
		newnode->next = after;
		prev->next = newnode;
	}

}

//displaying the 3x3 tic-tac-toe board

void display(node* head)
{
	system("CLS");    // to clear screen

	cout << "\n";
	cout << "                ___________________\n";
	cout << "                |     |     |     |  " << endl;
	cout << "                |  " << head->data << "  |  " << head->next->data << "  |  " << head->next->next->data << "  |  " << endl;
	head = head->next->next->next;
	cout << "                |_____|_____|_____|" << endl;
	cout << "                |     |     |     |  " << endl;
	cout << "                |  " << head->data << "  |  " << head->next->data << "  |  " << head->next->next->data << "  |  " << endl;
	head = head->next->next->next;
	cout << "                |_____|_____|_____|" << endl;
	cout << "                |     |     |     |  " << endl;
	cout << "                |  " << head->data << "  |  " << head->next->data << "  |  " << head->next->next->data << "  |  " << endl;
	head = head->next->next->next;
	cout << "                |_____|_____|_____|" << endl << endl;
}


//function to put either 'X' or 'O' in board
bool change_value(node* head, char data, int index)
{
	for (int i = 0; i < index; i++)
		head = head->next;
	if (head->data == 'X' || head->data == 'O')
	{
		return false;
	}
	head->data = data;
	return true;
}

//this function is used to check if either 'X' or 'O' won or draw

void iscompleted(node* head)
{
	// check if any row is matched with same type
	node* tmphead = head;
	int Xcounter = 0;
	int Ocounter = 0;
	for (int j = 0; j < 3; j++)
	{
		Xcounter = 0;
		Ocounter = 0;
		for (int i = 0; i < 3; i++)
		{
			if (tmphead->data == 'X')
				Xcounter++;
			else if (tmphead->data == 'O')
				Ocounter++;
			tmphead = tmphead->next;

		}
		if (Xcounter == 3)
		{
			display(head);
			std::cout << "\n---------------X Won...-------------\n";

			exit(0);
		}
		else if (Ocounter == 3)
		{
			display(head);
			std::cout << "\n---------------O Won...-------------\n";

			exit(0);
		}

	}

	//check if Left diagonal X is completed
	tmphead = head;
	Xcounter = Ocounter = 0;
	if (tmphead->data == 'X')
	{
		Xcounter++;
		//	for (int j = 0; j < 4; j++)
		tmphead = tmphead->next->next->next->next;

		if (tmphead->data == 'X')
			Xcounter++;

		//for (int j = 0; j < 4; j++)
		tmphead = tmphead->next->next->next->next;
		if (tmphead->data == 'X')
			Xcounter++;

	}

	//check if Left diagonal O is completed
	tmphead = head;
	if (tmphead->data == 'O')
	{
		Ocounter++;
		//for (int j = 0; j < 4; j++)
		tmphead = tmphead->next->next->next->next;
		if (tmphead->data == 'O')
			Ocounter++;

		//for (int j = 0; j < 4; j++)
		tmphead = tmphead->next->next->next->next;
		if (tmphead->data == 'O')
			Ocounter++;

	}
	if (Xcounter == 3)
	{
		display(head);
		std::cout << "\n---------------X Won...-------------\n";

		exit(0);
	}
	if (Ocounter == 3)
	{
		display(head);
		std::cout << "\n---------------O Won...-------------\n";

		exit(0);
	}

	//check if Right diagonal X is completed
	tmphead = head->next->next;
	Xcounter = Ocounter = 0;
	if (tmphead->data == 'X')
	{
		Xcounter++;
		//for (int j = 0; j < 2; j++)
		tmphead = tmphead->next->next;

		if (tmphead->data == 'X')
			Xcounter++;

		//for (int j = 0; j < 2; j++)
		tmphead = tmphead->next->next;

		if (tmphead->data == 'X')
			Xcounter++;

	}


	//check if Right diagonal O is completed
	tmphead = head->next->next;
	if (tmphead->data == 'O')
	{
		Ocounter++;
		//for (int j = 0; j < 2; j++)
		tmphead = tmphead->next->next;

		if (tmphead->data == 'O')
			Ocounter++;

		//for (int j = 0; j < 2; j++)
		tmphead = tmphead->next->next;

		if (tmphead->data == 'O')
			Ocounter++;

	}
	if (Xcounter == 3)
	{
		display(head);
		std::cout << "\n---------------X Won...-------------\n";

		exit(0);
	}
	if (Ocounter == 3)
	{
		display(head);
		std::cout << "\n---------------O Won...-------------\n";

		exit(0);
	}


	tmphead = head;
	// check if any column is matched with same type
	for (int j = 0; j < 3; j++)
	{
		//tmphead = head;
		Xcounter = Ocounter = 0;
		if (tmphead->data == 'X')
		{
			Xcounter++;
			//for (int j = 0; j < 3; j++)
			tmphead = tmphead->next->next->next;

			if (tmphead->data == 'X')
				Xcounter++;

			//for (int j = 0; j < 3; j++)
			tmphead = tmphead->next->next->next;

			if (tmphead->data == 'X')
				Xcounter++;

		}
		else if (tmphead->data == 'O')
		{

			Ocounter++;
			//for (int j = 0; j < 3; j++)
			tmphead = tmphead->next->next->next;

			if (tmphead->data == 'O')
				Ocounter++;

			//for (int j = 0; j < 3; j++)
			tmphead = tmphead->next->next->next;

			if (tmphead->data == 'O')
				Ocounter++;

		}
		for (int k = 0; k <= j; k++)
		{
			tmphead = head;
			tmphead = tmphead->next;
		}
		if (Xcounter == 3)
		{
			display(head);
			std::cout << "\n---------------X Won...-------------\n";

			exit(0);
		}
		tmphead = head;
		for (int k = 0; k <= j; k++)
			tmphead = tmphead->next;
		if (Ocounter == 3)
		{
			display(head);
			std::cout << "\n---------------O Won...-------------\n";

			exit(0);
		}
	}

}

//Easy diffuclty -single player function
int Easy_difficulty(node* head)
{
	node* current = head;
	bool Test = true;
	srand(time(0));
	int random_no = rand() % 9 + 1;

	while (Test)
	{
		for (int j = 1; j < random_no; j++)
			current = current->next;
		if (current->data == 'X' || current->data == 'O')
		{
			Test = true;
			srand(time(0));
			random_no = rand() % 9 + 1;
			current = head;
		}
		else
			Test = false;
	}
	return random_no;
}

//to draw grid
char gridChar(int i)
{
	switch (i) {
	case -1:
		return 'X';
	case 0:
		return ' ';
	case 1:
		return 'O';
	}
}

//this fucnction used to draw the square output of tic_tac_toe
void draw(int a[9])
{
	system("CLS");    // to clear screen
	cout << "\n";
	cout << "                ___________________\n";
	cout << "                |  1  |  2  |  3  |  " << endl;
	cout << "                |     |     |     |  " << endl;

	cout << "                |  " << gridChar(a[0]) << "  |  " << gridChar(a[1]) << "  |  " << gridChar(a[2]) << "  |  " << endl;


	cout << "                |_____|_____|_____|" << endl;
	cout << "                |  4  |  5  |  6  |  " << endl;
	cout << "                |     |     |     |  " << endl;


	cout << "                |  " << gridChar(a[3]) << "  |  " << gridChar(a[4]) << "  |  " << gridChar(a[5]) << "  |  " << endl;

	cout << "                |_____|_____|_____|" << endl;
	cout << "                |  7  |  8  |  9  |  " << endl;
	cout << "                |     |     |     |  " << endl;

	cout << "                |  " << gridChar(a[6]) << "  |  " << gridChar(a[7]) << "  |  " << gridChar(a[8]) << "  |  " << endl;
	cout << "                |_____|_____|_____|     " << endl << endl << endl;

}
int win(const int board[9])
{

	//determines if a player has won, returns 0 otherwise.
	unsigned wins[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
	int i;
	for (i = 0; i < 8; ++i) {
		if (board[wins[i][0]] != 0 &&
			board[wins[i][0]] == board[wins[i][1]] &&
			board[wins[i][0]] == board[wins[i][2]])
			return board[wins[i][2]];
	}
	return 0;
}

int minimax(int board[9], int player)
{


	//How is the position like for player (their turn) on board?
	int winner = win(board);
	if (winner != 0) return winner * player;

	int move = -1;
	int score = -2;//Losing moves are preferred to no move
	int i;
	for (i = 0; i < 9; ++i) {//For all moves,
		if (board[i] == 0) {//If legal,
			board[i] = player;//Try the move
			int thisScore = -minimax(board, player * -1);
			if (thisScore > score) {
				score = thisScore;
				move = i;
			}//Pick the one that's worst for the opponent
			board[i] = 0;//Reset board after try
		}
	}
	if (move == -1) return 0;
	return score;
}
void computerMove(int board[9])
{
	int move = -1;
	int score = -2;
	int i;
	for (i = 0; i < 9; ++i)
	{
		if (board[i] == 0)
		{
			board[i] = 1;
			int tempScore = -minimax(board, -1);
			board[i] = 0;
			if (tempScore > score) {
				score = tempScore;
				move = i;
			}
		}
	}
	//returns a score based on minimax tree at a given node.
	board[move] = 1;
}

void playerMove(int board[9])
{
	int move;
label1:
	cout << "Please enter a number from 1 to 9: ";
	cin >> move;
	cout << "\n";
	if (move > 9 || move < 1)
	{
		cout << "invalid try againg\n";
		goto label1;
	}
	else if (board[move - 1] == 1)
	{
		cout << "invalid try again\n";
		goto label1;
	}
	else
	{
		board[move - 1] = -1;
	}
}

int main()
{

	double start = clock();     //This is for calculation Time execution


	node* head = NULL;
	insert_at_position(&head, '1', 0);
	insert_at_position(&head, '2', 1);
	insert_at_position(&head, '3', 2);
	insert_at_position(&head, '4', 3);
	insert_at_position(&head, '5', 4);
	insert_at_position(&head, '6', 5);
	insert_at_position(&head, '7', 6);
	insert_at_position(&head, '8', 7);
	insert_at_position(&head, '9', 8);
	display(head);

	int select;





	for (int i = 0; i <= 4; i++)
		{

			std::cout << "\nwhere do you want to put X : ";
			std::cin >> select;

			while (select > 9 || select <= 0)
			{
				std::cout << "\nInvalid number please try again...\n";
				std::cout << "\nwhere do you want to put X : ";
				std::cin >> select;
				if (select > 0 && select <= 9)
					break;
			}
			if (!change_value(head, 'X', select - 1))
			{
				std::cout << "\nReserved place, please try in another location\n";
				i--;
				continue;
			}

			iscompleted(head);
			display(head);

			if (i == 4)
				break;
			std::cout << "\nwhere do you want to put O : ";
			std::cin >> select;
			while (select > 9 || select <= 0)
			{
				std::cout << "\nInvalid number please try again...\n";
				std::cout << "\nwhere do you want to put O : ";
				std::cin >> select;
				if (select > 0 && select <= 9)
					break;
			}


			change_value(head, 'O', select - 1);
			iscompleted(head);
			display(head);

		}

		std::cout << "\n ------------------Draw---------------\n";



	//Calculating the Time Execution

	double finish = clock();
	cout << "\nTime execution : " << (finish - start) / (CLOCKS_PER_SEC) << "\n\n";



	return 0;


}
