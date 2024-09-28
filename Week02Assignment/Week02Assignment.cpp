// Week02Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "account.h"
#include <iostream>

int main()
{
	//Creates a new account.
	Account account_init;
	account_init.inputAccountInfo();
	std::cout << account_init << std::endl;

	int user_input;
	bool quit = false;

	while (!quit) {
		std::cout << "Account Menu:\n";
		std::cout << "0. Quit Program\n";
		std::cout << "1. Display Account Information\n";
		std::cout << "2. Deposit\n";
		std::cout << "3. Withdraw\n";
		std::cout << "Enter your choice: ";
		std::cin >> user_input;
		std::cout << "\n"; //Line clear

		switch (user_input) {
		case 0:
			std::cout << "Exiting Program\n";
			quit = true;
			break;
		case 1:
			//account_init.displayAccountInfo();
			std::cout << account_init << std::endl;
			break;
		case 2:
			float deposit_amount;
			std::cout << "Enter the amount to deposit: $";
			std::cin >> deposit_amount;
			//account_init.add_to_account_balance(deposit_amount);
			account_init += deposit_amount;
			break;
		case 3:
			float withdrawal_amount;
			std::cout << "Enter the amount to withdraw: $";
			std::cin >> withdrawal_amount;
			account_init -= withdrawal_amount;
			break;
		}
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
