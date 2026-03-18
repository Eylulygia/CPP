#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 6;
    AAnimal* animals[size];
    for (int i = 0; i < size; ++i) {
        if (i < size / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }

    Dog dog1;
    dog1.setIdea(0, "chew a bone");
    Dog dog2(dog1);
    dog1.setIdea(0, "guard the house");
    std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;

    Cat cat1;
    cat1.setIdea(1, "stalk the curtains");
    Cat cat2;
    cat2 = cat1;
    cat1.setIdea(1, "jump onto the bookshelf");
    std::cout << "cat1 idea: " << cat1.getIdea(1) << std::endl;
    std::cout << "cat2 idea: " << cat2.getIdea(1) << std::endl;

    return 0;
}
