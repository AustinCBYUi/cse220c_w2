#include "account.h"
#include <string>
#include <iostream>

using bank_account_app::Account;

Account::Account() :account_id{ 0 }, account_name{ "" }, account_balance{ 0 }{}

Account::Account() {
}
//Need to work on this main().
void main() {
	int previous_account_id = 0;
	Account newAccount();
	std::cout << "Enter the name: ";
	//std::cin << newAccount().set_account_name()
}

void Account::set_account_id(int previous_account_id) {

	account_id = previous_account_id++;
}
int increase_last_account_id(int previous_account_id) {
	return previous_account_id++;
}
int Account::get_account_id()const {
	return account_id;
}
void Account::set_account_name(std::string name) {
	account_name = name;
}
std::string Account::get_account_name()const {
	return account_name;
}
void Account::set_account_balance(float balance) {
	account_balance = balance;
}
float Account::get_account_balance()const {
	return account_balance;
}
void display_account_info(Account account) {
	std::cout << "Account ID: " << account.get_account_id() << " Name: " << account.get_account_name() << " Balance: " << account.get_account_balance();
}
