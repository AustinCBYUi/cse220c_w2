#include "account.h"
#include <string>
#include <iostream>

int Account::next_id = 0;

Account::Account() : account_id(next_id++), account_balance(0.0f) {
	account_name = "";
}

void Account::inputAccountInfo() {
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


//************************************************************************************************************************************************************************************
//************************** UNUSED METHODS ******************************\\
//************************************************************************************************************************************************************************************
//***Unused***
void Account::add_to_account_balance(float amount) {
	account_balance += amount;
}
//***Unused***
void Account::subtract_from_account_balance(float amount) {
	account_balance -= amount;
}
