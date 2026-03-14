#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void) {
	std::cout << GREY << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void) {
	std::cout << CYAN << "[ INFO ]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
	std::cout << YELLOW << "[ WARNING ]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error(void) {
	std::cout << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) {
	// 1. Fonksiyon işaretçilerinden oluşan bir dizi
	HarlMemPtr functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	
	// 2. Bu fonksiyonlara karşılık gelen isimler dizisi
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	// 3. Döngü ile eşleşeni bul ve "if-else" kullanmadan çağır
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])(); // İşte o sihirli çağrı!
			return;
		}
	}
	
	// Eşleşme yoksa (isteğe bağlı)
	std::cout << "[ UNKNOWN ]\n*Harl mumbles something incomprehensible about pickles.*\n" << std::endl;
}
