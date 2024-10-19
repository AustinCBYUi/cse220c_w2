#include <iostream>
#include <memory>
#include "Contact.h"

void Contact::set_contact_info() {
	std::cout << "Enter street address: ";
	std::getline(std::cin, street_address);
	std::cout << "Enter city: ";
	std::getline(std::cin, city);
	std::cout << "Enter state: ";
	std::getline(std::cin, state);
	std::cout << "Enter zip code: ";
	std::getline(std::cin, zip_code);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
}

void Contact::get_contact_info()const {
	std::cout << "Street Address: " << street_address << "\n";
	std::cout << "City: " << city << "\n";
	std::cout << "State: " << state << "\n";
	std::cout << "Zip Code: " << zip_code << "\n";
	std::cout << "Phone Number: " << phone_number << "\n" << std::endl;
}