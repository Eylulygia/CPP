#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define RESET   "\033[0m"
# define GREY    "\033[90m"
# define CYAN    "\033[36m"
# define YELLOW  "\033[33m"
# define RED     "\033[31m"

class Harl {
public:
	Harl();
	~Harl();

	void complain(std::string level);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

// Üye fonksiyon işaretçisi tanımı için kısa yol (opsiyonel ama okunabilirliği artırır)
typedef void (Harl::*HarlMemPtr)(void);

#endif
