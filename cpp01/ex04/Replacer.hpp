#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replacer {
public:
	static int process(const std::string& filename, const std::string& s1, const std::string& s2);

private:
	static std::string replaceAll(std::string content, const std::string& s1, const std::string& s2);
};

#endif
