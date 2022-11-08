#include "Teacher.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#define TEACHER_BORROW_DURATION 50
#define TEACHER_BORROW_LIMIT 15

/*
bool Teacher::auth(std::string usr, std::string pas) {
    //code to input the file to a dtatabase opf login info
    //code to check the data for the matching usr and password 
    //if (usr and pas match atb the saem
    username = usr;
    password = pas;
    return (1);
    
    //else {
   // return 0;
}
 */

UserData Teacher::get_userdata(std::istream& in)
{
    std::string username;
    std::cout << "Enter a username: ";
    in >> username;
    UserData invalid = { "INVALID", {} };
    for (UserData data : database) {
        if (data.username == username) {
            return data;
        }
    }
    return invalid;
}

void Teacher::print_userdata(UserData data) {
    if (data.username == "INVALID") {
        std::cout << "User is not in the database." << std::endl;
        return;
    }
    std::cout << "Username: " << data.username << std::endl;
    // std::cerr << "Entering foreach" << std::endl;
    for (Book book : data.borrowed_books_teacher) {
        // std::cerr << "printing "; 
        std::cout << book.title << " is due in " << book.due_in << " days." << std::endl;
    }
    std::cout << std::endl;
}

void Teacher::update_day(int day, int id) {
    for (UserData data : database) {
        for (Book book : data.borrowed_books_teacher) {
            if (book.id == id)
                 book.due_in -= day;
        }
    }
}

int Teacher::index_of_username(std::string username) {
    // DEBUG std::cout << "to search: " << username << std::endl;
    int not_found = -1, index = 0;
    for (UserData data : database) {
        // DEBUG std::cout << data.username << std::endl;
        if (data.username == username) {
            return index;
        }
        index++;
    }
    return not_found;
}

Teacher::Teacher()
{
    fill_creds();
    for (std::string username : usernames) {
        database.push_back({ username, {}, {} });
    }
}

int Teacher::getNumCopy()
{
    return numCopies;
}
int Teacher::getBorrow()
{
    return maxBorrow;
}
std::string Teacher::GetUsername()
{
    return session_username;
}
std::string Teacher::GetPassword()
{
    return session_password;
}


void Teacher::clear_history()
{
    database.erase(database.begin(), database.end());
}

Book Teacher::return_book_teacher(Library lib, int id) {
    Book to_return = {-1, "", "", "", -1, -1};
    int index = -1;
    for (Book book : database[index_in_database].borrowed_books_teacher) {
        if (book.id == id) {
            to_return = book;
            break;
        }
        index++;
    }
    if (index > -1) {
        database[index_in_database].borrowed_books_teacher.erase(database[index_in_database].borrowed_books_teacher.begin() + index);
    }
    return to_return;
}

Book Teacher::renew_book_teacher(int id)
{
    Book invalid = {-1, "", "", "", -1, -1};
    for (Book book : database[index_in_database].borrowed_books_teacher) {
        if (book.id == id) {
            book.due_in = TEACHER_BORROW_DURATION;
            return book;
        }
    }
    return invalid;
}

void Teacher::borrow_book_teacher(Library lib, int id)
{
    // std::cout << user_index;
    Book book = *(lib.search_id(id));
    if (book.due_in > 0) {
        std::cout << "That copy is on loan. Please try another ID." << std::endl;
    } else {
        book.due_in = TEACHER_BORROW_DURATION;
        database[index_in_database].borrowed_books_teacher.push_back(book);
    }
}
    
    /*
    //current_teacher_books.push(lib.borrow_book(query_id, deadline));



    //search through the catalog till the book with the id
    //  using search_id in the library class
    //copy that info into our own vector of structs aka the history of the user
    //update the due_in value to 50 days
    //print out statement saying "check out successful!"
    Book* book_ptr = search_id(id);
    update_day(50, id);
    Book book1;
    for (UserData data : database)
    {
        for (Book book : data.borrowed_books_teacher)
        {
            if (data.current_teacher_books.size() <= 10)
            {
                std::cout << "You have too many books! Return a book before checking out another!" << std::endl;
            }
            else
            {
                if (book.id == book_ptr->id)
                {
                    data.borrowed_books_teacher.push_back(book);
                    data.current_teacher_books.push_back(book);
                    std::cout << "Check out successful!" << std::endl;
                }
            }
        }
    }
}
 */


void Teacher::update_day(int day) {
    for (UserData data : database) {
        for (Book book : data.current_teacher_books) {
            book.due_in -= day;
        }
    }
}

