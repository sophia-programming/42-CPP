#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//gradeに大きな値（ex. 1000）を入れるとエラーが出る
int main() {
	ShrubberyCreationForm form("target");
	RobotomyRequestForm form2("Neko");
	PresidentialPardonForm form3("Dog");
	Bureaucrat b("Bureaucrat", 140);
	try {
		form.beSigned(b);
		form.execute(b);
		form2.beSigned(b);
		form2.execute(b);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
//
//int main() {
//	PresidentialPardonForm form("Universe");
//	Bureaucrat highRankBureaucrat("HighRank", 1); // 高ランクの役人
//	Bureaucrat lowRankBureaucrat("LowRank", 150); // 低ランクの役人
//
//	try {
//		std::cout << form << std::endl; // フォームの状態を表示
//
//		// 高ランクの役人でフォームに署名を試みる
//		highRankBureaucrat.signForm(form);
//		std::cout << form << std::endl; // 署名後のフォームの状態を表示
//
//		// フォームを実行
//		form.execute(highRankBureaucrat);
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//
//	return 0;
//}

//int main() {
//	PresidentialPardonForm form("Galaxy");
//	Bureaucrat lowRankBureaucrat("LowRank", 150); // 実行権限がない低ランクの役人
//
//	try {
//		lowRankBureaucrat.signForm(form); // 低ランクの役人で署名を試みる
//		form.execute(lowRankBureaucrat); // 署名できないため、実行もできないはず
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//
//	return 0;
//}

//int main() {
//	PresidentialPardonForm form("SolarSystem");
//	Bureaucrat highRankBureaucrat("HighRank", 1); // 高ランクの役人
//
//	try {
//		form.execute(highRankBureaucrat); // 署名されていないフォームの実行を試みる
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//
//	return 0;
//}

