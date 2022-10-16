#include "Student.h"
#include <iostream>

Student::Student() {
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
        std::cout << pair.title << " is due in " << pair.due << " days." << std::endl;
    }
    std::cout << std::endl;
}