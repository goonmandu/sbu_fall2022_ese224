#include "Student.h"
#include <iostream>

Student::Student() {
    /* BOOK TITLES ARE DEPRECATED, USE BOOK STRUCTS IN PLACE OF "bookN"*/
    database = {
        (UserData) {
            "john", { 
                (BookAndDue) {"book1", 7},
                (BookAndDue) {"book2", 3}
            }
        },
        (UserData) {
            "gabe", {
                (BookAndDue) {"book2", 3},
                (BookAndDue) {"book4", 3},
                (BookAndDue) {"book5", 4}
            }
        }
    };
};

UserData Student::get_userdata(std::istream& in) {
    std::string username;
    std::cout << "Enter a username: ";
    in >> username;
    UserData invalid = {"INVALID", {}};
    for (UserData data : database) {
        if (data.username == username) {
            return data;
        }
    }
    return invalid;
}

void Student::print_userdata(UserData data) {
    if (data.username == "INVALID") {
        std::cout << "User is not in the database." << std::endl;
        return;
    }
    std::cout << "Username: " << data.username << std::endl;
    for (BookAndDue pair : data.borrowed_books) {
        std::cout << pair.book << " is due in " << pair.due << " days." << std::endl;
    }
    std::cout << std::endl;
}

void Student::update_day(int day) {
    for (UserData data : database) {
        for (BookAndDue book : data.borrowed_books) {
            book.due -= day;
        }
    }
}

int Student::index_of_username(std::string username) {
    int not_found = -1, index = 0;
    for (UserData data : database) {
        if (data.username == username) {
            return index;
        }
        index++;
    }
    return not_found;
}