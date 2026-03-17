#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "\n--- CLAPTRAP TESTS ---" << std::endl;
    ClapTrap clappy("Clappy");
    clappy.attack("Target");

    std::cout << "\n--- SCAVTRAP TESTS ---" << std::endl;
    ScavTrap scavy("Scavy");               
    scavy.attack("EnemyDummy");            
    scavy.guardGate();                     

    std::cout << "\n--- FRAGTRAP TESTS (New Addition) ---" << std::endl;
    FragTrap fraggy("Fraggy");

    fraggy.attack("BossEnemy");

    fraggy.highFivesGuys();

    fraggy.takeDamage(25);
    fraggy.beRepaired(10);

    std::cout << "\n--- FRAGTRAP ORTHODOX CANONICAL FORM TESTS ---" << std::endl;
    FragTrap copyFraggy(fraggy);
    FragTrap assignedFraggy("AssignedFraggy");
    assignedFraggy = copyFraggy;

    std::cout << "\n--- DESTRUCTION PHASE ---" << std::endl;
    return 0;
}
