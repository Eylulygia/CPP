#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    Animal* pack[4];
    pack[0] = new Dog();
    pack[1] = new Cat();
    pack[2] = new Animal();
    pack[3] = new Dog();
    for (int k = 0; k < 4; ++k) {
        pack[k]->makeSound();
    }
    for (int k = 0; k < 4; ++k) {
        delete pack[k];
    }

    Dog original;
    Dog copy(original);
    Dog assigned;
    assigned = original;
    original.makeSound();
    copy.makeSound();
    assigned.makeSound();

    WrongAnimal* wrong = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();
    wrong->makeSound();
    wrongCat->makeSound();
    delete wrong;
    delete wrongCat;

    WrongCat directWrongCat;
    directWrongCat.makeSound();

    delete i;
    delete j;
    delete meta;
    return 0;
}
