#include <iostream>
#include <fstream>
#include "Library.h"

Library::Library() {
    std::ifstream books, users;

    long long int isbn;
    std::string title;
    std::string author;
    std::string category;
    int copies;

    int is_teacher;
    std::string username;
    std::string password;

    Book book;
    User user;

    int consec_id = 0;

    books.open("book.txt");
    if (books.fail()) {
        std::cerr << "Could not open books file!" << std::endl;
        exit(1);
    }
    
    users.open("student.txt");
    if (users.fail()) {
        std::cerr << "Could not open credentials file!";
        exit(1);
    }

    while (!books.eof()) {
        books >> isbn >> title >> author >> category >> copies;
        for (int i = 0; i < copies; i++) {
            book = {isbn, title, author, category, consec_id};
            this->catalog.push_back(book);
            consec_id++;
        }
    }
    number_of_books = consec_id - 1;

    while (!users.eof()) {
        users >> is_teacher >> username >> password;
        user = {is_teacher, username, password};
        this->credentials.push_back(user);
    }
}

void Library::print_book(Book book) {
    std::cout << "ISBN:     " << book.isbn << std::endl;
    std::cout << "Title:    " << book.title << std::endl;
    std::cout << "Author:   " << book.author << std::endl;
    std::cout << "Category: " << book.category << std::endl;
    std::cout << "Intrn ID: " << book.id << std::endl << std::endl;
}

void Library::print_books_vector(std::vector<Book> bookvec) {
    for (Book book : bookvec)  {
        print_book(book);
    }
}

void Library::print_all_books() {
    for (Book book : catalog) {
        print_book(book);
    }
}

User Library::search_user(std::string username) {
    User placeholder = {-1, "n/a", "n/a"};
    for (User user : credentials) {
        if (user.username == username) {
            return user;
        }
    }
    return placeholder;
}

void Library::print_user(User user) {
    if (user.is_teacher) {
        std::cout << "User type: Teacher";
    } else {
        std::cout << "User type: Student";
    }
    std::cout << "Username: " << user.username << std::endl;
    std::cout << "Password: " << user.password << std::endl << std::endl;
}