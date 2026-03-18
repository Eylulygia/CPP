#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain& src) {
    std::cout << "Brain copy constructor" << std::endl;
    *this = src;
}

Brain& Brain::operator=(const Brain& src) {
    std::cout << "Brain copy assignment" << std::endl;
    if (this != &src) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = src.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        this->ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return this->ideas[index];
    }
    return std::string();
}
