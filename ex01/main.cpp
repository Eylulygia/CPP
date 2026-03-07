#include <iostream>
#include <sstream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static bool readField(const std::string &label, std::string &out)
{
	while (true)
	{
		std::cout << label;
		if (!std::getline(std::cin, out))
			return false;
		if (!out.empty())
			return true;
		std::cout << "  Field cannot be empty. Try again." << std::endl;
	}
}

static void addContact(PhoneBook &phoneBook)
{
	Contact contact;
	std::string input;

	if (!readField("First name: ", input))
		return;
	contact.setFirstName(input);
	if (!readField("Last name: ", input))
		return;
	contact.setLastName(input);
	if (!readField("Nickname: ", input))
		return;
	contact.setNickname(input);
	if (!readField("Phone number: ", input))
		return;
	contact.setPhoneNumber(input);
	if (!readField("Darkest secret: ", input))
		return;
	contact.setDarkestSecret(input);
	phoneBook.add(contact);
	std::cout << "  >> Contact saved." << std::endl;
}

static void searchContact(const PhoneBook &phoneBook)
{
	if (phoneBook.size() == 0)
	{
		std::cout << "  PhoneBook is empty." << std::endl;
		return;
	}
	std::cout << "------------------------------------------" << std::endl;
	phoneBook.list();
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Enter index: ";
	std::string line;
	if (!std::getline(std::cin, line))
		return;
	std::istringstream iss(line);
	int idx = 0;
	if (!(iss >> idx) || idx < 1 || static_cast<std::size_t>(idx) > phoneBook.size())
	{
		std::cout << "  Invalid index." << std::endl;
		return;
	}
	std::cout << "------------------------------------------" << std::endl;
	phoneBook.showContact(static_cast<std::size_t>(idx - 1));
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "==========================================" << std::endl;
	std::cout << "       MY AWESOME PHONEBOOK" << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "  Commands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << std::endl;
	while (std::cout << "phonebook> " && std::getline(std::cin, command))
	{
		if (command == "ADD")
			addContact(phoneBook);
		else if (command == "SEARCH")
			searchContact(phoneBook);
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			std::cout << "  Unknown command. Use ADD, SEARCH or EXIT." << std::endl;
	}
	return 0;
}
