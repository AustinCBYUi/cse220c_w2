// Week02Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "account.h"
#include <iostream>

int main()
{

	int user_input;
	bool quit = false;
	Account account;

	while (!quit) {
		std::cout << "Account Menu:\n";
		std::cout << "0. Quit Program\n";
		std::cout << "1. Create New Account\n";
		std::cout << "2. Display Account Information\n";
		std::cout << "3. Deposit\n";
		std::cout << "4. Withdraw\n";
		std::cout << "5. View All Accounts\n"; //Added this option to view all accounts.
		std::cout << "6. Remove Account\n"; //Added this option to remove an account.
		std::cout << "7. Get All Deposits\n";
		std::cout << "8. Apply Dividends\n";
		std::cout << "Enter your choice: ";
		std::cin >> user_input;
		std::cout << "\n"; //Line clear

		switch (user_input) {
		case 0:
			std::cout << "Exiting Program\n";
			quit = true;
			break;
		case 1: {
			Account reg_new_account;
			reg_new_account.inputAccountInfo();
			reg_new_account.add_account(reg_new_account);
			std::cout << reg_new_account << std::endl;
			break;
		}
		case 2: {
			int account_id;
			std::cout << "\nEnter the account ID: ";
			std::cin >> account_id;
			account.find_account(account_id);
			break;
		}
		case 3: {
			int account_id;
			std::cout << "\nEnter an Account ID to deposit into: ";
			std::cin >> account_id;

			Account acc;
			auto iter = acc.find_account_iter(account_id);
			if (iter != acc.get_accounts_map().end()) {
				Account& account = iter->second;
				float deposit_amount;
				std::cout << "Enter the amount to deposit: $";
				std::cin >> deposit_amount;
				account += deposit_amount;
			}
			else {
				std::cout << "Account with ID " << account_id << " was not found.\n" << std::endl;
			}
			break;
		}
		case 4: {
			int account_id;
			std::cout << "\nEnter an Account ID to withdraw from: ";
			std::cin >> account_id;

			Account acc;
			auto iter = acc.find_account_iter(account_id);
			if (iter != acc.get_accounts_map().end()) {
				Account& account = iter->second;
				float withdrawal_amount;
				std::cout << "Enter the amount to withdraw: $";
				std::cin >> withdrawal_amount;
				account -= withdrawal_amount;
			}
			else {
				std::cout << "Account with ID " << account_id << " was not found.\n" << std::endl;
			}
			break;
		}
		case 5: {
			Account account;
			account.get_accounts();
			break;
		}
		case 6: {
			int account_id;
			std::cout << "\nEnter an Account ID to remove: ";
			std::cin >> account_id;

			Account acc;
			acc.remove_accounts(account_id);
			break;
		}
		case 7: {
			Account acc;
			std::cout << "Total Deposits in All Accounts: $" << acc.get_total_deposits() << "\n" << std::endl;
			break;
		}
		case 8: {
			float percentage;
			std::cout << "Enter the percentage of dividends to apply: ";
			std::cin >> percentage;
			account.apply_dividends(percentage);
			break;
		}

		//End of switch statement
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
