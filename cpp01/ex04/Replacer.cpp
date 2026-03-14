#include "Replacer.hpp"

std::string Replacer::replaceAll(std::string content, const std::string& s1, const std::string& s2) {
	if (s1.empty())
		return content;

	std::string result;
	size_t pos = 0;
	size_t lastPos = 0;

	while ((pos = content.find(s1, lastPos)) != std::string::npos) {
		result += content.substr(lastPos, pos - lastPos);
		result += s2;
		lastPos = pos + s1.length();
	}
	
	result += content.substr(lastPos);
	return result;
}

int Replacer::process(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open()) {
		std::cout << "Error: Could not open file '" << filename << "'" << std::endl;
		return 1;
	}

	std::string content;
	std::string line;
	while (std::getline(inFile, line)) {
		content += line;
		if (!inFile.eof())
			content += "\n";
	}
	inFile.close();
	std::string finalContent = replaceAll(content, s1, s2);

	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile.is_open()) {
		std::cout << "Error: Could not create output file." << std::endl;
		return 1;
	}
	outFile << finalContent;
	outFile.close();

	return 0;
}
