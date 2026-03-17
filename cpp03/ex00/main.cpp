#include "ClapTrap.hpp"

int main() {
    // 1. Kurucu testleri (Constructor tests)
    std::cout << "\n--- CONSTRUCTOR TESTS ---" << std::endl;
    ClapTrap a;                     // Varsayılan (Default) kurucu
    ClapTrap b("ROB-01");           // İsim alan kurucu
    ClapTrap c(b);                  // Kopyalama (Copy) kurucusu
    ClapTrap d("TO-BE-OVERWRITTEN");
    d = b;                          // Kopyalama atama operatörü

    // 2. Aksiyon testleri (Action tests)
    std::cout << "\n--- ACTION TESTS ---" << std::endl;
    b.attack("TargetDummy");        // Normal saldırı (enerji 9 olur)
    b.takeDamage(5);                // 5 hasar alır (can 5 kalır)
    b.beRepaired(3);                // 3 tamir olur (can 8, enerji 8 olur)
    b.takeDamage(15);               // 15 hasar alır (can 0'a düşer, eksiye düşmez)

    // 3. Ölüm / Enerji tükenmesi testleri (Death / No Energy tests)
    std::cout << "\n--- DEATH AND ENERGY TESTS ---" << std::endl;
    b.attack("TargetDummy2");       // Canı 0 olduğu için saldıramamalı
    b.beRepaired(10);               // Canı 0 olduğu için tamir edememeli

    // a objesi için enerjiyi tamamen bitirme senaryosu
    std::cout << "\n--- ENERGY DEPLETION TEST ---" << std::endl;
    for (int i = 0; i < 11; i++) {
        a.attack("SpamTarget");     // 10 kere saldırır, 11'incide enerjisi olmaz
    }

    std::cout << "\n--- DESTRUCTOR TESTS ---" << std::endl;
    return 0;
}
