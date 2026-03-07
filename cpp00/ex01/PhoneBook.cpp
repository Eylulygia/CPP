#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : _size(0), _nextIndex(0)
{
}

void PhoneBook::add(const Contact &contact)
{
	_contacts[_nextIndex] = contact;
	_nextIndex = (_nextIndex + 1) % 8;
	if (_size < 8)
		++_size;
}

std::size_t PhoneBook::size() const
{
	return _size;
}

std::string PhoneBook::shorten(const std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void PhoneBook::list() const
{
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	for (std::size_t i = 0; i < _size; ++i)
	{
		std::cout << std::setw(10) << (i + 1) << "|"
				  << std::setw(10) << shorten(_contacts[i].getFirstName()) << "|"
				  << std::setw(10) << shorten(_contacts[i].getLastName()) << "|"
				  << std::setw(10) << shorten(_contacts[i].getNickname()) << std::endl;
	}
}

bool PhoneBook::showContact(std::size_t index) const
{
	if (index >= _size || _contacts[index].isEmpty())
		return false;

	const Contact &c = _contacts[index];
	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
	return true;
}
