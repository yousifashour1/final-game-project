int diff;
		std::cout << "\nFor Difficulty :\n  -Hard = '1' \n  -Easy = '0' \n";
	label:	std::cout << "\nChoose Difficulty : ";
		std::cin >> diff;

		if (diff == 0)
		{
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

				if (i == 4)
					break;

				change_value(head, 'O', Easy_difficulty(head) - 1);
				display(head);
				iscompleted(head);
			}

		}
