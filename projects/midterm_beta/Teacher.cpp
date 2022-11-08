#include "Teacher.h"
#include<fstream>
#include<vector>
#include<iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <chrono>

TeacherData Teacher::get_userdata(std::istream& in)
{
    std::string username;
    std::cout << "Enter a username: ";
    in >> username;
    TeacherData invalid = { "INVALID", {} };
    for (TeacherData data : database) {
        if (data.username == username) {
            return data;
        }
    }
    return invalid;
}

void Teacher::print_userdata(TeacherData data) {
    if (data.username == "INVALID") {
        std::cout << "User is not in the database." << std::endl;
        return;
    }
    std::cout << "Username: " << data.username << std::endl;
    // std::cerr << "Entering foreach" << std::endl;
    if (data.borrowed_books_teacher.empty()) {
        std::cout << "You have not borrowed any books!" << std::endl;
        return;
    }
    for (Book book : data.borrowed_books_teacher) {
        if (book.due_in == 0) {
            std::cout << book.title << " is overdue! Make sure to return it." << std::endl;
        } else {
            std::cout << book.title << " is due in " << (int) book.due_in << " days." << std::endl;
        }
    }
    std::cout << std::endl;
}

int Teacher::index_of_username(std::string username) {
    // DEBUG std::cout << "to search: " << username << std::endl;
    int not_found = -1, index = 0;
    for (TeacherData data : database) {
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
    int index = 0;
    bool found = false;
    for (Book book : database[index_in_database].borrowed_books_teacher) {
        if (book.id == id) {
            to_return = book;
            found = true;
            break;
        }
        index++;
    }
    if (found) {
        database[index_in_database].borrowed_books_teacher.erase(database[index_in_database].borrowed_books_teacher.begin() + index);
    }
    return to_return;
}

Book Teacher::renew_book_teacher(int id)
{
    Book invalid = {-1, "", "", "", -1, -1};
    for (int i = 0; i < database[index_in_database].borrowed_books_teacher.size(); ++i) {
        if (database[index_in_database].borrowed_books_teacher[i].id == id) {
            database[index_in_database].borrowed_books_teacher[i].due_in = TEACHER_BORROW_DURATION;
            return database[index_in_database].borrowed_books_teacher[i];
        }
    }
    return invalid;
}

bool Teacher::borrow_book_teacher(Library lib, int id)
{
    // std::cout << user_index;
    Book book = *(lib.search_id(id));
    if (book.isbn == -1) {
        std::cout << "The book was not found!" << std::endl;
        return false;
    }
    if (book.due_in >= 0) {
        std::cout << "That copy is on loan. Please try another ID." << std::endl;
        return false;
    } else {
        book.due_in = TEACHER_BORROW_DURATION;
        database[index_in_database].borrowed_books_teacher.push_back(book);
        return true;
    }
}

void Teacher::update_day(double day) {
    for (int user_iter = 0; user_iter < database.size(); ++user_iter) {
        for (int book_iter = 0; book_iter < database[user_iter].borrowed_books_teacher.size(); ++book_iter) {
            // std::cerr << book.due_in << " " << day << " ";
            if (database[user_iter].borrowed_books_teacher[book_iter].due_in > 0) {
                // book.due_in -= 3;
                database[user_iter].borrowed_books_teacher[book_iter].due_in -= day;
                if (database[user_iter].borrowed_books_teacher[book_iter].due_in < 0) {
                    database[user_iter].borrowed_books_teacher[book_iter].due_in = 0;
                }
                // std::cerr << book.due_in << std::endl;
            }
        }
    }
}

int Teacher::menu(Library &lib) {

    char expression = 'a';
    int commandchosen;
    int query_id;
    Book renewed, returned, deleted;
    long long int new_isbn;
    std::string new_title, new_author, new_category;
    double days_passed;
    std::__1::chrono::steady_clock::time_point end;
    bool success;

    auto start = std::chrono::steady_clock::now();
    std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "~      " << "Library Options" << std::setw(8) << "~" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "\nYou are logged in as: " << session_username << " (Teacher)" << std::endl << std::endl;
    std::cout << "(1) - Search Book" << std::endl;
    std::cout << "(2) - Borrow Book" << std::endl;
    std::cout << "(3) - Return Book" << std::endl;
    std::cout << "(4) - Renew Book" << std::endl;
    std::cout << "(5) - Request Book" << std::endl; // TEACHER ONLY
    std::cout << "(6) - Remove Book" << std::endl;  // TEACHER ONLY
    std::cout << "(7) - View Borrowed Books" << std::endl;
    std::cout << "(9) - List Library Catalog" << std::endl;
    std::cout << "(0) - Log Out " << std::endl;
    std::cout << "\nPlease select an option. ";
    std::cout << std::endl << "Enter a command: ";
    std::cin >> expression;
    switch (expression) {
        case '1': {
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            lib.update_day(days_passed);
            std::cout << "Enter the ID of the book youd like to search by: ";
            std::cin >> query_id;
            Book result = *(lib.search_id(query_id));
            if (result.isbn == -1) {
                std::cout << "The book with ID " << query_id << " was not found!" << std::endl << std::endl;
            } else {
                lib.print_book(result);
            }
            commandchosen = 1;
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            update_day(days_passed);
            break;
        }
        case '2':
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            lib.update_day(days_passed);
            if (session_has_overdue_books()) {
                std::cout << "You must return overdue books first!" << std::endl;
                break;
            }
            if (session_exceeded_books_limit()) {
                std::cout << "You are at your borrow limit! Return some books first." << std::endl;
                break;
            }
            std::cout << "Enter the ID of the book you would like to borrow: ";
            std::cin >> query_id;
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            update_day(days_passed);
            success = borrow_book_teacher(lib, query_id);
            if (success) {
                lib.set_loan_duration(query_id, TEACHER_BORROW_DURATION);  // ??
            }
            std::cout << std::endl;
            print_userdata(database[index_in_database]);
            commandchosen = 1;
            break;
        case '3':
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            lib.update_day(days_passed);
            std::cout << "Enter the ID of the book you would like to return: ";
            std::cin >> query_id;
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            update_day(days_passed);
            returned = return_book_teacher(lib, query_id);
            if (returned.isbn != -1) {
                lib.set_loan_duration(query_id, -1);
                std::cout << "Returned " << returned.title << "! Thank you." << std::endl;
            } else {
                std::cout << "You have not borrowed that book! Try another." << std::endl;
            }
            commandchosen = 1;
            break;
        case '4':
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            lib.update_day(days_passed);
            std::cout << "Enter the ID of the book you would like to renew: ";
            std::cin >> query_id;
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            update_day(days_passed);
            renewed = renew_book_teacher(query_id);
            if (renewed.isbn != -1) {
                lib.set_loan_duration(query_id, TEACHER_BORROW_DURATION);
                std::cout << "Renewed " << renewed.title <<  "! You have " << TEACHER_BORROW_DURATION << " days to return it." << std::endl;
            } else {
                std::cout << "You have not borrowed that book! Try another." << std::endl;
            }
            commandchosen = 1;
            break;
        case '5':
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            lib.update_day(days_passed);
            std::cout << "Enter the ISBN, title, author, and category (Separate values by spaces and use snake_case for strings): ";
            std::cin >> new_isbn >> new_title >> new_author >> new_category;
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            update_day(days_passed);
            lib.add_book(new_isbn, new_title, new_author, new_category);
            std::cout << "Added the book! Its internal ID is " << lib.get_last_book().id << "." << std::endl;
            commandchosen = 1;
            break;
        case '6':
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            lib.update_day(days_passed);
            std::cout << "Enter the ID of the book you want to remove from the catalog: ";
            std::cin >> query_id;
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            update_day(days_passed);
            success = lib.delete_book(query_id);
            if (success) {
                std::cout << "Removed book." << std::endl;
            } else {
                std::cout << "Book with ID " << query_id << " does not exist!" << std::endl;
            }
            commandchosen = 1;
            break;
        case '7':
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            lib.update_day(days_passed);
            update_day(days_passed);
            print_userdata(database[index_in_database]);
            commandchosen = 1;
            break;
        case '9':
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            lib.update_day(days_passed);
            update_day(days_passed);
            lib.print_all_books();
            commandchosen = 1;
            break;
        case '0':
            end = std::chrono::steady_clock::now();
            days_passed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / (1000.0 * SECONDS_PER_DAY);
            lib.update_day(days_passed);
            update_day(days_passed);
            commandchosen = 0;
            break;
        default:
            std::cout << "Invalid command! Try again." << std::endl << std::endl;
    }
    return commandchosen;
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
    for (TeacherData data : database) {
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