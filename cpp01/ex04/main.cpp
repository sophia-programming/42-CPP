#include "replace.hpp"
#include <iostream>

std::string readFile(const std::string &fileName)
{
	std::ifstream ifs(fileName);
	if (ifs.fail()) {
		std::cout << RedColor << "Failure in reading input file stream" << StopColor << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string fileContent;
	std::string nextLine;
	while (true) {
		if (!std::getline(ifs, nextLine))
			break ;
		fileContent += nextLine;
		fileContent += '\n';
	}
	if (fileContent.empty()) {
		std::cout << RedColor << "The file is empty." << StopColor << std::endl;
		exit(EXIT_FAILURE);
	}
	return fileContent;
}

void replaceString(std::string &fileContent, const std::string &s1, const std::string &s2)
{
	size_t position = 0;
	const size_t s1len = s1.length();
	const size_t s2len = s2.length();

	while (true) {
		position = fileContent.find(s1, position);
		if (position == std::string::npos) {
			break ;
		} else {
			fileContent.erase(position, s1len);
			fileContent.insert(position, s2);
			position += s2len;
		}
	}
}

void writeFile(const std::string &fileName, const std::string &fileContent)
{
	std::ofstream ofs(fileName + ".replace");
	if (ofs.fail()) {
		std::cout << RedColor << "Failure in writing output file stream" << StopColor << std::endl;
	}
	ofs << fileContent;
}

bool isStrEmpty(const std::string &s1, const std::string &s2)
{
	if (s1.empty() == true || s2.empty() == true) {
		std::cerr << RedColor << "Please avoid empty string..." << StopColor << std::endl;
		return true;
	}
	return false;
}

void replace(const std::string &fileName, const std::string &s1, const std::string &s2)
{
	if (isStrEmpty(s1, s2) == true) {
		exit (EXIT_FAILURE);
	}
	std::string fileContent = readFile(fileName);
	replaceString(fileContent, s1, s2);
	writeFile(fileName, fileContent);
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 4) {
		replace(std::string(argv[1]),std::string(argv[2]),std::string(argv[3]));
	} else {
		std::cerr << "Invalid argument count." << std::endl;
		printUsage();
	}
}
