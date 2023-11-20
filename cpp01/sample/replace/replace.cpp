#include <iostream>
#include <string>
#include <istream>
#include <ostream>
#include <fstream>

std::string readFile(const std::string &fileName)
{
	std::string fileContent;
	std::ifstream ifs(fileName);
	if (ifs.fail()) {
		std::cout << "Failed to open file!" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	while (true) {
		if (!getline(ifs, line)) {
			break ;
		} else {
			fileContent += line;
			fileContent += '\n';
		}
	}
	return fileContent;
}

void replaceContent(std::string &fileContent, std::string s1, std::string s2)
{
	size_t pos = 0;
	size_t s1len = s1.length();
	while (true) {
		pos = fileContent.find(s1, pos);
		if (pos == std::string::npos) {
			break ;
		} else {
			fileContent.erase(pos, s1len);
			fileContent.insert(pos, s2);
		}
		pos += s1len;
	}
}

void writeFile(const std::string &fileName, const std::string &fileContent)
{
	std::ofstream ofs(fileName + ".replace");
	if (ofs.fail()) {
		std::cout << "Failure in OFS" << std::endl;
		exit(EXIT_FAILURE);
	} else {
		ofs << fileContent;
	}
}

void replace(std::string fileName, std::string s1, std::string s2)
{
	/* ifs */
	std::string fileContent = readFile(fileName);

	/* main replace working */
	replaceContent(fileContent, s1, s2);
	/*
	 * refarenceは本当に引数に渡す時に&をつけるかつけないかだけでpolonger以上に
	 * 忘れやすいと思った。なのでその点は注意。
	 */

	/* ofs */
	writeFile(fileName, fileContent);
}

int main(int argc, char **argv)
{
	if (argc == 4) {
		std::string fileName(argv[1]);
		std::string s1(argv[2]);
		std::string s2(argv[3]);
		replace(fileName, s1, s2);
	} else {
		std::cerr << "Invalid argc" << std::endl;
		exit (EXIT_FAILURE);
	}
}
