#include "Library.h"
#include "Teacher.h"
#include <iostream>

int main()
{
	Teacher teacher = Teacher();
	Library library = Library();
	//Student Stud;

	std::string LoggedinUser;
	std::string Password;
	std::string usr;
	std::string pas;
	bool valid_student, valid_teacher;
	int cont = 1;
	while (1) {
		std::cout << "Enter username and password, space-separated: ";
		std::cin >> usr;
		std::cin >> pas;
	//  valid_student = student.check_auth(usr, pas);
		valid_teacher = teacher.check_auth(usr, pas);
		while (valid_teacher /* || valid_student */) {  // Check if usr/pas combination either a valid Student or Teacher
			if (/*valid_student && valid_teacher */0) {  // If it is valid in both, error out of program
				std::cout << "ERROR! Username and Password are valid entries of both Student and Teacher." << std::endl;
				return 1;
			}
			if (valid_teacher && !teacher.menu(library)) {  // If it is valid teacher, then call menu from teacher
				break;  // Break if menu returns 0, and go back to enter usr/pas
			}
			/*
			if (valid_student && !student.menu(library)) {  // If it is valid student, then call menu from student
				break;  // Break if menu returns 0, and go back to enter usr/pass
			}
			 */
		}
	}

	/*
	std::string test1 = "Computer_science";
	Library lib;
	lib.searchBook_category(test1);
	//int sizeofvalues = (lib.searchBook_category(test1)).size();
	//std::cout << sizeofvalues << std::endl;
	 */
	return 0;
}