#include "account.h"
#include <string>
#include <iostream>
#include <map>
#include <list>

//Static variables are initialized here.
int Account::next_id = 1;
std::map<int, Account> Account::accounts;


//The constructor is used to initialize the account ID and account balance.
Account::Account() : account_id(-1), account_balance(0.0f) {
	account_name = "";
}



//Methods begin.
std::map<int, Account>::iterator Account::find_account_iter(int id) {
	return accounts.find(id);
}

void Account::find_account(int account_id) const {
	auto iter = accounts.find(account_id);
	if (iter != accounts.end()) {
		const Account& account = iter->second;
		std::cout << "Found Account:: Account ID: " << account_id << " | Account Name: " << account.account_name << " | Account Balance: $" << account.account_balance << "\n" << std::endl;
	}
	else {
		std::cout << "Account with ID " << account_id << " was not found.\n" << std::endl;
	}
}

void Account::add_account(const Account& account) {
	accounts[account.account_id] = account;
}

void Account::get_accounts()const {
	if (accounts.empty()) {
		std::cout << "No accounts are available..\n" << std::endl;
		return;
	}

	for (const auto& pair : accounts) {
		const int& account_id = pair.first;
		const Account& account = pair.second;

		std::cout << "Account ID: " << account_id << " | Account Name: " << account.account_name << " | Account Balance: $" << account.account_balance << std::endl;
	}
	std::cout << "\n";
}

std::map<int, Account>& Account::get_accounts_map() {
	return accounts;
}

void Account::inputAccountInfo() {
	account_id = next_id++;
	std::cout << "Enter the name: ";
	std::cin >> account_name;
	std::cout << "Enter the initial balance: ";
	std::cin >> account_balance;
	std::cout << "\n"; //Line clear
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

//A lot more streamlined than the displayAccountInfo() function.
std::ostream& Account::display(std::ostream& out) const {
	return std::cout << "Account ID: " << account_id << " Name: " << account_name << " Balance: $" << account_balance << "\n" << std::endl;
}

//The overloaded operators here are also pretty cool, as they allow for a more streamlined way of adding and subtracting from the account balance.
Account& Account::operator+= (float deposit) {
	account_balance += deposit;
	return *this;
}

Account& Account::operator-= (float withdrawal) {
	account_balance -= withdrawal;
	return *this;
}

void Account::WriteToStream(std::ostream& os) const {
	os << "Account ID: " << account_id << "\n"
		<< "Account Name: " << account_name << "\n"
		<< "Account Balance: $" << account_balance << "\n";
}

std::ostream& operator<< (std::ostream& os, const Account& account) {
	account.WriteToStream(os);
	return os;
}
