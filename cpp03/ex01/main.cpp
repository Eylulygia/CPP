#include "ScavTrap.hpp"

int main() {
    std::cout << "\n--- CLAPTRAP TESTS (Base functionality) ---" << std::endl;
    ClapTrap clappy("Clappy");
    clappy.attack("Target");

    std::cout << "\n--- SCAVTRAP TESTS (Construction + Derived functionality) ---" << std::endl;
    // Construction zincirini (chaining) göreceğiz. Önce ClapTrap çalışıp sonra ScavTrap çalışmalı
    ScavTrap scavy("Scavy");               
    
    // ScavTrap'in kendi saldırı fonksiyonu ve 20 hasarı çalışmalı
    scavy.attack("EnemyDummy");            
    
    // ClapTrap'in hasar alma fonksiyonunu kullanmalı (hasar alınca can 100'den 90'a düşecek)
    scavy.takeDamage(10);                  
    
    // ClapTrap'in tamir fonksiyonunu kullanmalı (can 95 olacak)
    scavy.beRepaired(5);                   
    
    // ScavTrap'in özel yeteneği
    scavy.guardGate();                     

    std::cout << "\n--- SCAVTRAP ORTHODOX CANONICAL FORM TESTS ---" << std::endl;
    ScavTrap copyScavy(scavy);             // Copy constructor
    ScavTrap assignedScavy("Assigned");
    assignedScavy = copyScavy;             // Copy assignment operator

    std::cout << "\n--- DESTRUCTION PHASE ---" << std::endl;
    // Blok bitince önce ScavTrap, sonra ClapTrap yıkıcıları çağrılmalı (Destruction chaining)
    return 0;
}
