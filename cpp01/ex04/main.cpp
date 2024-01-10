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
		if (!getline(ifs, nextLine))
			break ;
		fileContent += nextLine;
		fileContent += '\n';
	}
	return fileContent;
}

void replaceString(std::string &fileContent, const std::string &s1, const std::string &s2)
{
	size_t pos = 0;
	const size_t s1len = s1.length();

	while (true) {
		pos = fileContent.find(s1, pos);
		if (pos == std::string::npos) {
			break ;
		} else {
			fileContent.erase(pos, s1len);
			fileContent.insert(pos, s2);
			pos += s1len;
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
