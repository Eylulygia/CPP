#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstddef>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
public:
    PhoneBook();

    void add(const Contact &contact);
    void list() const;
    bool showContact(std::size_t index) const;
    std::size_t size() const;

private:
    Contact _contacts[8];
    std::size_t _size;
    std::size_t _nextIndex;

    static std::string shorten(const std::string &field);
};

#endif
