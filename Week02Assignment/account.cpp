#include "account.h"
#include "contact.h"
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <numeric>
#include <memory>
#include <alg.h>

//Static variables are initialized here.
int Account::next_id = 1;
std::map<int, Account> Account::accounts;


//The constructor is used to initialize the account ID and account balance.
Account::Account() : account_id(-1), account_balance(0.0f) {
	account_name = "", contact_info = nullptr;
}



//Methods begin.

void Account::add_contact_info() {
	if (contact_info == nullptr) {
		contact_info = std::make_shared<Contact>();
	}
	contact_info->set_contact_info();
}

void Account::display_contact_info() const {
	std::cout << "Contact Information:\n";
	if (contact_info != nullptr) {
		contact_info->get_contact_info();
	}
	else {
		std::cout << "No contact information available.\n" << std::endl;
	}
}

//I tried using std::transform here for a while, but it was giving me a lot of trouble. I ended up using std::for_each instead.
//I kept getting a binary '=': no operator found which takes a right-hand operand of type '_T1' error.
void Account::apply_dividends(float percentage) {
	std::for_each(accounts.begin(), accounts.end(),
		[percentage](auto& pair) {
			// Modify the account balance directly
			Account& account = pair.second; // Get reference to Account
			float new_balance = account.get_account_balance();
			new_balance *= (1 + percentage / 100);
			account.set_account_balance(new_balance); // Update balance
		});
}

float Account::get_total_deposits() const {
	return std::accumulate(accounts.begin(), accounts.end(), 0.0f, [](float sum, const auto& pair) {
		return sum + pair.second.get_account_balance();
		});
}

//Needs to use Remove_if
void Account::remove_accounts(int account_id) {
	auto iter = accounts.find(account_id);
	if (iter != accounts.end()) {
		accounts.erase(iter);
		std::cout << "Account with ID " << account_id << " has been removed.\n" << std::endl;
	}
	else {
		std::cout << "Account with ID " << account_id << " was not found.\n" << std::endl;
	}
}

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

	std::for_each(accounts.begin(), accounts.end(), [](const auto& pair) {
		const int& account_id = pair.first;
		const Account& account = pair.second;

		std::cout << "Account ID: " << account_id << " | Account Name: " << account.account_name << " | Account Balance: $" << account.account_balance << std::endl;
		});
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

Account& Account::operator*=(float percentage) {
	account_balance *= (1 + percentage / 100.0f);
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
