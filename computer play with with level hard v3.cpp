else if (diff == 1)
		{

			int board[9] = { 0,0,0,0,0,0,0,0,0 };

			//computer squares are 1, player squares are -1.
			cout << "\n  -Computer: 'O'\n  -You: 'X'\nPlay (1)st or (2)nd? ";
			int player = 0;
			cin >> player;
			cout << "\n";
			unsigned turn;

			for (turn = 0; turn < 9 && win(board) == 0; ++turn) {
				if ((turn + player) % 2 == 0)
					computerMove(board);
				else {
					draw(board);
					playerMove(board);
				}
			}

			switch (win(board)) {
			case 0:
				draw(board);
				cout << "A draw. How droll.\n";
				break;
			case 1:
				draw(board);
				cout << "You lose.\n";
				break;
			case -1:
				draw(board);
				cout << "You win. Inconceivable!\n";
				break;
			}

		}
		else
		{
			cout << "Invalid input please enter 0 OR 1 ONLY!\n";
			goto label;
		}