int Teacher::menu(Library &lib) {

    char expression = 'a';
    //library ascii art goes here
    double last_event_time = 0.00;
    double this_event_time = 0.00;
    int days_passed = 0;
    //char c;
    int query_id;
    int days_due = 900;
    Book renewed, returned, last;
    long long int new_isbn;
    std::string new_title, new_author, new_category;

    while (expression != '0') {
        //std::cout << "press c AND ENTER (simulate menu choice) ";
        //std::cin >> c;
        this_event_time = clock();
        days_passed = (int)(((fabs(last_event_time - this_event_time)) / 1000) / 5);
        //std::cout << "Days passed: " << days_passed << std::endl;
        last_event_time = this_event_time;
        days_due = days_due - days_passed;
       // Teacher::update_day(days_passed);
       // Library::update_day(days_passed);

        //mingi code: use this code below to pass in what you need
        //books.duein(days_passed);
        //std::cout << std::endl << "days remaining: " << days_due << std::endl;

        //pass days_passed into mingis timing fucntion


        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "~      " << "Library Options" << std::setw(8) << "~" << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "\nYou are logged in as: " << session_username << std::endl << std::endl;
        std::cout << "(1) - Search Book" << std::endl;
        std::cout << "(2) - Borrow Book" << std::endl;
        std::cout << "(3) - Return Book" << std::endl;
        std::cout << "(4) - Renew Book" << std::endl;
        std::cout << "(5) - Request Book" << std::endl; // TEACHER ONLY
        std::cout << "(6) - Remove Book" << std::endl; //TEACHER ONLY
        std::cout << "(7) - View Borrowed Books" << std::endl;
        std::cout << "(0) - Log Out " << std::endl;
        std::cout << "\nPlease select an option. ";
        std::cout << std::endl << "Enter a command: ";
        std::cin >> expression;

        switch (expression) {
            case '1': {
                std::cout << "Enter the ID of the book youd like to search by: ";
                std::cin >> query_id;
                Book result = *(lib.search_id(query_id));
                if (result.isbn == -1) {
                    std::cout << "The book with ID " << query_id << " was not found!" << std::endl << std::endl;
                } else {
                    lib.print_book(result);
                }
                break;
            }
            case '2':
                if (session_has_overdue_books()) {
                    std::cout << "You must return overdue books first!" << std::endl;
                    break;
                }
                if (session_exceeded_books_limit()) {
                    std::cout << "You are at your borrow limit! Return a book first." << std::endl;
                    break;
                }
                std::cout << "Enter the ID of the book you would like to borrow: ";
                std::cin >> query_id;
                borrow_book_teacher(lib, query_id);
                lib.set_loan_duration(query_id, TEACHER_BORROW_DURATION);  // ??
                std::cout << std::endl;
                print_userdata(database[index_in_database]);
                // lib.print_book(database[index_of_username(session_username)].borrowed_books_teacher[0]);
                // lib.print_all_books();
                break;
            case '3':
                std::cout << "Enter the ID of the book you would like to return: ";
                std::cin >> query_id;
                returned = return_book_teacher(lib, query_id);
                if (returned.isbn != -1) {
                    lib.set_loan_duration(query_id, -1);
                    std::cout << "Returned " << returned.title << "! Thank you." << std::endl;
                } else {
                    std::cout << "You have not borrowed that book! Try another." << std::endl;
                }
                break;
            case '4':
                std::cout << "Enter the ID of the book you would like to renew: ";
                std::cin >> query_id;
                renewed = renew_book_teacher(query_id);
                if (renewed.isbn != -1) {
                    std::cout << "Renewed " << renewed.title <<  "! You have " << TEACHER_BORROW_DURATION << " days to return it." << std::endl;
                } else {
                    std::cout << "You have not borrowed that book! Try another." << std::endl;
                }
                break;
            case '5':
                std::cout << "Enter the ISBN, title, author, and category (Separate values by spaces and use snake_case for strings): ";
                std::cin >> new_isbn >> new_title >> new_author >> new_category;
                lib.add_book(new_isbn, new_title, new_author, new_category);
                std::cout << "Added the book! Its internal ID is " << lib.get_last_book().id << "." << std::endl;
                break;
            case '6':
                std::cout << "Enter the ID of the book you want to remove from the catalog: ";
                std::cin >> query_id;
                last = lib.get_last_book();
                lib.delete_book(query_id);
                std::cout << "Removed book:" << std::endl;
                lib.print_book(last);
                break;
            case '7':
                print_userdata(database[index_in_database]);
                break;
            case '8':
                print_all_users_in_db();
                break;
            case '9':
                lib.print_all_books();
                break;
            case '0':
                break;
        }
    }
    return 0;
}

void Teacher::request_book(Library lib, long long int isbn, std::string title, std::string author, std::string category) {
    lib.add_book(isbn, title, author, category);
}

void Teacher::fill_creds() {
    // fstream student is opened with "students.txt"
    std::ifstream student;
    student.open("student.txt");
    bool role;
    std::string id, pw;
    while (!student.eof()) {
        student >> role >> id >> pw;
        if (!role) {
            usernames.push_back(id);
            passwords.push_back(pw);
        }
    }
}

bool Teacher::check_auth(std::string id, std::string pw) {
    for (int i = 0; i < usernames.size(); ++i) {
        if (id == usernames[i]) {
            if (pw == passwords[i]) {
                session_username = usernames[i];
                session_password = passwords[i];
                index_in_database = i;
                return true;
            }
            else {
                break;
            }
        }
    }
    return false;
}

void Teacher::print_all_users_in_db() {
    for (UserData data : database) {
        std::cout << data.username << " ";
    }
    std::cout << std::endl;
}

bool Teacher::session_has_overdue_books() {
    for (Book book : database[index_in_database].borrowed_books_teacher) {
        if (!book.due_in) {
            return true;
        }
    }
    return false;
}

bool Teacher::session_exceeded_books_limit() {
    return database[index_in_database].borrowed_books_teacher.size() < TEACHER_BORROW_LIMIT ? false : true;
}